#include <string>

using namespace System;

#pragma once
public ref class Cliente {
public:
	property int Codigo;
	property String^ Nombre;
	property String^ Direccion;
	property String^ Telefono;
	property String^ CorreoElectronico;

	Cliente(int codigo, String^ nombre, String^ direccion, String^ telefono, String^ correoElectronico) {
		Codigo = codigo;
		Nombre = nombre;
		Direccion = direccion;
		Telefono = telefono;
		CorreoElectronico = correoElectronico;
	}
};