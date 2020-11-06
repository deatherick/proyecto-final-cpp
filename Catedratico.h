#pragma once
#include <string>
#include <vector>

using namespace std;

class Catedratico
{
public:
	Catedratico();
	Catedratico(int codigo, const string& nombre, const string& apellido, const string& dpi, int telefono, const string& direccion);
	Catedratico(const string& codigo, const string& nombre, const string& apellido, const string& dpi, const string& telefono, const string& direccion);

private:
	int codigo;
	string nombre;
	string apellido;
	string dpi;
	int telefono;
	string direccion;

public:
	void setCodigo(int newval);
	int getCodigo();
	
	void setNombre(string newval);
	string getNombre();

	void setApellido(string newval);
	string getApellido();

	void setDpi(string newval);
	string getDpi();

	void setTelefono(int newval);
	int getTelefono();

	void setDireccion(string newval);
	string getDireccion();

	static bool existeCatedratico(vector<Catedratico> catedraticos, int codigo);

	static Catedratico obtenerCatedratico(vector<Catedratico> catedraticos, int codigo);

	string toString();
};

