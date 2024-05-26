#pragma once
#include <string>

using namespace System;

public ref class Producto {
public:
    Producto() {}
	Producto(String^ codigo, String^ nombre, String^ categoria, String^ marca, String^ descripcion, String^ precio, String^ cantidad) {
		this->CodigoProducto = codigo;
		this->Nombre = nombre;
		this->Categoria = categoria;
		this->Marca = marca;
		this->Descripcion = descripcion;
		this->PrecioUnitario = precio;
		this->CantidadStock = cantidad;
	}

    //Metodos set y get para todas las propiedades
	void setCodigoProducto(String^ codigoProducto) {
		CodigoProducto = codigoProducto;
	}

	String^ getCodigoProducto() {
		return CodigoProducto;
	}

	void setNombre(String^ nombre) {
		Nombre = nombre;
	}

	String^ getNombre() {
		return Nombre;
	}

	void setCategoria(String^ categoria) {
		Categoria = categoria;
	}

	String^ getCategoria() {
		return Categoria;
	}

	void setMarca(String^ marca) {
		Marca = marca;
	}

	String^ getMarca() {
		return Marca;
	}

	void setDescripcion(String^ descripcion) {
		Descripcion = descripcion;
	}

	String^ getDescripcion() {
		return Descripcion;
	}

	void setPrecioUnitario(String^ precioUnitario) {
		PrecioUnitario = precioUnitario;
	}

	String^ getPrecioUnitario() {
		return PrecioUnitario;
	}

	void setCantidadStock(String^ cantidadStock) {
		CantidadStock = cantidadStock;
	}

	String^ getCantidadStock() {
		return CantidadStock;
	}

	void restarCantidadStock(int cantidadARestar) {
		int cantidadActual = Int32::Parse(CantidadStock);
		cantidadActual -= cantidadARestar;
		CantidadStock = cantidadActual.ToString();
	}

private:
	String^ CodigoProducto;
	String^ Nombre;
	String^ Categoria;
	String^ Marca;
	String^ Descripcion;
	String^ PrecioUnitario;
	String^ CantidadStock;
};