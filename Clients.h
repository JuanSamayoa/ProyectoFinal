#pragma once
#include "GlobalVariables.h"
#include "Cliente.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	public ref class Clients : public Form
	{
	public:
		Clients()
		{
			InitializeComponent(); //Se inicializa el ID del cliente para poder llamarlo en accciones posteriores
		}

		void LoadCustomerData(String^ filePath, DataGridView^ grid); //Carga los datos del archivo CSV en el DataGridView
		void SaveCustomerData(String^ filePath, DataGridView^ grid); //Guarda los datos del en el archivo CSV al momento de realizar cualquier accion
		void ModifyCustomerViewData(DataGridView^ grid); //Modifica los datos del archivo CSV al momento de realizar alguna accion
		bool IsFileOpen(String^ filePath); //Verifica que el archivo no haya sido abierto por otro programa

		property Cliente^ SelectedClient; //Propiedad para obtener el cliente seleccionado

	public:
		property int Codigo;
		property String^ Nombre;
		property String^ Direccion;
		property String^ Telefono;
		property String^ CorreoElectronico;
	protected:
		~Clients()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ clientFullNameLabel;
	protected:
	private: System::Windows::Forms::Label^ clientEmailLabel;
	private: System::Windows::Forms::Label^ clientPhoneLabel;
	private: System::Windows::Forms::Label^ clientAddressLabel;
	private: System::Windows::Forms::TextBox^ clientEmailText;
	private: System::Windows::Forms::TextBox^ clientPhoneText;
	private: System::Windows::Forms::TextBox^ clientAddressText;
	private: System::Windows::Forms::TextBox^ clientNameText;
	private: System::Windows::Forms::GroupBox^ actionControlBox;
	private: System::Windows::Forms::Button^ modifyClientButton;
	private: System::Windows::Forms::Button^ deleteClientButton;
	private: System::Windows::Forms::Button^ addClientButton;
	private: System::Windows::Forms::DataGridView^ clientsDataGridView;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ saveChangesButton;
	private: System::Windows::Forms::Label^ clientCodeLabel;
	private: System::Windows::Forms::TextBox^ clientCodeText;
	private: System::Windows::Forms::Label^ saveReminderLabel;
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::Button^ selectClientButton;

	//Variable de ruta del archivo CSV
	private: String^ filePath = "data\\Clientes.csv";

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->clientCodeLabel = (gcnew System::Windows::Forms::Label());
			this->clientCodeText = (gcnew System::Windows::Forms::TextBox());
			this->clientEmailText = (gcnew System::Windows::Forms::TextBox());
			this->clientPhoneText = (gcnew System::Windows::Forms::TextBox());
			this->clientAddressText = (gcnew System::Windows::Forms::TextBox());
			this->clientNameText = (gcnew System::Windows::Forms::TextBox());
			this->clientEmailLabel = (gcnew System::Windows::Forms::Label());
			this->clientPhoneLabel = (gcnew System::Windows::Forms::Label());
			this->clientAddressLabel = (gcnew System::Windows::Forms::Label());
			this->clientFullNameLabel = (gcnew System::Windows::Forms::Label());
			this->actionControlBox = (gcnew System::Windows::Forms::GroupBox());
			this->saveChangesButton = (gcnew System::Windows::Forms::Button());
			this->modifyClientButton = (gcnew System::Windows::Forms::Button());
			this->deleteClientButton = (gcnew System::Windows::Forms::Button());
			this->addClientButton = (gcnew System::Windows::Forms::Button());
			this->clientsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->saveReminderLabel = (gcnew System::Windows::Forms::Label());
			this->selectClientButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->actionControlBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clientsDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->selectClientButton);
			this->groupBox1->Controls->Add(this->clearButton);
			this->groupBox1->Controls->Add(this->clientCodeLabel);
			this->groupBox1->Controls->Add(this->clientCodeText);
			this->groupBox1->Controls->Add(this->clientEmailText);
			this->groupBox1->Controls->Add(this->clientPhoneText);
			this->groupBox1->Controls->Add(this->clientAddressText);
			this->groupBox1->Controls->Add(this->clientNameText);
			this->groupBox1->Controls->Add(this->clientEmailLabel);
			this->groupBox1->Controls->Add(this->clientPhoneLabel);
			this->groupBox1->Controls->Add(this->clientAddressLabel);
			this->groupBox1->Controls->Add(this->clientFullNameLabel);
			this->groupBox1->Location = System::Drawing::Point(12, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(340, 242);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Informacion del cliente";
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(252, 19);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 108;
			this->clearButton->Text = L"Limpiar";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Clients::clearButton_Click);
			// 
			// clientCodeLabel
			// 
			this->clientCodeLabel->AutoSize = true;
			this->clientCodeLabel->Location = System::Drawing::Point(13, 41);
			this->clientCodeLabel->Name = L"clientCodeLabel";
			this->clientCodeLabel->Size = System::Drawing::Size(92, 13);
			this->clientCodeLabel->TabIndex = 11;
			this->clientCodeLabel->Text = L"Codigo de cliente:";
			// 
			// clientCodeText
			// 
			this->clientCodeText->Enabled = false;
			this->clientCodeText->Location = System::Drawing::Point(113, 38);
			this->clientCodeText->MaxLength = 25;
			this->clientCodeText->Name = L"clientCodeText";
			this->clientCodeText->Size = System::Drawing::Size(64, 20);
			this->clientCodeText->TabIndex = 0;
			// 
			// clientEmailText
			// 
			this->clientEmailText->Location = System::Drawing::Point(113, 165);
			this->clientEmailText->MaxLength = 30;
			this->clientEmailText->Name = L"clientEmailText";
			this->clientEmailText->Size = System::Drawing::Size(155, 20);
			this->clientEmailText->TabIndex = 4;
			// 
			// clientPhoneText
			// 
			this->clientPhoneText->Location = System::Drawing::Point(113, 134);
			this->clientPhoneText->MaxLength = 8;
			this->clientPhoneText->Name = L"clientPhoneText";
			this->clientPhoneText->Size = System::Drawing::Size(155, 20);
			this->clientPhoneText->TabIndex = 3;
			// 
			// clientAddressText
			// 
			this->clientAddressText->Location = System::Drawing::Point(113, 104);
			this->clientAddressText->MaxLength = 50;
			this->clientAddressText->Name = L"clientAddressText";
			this->clientAddressText->Size = System::Drawing::Size(155, 20);
			this->clientAddressText->TabIndex = 2;
			// 
			// clientNameText
			// 
			this->clientNameText->Location = System::Drawing::Point(113, 75);
			this->clientNameText->MaxLength = 25;
			this->clientNameText->Name = L"clientNameText";
			this->clientNameText->Size = System::Drawing::Size(155, 20);
			this->clientNameText->TabIndex = 1;
			// 
			// clientEmailLabel
			// 
			this->clientEmailLabel->AutoSize = true;
			this->clientEmailLabel->Location = System::Drawing::Point(6, 168);
			this->clientEmailLabel->Name = L"clientEmailLabel";
			this->clientEmailLabel->Size = System::Drawing::Size(96, 13);
			this->clientEmailLabel->TabIndex = 4;
			this->clientEmailLabel->Text = L"Correo electrónico:";
			// 
			// clientPhoneLabel
			// 
			this->clientPhoneLabel->AutoSize = true;
			this->clientPhoneLabel->Location = System::Drawing::Point(30, 137);
			this->clientPhoneLabel->Name = L"clientPhoneLabel";
			this->clientPhoneLabel->Size = System::Drawing::Size(72, 13);
			this->clientPhoneLabel->TabIndex = 3;
			this->clientPhoneLabel->Text = L"No. Telefono:";
			// 
			// clientAddressLabel
			// 
			this->clientAddressLabel->AutoSize = true;
			this->clientAddressLabel->Location = System::Drawing::Point(47, 107);
			this->clientAddressLabel->Name = L"clientAddressLabel";
			this->clientAddressLabel->Size = System::Drawing::Size(55, 13);
			this->clientAddressLabel->TabIndex = 2;
			this->clientAddressLabel->Text = L"Dirección:";
			// 
			// clientFullNameLabel
			// 
			this->clientFullNameLabel->AutoSize = true;
			this->clientFullNameLabel->Location = System::Drawing::Point(9, 78);
			this->clientFullNameLabel->Name = L"clientFullNameLabel";
			this->clientFullNameLabel->Size = System::Drawing::Size(93, 13);
			this->clientFullNameLabel->TabIndex = 0;
			this->clientFullNameLabel->Text = L"Nombre completo:";
			// 
			// actionControlBox
			// 
			this->actionControlBox->Controls->Add(this->saveChangesButton);
			this->actionControlBox->Controls->Add(this->modifyClientButton);
			this->actionControlBox->Controls->Add(this->deleteClientButton);
			this->actionControlBox->Controls->Add(this->addClientButton);
			this->actionControlBox->Location = System::Drawing::Point(12, 298);
			this->actionControlBox->Name = L"actionControlBox";
			this->actionControlBox->Size = System::Drawing::Size(340, 62);
			this->actionControlBox->TabIndex = 1;
			this->actionControlBox->TabStop = false;
			// 
			// saveChangesButton
			// 
			this->saveChangesButton->Location = System::Drawing::Point(252, 17);
			this->saveChangesButton->Name = L"saveChangesButton";
			this->saveChangesButton->Size = System::Drawing::Size(75, 39);
			this->saveChangesButton->TabIndex = 8;
			this->saveChangesButton->Text = L"Guardar cambios";
			this->saveChangesButton->UseVisualStyleBackColor = true;
			this->saveChangesButton->Click += gcnew System::EventHandler(this, &Clients::saveChangesButton_Click);
			// 
			// modifyClientButton
			// 
			this->modifyClientButton->Location = System::Drawing::Point(90, 17);
			this->modifyClientButton->Name = L"modifyClientButton";
			this->modifyClientButton->Size = System::Drawing::Size(75, 39);
			this->modifyClientButton->TabIndex = 6;
			this->modifyClientButton->Text = L"Modificar Cliente";
			this->modifyClientButton->UseVisualStyleBackColor = true;
			this->modifyClientButton->Click += gcnew System::EventHandler(this, &Clients::modifyClientButton_Click);
			// 
			// deleteClientButton
			// 
			this->deleteClientButton->Location = System::Drawing::Point(171, 17);
			this->deleteClientButton->Name = L"deleteClientButton";
			this->deleteClientButton->Size = System::Drawing::Size(75, 39);
			this->deleteClientButton->TabIndex = 7;
			this->deleteClientButton->Text = L"Eliminar Cliente";
			this->deleteClientButton->UseVisualStyleBackColor = true;
			this->deleteClientButton->Click += gcnew System::EventHandler(this, &Clients::deleteClientButton_Click);
			// 
			// addClientButton
			// 
			this->addClientButton->Location = System::Drawing::Point(9, 17);
			this->addClientButton->Name = L"addClientButton";
			this->addClientButton->Size = System::Drawing::Size(75, 39);
			this->addClientButton->TabIndex = 5;
			this->addClientButton->Text = L"Agregar Cliente";
			this->addClientButton->UseVisualStyleBackColor = true;
			this->addClientButton->Click += gcnew System::EventHandler(this, &Clients::addClientButton_Click);
			// 
			// clientsDataGridView
			// 
			this->clientsDataGridView->AllowUserToDeleteRows = false;
			this->clientsDataGridView->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->clientsDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->clientsDataGridView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->clientsDataGridView->Location = System::Drawing::Point(358, 50);
			this->clientsDataGridView->Name = L"clientsDataGridView";
			this->clientsDataGridView->ReadOnly = true;
			this->clientsDataGridView->Size = System::Drawing::Size(616, 355);
			this->clientsDataGridView->TabIndex = 2;
			this->clientsDataGridView->DoubleClick += gcnew System::EventHandler(this, &Clients::clientsDataGridView_SelectionChanged);
			// 
			// saveReminderLabel
			// 
			this->saveReminderLabel->AutoSize = true;
			this->saveReminderLabel->Font = (gcnew System::Drawing::Font(L"Montserrat Thin", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveReminderLabel->Location = System::Drawing::Point(12, 372);
			this->saveReminderLabel->Name = L"saveReminderLabel";
			this->saveReminderLabel->Size = System::Drawing::Size(286, 36);
			this->saveReminderLabel->TabIndex = 101;
			this->saveReminderLabel->Text = L"Recuerda siempre guardar tus cambios \r\npara que sean reflejados*";
			// 
			// selectClientButton
			// 
			this->selectClientButton->Location = System::Drawing::Point(207, 213);
			this->selectClientButton->Name = L"selectClientButton";
			this->selectClientButton->Size = System::Drawing::Size(127, 23);
			this->selectClientButton->TabIndex = 109;
			this->selectClientButton->Text = L"Seleccionar Cliente";
			this->selectClientButton->UseVisualStyleBackColor = true;
			this->selectClientButton->Click += gcnew System::EventHandler(this, &Clients::selectClientButton_Click);
			// 
			// Clients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(986, 418);
			this->ControlBox = false;
			this->Controls->Add(this->saveReminderLabel);
			this->Controls->Add(this->clientsDataGridView);
			this->Controls->Add(this->actionControlBox);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Clients";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Módulo de clientes";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Clients::Clients_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->actionControlBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clientsDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	public:
		Void Clients::SelectClientButtonVisbility(bool isClientsActive) {
			if (isClientsActive) {
				selectClientButton->Enabled= false;
			}
			else {
				selectClientButton->Enabled = true;
			}
		}
		
	//Funcion para cargar los datos del archivo CSV en el DataGridView cuando se inicialice la pantalla
	private: Void Clients_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadCustomerData(filePath, clientsDataGridView);
	}

	private: Void clientsDataGridView_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		if (clientsDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = clientsDataGridView->SelectedRows[0];
			if (selectedRow != nullptr && selectedRow->Cells[0]->Value != nullptr) {
				// Evitar la fila temporal (*)
				if (selectedRow->Cells[0]->Value->ToString() != "*") {
					// Cargar la información del cliente en los campos de texto
					clientCodeText->Text = selectedRow->Cells[0]->Value->ToString();
					clientNameText->Text = selectedRow->Cells[1]->Value->ToString();
					clientAddressText->Text = selectedRow->Cells[2]->Value->ToString();
					clientPhoneText->Text = selectedRow->Cells[3]->Value->ToString();
					clientEmailText->Text = selectedRow->Cells[4]->Value->ToString();
				}
			}
			else {
				// Mostrar un mensaje de advertencia si la fila seleccionada o su valor es nulo
				MessageBox::Show("Error: La fila seleccionada no contiene datos válidos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	//Funcion para agregar los clientes al archivo CSV
	private: Void addClientButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Incrementamos el ID de cliente para el nuevo cliente
		String^ name = clientNameText->Text;
		String^ address = clientAddressText->Text;
		String^ phone = clientPhoneText->Text;
		String^ email = clientEmailText->Text;

		clientIndex++;
		if (name == "" || address == "" || phone == "" || email == "") {
			MessageBox::Show("Por favor, llene todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Validación del formato de correo electrónico
		if (!Regex::IsMatch(email, "^\\S+@\\S+\\.\\S+$")) {
			MessageBox::Show("El formato del correo electrónico no es válido. Debe ser de la forma 'usuario@dominio.com'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Validación del número de teléfono para que sean exactamente 8 dígitos
		if (!Regex::IsMatch(phone, "^\\d{8}$")) {
			MessageBox::Show("El número de teléfono debe contener exactamente 8 dígitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Construimos la cadena de datos con el nuevo ID de cliente
		String^ data = clientIndex + ",\"" + name + "\",\"" + address + "\",\"" + phone + "\",\"" + email + "\"\n";

		// Agregamos la nueva línea al DataGridView
		clientsDataGridView->Rows->Add(clientIndex, name, address, phone, email);

		// Limpiar los campos después de agregar el cliente
		clientCodeText->Text = "";
		clientNameText->Text = "";
		clientAddressText->Text = "";
		clientPhoneText->Text = "";
		clientEmailText->Text = "";
	}

	private: Void modifyClientButton_Click(Object^ sender, EventArgs^ e){
		// Verificar si hay una fila seleccionada para modificar
		if (clientsDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = clientsDataGridView->SelectedRows[0];

			// Obtener los nuevos valores de la fila desde los campos de texto
			String^ name = clientNameText->Text;
			String^ address = clientAddressText->Text;
			String^ phone = clientPhoneText->Text;
			String^ email = clientEmailText->Text;

			//Valifacion de campos vacios ya que todos son obligatorios para completar la informacion
			if (name == "" || address == "" || phone == "" || email == "") {
				MessageBox::Show("Por favor, llene todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Validación del formato de correo electrónico con expresión regular
			if (!Regex::IsMatch(email, "^\\S+@\\S+\\.\\S+$")) {
				MessageBox::Show("El formato del correo electrónico no es válido. Debe ser de la forma 'usuario@dominio.com'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Validación del número de teléfono para que sean exactamente 8 dígitos con expresion regular
			if (!Regex::IsMatch(phone, "^\\d{8}$")) {
				MessageBox::Show("El número de teléfono debe contener exactamente 8 dígitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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

	private: Void deleteClientButton_Click(Object^ sender, EventArgs^ e) {
		// Verificar si hay una fila seleccionada para eliminar
		if (clientsDataGridView->SelectedRows->Count > 0) {
			// Eliminar la fila seleccionada del DataGridView
			clientsDataGridView->Rows->RemoveAt(clientsDataGridView->SelectedRows[0]->Index);
			clientIndex--;
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: Void saveChangesButton_Click(Object ^ sender, EventArgs ^ e) {
		// Guardar los cambios en el archivo CSV utilizando el método existente
		Clients^ clientsInstance = gcnew Clients();
		clientsInstance->SaveCustomerData(filePath, clientsDataGridView);
	}

	private: Void clientsDataGridView_CellClick(Object^ sender, Windows::Forms::DataGridViewCellEventArgs^ e) {
		// Obtener la fila seleccionada
		DataGridViewRow^ selectedRow = clientsDataGridView->Rows[e->RowIndex];

		// Obtener los valores de la fila seleccionada
		String^ codigoCliente = safe_cast<String^>(selectedRow->Cells["CódigoCliente"]->Value);
		String^ nombre = safe_cast<String^>(selectedRow->Cells["Nombre"]->Value);
		String^ direccion = safe_cast<String^>(selectedRow->Cells["Dirección"]->Value);
		String^ numeroTelefono = safe_cast<String^>(selectedRow->Cells["NúmeroTeléfono"]->Value);
		String^ correoElectronico = safe_cast<String^>(selectedRow->Cells["CorreoElectrónico"]->Value);

		// Asignar los valores a los campos correspondientes
		clientCodeText->Text = codigoCliente;
		clientNameText->Text = nombre;
		clientAddressText->Text = direccion;
		clientPhoneText->Text = numeroTelefono;
		clientEmailText->Text = correoElectronico;
	}

	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		clientCodeText->Text = "";
		clientNameText->Text = "";
		clientAddressText->Text = "";
		clientPhoneText->Text = "";
		clientEmailText->Text = "";
	}
	private: System::Void selectClientButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (clientsDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = clientsDataGridView->SelectedRows[0];
			int codigoCliente = Convert::ToInt32(selectedRow->Cells["CódigoCliente"]->Value);
			String^ nombre = safe_cast<String^>(selectedRow->Cells["Nombre"]->Value);
			String^ direccion = safe_cast<String^>(selectedRow->Cells["Dirección"]->Value);
			String^ telefono = safe_cast<String^>(selectedRow->Cells["NúmeroTeléfono"]->Value);
			String^ correoElectronico = safe_cast<String^>(selectedRow->Cells["CorreoElectrónico"]->Value);

			SelectedClient = gcnew Cliente(codigoCliente, nombre, direccion, telefono, correoElectronico);

			this->Close();
		}
		else {
			MessageBox::Show("Por favor, selecciona un cliente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
};