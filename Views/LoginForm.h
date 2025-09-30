#pragma once
#include "HomeMenu.h"
#include "UserManager.h"
#include "Usuarios.h"


namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	public ref class UserLogin : public Form
	{
	public:
		UserLogin()
		{
			InitializeComponent();
			userManager = gcnew UserManager(); // Inicializar el objeto de la clase UserManager

		}

	protected:
		~UserLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ username;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Label^ welcomeLabel;
	private: System::Windows::Forms::TextBox^ usernameText;
	private: System::Windows::Forms::TextBox^ passwordText;
	private: System::Windows::Forms::Label^ welcomeInfoLabel;
	private: System::Windows::Forms::Button^ loginButton;
	private: System::Windows::Forms::Label^ dateLabel;
	private: System::Windows::Forms::Label^ timeLabel;
	private: UserManager^ userManager; // Declarar un objeto de la clase UserManager
	protected:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->welcomeLabel = (gcnew System::Windows::Forms::Label());
			this->usernameText = (gcnew System::Windows::Forms::TextBox());
			this->passwordText = (gcnew System::Windows::Forms::TextBox());
			this->welcomeInfoLabel = (gcnew System::Windows::Forms::Label());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Location = System::Drawing::Point(74, 150);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(49, 13);
			this->usernameLabel->TabIndex = 0;
			this->usernameLabel->Text = L"Usuario: ";
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(56, 208);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(67, 13);
			this->passwordLabel->TabIndex = 1;
			this->passwordLabel->Text = L"Contraseña: ";
			// 
			// welcomeLabel
			// 
			this->welcomeLabel->AutoSize = true;
			this->welcomeLabel->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcomeLabel->Location = System::Drawing::Point(152, 27);
			this->welcomeLabel->Name = L"welcomeLabel";
			this->welcomeLabel->Size = System::Drawing::Size(124, 24);
			this->welcomeLabel->TabIndex = 2;
			this->welcomeLabel->Text = L"Bienvenido";
			this->welcomeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// usernameText
			// 
			this->usernameText->Location = System::Drawing::Point(152, 147);
			this->usernameText->MaxLength = 20;
			this->usernameText->Name = L"usernameText";
			this->usernameText->Size = System::Drawing::Size(124, 20);
			this->usernameText->TabIndex = 1;
			// 
			// passwordText
			// 
			this->passwordText->Location = System::Drawing::Point(152, 205);
			this->passwordText->MaxLength = 20;
			this->passwordText->Name = L"passwordText";
			this->passwordText->PasswordChar = '*';
			this->passwordText->Size = System::Drawing::Size(124, 20);
			this->passwordText->TabIndex = 2;
			this->passwordText->WordWrap = false;
			// 
			// welcomeInfoLabel
			// 
			this->welcomeInfoLabel->AutoSize = true;
			this->welcomeInfoLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->welcomeInfoLabel->Location = System::Drawing::Point(109, 64);
			this->welcomeInfoLabel->Name = L"welcomeInfoLabel";
			this->welcomeInfoLabel->Size = System::Drawing::Size(207, 16);
			this->welcomeInfoLabel->TabIndex = 5;
			this->welcomeInfoLabel->Text = L"Ingrese sus credenciales para iniciar el dia";
			// 
			// loginButton
			// 
			this->loginButton->Location = System::Drawing::Point(170, 255);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(94, 23);
			this->loginButton->TabIndex = 3;
			this->loginButton->Text = L"Iniciar sesión";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &UserLogin::button1_Click);
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Location = System::Drawing::Point(12, 9);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(34, 13);
			this->dateLabel->TabIndex = 6;
			this->dateLabel->Text = L"fecha";
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->Location = System::Drawing::Point(12, 27);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(28, 13);
			this->timeLabel->TabIndex = 7;
			this->timeLabel->Text = L"hora";
			// 
			// UserLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(414, 349);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->welcomeInfoLabel);
			this->Controls->Add(this->passwordText);
			this->Controls->Add(this->usernameText);
			this->Controls->Add(this->welcomeLabel);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"UserLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sistema de Control de Inventario - Supermercado";
			this->Load += gcnew System::EventHandler(this, &UserLogin::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private:
		System::ComponentModel::Container^ components;
		Void MyForm_Load(Object^ sender, EventArgs^ e) {
			dateLabel->Text = DateTime::Now.ToString("dd/MM/yyyy"); // Mostrar la fecha actual
			timeLabel->Text = DateTime::Now.ToString("hh:mm:ss tt"); // Mostrar la hora actual
		}

		Void button1_Click(Object^ sender, EventArgs^ e) {
			String^ username = usernameText->Text;
			String^ password = passwordText->Text;
			HomeMenu^ homeMenuForm = gcnew HomeMenu();

			if (username == "" || password == "") {
				MessageBox::Show("Por favor, llene todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (!Regex::IsMatch(username, "^[a-zA-Z0-9]+$")) {
				MessageBox::Show("El nombre de usuario no puede contener caracteres especiales, verifique su usario e intentelo de nuevo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (String::IsNullOrWhiteSpace(password)) {
				MessageBox::Show("La contraseña no puede estar vacía, verifiquela e intentelo de nuevo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			for each (Usuario ^ usuario in userManager->usuarios) {
				if (usuario->Username == username && usuario->Password == password) {
					if (usuario->SesionActiva) {
						MessageBox::Show("Este usuario ya ha iniciado sesión en otro lugar.", "Inicio de sesión denegado", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					usuario->SesionActiva = true;  // Marcar la sesión como activa
					MessageBox::Show("Bienvenido al sistema, " + usuario->Username, "Inicio de sesión exitoso", MessageBoxButtons::OK, MessageBoxIcon::Information);
					homeMenuForm->ShowButtonsByProfile(usuario->Tipo);
					this->Visible = false;
					homeMenuForm->ShowDialog();
					usuario->SesionActiva = false;  // Marcar la sesión como no activa después de cerrar sesión
					return;
				}
			}
			MessageBox::Show("Usuario o contraseña incorrectos, intente de nuevo por favor", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
};
}