#pragma once
#include "GlobalVariables.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace System::Text::RegularExpressions;

	public ref class Users : public Form
	{
	public:
		Users(void)
		{
			InitializeComponent();
		}

		bool IsFileOpen(String^ filePath);
		void LoadUsersData(String^ filePath, DataGridView^ grid);
		void SaveUsersData(String^ filePath, DataGridView^ grid);
		void ModifyUsersViewData(String^ filePath, DataGridView^ grid);
		void CopyCsvToBin(String^ csvFilePath, String^ binFilePath);
		void UpdateBinFile(String^ csvFilePath, String^ binFilePath);


	protected:
		~Users()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ userControlBox;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::TextBox^ userUsernameText;
	private: System::Windows::Forms::TextBox^ userSurnameText;
	protected:
	private: System::Windows::Forms::TextBox^ userNameText;
	private: System::Windows::Forms::TextBox^ userPasswordText;
	private: System::Windows::Forms::Label^ clientEmailLabel;
	private: System::Windows::Forms::Label^ clientPhoneLabel;
	private: System::Windows::Forms::Label^ clientAddressLabel;
	private: System::Windows::Forms::Label^ userPasswordLabel;
	private: System::Windows::Forms::DataGridView^ usersDataGridView;
	private: System::Windows::Forms::ComboBox^ userTypeComboBox;
	private: System::Windows::Forms::TextBox^ userAddressText;
	private: System::Windows::Forms::TextBox^ userPhoneText;
	private: System::Windows::Forms::TextBox^ userEmailText;
	private: System::Windows::Forms::TextBox^ userDocumentText;
	private: System::Windows::Forms::Label^ userAddressLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ userDocumentLabel;
	private: System::Windows::Forms::GroupBox^ actionControlBox;
	private: System::Windows::Forms::Button^ saveChangesButton;
	private: System::Windows::Forms::Button^ modifyUserButton;
	private: System::Windows::Forms::Button^ deleteUserButton;
	private: System::Windows::Forms::Button^ addUserButton;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ label2;

	private: String^ filePath = "data\\Usuarios.csv";
	private: System::Windows::Forms::Button^ clearButton;
	private: String^ binFilePath = "data\\Usuarios.bin";


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->userControlBox = (gcnew System::Windows::Forms::GroupBox());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->userAddressText = (gcnew System::Windows::Forms::TextBox());
			this->userPhoneText = (gcnew System::Windows::Forms::TextBox());
			this->userEmailText = (gcnew System::Windows::Forms::TextBox());
			this->userDocumentText = (gcnew System::Windows::Forms::TextBox());
			this->userAddressLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->userDocumentLabel = (gcnew System::Windows::Forms::Label());
			this->userTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->userUsernameText = (gcnew System::Windows::Forms::TextBox());
			this->userSurnameText = (gcnew System::Windows::Forms::TextBox());
			this->userNameText = (gcnew System::Windows::Forms::TextBox());
			this->userPasswordText = (gcnew System::Windows::Forms::TextBox());
			this->clientEmailLabel = (gcnew System::Windows::Forms::Label());
			this->clientPhoneLabel = (gcnew System::Windows::Forms::Label());
			this->clientAddressLabel = (gcnew System::Windows::Forms::Label());
			this->userPasswordLabel = (gcnew System::Windows::Forms::Label());
			this->usersDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->actionControlBox = (gcnew System::Windows::Forms::GroupBox());
			this->saveChangesButton = (gcnew System::Windows::Forms::Button());
			this->modifyUserButton = (gcnew System::Windows::Forms::Button());
			this->deleteUserButton = (gcnew System::Windows::Forms::Button());
			this->addUserButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->userControlBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->usersDataGridView))->BeginInit();
			this->actionControlBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// userControlBox
			// 
			this->userControlBox->Controls->Add(this->clearButton);
			this->userControlBox->Controls->Add(this->userAddressText);
			this->userControlBox->Controls->Add(this->userPhoneText);
			this->userControlBox->Controls->Add(this->userEmailText);
			this->userControlBox->Controls->Add(this->userDocumentText);
			this->userControlBox->Controls->Add(this->userAddressLabel);
			this->userControlBox->Controls->Add(this->label1);
			this->userControlBox->Controls->Add(this->label3);
			this->userControlBox->Controls->Add(this->userDocumentLabel);
			this->userControlBox->Controls->Add(this->userTypeComboBox);
			this->userControlBox->Controls->Add(this->usernameLabel);
			this->userControlBox->Controls->Add(this->userUsernameText);
			this->userControlBox->Controls->Add(this->userSurnameText);
			this->userControlBox->Controls->Add(this->userNameText);
			this->userControlBox->Controls->Add(this->userPasswordText);
			this->userControlBox->Controls->Add(this->clientEmailLabel);
			this->userControlBox->Controls->Add(this->clientPhoneLabel);
			this->userControlBox->Controls->Add(this->clientAddressLabel);
			this->userControlBox->Controls->Add(this->userPasswordLabel);
			this->userControlBox->Location = System::Drawing::Point(12, 48);
			this->userControlBox->Name = L"userControlBox";
			this->userControlBox->Size = System::Drawing::Size(340, 288);
			this->userControlBox->TabIndex = 99;
			this->userControlBox->TabStop = false;
			this->userControlBox->Text = L"Control de usuarios";
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(259, 12);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 108;
			this->clearButton->Text = L"Limpiar";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Users::clearButton_Click);
			// 
			// userAddressText
			// 
			this->userAddressText->Location = System::Drawing::Point(114, 254);
			this->userAddressText->MaxLength = 50;
			this->userAddressText->Name = L"userAddressText";
			this->userAddressText->Size = System::Drawing::Size(155, 20);
			this->userAddressText->TabIndex = 9;
			// 
			// userPhoneText
			// 
			this->userPhoneText->Location = System::Drawing::Point(114, 200);
			this->userPhoneText->MaxLength = 8;
			this->userPhoneText->Name = L"userPhoneText";
			this->userPhoneText->Size = System::Drawing::Size(155, 20);
			this->userPhoneText->TabIndex = 7;
			// 
			// userEmailText
			// 
			this->userEmailText->Location = System::Drawing::Point(114, 228);
			this->userEmailText->MaxLength = 50;
			this->userEmailText->Name = L"userEmailText";
			this->userEmailText->Size = System::Drawing::Size(155, 20);
			this->userEmailText->TabIndex = 8;
			// 
			// userDocumentText
			// 
			this->userDocumentText->Location = System::Drawing::Point(114, 174);
			this->userDocumentText->MaxLength = 13;
			this->userDocumentText->Name = L"userDocumentText";
			this->userDocumentText->Size = System::Drawing::Size(155, 20);
			this->userDocumentText->TabIndex = 6;
			// 
			// userAddressLabel
			// 
			this->userAddressLabel->AutoSize = true;
			this->userAddressLabel->Location = System::Drawing::Point(50, 257);
			this->userAddressLabel->Name = L"userAddressLabel";
			this->userAddressLabel->Size = System::Drawing::Size(55, 13);
			this->userAddressLabel->TabIndex = 8;
			this->userAddressLabel->Text = L"Dirección:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 203);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Teléfono:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Correo Electronico:";
			// 
			// userDocumentLabel
			// 
			this->userDocumentLabel->AutoSize = true;
			this->userDocumentLabel->Location = System::Drawing::Point(20, 177);
			this->userDocumentLabel->Name = L"userDocumentLabel";
			this->userDocumentLabel->Size = System::Drawing::Size(85, 13);
			this->userDocumentLabel->TabIndex = 14;
			this->userDocumentLabel->Text = L"No. Documento:";
			// 
			// userTypeComboBox
			// 
			this->userTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Administrador", L"Operador" });
			this->userTypeComboBox->Location = System::Drawing::Point(114, 93);
			this->userTypeComboBox->Name = L"userTypeComboBox";
			this->userTypeComboBox->Size = System::Drawing::Size(155, 21);
			this->userTypeComboBox->TabIndex = 3;
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Location = System::Drawing::Point(6, 44);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(99, 13);
			this->usernameLabel->TabIndex = 11;
			this->usernameLabel->Text = L"Nombre de usuario:";
			// 
			// userUsernameText
			// 
			this->userUsernameText->Location = System::Drawing::Point(114, 41);
			this->userUsernameText->MaxLength = 20;
			this->userUsernameText->Name = L"userUsernameText";
			this->userUsernameText->Size = System::Drawing::Size(155, 20);
			this->userUsernameText->TabIndex = 0;
			// 
			// userSurnameText
			// 
			this->userSurnameText->Location = System::Drawing::Point(114, 146);
			this->userSurnameText->MaxLength = 20;
			this->userSurnameText->Name = L"userSurnameText";
			this->userSurnameText->Size = System::Drawing::Size(155, 20);
			this->userSurnameText->TabIndex = 5;
			// 
			// userNameText
			// 
			this->userNameText->Location = System::Drawing::Point(114, 120);
			this->userNameText->MaxLength = 20;
			this->userNameText->Name = L"userNameText";
			this->userNameText->Size = System::Drawing::Size(155, 20);
			this->userNameText->TabIndex = 4;
			// 
			// userPasswordText
			// 
			this->userPasswordText->Location = System::Drawing::Point(114, 67);
			this->userPasswordText->MaxLength = 20;
			this->userPasswordText->Name = L"userPasswordText";
			this->userPasswordText->Size = System::Drawing::Size(155, 20);
			this->userPasswordText->TabIndex = 1;
			// 
			// clientEmailLabel
			// 
			this->clientEmailLabel->AutoSize = true;
			this->clientEmailLabel->Location = System::Drawing::Point(58, 149);
			this->clientEmailLabel->Name = L"clientEmailLabel";
			this->clientEmailLabel->Size = System::Drawing::Size(47, 13);
			this->clientEmailLabel->TabIndex = 4;
			this->clientEmailLabel->Text = L"Apellido:";
			// 
			// clientPhoneLabel
			// 
			this->clientPhoneLabel->AutoSize = true;
			this->clientPhoneLabel->Location = System::Drawing::Point(58, 123);
			this->clientPhoneLabel->Name = L"clientPhoneLabel";
			this->clientPhoneLabel->Size = System::Drawing::Size(47, 13);
			this->clientPhoneLabel->TabIndex = 3;
			this->clientPhoneLabel->Text = L"Nombre:";
			// 
			// clientAddressLabel
			// 
			this->clientAddressLabel->AutoSize = true;
			this->clientAddressLabel->Location = System::Drawing::Point(22, 96);
			this->clientAddressLabel->Name = L"clientAddressLabel";
			this->clientAddressLabel->Size = System::Drawing::Size(83, 13);
			this->clientAddressLabel->TabIndex = 2;
			this->clientAddressLabel->Text = L"Tipo de usuario:";
			// 
			// userPasswordLabel
			// 
			this->userPasswordLabel->AutoSize = true;
			this->userPasswordLabel->Location = System::Drawing::Point(41, 70);
			this->userPasswordLabel->Name = L"userPasswordLabel";
			this->userPasswordLabel->Size = System::Drawing::Size(64, 13);
			this->userPasswordLabel->TabIndex = 0;
			this->userPasswordLabel->Text = L"Contraseña:";
			// 
			// usersDataGridView
			// 
			this->usersDataGridView->AllowUserToDeleteRows = false;
			this->usersDataGridView->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->usersDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->usersDataGridView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->usersDataGridView->Location = System::Drawing::Point(389, 49);
			this->usersDataGridView->Name = L"usersDataGridView";
			this->usersDataGridView->ReadOnly = true;
			this->usersDataGridView->Size = System::Drawing::Size(943, 355);
			this->usersDataGridView->TabIndex = 99;
			this->usersDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Users::usersDataGridView_CellClick);
			this->usersDataGridView->SelectionChanged += gcnew System::EventHandler(this, &Users::usersDataGridView_SelectionChanged);
			// 
			// actionControlBox
			// 
			this->actionControlBox->Controls->Add(this->saveChangesButton);
			this->actionControlBox->Controls->Add(this->modifyUserButton);
			this->actionControlBox->Controls->Add(this->deleteUserButton);
			this->actionControlBox->Controls->Add(this->addUserButton);
			this->actionControlBox->Location = System::Drawing::Point(12, 342);
			this->actionControlBox->Name = L"actionControlBox";
			this->actionControlBox->Size = System::Drawing::Size(340, 62);
			this->actionControlBox->TabIndex = 99;
			this->actionControlBox->TabStop = false;
			// 
			// saveChangesButton
			// 
			this->saveChangesButton->Location = System::Drawing::Point(252, 17);
			this->saveChangesButton->Name = L"saveChangesButton";
			this->saveChangesButton->Size = System::Drawing::Size(75, 39);
			this->saveChangesButton->TabIndex = 13;
			this->saveChangesButton->Text = L"Guardar cambios";
			this->saveChangesButton->UseVisualStyleBackColor = true;
			this->saveChangesButton->Click += gcnew System::EventHandler(this, &Users::saveChangesButton_Click);
			// 
			// modifyUserButton
			// 
			this->modifyUserButton->Location = System::Drawing::Point(90, 17);
			this->modifyUserButton->Name = L"modifyUserButton";
			this->modifyUserButton->Size = System::Drawing::Size(75, 39);
			this->modifyUserButton->TabIndex = 11;
			this->modifyUserButton->Text = L"Modificar Usuario";
			this->modifyUserButton->UseVisualStyleBackColor = true;
			this->modifyUserButton->Click += gcnew System::EventHandler(this, &Users::modifyUserButton_Click);
			// 
			// deleteUserButton
			// 
			this->deleteUserButton->Location = System::Drawing::Point(171, 17);
			this->deleteUserButton->Name = L"deleteUserButton";
			this->deleteUserButton->Size = System::Drawing::Size(75, 39);
			this->deleteUserButton->TabIndex = 12;
			this->deleteUserButton->Text = L"Eliminar Cliente";
			this->deleteUserButton->UseVisualStyleBackColor = true;
			this->deleteUserButton->Click += gcnew System::EventHandler(this, &Users::deleteUserButton_Click);
			// 
			// addUserButton
			// 
			this->addUserButton->Location = System::Drawing::Point(9, 17);
			this->addUserButton->Name = L"addUserButton";
			this->addUserButton->Size = System::Drawing::Size(75, 39);
			this->addUserButton->TabIndex = 10;
			this->addUserButton->Text = L"Agregar Usuario";
			this->addUserButton->UseVisualStyleBackColor = true;
			this->addUserButton->Click += gcnew System::EventHandler(this, &Users::addUserButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat Thin", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(18, 416);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(286, 36);
			this->label2->TabIndex = 102;
			this->label2->Text = L"Recuerda siempre guardar tus cambios \r\npara que sean reflejados*";
			// 
			// Users
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1345, 555);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->actionControlBox);
			this->Controls->Add(this->usersDataGridView);
			this->Controls->Add(this->userControlBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Users";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Control de usuarios";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Users::Users_Load);
			this->userControlBox->ResumeLayout(false);
			this->userControlBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->usersDataGridView))->EndInit();
			this->actionControlBox->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: Void Users_Load(Object^ sender, EventArgs^ e) {
		LoadUsersData(filePath, usersDataGridView);
		userTypeComboBox->SelectedIndex = 1;
	}

	private: System::Void usersDataGridView_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		if (usersDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = usersDataGridView->SelectedRows[0];
			if (selectedRow != nullptr && selectedRow->Cells[0]->Value != nullptr) {
				// Evitar la fila temporal (*)
				if (selectedRow->Cells[0]->Value->ToString() != "*") {
					// Cargar la información del usuario en los campos de texto
					userUsernameText->Text = selectedRow->Cells["Usuario"]->Value->ToString();
					userPasswordText->Text = selectedRow->Cells["Contraseña"]->Value->ToString();
					userNameText->Text = selectedRow->Cells["Nombre"]->Value->ToString();
					userSurnameText->Text = selectedRow->Cells["Apellido"]->Value->ToString();
					userDocumentText->Text = selectedRow->Cells["CUI/Pasaporte"]->Value->ToString();
					userPhoneText->Text = selectedRow->Cells["Teléfono"]->Value->ToString();
					userEmailText->Text = selectedRow->Cells["CorreoElectrónico"]->Value->ToString();
					userAddressText->Text = selectedRow->Cells["Dirección"]->Value->ToString();

					// Obtener el tipo de usuario de la fila seleccionada
					String^ userType = selectedRow->Cells["Tipo"]->Value->ToString();

					// Convertir el tipo de usuario a mayúscula inicial si es necesario
					userType = CultureInfo::CurrentCulture->TextInfo->ToTitleCase(userType->ToLower());

					// Buscar el índice del tipo de usuario en el ComboBox
					int userTypeIndex = userTypeComboBox->FindStringExact(userType);

					// Establecer el tipo de usuario seleccionado en el ComboBox si se encuentra
					if (userTypeIndex != -1) {
						userTypeComboBox->SelectedIndex = userTypeIndex;
					}
				}
			}
			else {
				// Mostrar un mensaje de advertencia si la fila seleccionada o su valor es nulo
				MessageBox::Show("Error: La fila seleccionada no contiene datos válidos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void usersDataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		// Verificar si hay una fila seleccionada
		if (usersDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = usersDataGridView->Rows[e->RowIndex];

			// Obtener los valores de la fila seleccionada
			String^ username = safe_cast<String^>(selectedRow->Cells["Usuario"]->Value);
			String^ password = safe_cast<String^>(selectedRow->Cells["Contraseña"]->Value);
			String^ userType = safe_cast<String^>(selectedRow->Cells["Tipo"]->Value);
			String^ name = safe_cast<String^>(selectedRow->Cells["Nombre"]->Value);
			String^ surname = safe_cast<String^>(selectedRow->Cells["Apellido"]->Value);
			String^ document = safe_cast<String^>(selectedRow->Cells["CUI/Pasaporte"]->Value);
			String^ phone = safe_cast<String^>(selectedRow->Cells["Teléfono"]->Value);
			String^ email = safe_cast<String^>(selectedRow->Cells["CorreoElectrónico"]->Value);
			String^ address = safe_cast<String^>(selectedRow->Cells["Dirección"]->Value);

			// Convertir el tipo de usuario a mayúscula inicial si es necesario
			userType = CultureInfo::CurrentCulture->TextInfo->ToTitleCase(userType->ToLower());

			// Verificar si el tipo de usuario existe en el ComboBox y establecerlo si es así
			int userTypeIndex = userTypeComboBox->FindStringExact(userType);
			if (userTypeIndex != -1) {
				userTypeComboBox->SelectedIndex = userTypeIndex;
			}

			// Establecer los valores en los campos de texto
			userUsernameText->Text = username;
			userPasswordText->Text = password;
			userNameText->Text = name;
			userSurnameText->Text = surname;
			userDocumentText->Text = document;
			userPhoneText->Text = phone;
			userEmailText->Text = email;
			userAddressText->Text = address;
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para ver los detalles.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void addUserButton_Click(Object^ sender, EventArgs^ e) {
		// Obtener los valores de los campos de texto y del ComboBox
		String^ username = userUsernameText->Text;
		String^ password = userPasswordText->Text;
		String^ userType = userTypeComboBox->SelectedItem->ToString();
		String^ name = userNameText->Text;
		String^ surname = userSurnameText->Text;
		String^ document = userDocumentText->Text;
		String^ phone = userPhoneText->Text;
		String^ email = userEmailText->Text;
		String^ address = userAddressText->Text;

		// Validar los campos obligatorios
		if (username == "" || password == "" || name == "" || surname == "" || email == "") {
			MessageBox::Show("Por favor, llene todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Validar el formato del correo electrónico con una expresión regular
		if (!Regex::IsMatch(email, "^\\S+@\\S+\\.\\S+$")) {
			MessageBox::Show("El formato del correo electrónico no es válido. Debe ser de la forma 'usuario@dominio.com'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Validar el número de DPI con una expresión regular
		if (!Regex::IsMatch(document, "^\\d{13}$")) {
			MessageBox::Show("El número de DPI debe contener exactamente 13 dígitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Agregar el nuevo usuario al DataGridView
		array<String^>^ rowData = { username, password, userType, name, surname, document, phone, email, address };
		usersDataGridView->Rows->Add(rowData);

		// Limpiar los campos después de agregar el usuario
		userUsernameText->Text = "";
		userPasswordText->Text = "";
		userTypeComboBox->SelectedIndex = -1; // Limpiar la selección del ComboBox
		userNameText->Text = "";
		userSurnameText->Text = "";
		userDocumentText->Text = "";
		userPhoneText->Text = "";
		userEmailText->Text = "";
		userAddressText->Text = "";
	}


	private: System::Void modifyUserButton_Click(Object^ sender, EventArgs^ e) {
		if (usersDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = usersDataGridView->SelectedRows[0];

			// Obtener los nuevos valores de la fila desde los campos de texto
			String^ name = userUsernameText->Text;
			String^ password = userPasswordText->Text;
			String^ userType = userTypeComboBox->SelectedItem->ToString(); // Obtener el tipo de usuario del ComboBox
			String^ surname = userNameText->Text;
			String^ document = userSurnameText->Text;
			String^ phone = userDocumentText->Text;
			String^ email = userPhoneText->Text;
			String^ address = userEmailText->Text;

			// Validación de campos vacíos ya que todos son obligatorios para completar la información
			if (name == "" || password == "" || surname == "" || document == "" || phone == "" || email == "" || address == "") {
				MessageBox::Show("Por favor, llene todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Validación del formato de correo electrónico con expresión regular
			if (!Regex::IsMatch(email, "^\\S+@\\S+\\.\\S+$")) {
				MessageBox::Show("El formato del correo electrónico no es válido. Debe ser de la forma 'usuario@dominio.com'.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Validación del número de teléfono para que sean exactamente 8 dígitos con expresión regular
			if (!Regex::IsMatch(phone, "^\\d{8}$")) {
				MessageBox::Show("El número de teléfono debe contener exactamente 8 dígitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			//Validación del número de documento para que sean exactamente 13 dígitos con expresión regular
			if(!Regex::IsMatch(document, "^\\d{13}$")) {
				MessageBox::Show("El número de documento debe contener exactamente 13 dígitos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Actualizar los valores de la fila seleccionada en el DataGridView
			selectedRow->Cells["Nombre"]->Value = name;
			selectedRow->Cells["Apellido"]->Value = surname;
			selectedRow->Cells["CUI/Pasaporte"]->Value = document;
			selectedRow->Cells["Teléfono"]->Value = phone;
			selectedRow->Cells["CorreoElectrónico"]->Value = email;
			selectedRow->Cells["Dirección"]->Value = address;

			// Convertir el tipo de usuario a mayúscula inicial si es necesario
			userType = CultureInfo::CurrentCulture->TextInfo->ToTitleCase(userType->ToLower());

			// Actualizar el valor del tipo de usuario en la fila seleccionada
			selectedRow->Cells["Tipo"]->Value = userType;
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para modificar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: Void deleteUserButton_Click(Object^ sender, EventArgs^ e) {
		if (usersDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = usersDataGridView->SelectedRows[0];

			// Evitar la fila temporal (*)
			if (selectedRow->Cells[0]->Value->ToString() != "*") {
				// Eliminar la fila seleccionada del DataGridView
				usersDataGridView->Rows->Remove(selectedRow);
			}
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: Void saveChangesButton_Click(Object^ sender, EventArgs^ e) {
		SaveUsersData(filePath, usersDataGridView);
		UpdateBinFile(filePath, binFilePath);
	}

	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		userUsernameText->Text = "";
		userPasswordText->Text = "";
		userTypeComboBox->SelectedIndex = -1;
		userNameText->Text = "";
		userSurnameText->Text = "";
		userDocumentText->Text = "";
		userPhoneText->Text = "";
		userEmailText->Text = "";
		userAddressText->Text = "";
	}
};
}