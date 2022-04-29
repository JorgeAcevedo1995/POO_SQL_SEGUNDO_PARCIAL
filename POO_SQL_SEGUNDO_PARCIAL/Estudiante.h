#pragma once
#include "Info_Estudiante.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;

class Estudiante :
    public Info_Estudiante{


	// atributos
private: int id_estudiante = 0;
	   // constructor
public:
	Estudiante() {
	}
	Estudiante(int idest, string car, string nom, string ape, string dir, int tel, int gen, string mail, string fn) : Info_Estudiante(car, nom, ape, dir, tel, gen, mail, fn) {
		id_estudiante = idest;
	}

	// METODOS
	//set (modificar)
	void setID_estudiante(int idest) { id_estudiante = idest; }
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombre = nom; }
	void setApellidos(string ape) { apellido = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int gen) { genero = gen;	}
	void setEmail(string mail) { email = mail; }
	void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	int getID_estudiante() { return id_estudiante; }
	string getCarnet() { return carnet; }
	string getNombres() { return nombre; }
	string getApellidos() { return apellido; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getGenero() { return genero; }
	string getEmail() { return email; }
	string getFechaNacimiento() { return fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(id_estudiante);
			string t = to_string(telefono);
			string g = to_string(genero);
			string insert = "INSERT INTO estudiantes.estudiantes (idEstudiante,Carnet,Nombres,Apellidos,Direccion,Telefono,Genero,Email,Fecha_Nacimiento)VALUES(" + id + ",'" + carnet + "','" + nombre + "','" + apellido + "','" + direccion + "'," + t + "," + g + ",'" + email + "','" + fecha_nacimiento + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso.." << endl;
			}
			else {
				cout << "Error al ingresar información" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM estudiantes.estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------ESTUDIANTES--------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," "," << fila[6] << "," "," << fila[7] << "," "," << fila[8] << endl;
				}
			}
			else {
				cout << "Error al ingresar informacion" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(id_estudiante);
			string eliminar = "DELETE from estudiantes.estudiantes WHERE idEstudiante = " + id + ";";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se ha eliminado con exito" << endl;
			}
			else {
				cout << "Error al ingresar informacion" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(id_estudiante);
			string t = to_string(telefono);
			string g = to_string(genero);
			string actualizar = "UPDATE estudiantes.estudiantes SET Carnet='" + carnet + "',Nombres='" + nombre + "',Apellidos='" + apellido + "',Direccion='" + direccion + "',Telefono = " + t + ",Genero=" + g + ",Email='" + fecha_nacimiento + "',Fecha_Nacimiento='" + fecha_nacimiento + "' WHERE idEstudiante =" + id + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se ha modificado con exito" << endl;
			}
			else {
				cout << "Error al ingresar información" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

};


