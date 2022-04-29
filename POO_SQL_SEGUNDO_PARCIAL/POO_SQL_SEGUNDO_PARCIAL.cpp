// POO_SQL_SEGUNDO_PARCIAL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma once
#include <iostream>
#include "Estudiante.h"
using namespace std;

int main() {
	
	int idest=0, tel=0, gen=0;
	string car,nom, ape, dir, mail, fn;

	Estudiante obj = Estudiante(idest,car, nom, ape, dir, tel, gen, mail, fn);
	obj.leer();

	cout << "\n 1 - Ingresar datos del estudiante nuevo: ";
	cout << "\n 2 - Modificar datos del estudiante: ";
	cout << "\n 3 - Eliminar datos del estudiante: ";
	cout << "\n\nIngrese la opcion a ejecutar: ";
	int opcion = 0;
	cin >> opcion;

	if (opcion == 1) {

		cout << "Ingrese ID del estudiante:";
		cin >> idest;
		cout << "Ingrese carnet:";
		cin >> car;
		cout << "Ingrese nombre:";
		cin >> nom;
		cout << "Ingrese apellido:";
		cin >> ape;
		cout << "Ingrese direccion:";
		cin >> dir;
		cout << "Ingrese telefono:";
		cin >> tel;
		cout << "0 - Si es FEMENINO\n";
		cout << "1 - Si es MASCULINO\n";
		cout << "Ingrese genero:";
		cin >> gen;
		cout << "Ingrese email:";
		cin >> mail;
		cout << "Ingrese fecha de nacimiento:";
		cin >> fn;

		// instancia de un objeto
		Estudiante obj = Estudiante(idest, car, nom, ape, dir, tel, gen, mail, fn);
		obj.crear();
		obj.leer();
	}

	if (opcion == 2) {

		cout << "Modificar ID del estudiante:";
		cin >> idest;
		cout << "Modificar carnet:";
		cin >> car;
		cout << "Modificar nombre:";
		cin >> nom;
		cout << "Modificar apellido:";
		cin >> ape;
		cout << "Modificar direccion:";
		cin >> dir;
		cout << "Modificar telefono:";
		cin >> tel;
		cout << "0 - Si es FEMENINO\n";
		cout << "1 - Si es MASCULINO\n";
		cout << "Modificar genero:";
		cin >> gen;
		cout << "Modificar email:";
		cin >> mail;
		cout << "Modificar fecha de nacimiento:";
		cin >> fn;

		Estudiante obj = Estudiante(idest, car, nom, ape, dir, tel, gen, mail, fn);

		obj.setID_estudiante(idest);
		obj.setCarnet(car);
		obj.setNombres(nom);
		obj.setApellidos(ape);
		obj.setDireccion(dir);
		obj.setTelefono(tel);
		obj.setGenero(gen);
		obj.setEmail(mail);
		obj.setFechaNacimiento(fn);

		obj.modificar();
		obj.leer();
	}

	if (opcion == 3) {

		cout << "Eliminar ID del estudiante:";
		cin >> idest;

		Estudiante obj = Estudiante(idest, car, nom, ape, dir, tel, gen, mail, fn);

		obj.eliminar();
		obj.leer();
	}

	system("pause");
	return 0;

}
