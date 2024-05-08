#include "Users.h"
#include "HomeMenu.h"
#include "GlobalVariables.h"
#include <fstream>
#include <string>

using namespace System::IO;
using namespace System::Collections;
using namespace System::Globalization;

namespace ProyectoFinal {
    int userIndex = 0;

    //Metodo validador para verificar si se esta haciendo uso del archivo csv
	bool Users::IsFileOpen(String^ filePath) {
		try {
			FileStream^ fs = File::Open(filePath, FileMode::OpenOrCreate, FileAccess::ReadWrite, FileShare::None);
			fs->Close();
			return false;
		}
		catch (IOException^) {
			return true;
		}
	}

    //Metodo para cargar la informacion de usuarios contenida en el archivo csv
    void Users::LoadUsersData(String^ filePath, DataGridView^ grid) {
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

                // Agregar el último valor a la lista
                valuesList->Add(currentValue);

                // Si es la primera línea, es la cabecera
                if (isHeader) {
                    headerValues = safe_cast<array<String^>^>(valuesList->ToArray(String::typeid));
                    for (int i = 0; i < headerValues->Length; i++) {
                        grid->Columns->Add(headerValues[i], headerValues[i]);
                    }
                    isHeader = false;
                }
                else {
                    // Si no es la cabecera, es un registro
                    array<String^>^ rowValues = safe_cast<array<String^>^>(valuesList->ToArray(String::typeid));

                    // Convertir el tipo de usuario a mayúscula inicial si es necesario
                    if (rowValues[2]->ToLower() == "administrador" || rowValues[2]->ToLower() == "operador") {
                        rowValues[2] = CultureInfo::CurrentCulture->TextInfo->ToTitleCase(rowValues[2]->ToLower());
                    }

                    grid->Rows->Add(rowValues);
                }
            }
        }
        finally {
            reader->Close();
        }
    }

    //Metodo para guardar la informacion de los usuarios que se encuentra activa en el datagridview
    void Users::SaveUsersData(String^ filePath, DataGridView^ grid) {
        if (IsFileOpen(filePath)) {
            MessageBox::Show("No se puede continuar, el archivo está abierto, ciérralo e intenta de nuevo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        StreamWriter^ writer = gcnew StreamWriter(filePath);

        try {
            // Escribir la cabecera
            for (int i = 0; i < grid->Columns->Count; i++) {
                writer->Write(grid->Columns[i]->HeaderText);
                if (i < grid->Columns->Count - 1) {
                    writer->Write(",");
                }
            }
            writer->WriteLine();

            // Escribir los registros
            for (int i = 0; i < grid->Rows->Count - 1; i++) { // Iterar solo hasta grid->Rows->Count - 1
                for (int j = 0; j < grid->Columns->Count; j++) {
                    String^ value = Convert::ToString(grid->Rows[i]->Cells[j]->Value);
                    if (j == grid->Columns->Count - 1 && grid->Columns[j]->HeaderText == "Dirección") {
                        // Si es la columna de dirección, agregar comillas
                        writer->Write("\"" + value + "\"");
                    }
                    else {
                        // De lo contrario, escribir el valor sin comillas
                        writer->Write(value);
                    }
                    if (j < grid->Columns->Count - 1) {
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


    //Metodo para modificar la informacion de los usuarios que se encuentra activa en el datagridview
	void Users::ModifyUsersViewData(String^ filePath, DataGridView^ grid) {
		// Verificar si hay una fila seleccionada para modificar
		if (grid->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = grid->SelectedRows[0];

			// Obtener los nuevos valores de los campos de texto
			String^ username = userUsernameText->Text;
			String^ password = userPasswordText->Text;
			String^ userType = safe_cast<String^>(userTypeComboBox->SelectedItem);
			String^ name = userNameText->Text;
			String^ surname = userSurnameText->Text;
			String^ document = userDocumentText->Text;
			String^ phone = userPhoneText->Text;
			String^ email = userEmailText->Text;
			String^ address = userAddressText->Text;

			// Actualizar los valores de la fila seleccionada en el DataGridView
			selectedRow->Cells["Usuario"]->Value = username;
			selectedRow->Cells["Contraseña"]->Value = password;
			selectedRow->Cells["Tipo"]->Value = userType;
			selectedRow->Cells["Nombre"]->Value = name;
			selectedRow->Cells["Apellido"]->Value = surname;
			selectedRow->Cells["CUI/Pasaporte"]->Value = document;
			selectedRow->Cells["Teléfono"]->Value = phone;
			selectedRow->Cells["CorreoElectrónico"]->Value = email;
			selectedRow->Cells["Dirección"]->Value = address;
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para modificar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

    void Users::CopyCsvToBin(String^ csvFilePath, String^ binFilePath) {
        try {
            // Leer todo el contenido del archivo CSV
            array<String^>^ lines = System::IO::File::ReadAllLines(csvFilePath);

            // Escribir el contenido en el archivo binario
            System::IO::File::WriteAllLines(binFilePath, lines);
        }
        catch (System::Exception^ ex) {
            System::Windows::Forms::MessageBox::Show("Error al copiar el archivo: " + ex->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
        }
    }

    void Users::UpdateBinFile(String^ csvFilePath, String^ binFilePath) {
        try {
            // Leer todo el contenido del archivo CSV
            array<String^>^ lines = System::IO::File::ReadAllLines(csvFilePath);

            // Escribir el contenido en el archivo binario
            System::IO::File::WriteAllLines(binFilePath, lines);
        }
        catch (System::Exception^ ex) {
            System::Windows::Forms::MessageBox::Show("Error al actualizar el archivo binario: " + ex->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
        }
    }

}
