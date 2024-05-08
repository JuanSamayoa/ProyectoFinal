#pragma once

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de SalesModule
	/// </summary>
	public ref class SalesModule : public System::Windows::Forms::Form
	{
	public:
		SalesModule(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~SalesModule()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ shoppingCartDataGridView;
	protected:

	protected:
	private: System::Windows::Forms::Label^ shoppingCartLabel;
	private: System::Windows::Forms::Button^ addProductToCartButton;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->shoppingCartDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
