#pragma once
#include "Clients.h"
#include "Cliente.h"
#include "Inventory.h"

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
			this->Load += gcnew System::EventHandler(this, &SalesModule::SalesModule_Load);
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
	private: Inventory^ productsForm;

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->shoppingCartDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// shoppingCartDataGridView
			// 
			this->shoppingCartDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->shoppingCartDataGridView->Location = System::Drawing::Point(12, 108);
			this->shoppingCartDataGridView->Name = L"shoppingCartDataGridView";
			this->shoppingCartDataGridView->Size = System::Drawing::Size(716, 340);
			this->shoppingCartDataGridView->TabIndex = 0;
			// 
			// shoppingCartLabel
			// 
			this->shoppingCartLabel->AutoSize = true;
			this->shoppingCartLabel->Font = (gcnew System::Drawing::Font(L"Lato", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->shoppingCartLabel->Location = System::Drawing::Point(302, 69);
			this->shoppingCartLabel->Name = L"shoppingCartLabel";
			this->shoppingCartLabel->Size = System::Drawing::Size(141, 19);
			this->shoppingCartLabel->TabIndex = 1;
			this->shoppingCartLabel->Text = L"Carrito de compras";
			// 
			// addProductToCartButton
			// 
			this->addProductToCartButton->Location = System::Drawing::Point(12, 68);
			this->addProductToCartButton->Name = L"addProductToCartButton";
			this->addProductToCartButton->Size = System::Drawing::Size(84, 34);
			this->addProductToCartButton->TabIndex = 2;
			this->addProductToCartButton->Text = L"Seleccionar producto(s)";
			this->addProductToCartButton->UseVisualStyleBackColor = true;
			this->addProductToCartButton->Click += gcnew System::EventHandler(this, &SalesModule::addProductToCartButton_Click);
			// 
			// SalesModule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(740, 460);
			this->ControlBox = false;
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
		clientsForm->SelectClientButtonVisibility(false);
		// Mostrar el formulario Clients después de suscribirse al evento
		clientsForm->Show();
	}

	private: Void productFormInitialProperties() {
		productsForm->ControlBox = true;
		productsForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
		productsForm->StartPosition = FormStartPosition::CenterScreen;
		productsForm->WindowState = FormWindowState::Normal;
		productsForm->TopMost = true;
	}

	private: Void clientFormInitialProperties() {
		clientsForm->ControlBox = true;
		clientsForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
		clientsForm->StartPosition = FormStartPosition::CenterScreen;
		clientsForm->WindowState = FormWindowState::Normal;
		clientsForm->TopMost = true;
	}

	// Otro evento para agregar productos al carrito u otras acciones relacionadas con la venta
	private: System::Void addProductToCartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		productsForm = gcnew Inventory();
		productsForm->selectProductVisibility(false);
		productFormInitialProperties();
		productsForm->Show();
	}

	public: Void showProductToCart(Producto^ producto, int cantidadCompra) {
		String^ productCode = producto->getCodigoProducto();

		if (producto != nullptr) {
			shoppingCartDataGridView->Rows->Add(gcnew array<String^>{
				producto->getCodigoProducto(),
				producto->getNombre(),
				producto->getCategoria(),
				producto->getMarca(),
				producto->getDescripcion(),
				producto->getPrecioUnitario(),
				//agregar la cantidad que se selecciono en la pantalla de inventario
			});
		}
		else {
			MessageBox::Show("Producto no encontrado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	void InitializeDataGridView() {
		shoppingCartDataGridView->Columns->Add("CodigoProducto", "Código del Producto");
		shoppingCartDataGridView->Columns->Add("Nombre", "Nombre del Producto");
		shoppingCartDataGridView->Columns->Add("Categoria", "Categoría");
		shoppingCartDataGridView->Columns->Add("Marca", "Marca");
		shoppingCartDataGridView->Columns->Add("Descripcion", "Descripción");
		shoppingCartDataGridView->Columns->Add("PrecioUnitario", "Precio Unitario");
		shoppingCartDataGridView->Columns->Add("CantidadStock", "Cantidad Disponible");
	}

};
}