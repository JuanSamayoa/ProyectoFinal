#pragma once

#include "../Models/Customer.h"
#include "../Utils/EncryptionHelper.h"
#include <vector>

namespace SupermarketManagement
{

public
	ref class CustomerManager
	{
	private:
		String ^ dataFilePath = "Data/customers.bin";

	public:
		void SaveCustomers(System::Collections::Generic::List<Customer ^> ^ customers)
		{
			String ^ csvData = "Code,Name,Address,Phone,Email\n";
			for each (Customer ^ customer in customers)
			{
				csvData += customer->ToCSV() + "\n";
			}
			EncryptionHelper::SaveEncryptedData(dataFilePath, csvData);
		}

		System::Collections::Generic::List<Customer ^> ^ LoadCustomers() {
			System::Collections::Generic::List<Customer ^> ^ customers = gcnew System::Collections::Generic::List<Customer ^>();
			String ^ csvData = EncryptionHelper::LoadEncryptedData(dataFilePath);
			if (String::IsNullOrEmpty(csvData))
				return customers;

			array<String ^> ^ lines = csvData->Split('\n');
			for (int i = 1; i < lines->Length; i++)
			{ // Skip header
				if (!String::IsNullOrWhiteSpace(lines[i]))
				{
					Customer ^ customer = Customer::FromCSV(lines[i]);
					if (customer != nullptr)
						customers->Add(customer);
				}
			}
			return customers;
		}
	};
}