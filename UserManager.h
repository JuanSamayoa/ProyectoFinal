#pragma once
#include "Usuarios.h"
#include "FileManager.h"

using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace ProyectoFinal {

    public ref class UserManager
    {
    private:
        FileManager^ fileManager;

    public:
        List<Usuario^>^ usuarios;

        UserManager()
        {
            usuarios = gcnew List<Usuario^>();
            fileManager = gcnew FileManager();
            CargarUsuariosDesdeArchivo();
        }

        void CargarUsuariosDesdeArchivo()
        {
            try {
                array<String^>^ lines = fileManager->ReadBinFile();
                if (lines != nullptr) {
                    for each (String ^ line in lines) {
                        array<String^>^ datos = line->Split(',');
                        usuarios->Add(gcnew Usuario(datos[0], datos[1], datos[2], datos[3], datos[4], datos[5], datos[6], datos[7], datos[8]));
                    }
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar usuarios desde el archivo: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    };
}
