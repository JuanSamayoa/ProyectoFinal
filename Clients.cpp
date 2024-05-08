#include "GlobalVariables.h"
#include "Clients.h"
#include "HomeMenu.h"
#include <fstream>
#include <string>


using namespace System::IO;
using namespace System::Collections;

namespace ProyectoFinal{
int clientIndex = 0;

bool Clients::IsFileOpen(String^ filePath) {
    try {
        FileStream^ fs = File::Open(filePath, FileMode::OpenOrCreate, FileAccess::ReadWrite, FileShare::None);
        fs->Close();
        return false;
    }
    catch (IOException^) {
        return true;
    }
}

void Clients::LoadCustomerData(String^ filePath, DataGridView^ grid) {
    if (IsFileOpen(filePath)) {
        MessageBox::Show("No se puede continuar, el archivo está abierto, ciérralo e intenta de nuevo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    grid->Columns->Clear(); // Limpiamos las columnas antes de agregar nuevas
    grid->Rows->Clear();    // Aseguramos que el DataGridView esté limpio antes de cargar nuevos datos
    array<String^>^ headerValues = nullptr; // Almacenar las cabeceras

    StreamReader^ reader = gcnew StreamReader(filePath);
    try {
        String^ line;
        bool isHeader = true;

        while ((line = reader->ReadLine()) != nullptr) {
            // Variables para seguir el análisis del CSV
            bool inQuotes = false;
            String^ currentValue = "";
            ArrayList^ valuesList = gcnew ArrayList(); // ArrayList para almacenar los valores

            // Iterar sobre cada caracter de la línea
            for (int i = 0; i < line->Length; i++) {
                Char currentChar = line[i];

                // Manejar comillas dobles
                if (currentChar == '"') {
                    inQuotes = !inQuotes; // Cambiar el estado de las comillas
                }
                else if (currentChar == ',' && !inQuotes) {
                    // Si encontramos una coma fuera de las comillas, agregamos el valor actual a la lista
                    valuesList->Add(currentValue);
                    currentValue = ""; // Reiniciamos el valor actual para el próximo campo
                }
                else {
                    currentValue += currentChar; // Agregar el caracter al valor actual
                }
            }

            // Añadir el último valor a la lista
            valuesList->Add(currentValue);

            // Convertir la lista de valores a un arreglo
            array<String^>^ values = gcnew array<String^>(valuesList->Count);
            for (int i = 0; i < valuesList->Count; i++) {
                values[i] = safe_cast<String^>(valuesList[i]);
            }

            // Procesar los valores
            if (isHeader) {
                // Guardar las cabeceras
                headerValues = values;
                // Configurar las columnas si es el encabezado, solo la primera vez
                for (int i = 0; i < headerValues->Length; i++) {
                    grid->Columns->Add(gcnew DataGridViewTextBoxColumn());
                    grid->Columns[i]->Name = headerValues[i];
                }
                isHeader = false;
            }
            else {
                // Validar y corregir los valores según las especificaciones
                // 1. Validar el formato del código de cliente
                int codigoCliente;
                if (Int32::TryParse(values[0], codigoCliente)) {
                    // Código de cliente válido
                }
                else {
                    MessageBox::Show("Error: El código de cliente debe ser un número válido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    continue; // Pasar a la siguiente línea
                }

                // 2. No necesitamos corregir el formato del nombre

                // 3. No necesitamos corregir el formato de la dirección

                // 4. Validar y corregir el número de teléfono
                if (values[3]->Length > 8) {
                    // El número de teléfono tiene más de 8 dígitos, corregir
                    values[3] = values[3]->Substring(0, 8); // Tomar los primeros 8 dígitos
                }

                // 5. Validar el formato del correo electrónico
                if (!values[4]->Contains("@") || !values[4]->Contains(".")) {
                    MessageBox::Show("Error: El formato del correo electrónico es inválido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    continue; // Pasar a la siguiente línea
                }

                // Agregar los datos como nuevas filas al DataGridView
                grid->Rows->Add(values);
                clientIndex = grid->Rows->Count - 1;
            }
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al cargar los datos: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        reader->Close();
    }
}

// Métodos SaveCsvData y ModifyCsvData sin cambios
void Clients::SaveCustomerData(String^ filePath, DataGridView^ grid) {
    if (IsFileOpen(filePath)) {
        MessageBox::Show("No se puede continuar, el archivo está abierto, ciérralo e intenta de nuevo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    StreamWriter^ writer = gcnew StreamWriter(filePath);
    try {
        // Siempre escribir las cabeceras
        for (int i = 0; i < grid->ColumnCount; i++) {
            if (i == 1 || i == 2) {
                // Si es la columna de nombre o dirección, escribir la cabecera como string
                writer->Write("\"" + grid->Columns[i]->HeaderText + "\"");
            }
            else {
                writer->Write(grid->Columns[i]->HeaderText);
            }
            if (i < grid->ColumnCount - 1) {
                writer->Write(",");
            }
        }
        writer->WriteLine();

        // Escribir los datos
        for (int i = 0; i < grid->RowCount - 1; i++) {
            for (int j = 0; j < grid->ColumnCount; j++) {
                Object^ value = grid->Rows[i]->Cells[j]->Value;
                if (value != nullptr) {
                    String^ strValue = value->ToString();
                    if (j == 1 || j == 2) {
                        // Si es la columna de nombre o dirección, escribir el valor como string
                        writer->Write("\"" + strValue + "\"");
                    }
                    else {
                        writer->Write(strValue);
                    }
                }
                else {
                    // Si el valor es nulo, escribir una cadena vacía entre comillas dobles
                    writer->Write("\"\"");
                }
                if (j < grid->ColumnCount - 1) {
                    writer->Write(",");
                }
            }
            writer->WriteLine();
        }
    }
    finally {
        writer->Close();
    }
}


void Clients::ModifyCustomerViewData(DataGridView^ grid) {
    // Verificar si hay una fila seleccionada para modificar
    if (grid->SelectedRows->Count > 0) {
        DataGridViewRow^ selectedRow = grid->SelectedRows[0];

        // Obtener los nuevos valores de la fila desde los campos de texto
        String^ name = clientNameText->Text;
        String^ address = clientAddressText->Text;
        String^ phone = clientPhoneText->Text;
        String^ email = clientEmailText->Text;

        // Actualizar los valores de la fila seleccionada en el DataGridView
        selectedRow->Cells[1]->Value = name;
        selectedRow->Cells[2]->Value = address;
        selectedRow->Cells[3]->Value = phone;
        selectedRow->Cells[4]->Value = email;
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para modificar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
}