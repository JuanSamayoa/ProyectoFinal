#pragma once
#include "Clients.h"
#include "Users.h"
#include "Inventory.h"
#include "SalesModule.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class HomeMenu : public Form
	{
	public:
		HomeMenu()
		{
			InitializeComponent();
			this->exitButton->Click += gcnew System::EventHandler(this, &HomeMenu::exitButton_Click);
		}

	public:

	private: System::Windows::Forms::Label^ welcomeLabelText;
	private: System::Windows::Forms::Label^ homeTimeLabel;
	private: System::Windows::Forms::Label^ homeDateLabel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	public:
	public:
	private: Clients^ clientsForm;
	private: System::Windows::Forms::Panel^ homeMenuPanel;
	private: Users^ usersForm;
	private: Inventory^ inventoryForm;
	private: SalesModule^ salesForm;

	protected:
		~HomeMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ clientButton;
	private: System::Windows::Forms::Button^ inventoryButton;
	private: System::Windows::Forms::Button^ salesButton;
	private: System::Windows::Forms::Button^ userAdminButton;
	private: System::Windows::Forms::Button^ reportsButton;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ fileUploadButton;
	private: 
		bool isAdminActive = false;
		bool isInventoryActive = false;
		bool isReportsActive = false;
		bool isClientsActive = false;
		bool isSalesActive = false;
		bool isFileUploadActive = false;

	protected:

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->clientButton = (gcnew System::Windows::Forms::Button());
			this->inventoryButton = (gcnew System::Windows::Forms::Button());
			this->salesButton = (gcnew System::Windows::Forms::Button());
			this->userAdminButton = (gcnew System::Windows::Forms::Button());
			this->reportsButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->fileUploadButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->homeTimeLabel = (gcnew System::Windows::Forms::Label());
			this->homeDateLabel = (gcnew System::Windows::Forms::Label());
			this->welcomeLabelText = (gcnew System::Windows::Forms::Label());
			this->homeMenuPanel = (gcnew System::Windows::Forms::Panel());
			this->homeMenuPanel->SuspendLayout();
			// 
			// clientButton
			// 
			this->clientButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->clientButton->Location = System::Drawing::Point(12, 12);
			this->clientButton->Name = L"clientButton";
			this->clientButton->Size = System::Drawing::Size(117, 27);
			this->clientButton->TabIndex = 0;
			this->clientButton->Text = L"Clientes";
			this->clientButton->UseVisualStyleBackColor = true;
			this->clientButton->Click += gcnew System::EventHandler(this, &HomeMenu::clientButton_Click);
			// 
			// inventoryButton
			// 
			this->inventoryButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->inventoryButton->Location = System::Drawing::Point(135, 12);
			this->inventoryButton->Name = L"inventoryButton";
			this->inventoryButton->Size = System::Drawing::Size(117, 27);
			this->inventoryButton->TabIndex = 1;
			this->inventoryButton->Text = L"Inventario";
			this->inventoryButton->UseVisualStyleBackColor = true;
			this->inventoryButton->Click += gcnew System::EventHandler(this, &HomeMenu::inventoryButton_Click);
			// 
			// salesButton
			// 
			this->salesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->salesButton->Location = System::Drawing::Point(258, 12);
			this->salesButton->Name = L"salesButton";
			this->salesButton->Size = System::Drawing::Size(117, 27);
			this->salesButton->TabIndex = 2;
			this->salesButton->Text = L"Venta de productos";
			this->salesButton->UseVisualStyleBackColor = true;
			this->salesButton->Click += gcnew System::EventHandler(this, &HomeMenu::salesButton_Click);
			// 
			// userAdminButton
			// 
			this->userAdminButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->userAdminButton->Location = System::Drawing::Point(12, 45);
			this->userAdminButton->Name = L"userAdminButton";
			this->userAdminButton->Size = System::Drawing::Size(117, 27);
			this->userAdminButton->TabIndex = 3;
			this->userAdminButton->Text = L"Gestion de usuarios";
			this->userAdminButton->UseVisualStyleBackColor = true;
			this->userAdminButton->Click += gcnew System::EventHandler(this, &HomeMenu::userAdminButton_Click);
			// 
			// reportsButton
			// 
			this->reportsButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->reportsButton->Location = System::Drawing::Point(258, 45);
			this->reportsButton->Name = L"reportsButton";
			this->reportsButton->Size = System::Drawing::Size(117, 25);
			this->reportsButton->TabIndex = 4;
			this->reportsButton->Text = L"Reportes";
			this->reportsButton->UseVisualStyleBackColor = true;
			this->reportsButton->Click += gcnew System::EventHandler(this, &HomeMenu::reportsButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Dock = System::Windows::Forms::DockStyle::Right;
			this->exitButton->Location = System::Drawing::Point(609, 0);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 87);
			this->exitButton->TabIndex = 6;
			this->exitButton->Text = L"Salir";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &HomeMenu::exitButton_Click);
			// 
			// fileUploadButton
			// 
			this->fileUploadButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->fileUploadButton->Location = System::Drawing::Point(135, 46);
			this->fileUploadButton->Name = L"fileUploadButton";
			this->fileUploadButton->Size = System::Drawing::Size(117, 26);
			this->fileUploadButton->TabIndex = 7;
			this->fileUploadButton->Text = L"Carga de archivos";
			this->fileUploadButton->UseVisualStyleBackColor = true;
			this->fileUploadButton->Click += gcnew System::EventHandler(this, &HomeMenu::fileUploadButton_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(418, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"La hora actual es";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(412, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"La fecha actual es";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// homeTimeLabel
			// 
			this->homeTimeLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->homeTimeLabel->AutoSize = true;
			this->homeTimeLabel->Location = System::Drawing::Point(513, 59);
			this->homeTimeLabel->Name = L"homeTimeLabel";
			this->homeTimeLabel->Size = System::Drawing::Size(28, 13);
			this->homeTimeLabel->TabIndex = 10;
			this->homeTimeLabel->Text = L"hora";
			this->homeTimeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// homeDateLabel
			// 
			this->homeDateLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->homeDateLabel->AutoSize = true;
			this->homeDateLabel->Location = System::Drawing::Point(513, 36);
			this->homeDateLabel->Name = L"homeDateLabel";
			this->homeDateLabel->Size = System::Drawing::Size(34, 13);
			this->homeDateLabel->TabIndex = 9;
			this->homeDateLabel->Text = L"fecha";
			this->homeDateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// welcomeLabelText
			// 
			this->welcomeLabelText->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->welcomeLabelText->AutoSize = true;
			this->welcomeLabelText->Location = System::Drawing::Point(438, 9);
			this->welcomeLabelText->Name = L"welcomeLabelText";
			this->welcomeLabelText->Size = System::Drawing::Size(97, 13);
			this->welcomeLabelText->TabIndex = 8;
			this->welcomeLabelText->Text = L"Bienvenido usuario";
			this->welcomeLabelText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// homeMenuPanel
			// 
			this->homeMenuPanel->Controls->Add(this->exitButton);
			this->homeMenuPanel->Controls->Add(this->label2);
			this->homeMenuPanel->Controls->Add(this->welcomeLabelText);
			this->homeMenuPanel->Controls->Add(this->label1);
			this->homeMenuPanel->Controls->Add(this->homeTimeLabel);
			this->homeMenuPanel->Controls->Add(this->clientButton);
			this->homeMenuPanel->Controls->Add(this->homeDateLabel);
			this->homeMenuPanel->Controls->Add(this->userAdminButton);
			this->homeMenuPanel->Controls->Add(this->inventoryButton);
			this->homeMenuPanel->Controls->Add(this->reportsButton);
			this->homeMenuPanel->Controls->Add(this->fileUploadButton);
			this->homeMenuPanel->Controls->Add(this->salesButton);
			this->homeMenuPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->homeMenuPanel->Location = System::Drawing::Point(0, 0);
			this->homeMenuPanel->Name = L"homeMenuPanel";
			this->homeMenuPanel->Size = System::Drawing::Size(684, 87);
			this->homeMenuPanel->TabIndex = 13;
			// 
			// HomeMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 661);
			this->Controls->Add(this->homeMenuPanel);
			this->IsMdiContainer = true;
			this->Name = L"HomeMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu Principal";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &HomeMenu::MenuPrincipal_Load);
			this->homeMenuPanel->ResumeLayout(false);
			this->homeMenuPanel->PerformLayout();

		}
#pragma endregion

	private: System::ComponentModel::Container^ components;

	public:
		void HomeMenu::ShowButtonsByProfile(String^ tipoUsuario)
		{
			if (tipoUsuario == "Administrador")
			{
				userAdminButton->Visible = true;
				reportsButton->Visible = true;
				fileUploadButton->Visible = true;
			}
			else if (tipoUsuario == "Operador")
			{
				userAdminButton->Visible = false;
				reportsButton->Visible = false;
				fileUploadButton->Visible = false;
			}
		}


	private: 
		Void MenuPrincipal_Load(Object^ sender, EventArgs^ e) {
			homeDateLabel->Text = DateTime::Now.ToString("dd/MM/yyyy");
			homeTimeLabel->Text = DateTime::Now.ToString("hh:mm:ss tt");
		}

		Void clientButton_Click(Object^ sender, EventArgs^ e) {
			if (isClientsActive) {
				MessageBox::Show("El menú ya se encuentra activo.", "Ventana ya abierta", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			} else{
				isClientsActive = true;
				clientsForm = gcnew Clients();
				clientsForm->MdiParent = this; // Establecer el contenedor MDI como el padre
				clientsForm->SelectClientButtonVisbility(isClientsActive);
				if (isAdminActive) {
					usersForm->Close();
					isAdminActive = false;
				}
				if(isInventoryActive){
					inventoryForm->Close();
					isInventoryActive = false;
				}
				if (isSalesActive) {
					salesForm->Close();
					isSalesActive = false;
				}
				clientsForm->Show();
			}
		}

		Void exitButton_Click(Object^ sender, EventArgs^ e) {
			Windows::Forms::DialogResult confirmacion = MessageBox::Show("Desea salir del sistema? Se realizara un cierre de día al momento de cerrar sesión", "Salir del sistema", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation);
			if (confirmacion == System::Windows::Forms::DialogResult::OK) {
				Application::Exit();
			} else if (confirmacion == System::Windows::Forms::DialogResult::Cancel) {
				
			}
			
		}

		private: Void inventoryButton_Click(Object^ sender, EventArgs^ e) {
			if (isInventoryActive) {
				MessageBox::Show("El menú ya se encuentra activo.", "Ventana ya abierta", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else {
				isInventoryActive = true;
				inventoryForm = gcnew Inventory();
				inventoryForm->MdiParent = this; // Establecer el contenedor MDI como el padre
				if (isClientsActive) {
					clientsForm->Close();
					isClientsActive = false;
				}
				if (isAdminActive) {
					usersForm->Close();
					isAdminActive = false;
				}
				if (isSalesActive) {
					salesForm->Close();
					isSalesActive = false;
				}
				inventoryForm->Show();
			}
		}

		private: Void salesButton_Click(Object^ sender, EventArgs^ e) {
			if (isSalesActive) {
				MessageBox::Show("El menú ya se encuentra activo.", "Ventana ya abierta", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else {
				isSalesActive = true;
				salesForm = gcnew SalesModule();
				salesForm->MdiParent = this;
				if (isClientsActive) {
					clientsForm->Close();
					isClientsActive = false;
				}
				if (isAdminActive) {
					usersForm->Close();
					isAdminActive = false;
				}
				if (isInventoryActive) {
					inventoryForm->Close();
					isInventoryActive = false;
				}
				salesForm->Show();
			}
		}

		private: Void userAdminButton_Click(Object^ sender, EventArgs^ e) {
			if (isAdminActive) {
				MessageBox::Show("El menú ya se encuentra activo.", "Ventana ya abierta", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			} else {
				isAdminActive = true;
				usersForm = gcnew Users();
				usersForm->MdiParent = this; // Establecer el contenedor MDI como el padre
				if (isClientsActive) {
					clientsForm->Hide();
					isClientsActive = false;
				}
				if (isInventoryActive) {
					inventoryForm->Close();
					isInventoryActive = false;
				}
				if (isSalesActive) {
					salesForm->Close();
					isSalesActive = false;
				}
				usersForm->Show();
			}
		}

	private: Void fileUploadButton_Click(Object^ sender, EventArgs^ e) {
	}

	private: Void reportsButton_Click(Object^ sender, EventArgs^ e) {
	}
};
}
