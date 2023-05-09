#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;
class Cliente :
    public Persona
{
private: string nit;

public:
	Cliente() {
	}

	Cliente(string nom, string ape, string dir, int tel,string fn, string n) : Persona(nom, ape, dir, tel,fn) {

		nit = n;
	}

	//metodos get y set antes de la funcion mostrar

	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombre,apellidos,direccion,telefono,fecha_nacimiento)VALUES('" + nit + "','" + nombres + "','" + apellidos +"','" + direccion +"'," + t + ",'" + fecha_nacimiento +"');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << " Ingreso Exitoso... " << endl;
			}
			else {
				cout << " xxxx Error al ingresar xxxx" << endl;
			}
		}
		else {
			cout << "---Error en la Conexion ---" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select * from clientes";
			const char* C = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), C);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "------------------------Clientes---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;

				}
			}
			else {
				cout << " xxxx Error al ingresar informacion xxxx" << endl;
			}
		}
		else {
			cout << "---Error en la Conexion ---" << endl;
		}
		cn.cerrar_conexion();
	}

};

