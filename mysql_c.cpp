// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int main()
{
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empres@123", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		cout << "Conexion Exitosa.." << endl;
	}
	else {
		cout << "Error en la Concexion..." << endl;
	}
	cout << "Hello World!\n";
  system("pause");
  return 0;
}

