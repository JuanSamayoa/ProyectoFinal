#pragma once
#include <string>

using namespace System;

namespace ProyectoFinal{

    public ref class Usuario
    {
    public:
        String^ Username;
        String^ Password;
        String^ Tipo;
        String^ Nombre;
        String^ Apellido;
        String^ Cui;
        String^ Telefono;
        String^ CorreoElectronico;
        String^ Direccion;
        bool SesionActiva;  // Nuevo campo para gestionar la sesión

        Usuario(String^ username, String^ password, String^ tipo, String^ nombre, String^ apellido, String^ cui, String^ telefono, String^ correoElectronico, String^ direccion)
        {
            Username = username;
            Password = password;
            Tipo = tipo;
            Nombre = nombre;
            Apellido = apellido;
            Cui = cui;
            Telefono = telefono;
            CorreoElectronico = correoElectronico;
            Direccion = direccion;
            SesionActiva = false;  // Inicializar la sesión como no activa
        }
    };
}