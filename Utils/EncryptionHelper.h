#pragma once

using namespace System;
using namespace System::Security::Cryptography;
using namespace System::IO;
using namespace System::Text;

namespace SupermarketManagement
{

public
	ref class EncryptionHelper
	{
	private:
		static array<Byte> ^ key = Encoding::UTF8->GetBytes("YourSecretKey123"); // Use a secure key
		static array<Byte> ^ iv = Encoding::UTF8->GetBytes("YourIV1234567890");	 // Use a secure IV

	public:
		static array<Byte> ^ EncryptData(String ^ plainText) {
			Aes ^ aes = Aes::Create();
			aes->Key = key;
			aes->IV = iv;

			ICryptoTransform ^ encryptor = aes->CreateEncryptor();

			MemoryStream ^ ms = gcnew MemoryStream();
			CryptoStream ^ cs = gcnew CryptoStream(ms, encryptor, CryptoStreamMode::Write);
			StreamWriter ^ sw = gcnew StreamWriter(cs);

			sw->Write(plainText);
			sw->Close();
			cs->Close();

			return ms->ToArray();
		}

				static String
				^ DecryptData(array<Byte> ^ cipherText) {
						Aes ^ aes = Aes::Create();
						aes->Key = key;
						aes->IV = iv;

						ICryptoTransform ^ decryptor = aes->CreateDecryptor();

						MemoryStream ^ ms = gcnew MemoryStream(cipherText);
						CryptoStream ^ cs = gcnew CryptoStream(ms, decryptor, CryptoStreamMode::Read);
						StreamReader ^ sr = gcnew StreamReader(cs);

						String ^ plainText = sr->ReadToEnd();
						sr->Close();
						cs->Close();

						return plainText;
					}

				static void SaveEncryptedData(String ^ filePath, String ^ data)
		{
			array<Byte> ^ encryptedData = EncryptData(data);
			File::WriteAllBytes(filePath, encryptedData);
		}

		static String ^ LoadEncryptedData(String ^ filePath) {
			if (!File::Exists(filePath))
				return "";
			array<Byte> ^ encryptedData = File::ReadAllBytes(filePath);
			return DecryptData(encryptedData);
		}
	};
}