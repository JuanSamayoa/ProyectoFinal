#pragma once
#include "Clients.h"
#include "Cliente.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SalesModule : public System::Windows::Forms::Form
	{
	public:
		SalesModule(void)
		{
			InitializeComponent();
		}

	protected:
		~SalesModule()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ shoppingCartDataGridView;
	private: System::Windows::Forms::Label^ shoppingCartLabel;
	private: System::Windows::Forms::Button^ addProductToCartButton;
	private: System::ComponentModel::Container ^components;
	private: Clients^ clientsForm;
	private: System::Windows::Forms::Label^ clientNameLabel;
	private: System::Windows::Forms::Label^ clientName;
	private: System::Windows::Forms::Label^ clientAddressLabel;
	private: System::Windows::Forms::Label^ clientEmail;
	private: System::Windows::Forms::Label^ clientEmailLabel;
	private: System::Windows::Forms::Label^ clientPhoneNumber;
	private: System::Windows::Forms::Label^ clientPhoneNumberLabel;
	private: System::Windows::Forms::Label^ clientBillingDataLabel;
	private: System::Windows::Forms::Label^ clientAddress;





	private: Cliente^ selectedClient; // Variable para almacenar el cliente seleccionado

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->shoppingCartDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->shoppingCartLabel = (gcnew System::Windows::Forms::Label());
			this->addProductToCartButton = (gcnew System::Windows::Forms::Button());
			this->clientNameLabel = (gcnew System::Windows::Forms::Label());
			this->clientName = (gcnew System::Windows::Forms::Label());
			this->clientAddressLabel = (gcnew System::Windows::Forms::Label());
			this->clientEmail = (gcnew System::Windows::Forms::Label());
			this->clientEmailLabel = (gcnew System::Windows::Forms::Label());
			this->clientPhoneNumber = (gcnew System::Windows::Forms::Label());
			this->clientPhoneNumberLabel = (gcnew System::Windows::Forms::Label());
			this->clientBillingDataLabel = (gcnew System::Windows::Forms::Label());
			this->clientAddress = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->shoppingCartDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// shoppingCartDataGridView
			// 
			this->shoppingCartDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->shoppingCartDataGridView->Location = System::Drawing::Point(331, 192);
			this->shoppingCartDataGridView->Name = L"shoppingCartDataGridView";
			this->shoppingCartDataGridView->Size = System::Drawing::Size(397, 256);
			this->shoppingCartDataGridView->TabIndex = 0;
			// 
			// shoppingCartLabel
			// 
			this->shoppingCartLabel->AutoSize = true;
			this->shoppingCartLabel->Font = (gcnew System::Drawing::Font(L"Lato", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->shoppingCartLabel->Location = System::Drawing::Point(507, 167);
			this->shoppingCartLabel->Name = L"shoppingCartLabel";
			this->shoppingCartLabel->Size = System::Drawing::Size(141, 19);
			this->shoppingCartLabel->TabIndex = 1;
			this->shoppingCartLabel->Text = L"Carrito de compras";
			// 
			// addProductToCartButton
			// 
			this->addProductToCartButton->Location = System::Drawing::Point(331, 152);
			this->addProductToCartButton->Name = L"addProductToCartButton";
			this->addProductToCartButton->Size = System::Drawing::Size(84, 34);
			this->addProductToCartButton->TabIndex = 2;
			this->addProductToCartButton->Text = L"Seleccionar producto(s)";
			this->addProductToCartButton->UseVisualStyleBackColor = true;
			// 
			// clientNameLabel
			// 
			this->clientNameLabel->AutoSize = true;
			this->clientNameLabel->Location = System::Drawing::Point(65, 37);
			this->clientNameLabel->Name = L"clientNameLabel";
			this->clientNameLabel->Size = System::Drawing::Size(45, 13);
			this->clientNameLabel->TabIndex = 3;
			this->clientNameLabel->Text = L"Cliente: ";
			// 
			// clientName
			// 
			this->clientName->AutoSize = true;
			this->clientName->Location = System::Drawing::Point(116, 37);
			this->clientName->Name = L"clientName";
			this->clientName->Size = System::Drawing::Size(39, 13);
			this->clientName->TabIndex = 4;
			this->clientName->Text = L"Cliente";
			// 
			// clientAddressLabel
			// 
			this->clientAddressLabel->AutoSize = true;
			this->clientAddressLabel->Location = System::Drawing::Point(52, 63);
			this->clientAddressLabel->Name = L"clientAddressLabel";
			this->clientAddressLabel->Size = System::Drawing::Size(58, 13);
			this->clientAddressLabel->TabIndex = 5;
			this->clientAddressLabel->Text = L"Dirección: ";
			// 
			// clientEmail
			// 
			this->clientEmail->AutoSize = true;
			this->clientEmail->Location = System::Drawing::Point(116, 118);
			this->clientEmail->Name = L"clientEmail";
			this->clientEmail->Size = System::Drawing::Size(32, 13);
			this->clientEmail->TabIndex = 6;
			this->clientEmail->Text = L"Email";
			// 
			// clientEmailLabel
			// 
			this->clientEmailLabel->AutoSize = true;
			this->clientEmailLabel->Location = System::Drawing::Point(10, 118);
			this->clientEmailLabel->Name = L"clientEmailLabel";
			this->clientEmailLabel->Size = System::Drawing::Size(100, 13);
			this->clientEmailLabel->TabIndex = 9;
			this->clientEmailLabel->Text = L"Correo Electrónico: ";
			// 
			// clientPhoneNumber
			// 
			this->clientPhoneNumber->AutoSize = true;
			this->clientPhoneNumber->Location = System::Drawing::Point(116, 91);
			this->clientPhoneNumber->Name = L"clientPhoneNumber";
			this->clientPhoneNumber->Size = System::Drawing::Size(44, 13);
			this->clientPhoneNumber->TabIndex = 8;
			this->clientPhoneNumber->Text = L"Numero";
			// 
			// clientPhoneNumberLabel
			// 
			this->clientPhoneNumberLabel->AutoSize = true;
			this->clientPhoneNumberLabel->Location = System::Drawing::Point(55, 91);
			this->clientPhoneNumberLabel->Name = L"clientPhoneNumberLabel";
			this->clientPhoneNumberLabel->Size = System::Drawing::Size(55, 13);
			this->clientPhoneNumberLabel->TabIndex = 7;
			this->clientPhoneNumberLabel->Text = L"Teléfono: ";
			// 
			// clientBillingDataLabel
			// 
			this->clientBillingDataLabel->AutoSize = true;
			this->clientBillingDataLabel->Font = (gcnew System::Drawing::Font(L"Lato", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientBillingDataLabel->Location = System::Drawing::Point(29, 9);
			this->clientBillingDataLabel->Name = L"clientBillingDataLabel";
			this->clientBillingDataLabel->Size = System::Drawing::Size(152, 19);
			this->clientBillingDataLabel->TabIndex = 15;
			this->clientBillingDataLabel->Text = L"Datos de facturación";
			// 
			// clientAddress
			// 
			this->clientAddress->AutoSize = true;
			this->clientAddress->Location = System::Drawing::Point(116, 63);
			this->clientAddress->Name = L"clientAddress";
			this->clientAddress->Size = System::Drawing::Size(52, 13);
			this->clientAddress->TabIndex = 16;
			this->clientAddress->Text = L"Direccion";
			// 
			// SalesModule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(740, 460);
			this->ControlBox = false;
			this->Controls->Add(this->clientAddress);
			this->Controls->Add(this->clientBillingDataLabel);
			this->Controls->Add(this->clientEmailLabel);
			this->Controls->Add(this->clientPhoneNumber);
			this->Controls->Add(this->clientPhoneNumberLabel);
			this->Controls->Add(this->clientEmail);
			this->Controls->Add(this->clientAddressLabel);
			this->Controls->Add(this->clientName);
			this->Controls->Add(this->clientNameLabel);
			this->Controls->Add(this->addProductToCartButton);
			this->Controls->Add(this->shoppingCartLabel);
			this->Controls->Add(this->shoppingCartDataGridView);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SalesModule";
			this->Text = L"SalesModule";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &SalesModule::SalesModule_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->shoppingCartDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Void SalesModule_Load(Object^ sender, EventArgs^ e) {
		clientsForm = gcnew Clients();
		clientFormInitialProperties();
		retrieveSelectedClient();
		clientsForm->SelectClientButtonVisbility(false);
	}

	private: Void clientFormInitialProperties() {
		clientsForm->ControlBox = true;
		clientsForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
		clientsForm->StartPosition = FormStartPosition::CenterScreen;
		clientsForm->WindowState = FormWindowState::Normal;
		clientsForm->TopMost = true;
	}

	private: Void retrieveSelectedClient() {
		// Mostrar el formulario de clientes
		clientsForm->Show();

		// Verificar si se ha seleccionado un cliente en el formulario de clientes
		if (clientsForm->SelectedClient != nullptr) {
			// Asigna el cliente seleccionado a la variable selectedClient
			selectedClient = clientsForm->SelectedClient;

			// Utilizar los datos del cliente seleccionado según sea necesario
			int codigoCliente = selectedClient->Codigo;
			String^ nombre = selectedClient->Nombre;
			String^ direccion = selectedClient->Direccion;
			String^ telefono = selectedClient->Telefono;
			String^ correoElectronico = selectedClient->CorreoElectronico;

			// Asignar los datos del cliente seleccionado a los controles de la interfaz de usuario
			clientName->Text = nombre;
			clientAddress->Text = direccion;
			clientPhoneNumber->Text = telefono;
			clientEmail->Text = correoElectronico;
		}
	}
};
}
