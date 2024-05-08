#pragma once
#include "GlobalVariables.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	public ref class Inventory : public Form
	{
	public:
		Inventory(void)
		{
			InitializeComponent();
		}

		void LoadInventoryData(String^ filePath, DataGridView^ grid); //Carga los datos del archivo CSV en el DataGridView
		void SaveInventoryData(String^ filePath, DataGridView^ grid); //Guarda los datos del en el archivo CSV al momento de realizar cualquier accion
		void ModifyInventoryViewData(DataGridView^ grid); //Modifica los datos del archivo CSV al momento de realizar alguna accion
		bool IsFileOpen(String^ filePath); //Verifica que el archivo no haya sido abierto por otro programa


	protected:
		~Inventory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::GroupBox^ actionControlBox;
	private: System::Windows::Forms::Button^ saveChangesButton;
	private: System::Windows::Forms::Button^ modifyProductButton;
	private: System::Windows::Forms::Button^ deleteProductButton;
	private: System::Windows::Forms::Button^ addProductButton;
	private: System::Windows::Forms::DataGridView^ inventoryDataGridView;
	private: System::Windows::Forms::GroupBox^ inventoryControlBox;
	private: System::Windows::Forms::TextBox^ productQuantityText;
	private: System::Windows::Forms::TextBox^ unitPriceText;
	private: System::Windows::Forms::Label^ productQuantityLabel;
	private: System::Windows::Forms::Label^ unitPriceLabel;
	private: System::Windows::Forms::ComboBox^ productCategoryComboBox;
	private: System::Windows::Forms::Label^ productCodeLabel;
	private: System::Windows::Forms::TextBox^ productCodeText;
	private: System::Windows::Forms::TextBox^ productDescriptionText;
	private: System::Windows::Forms::TextBox^ productLineText;
	private: System::Windows::Forms::TextBox^ productNameText;
	private: System::Windows::Forms::Label^ productDescriptionLabel;
	private: System::Windows::Forms::Label^ productLineLabel;
	private: System::Windows::Forms::Label^ productCategoryLabel;
	private: System::Windows::Forms::Label^ productNameLabel;

	private:
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ clearButton;
		   String^ filePath = "data\\Productos.csv";


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->actionControlBox = (gcnew System::Windows::Forms::GroupBox());
			this->saveChangesButton = (gcnew System::Windows::Forms::Button());
			this->modifyProductButton = (gcnew System::Windows::Forms::Button());
			this->deleteProductButton = (gcnew System::Windows::Forms::Button());
			this->addProductButton = (gcnew System::Windows::Forms::Button());
			this->inventoryDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->inventoryControlBox = (gcnew System::Windows::Forms::GroupBox());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->productQuantityText = (gcnew System::Windows::Forms::TextBox());
			this->unitPriceText = (gcnew System::Windows::Forms::TextBox());
			this->productQuantityLabel = (gcnew System::Windows::Forms::Label());
			this->unitPriceLabel = (gcnew System::Windows::Forms::Label());
			this->productCategoryComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->productCodeLabel = (gcnew System::Windows::Forms::Label());
			this->productCodeText = (gcnew System::Windows::Forms::TextBox());
			this->productDescriptionText = (gcnew System::Windows::Forms::TextBox());
			this->productLineText = (gcnew System::Windows::Forms::TextBox());
			this->productNameText = (gcnew System::Windows::Forms::TextBox());
			this->productDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->productLineLabel = (gcnew System::Windows::Forms::Label());
			this->productCategoryLabel = (gcnew System::Windows::Forms::Label());
			this->productNameLabel = (gcnew System::Windows::Forms::Label());
			this->actionControlBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inventoryDataGridView))->BeginInit();
			this->inventoryControlBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat Thin", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(10, 424);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(286, 36);
			this->label2->TabIndex = 106;
			this->label2->Text = L"Recuerda siempre guardar tus cambios \r\npara que sean reflejados*";
			// 
			// actionControlBox
			// 
			this->actionControlBox->Controls->Add(this->saveChangesButton);
			this->actionControlBox->Controls->Add(this->modifyProductButton);
			this->actionControlBox->Controls->Add(this->deleteProductButton);
			this->actionControlBox->Controls->Add(this->addProductButton);
			this->actionControlBox->Location = System::Drawing::Point(4, 350);
			this->actionControlBox->Name = L"actionControlBox";
			this->actionControlBox->Size = System::Drawing::Size(340, 62);
			this->actionControlBox->TabIndex = 103;
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
			this->saveChangesButton->Click += gcnew System::EventHandler(this, &Inventory::saveChangesButton_Click);
			// 
			// modifyProductButton
			// 
			this->modifyProductButton->Location = System::Drawing::Point(90, 17);
			this->modifyProductButton->Name = L"modifyProductButton";
			this->modifyProductButton->Size = System::Drawing::Size(75, 39);
			this->modifyProductButton->TabIndex = 11;
			this->modifyProductButton->Text = L"Modificar Producto";
			this->modifyProductButton->UseVisualStyleBackColor = true;
			this->modifyProductButton->Click += gcnew System::EventHandler(this, &Inventory::modifyProductButton_Click);
			// 
			// deleteProductButton
			// 
			this->deleteProductButton->Location = System::Drawing::Point(171, 17);
			this->deleteProductButton->Name = L"deleteProductButton";
			this->deleteProductButton->Size = System::Drawing::Size(75, 39);
			this->deleteProductButton->TabIndex = 12;
			this->deleteProductButton->Text = L"Eliminar Producto";
			this->deleteProductButton->UseVisualStyleBackColor = true;
			this->deleteProductButton->Click += gcnew System::EventHandler(this, &Inventory::deleteProductButton_Click);
			// 
			// addProductButton
			// 
			this->addProductButton->Location = System::Drawing::Point(9, 17);
			this->addProductButton->Name = L"addProductButton";
			this->addProductButton->Size = System::Drawing::Size(75, 39);
			this->addProductButton->TabIndex = 10;
			this->addProductButton->Text = L"Agregar Producto";
			this->addProductButton->UseVisualStyleBackColor = true;
			this->addProductButton->Click += gcnew System::EventHandler(this, &Inventory::addProductButton_Click);
			// 
			// inventoryDataGridView
			// 
			this->inventoryDataGridView->AllowUserToDeleteRows = false;
			this->inventoryDataGridView->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->inventoryDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->inventoryDataGridView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->inventoryDataGridView->Location = System::Drawing::Point(381, 57);
			this->inventoryDataGridView->Name = L"inventoryDataGridView";
			this->inventoryDataGridView->ReadOnly = true;
			this->inventoryDataGridView->Size = System::Drawing::Size(943, 355);
			this->inventoryDataGridView->TabIndex = 104;
			this->inventoryDataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Inventory::inventoryDataGridView_CellClick);
			// 
			// inventoryControlBox
			// 
			this->inventoryControlBox->Controls->Add(this->clearButton);
			this->inventoryControlBox->Controls->Add(this->productQuantityText);
			this->inventoryControlBox->Controls->Add(this->unitPriceText);
			this->inventoryControlBox->Controls->Add(this->productQuantityLabel);
			this->inventoryControlBox->Controls->Add(this->unitPriceLabel);
			this->inventoryControlBox->Controls->Add(this->productCategoryComboBox);
			this->inventoryControlBox->Controls->Add(this->productCodeLabel);
			this->inventoryControlBox->Controls->Add(this->productCodeText);
			this->inventoryControlBox->Controls->Add(this->productDescriptionText);
			this->inventoryControlBox->Controls->Add(this->productLineText);
			this->inventoryControlBox->Controls->Add(this->productNameText);
			this->inventoryControlBox->Controls->Add(this->productDescriptionLabel);
			this->inventoryControlBox->Controls->Add(this->productLineLabel);
			this->inventoryControlBox->Controls->Add(this->productCategoryLabel);
			this->inventoryControlBox->Controls->Add(this->productNameLabel);
			this->inventoryControlBox->Location = System::Drawing::Point(4, 56);
			this->inventoryControlBox->Name = L"inventoryControlBox";
			this->inventoryControlBox->Size = System::Drawing::Size(340, 274);
			this->inventoryControlBox->TabIndex = 105;
			this->inventoryControlBox->TabStop = false;
			this->inventoryControlBox->Text = L"Control de inventarios";
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(252, 19);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 107;
			this->clearButton->Text = L"Limpiar";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Inventory::clearButton_Click);
			// 
			// productQuantityText
			// 
			this->productQuantityText->Location = System::Drawing::Point(132, 206);
			this->productQuantityText->MaxLength = 4;
			this->productQuantityText->Name = L"productQuantityText";
			this->productQuantityText->Size = System::Drawing::Size(155, 20);
			this->productQuantityText->TabIndex = 8;
			// 
			// unitPriceText
			// 
			this->unitPriceText->Location = System::Drawing::Point(132, 180);
			this->unitPriceText->MaxLength = 8;
			this->unitPriceText->Name = L"unitPriceText";
			this->unitPriceText->Size = System::Drawing::Size(155, 20);
			this->unitPriceText->TabIndex = 6;
			// 
			// productQuantityLabel
			// 
			this->productQuantityLabel->AutoSize = true;
			this->productQuantityLabel->Location = System::Drawing::Point(23, 209);
			this->productQuantityLabel->Name = L"productQuantityLabel";
			this->productQuantityLabel->Size = System::Drawing::Size(104, 13);
			this->productQuantityLabel->TabIndex = 6;
			this->productQuantityLabel->Text = L"Cantidad Disponible:";
			// 
			// unitPriceLabel
			// 
			this->unitPriceLabel->AutoSize = true;
			this->unitPriceLabel->Location = System::Drawing::Point(49, 183);
			this->unitPriceLabel->Name = L"unitPriceLabel";
			this->unitPriceLabel->Size = System::Drawing::Size(77, 13);
			this->unitPriceLabel->TabIndex = 14;
			this->unitPriceLabel->Text = L"Precio unitario:";
			// 
			// productCategoryComboBox
			// 
			this->productCategoryComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"Alimentos frescos", L"Frutas y verduras",
					L"Carnes y pescados", L"Productos lácteos", L"Panadería y repostería", L"Congelados", L"Conservas y enlatados", L"Productos de despensa",
					L"Bebidas", L"Snacks y golosinas", L"Productos de limpieza", L"Artículos de cuidado personal", L"Productos para mascotas", L"Artículos para el hogar",
					L"Productos de higiene personal", L"Otros"
			});
			this->productCategoryComboBox->Location = System::Drawing::Point(132, 99);
			this->productCategoryComboBox->Name = L"productCategoryComboBox";
			this->productCategoryComboBox->Size = System::Drawing::Size(155, 21);
			this->productCategoryComboBox->TabIndex = 3;
			// 
			// productCodeLabel
			// 
			this->productCodeLabel->AutoSize = true;
			this->productCodeLabel->Location = System::Drawing::Point(23, 50);
			this->productCodeLabel->Name = L"productCodeLabel";
			this->productCodeLabel->Size = System::Drawing::Size(103, 13);
			this->productCodeLabel->TabIndex = 11;
			this->productCodeLabel->Text = L"Código de producto:";
			// 
			// productCodeText
			// 
			this->productCodeText->Enabled = false;
			this->productCodeText->Location = System::Drawing::Point(132, 47);
			this->productCodeText->MaxLength = 20;
			this->productCodeText->Name = L"productCodeText";
			this->productCodeText->Size = System::Drawing::Size(88, 20);
			this->productCodeText->TabIndex = 0;
			// 
			// productDescriptionText
			// 
			this->productDescriptionText->Location = System::Drawing::Point(132, 152);
			this->productDescriptionText->MaxLength = 50;
			this->productDescriptionText->Name = L"productDescriptionText";
			this->productDescriptionText->Size = System::Drawing::Size(155, 20);
			this->productDescriptionText->TabIndex = 5;
			// 
			// productLineText
			// 
			this->productLineText->Location = System::Drawing::Point(132, 126);
			this->productLineText->MaxLength = 20;
			this->productLineText->Name = L"productLineText";
			this->productLineText->Size = System::Drawing::Size(155, 20);
			this->productLineText->TabIndex = 4;
			// 
			// productNameText
			// 
			this->productNameText->Location = System::Drawing::Point(132, 73);
			this->productNameText->MaxLength = 20;
			this->productNameText->Name = L"productNameText";
			this->productNameText->Size = System::Drawing::Size(155, 20);
			this->productNameText->TabIndex = 1;
			// 
			// productDescriptionLabel
			// 
			this->productDescriptionLabel->AutoSize = true;
			this->productDescriptionLabel->Location = System::Drawing::Point(61, 155);
			this->productDescriptionLabel->Name = L"productDescriptionLabel";
			this->productDescriptionLabel->Size = System::Drawing::Size(66, 13);
			this->productDescriptionLabel->TabIndex = 4;
			this->productDescriptionLabel->Text = L"Descripción:";
			// 
			// productLineLabel
			// 
			this->productLineLabel->AutoSize = true;
			this->productLineLabel->Location = System::Drawing::Point(87, 129);
			this->productLineLabel->Name = L"productLineLabel";
			this->productLineLabel->Size = System::Drawing::Size(40, 13);
			this->productLineLabel->TabIndex = 3;
			this->productLineLabel->Text = L"Marca:";
			// 
			// productCategoryLabel
			// 
			this->productCategoryLabel->AutoSize = true;
			this->productCategoryLabel->Location = System::Drawing::Point(68, 102);
			this->productCategoryLabel->Name = L"productCategoryLabel";
			this->productCategoryLabel->Size = System::Drawing::Size(57, 13);
			this->productCategoryLabel->TabIndex = 2;
			this->productCategoryLabel->Text = L"Categoría:";
			// 
			// productNameLabel
			// 
			this->productNameLabel->AutoSize = true;
			this->productNameLabel->Location = System::Drawing::Point(18, 76);
			this->productNameLabel->Name = L"productNameLabel";
			this->productNameLabel->Size = System::Drawing::Size(109, 13);
			this->productNameLabel->TabIndex = 0;
			this->productNameLabel->Text = L"Nombre del producto:";
			// 
			// Inventory
			// 
			this->AccessibleName = L"Inventory";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1329, 516);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->actionControlBox);
			this->Controls->Add(this->inventoryDataGridView);
			this->Controls->Add(this->inventoryControlBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inventory";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Control de inventario";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Inventory::Inventory_Load);
			this->actionControlBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inventoryDataGridView))->EndInit();
			this->inventoryControlBox->ResumeLayout(false);
			this->inventoryControlBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: Void Inventory_Load(Object^ sender, EventArgs^ e) {
		LoadInventoryData(filePath, inventoryDataGridView);
		productCategoryComboBox->SelectedIndex = 0;
	}

	private: System::Void inventoryDataGridView_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0 && e->RowIndex < inventoryDataGridView->Rows->Count) {
			DataGridViewRow^ selectedRow = inventoryDataGridView->Rows[e->RowIndex];

			// Obtener los valores de la fila seleccionada
			String^ productCode = safe_cast<String^>(selectedRow->Cells["CódigoProducto"]->Value);
			String^ productName = safe_cast<String^>(selectedRow->Cells["Nombre"]->Value);
			String^ productCategory = safe_cast<String^>(selectedRow->Cells["Categoría"]->Value);
			String^ productLine = safe_cast<String^>(selectedRow->Cells["Marca"]->Value);
			String^ productDescription = safe_cast<String^>(selectedRow->Cells["Descripción"]->Value);
			String^ unitPrice = safe_cast<String^>(selectedRow->Cells["PrecioUnitario"]->Value);
			String^ productQuantity = safe_cast<String^>(selectedRow->Cells["CantidadStock"]->Value);

			// Asignar los valores a los campos correspondientes
			productCodeText->Text = productCode;
			productNameText->Text = productName;
			productCategoryComboBox->Text = productCategory;
			productLineText->Text = productLine;
			productDescriptionText->Text = productDescription;
			unitPriceText->Text = unitPrice;
			productQuantityText->Text = productQuantity;
		}
		else {
			// Mostrar un mensaje de advertencia si la fila seleccionada es inválida
			MessageBox::Show("La fila seleccionada no es válida.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: Void addProductButton_Click(Object^ sender, EventArgs^ e) {
		inventoryIndex++;
		String^ name = productNameText->Text;
		String^ category = productCategoryComboBox->SelectedItem->ToString();
		String^ line = productLineText->Text;
		String^ description = productDescriptionText->Text;
		String^ price = unitPriceText->Text;
		String^ quantity = productQuantityText->Text;

		

		if (name == "" || category == "" || line == "" || description == "" || price == "" || quantity == "") {
			MessageBox::Show("Por favor, llene todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Validación del formato de precio con expresión regular
		if (!Regex::IsMatch(price, "^[0-9]+(\\.[0-9]{1,2})?$")) {
			MessageBox::Show("El formato del precio no es válido. Debe ser un número válido con hasta dos decimales.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Validación de la cantidad con expresión regular
		if (!Regex::IsMatch(quantity, "^\\d+$")) {
			MessageBox::Show("La cantidad debe ser un número entero positivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Aquí incluirías la validación de los datos antes de añadirlos
		inventoryDataGridView->Rows->Add(inventoryIndex, name, category, line, description, price, quantity);

		// Limpiar los campos después de añadir el producto
		productCodeText->Text = "";
		productNameText->Text = "";
		productCategoryComboBox->SelectedIndex = -1;
		productLineText->Text = "";
		productDescriptionText->Text = "";
		unitPriceText->Text = "";
		productQuantityText->Text = "";
	}

	private: Void modifyProductButton_Click(Object^ sender, EventArgs^ e) {
		if (inventoryDataGridView->SelectedRows->Count > 0) {
			DataGridViewRow^ selectedRow = inventoryDataGridView->SelectedRows[0];

			// Obtener los nuevos valores de la fila desde los campos de texto
			String^ productCode = productCodeText->Text;
			String^ productName = productNameText->Text;
			String^ productCategory = productCategoryComboBox->SelectedItem->ToString();
			String^ productLine = productLineText->Text;
			String^ productDescription = productDescriptionText->Text;
			String^ unitPrice = unitPriceText->Text;
			String^ productQuantity = productQuantityText->Text;

			// Validación de campos vacíos ya que todos son obligatorios para completar la información
			if (productCode == "" || productName == "" || productCategory == "" || productLine == "" || productDescription == "" || unitPrice == "" || productQuantity == "") {
				MessageBox::Show("Por favor, llene todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Validación del formato de precio con expresión regular
			if (!Regex::IsMatch(unitPrice, "^[0-9]+(\\.[0-9]{1,2})?$")) {
				MessageBox::Show("El formato del precio no es válido. Debe ser un número válido con hasta dos decimales.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Validación de la cantidad con expresión regular
			if (!Regex::IsMatch(productQuantity, "^\\d+$")) {
				MessageBox::Show("La cantidad debe ser un número entero positivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Actualizar los valores de la fila seleccionada en el DataGridView
			selectedRow->Cells["CódigoProducto"]->Value = productCode;
			selectedRow->Cells["Nombre"]->Value = productName;
			selectedRow->Cells["Categoría"]->Value = productCategory;
			selectedRow->Cells["Marca"]->Value = productLine;
			selectedRow->Cells["Descripción"]->Value = productDescription;
			selectedRow->Cells["PrecioUnitario"]->Value = unitPrice;
			selectedRow->Cells["CantidadStock"]->Value = productQuantity;
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para modificar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	private: Void deleteProductButton_Click(Object^ sender, EventArgs^ e) {
		if (inventoryDataGridView->SelectedRows->Count > 0) {
			inventoryDataGridView->Rows->RemoveAt(inventoryDataGridView->SelectedRows[0]->Index);
			inventoryIndex--;
		}
		else {
			MessageBox::Show("Por favor, selecciona una fila para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: Void saveChangesButton_Click(Object^ sender, EventArgs^ e) {
		Inventory^ inventoryInstance = gcnew Inventory();
		inventoryInstance->SaveInventoryData(filePath, inventoryDataGridView);
	}

	private: Void clearButton_Click(Object^ sender, EventArgs^ e) {
		productCodeText->Text = "";
		productNameText->Text = "";
		productCategoryComboBox->SelectedIndex = -1;
		productLineText->Text = "";
		productDescriptionText->Text = "";
		unitPriceText->Text = "";
		productQuantityText->Text = "";
	}
};
}
