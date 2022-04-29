#pragma once
#include <iostream>
using namespace std;

class Info_Estudiante {
	// atributos
protected:
	string carnet, nombre, apellido, direccion, email, fecha_nacimiento;
	int telefono = 0, genero = 0;

	// costructor
protected:
	Info_Estudiante() {
	}
	Info_Estudiante(string car, string nom, string ape, string dir, int tel, int gen, string mail, string fn) {
		carnet = car;
		nombre = nom;
		apellido = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		email = mail;
		fecha_nacimiento = fn;
	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};

