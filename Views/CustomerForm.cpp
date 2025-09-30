#include "../Utils/GlobalVariables.h"
#include "CustomerForm.h"
#include "../Managers/CustomerManager.h"
#include <fstream>
#include <string>

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace SupermarketManagement;

namespace SupermarketManagement
{

    int clientIndex = 0;

    bool CustomerForm::IsFileOpen(String ^ filePath)
    {
        try
        {
            FileStream ^ fs = File::Open(filePath, FileMode::OpenOrCreate, FileAccess::ReadWrite, FileShare::None);
            fs->Close();
            return false;
        }
        catch (IOException ^)
        {
            return true;
        }
    }

    void CustomerForm::LoadCustomerData(DataGridView ^ grid)
    {
        CustomerManager ^ manager = gcnew CustomerManager();
        auto customers = manager->LoadCustomers();

        grid->Columns->Clear();
        grid->Rows->Clear();

        // Add columns
        grid->Columns->Add("Code", "Code");
        grid->Columns->Add("Name", "Name");
        grid->Columns->Add("Address", "Address");
        grid->Columns->Add("Phone", "Phone");
        grid->Columns->Add("Email", "Email");

        // Add rows
        for each (Customer ^ customer in customers)
        {
            grid->Rows->Add(customer->Code, customer->Name, customer->Address, customer->Phone, customer->Email);
        }
    }

    void CustomerForm::SaveCustomerData(DataGridView ^ grid)
    {
        CustomerManager ^ manager = gcnew CustomerManager();
        auto customers = gcnew System::Collections::Generic::List<Customer ^>();
        for (int i = 0; i < grid->Rows->Count - 1; i++)
        {
            int code = Int32::Parse(grid->Rows[i]->Cells[0]->Value->ToString());
            String ^ name = grid->Rows[i]->Cells[1]->Value->ToString();
            String ^ address = grid->Rows[i]->Cells[2]->Value->ToString();
            String ^ phone = grid->Rows[i]->Cells[3]->Value->ToString();
            String ^ email = grid->Rows[i]->Cells[4]->Value->ToString();
            customers->Add(gcnew Customer(code, name, address, phone, email));
        }
        manager->SaveCustomers(customers);
    }

    void CustomerForm::ModifyCustomerData(DataGridView ^ grid)
    {
        // Check if a row is selected for modification
        if (grid->SelectedRows->Count > 0)
        {
            DataGridViewRow ^ selectedRow = grid->SelectedRows[0];

            // Get new values from text fields
            String ^ name = clientNameText->Text;
            String ^ address = clientAddressText->Text;
            String ^ phone = clientPhoneText->Text;
            String ^ email = clientEmailText->Text;

            // Update the selected row in DataGridView
            selectedRow->Cells[1]->Value = name;
            selectedRow->Cells[2]->Value = address;
            selectedRow->Cells[3]->Value = phone;
            selectedRow->Cells[4]->Value = email;
        }
        else
        {
            MessageBox::Show("Please select a row to modify.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}