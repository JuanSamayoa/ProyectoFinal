#pragma once
#include <iostream>
#include <fstream>
#include <string>

ref class FileManager {
private:
    System::String^ binFilePath;
    static String^ basePath = "data\\";

public:
    FileManager() {
        this->binFilePath = basePath + "Usuarios.bin";
    }

    array<System::String^>^ ReadBinFile() {
        if (System::IO::File::Exists(binFilePath)) {
            try {
                return System::IO::File::ReadAllLines(binFilePath);
            }
            catch (System::Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error al leer el archivo: " + ex->Message, "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            }
        }
        else {
            System::Windows::Forms::MessageBox::Show("El archivo binario no existe.", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
            return nullptr;
        }
    }
};
