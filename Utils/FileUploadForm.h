#pragma once

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FileUpload : public System::Windows::Forms::Form
	{
	public:
		FileUpload(void)
		{
			InitializeComponent();
		}

	protected:
		~FileUpload()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ fileUploadButton;
	private: System::Windows::Forms::Label^ reminderLabel;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FileUpload::typeid));
			this->fileUploadButton = (gcnew System::Windows::Forms::Button());
			this->reminderLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// fileUploadButton
			// 
			this->fileUploadButton->Location = System::Drawing::Point(215, 214);
			this->fileUploadButton->Name = L"fileUploadButton";
			this->fileUploadButton->Size = System::Drawing::Size(305, 105);
			this->fileUploadButton->TabIndex = 0;
			this->fileUploadButton->Text = L"Subir archivo";
			this->fileUploadButton->UseVisualStyleBackColor = true;
			this->fileUploadButton->Click += gcnew System::EventHandler(this, &FileUpload::fileUploadButton_Click);
			// 
			// reminderLabel
			// 
			this->reminderLabel->AutoSize = true;
			this->reminderLabel->Font = (gcnew System::Drawing::Font(L"Lato", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reminderLabel->Location = System::Drawing::Point(103, 24);
			this->reminderLabel->Name = L"reminderLabel";
			this->reminderLabel->Size = System::Drawing::Size(551, 160);
			this->reminderLabel->TabIndex = 1;
			this->reminderLabel->Text = resources->GetString(L"reminderLabel.Text");
			// 
			// FileUpload
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(785, 512);
			this->Controls->Add(this->reminderLabel);
			this->Controls->Add(this->fileUploadButton);
			this->Name = L"FileUpload";
			this->Text = L"FileUpload";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:System::Void fileUploadButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

        openFileDialog->InitialDirectory = "c:\\";
        openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";
        openFileDialog->FilterIndex = 1;
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            // Obtener la ruta del archivo seleccionado
            String^ filePath = openFileDialog->FileName;

            try
            {
                // Leer el contenido del archivo
                array<String^>^ lines = System::IO::File::ReadAllLines(filePath);

                if (lines->Length > 0)
                {
                    // Leer la primera línea para obtener las cabeceras
                    String^ headerLine = lines[0];
                    array<String^>^ headers = headerLine->Split(',');

                    // Cabeceras esperadas
                    array<String^>^ expectedHeaders1 = { "CódigoProducto", "Nombre", "Categoría", "Marca", "Descripción", "PrecioUnitario", "CantidadStock" };
                    array<String^>^ expectedHeaders2 = { "CódigoCliente", "Nombre", "Dirección", "NúmeroTeléfono", "CorreoElectrónico" };
                    array<String^>^ expectedHeaders3 = { "Usuario", "Contraseña", "Tipo", "Nombre", "Apellido", "CUI/Pasaporte", "Teléfono", "CorreoElectrónico", "Dirección" };

                    bool isValid = false;

                    // Comparar las cabeceras leídas con las esperadas
                    if (headers->Length == expectedHeaders1->Length)
                    {
                        isValid = true;
                        for (int i = 0; i < headers->Length; i++)
                        {
                            if (headers[i]->Trim() != expectedHeaders1[i])
                            {
                                isValid = false;
                                break;
                            }
                        }
                    }
                    else if (headers->Length == expectedHeaders2->Length)
                    {
                        isValid = true;
                        for (int i = 0; i < headers->Length; i++)
                        {
                            if (headers[i]->Trim() != expectedHeaders2[i])
                            {
                                isValid = false;
                                break;
                            }
                        }
                    }
                    else if (headers->Length == expectedHeaders3->Length)
                    {
                        isValid = true;
                        for (int i = 0; i < headers->Length; i++)
                        {
                            if (headers[i]->Trim() != expectedHeaders3[i])
                            {
                                isValid = false;
                                break;
                            }
                        }
                    }

                    if (isValid)
                    {
                        // Mostrar mensaje de éxito
                        MessageBox::Show("Archivo subido correctamente: " + filePath, "Archivo Subido", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    }
                    else
                    {
                        // Mostrar mensaje de error de cabeceras
                        MessageBox::Show("Las cabeceras del archivo no coinciden con las esperadas.", "Error de Cabeceras", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else
                {
                    // Mostrar mensaje de error si el archivo está vacío
                    MessageBox::Show("El archivo está vacío.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error al leer el archivo: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }
	};
}
