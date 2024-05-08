#include "Inventory.h"
#include "GlobalVariables.h"
#include "HomeMenu.h"
#include <fstream>
#include <string>

using namespace System::IO;
using namespace System::Collections;

namespace ProyectoFinal {
	int inventoryIndex = 0;

	bool Inventory::IsFileOpen(String^ filePath) {
		try {
			FileStream^ fs = File::Open(filePath, FileMode::OpenOrCreate, FileAccess::ReadWrite, FileShare::None);
			fs->Close();
			return false;
		}
		catch (IOException^) {
			return true;
		}
	}

    void Inventory::LoadInventoryData(String^ filePath, DataGridView^ grid) {
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

                // Procesar los valores
                if (isHeader) {
                    // Guardar las cabeceras
                    headerValues = safe_cast<array<String^>^>(valuesList->ToArray(String::typeid));
                    // Configurar las columnas si es el encabezado, solo la primera vez
                    for (int i = 0; i < headerValues->Length; i++) {
                        grid->Columns->Add(headerValues[i], headerValues[i]);
                    }
                    isHeader = false;
                }
                else {
                    // Convertir la lista de valores a un arreglo
                    array<String^>^ values = safe_cast<array<String^>^>(valuesList->ToArray(String::typeid));
                    // Agregar los datos como nuevas filas al DataGridView
                    grid->Rows->Add(values);
                    inventoryIndex = grid->Rows->Count - 1;
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


    void Inventory::SaveInventoryData(String^ filePath, DataGridView^ grid) {
        StreamWriter^ writer = gcnew StreamWriter(filePath);
        try {
            // Escribir las cabeceras
            for (int i = 0; i < grid->Columns->Count; i++) {
                writer->Write(grid->Columns[i]->Name);
                if (i < grid->Columns->Count - 1) {
                    writer->Write(",");
                }
            }
            writer->WriteLine();

            // Escribir los datos
            for (int i = 0; i < grid->Rows->Count; i++) {
                for (int j = 0; j < grid->Columns->Count; j++) {
                    // Verificar si la celda tiene un valor
                    if (grid->Rows[i]->Cells[j]->Value != nullptr) {
                        // Obtener el valor en la celda actual
                        String^ value = grid->Rows[i]->Cells[j]->Value->ToString();

                        // Checar si necesitamos encerrar el valor en comillas
                        if (j == 1 || j == 2 || j == 3 || j == 4) { // Asumiendo que las columnas 1, 2, 3 y 4 necesitan estar entrecomilladas
                            value = "\"" + value->Replace("\"", "\"\"") + "\""; // Escapar las comillas dentro del valor y encerrar el resultado en comillas
                        }

                        writer->Write(value);
                    }

                    if (j < grid->Columns->Count - 1) {
                        writer->Write(",");
                    }
                }
                writer->WriteLine();
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error al guardar los datos: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            writer->Close();
        }
    }


    void Inventory::ModifyInventoryViewData(DataGridView^ grid) {
        // Verificar si hay una fila seleccionada para modificar
        if (grid->SelectedRows->Count > 0) {
            DataGridViewRow^ selectedRow = grid->SelectedRows[0];

            // Obtener los nuevos valores de los campos de texto
            String^ productCode = productCodeText->Text;
            String^ productName = productNameText->Text;
            String^ productCategory = productCategoryComboBox->Text;
            String^ productLine = productLineText->Text;
            String^ productDescription = productDescriptionText->Text;
            String^ unitPrice = unitPriceText->Text;
            String^ productQuantity = productQuantityText->Text;

            // Actualizar los valores de la fila seleccionada en el DataGridView
            selectedRow->Cells["CódigoProducto"]->Value = productCode;
            selectedRow->Cells["Nombre"]->Value = productName;
            selectedRow->Cells["Categoría"]->Value = productCategory;
            selectedRow->Cells["Marca"]->Value = productLine; // Suponiendo que "Marca" se refiere a "productLineText"
            selectedRow->Cells["Descripción"]->Value = productDescription;
            selectedRow->Cells["PrecioUnitario"]->Value = unitPrice;
            selectedRow->Cells["CantidadStock"]->Value = productQuantity;
        }
        else {
            MessageBox::Show("Por favor, selecciona una fila para modificar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}