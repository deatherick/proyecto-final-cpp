#include "Catedratico.h"

Catedratico::Catedratico()
{
}

Catedratico::Catedratico(int codigo, const string& nombre, const string& apellido, const string& dpi, int telefono, const string& direccion):
	codigo(codigo),
	nombre(nombre),
	apellido(apellido),
	dpi(dpi),
	telefono(telefono),
	direccion(direccion)
{
}

Catedratico::Catedratico(const string& codigo, const string& nombre, const string& apellido, const string& dpi, const string& telefono,
	const string& direccion) :
	codigo(stoi(codigo)),
	nombre(nombre),
	apellido(apellido),
	dpi(dpi),
	telefono(stoi(telefono)),
	direccion(direccion)
{
}

void Catedratico::setCodigo(int newval)
{
	codigo = newval;
}

int Catedratico::getCodigo()
{
	return codigo;
}

void Catedratico::setNombre(string newval)
{
	nombre = newval;
}

string Catedratico::getNombre()
{
	return nombre;
}

void Catedratico::setApellido(string newval)
{
	apellido = newval;
}

string Catedratico::getApellido()
{
	return apellido;
}

void Catedratico::setDpi(string newval)
{
	dpi = newval;
}

string Catedratico::getDpi()
{
	return dpi;
}

void Catedratico::setTelefono(int newval)
{
	telefono = newval;
}

int Catedratico::getTelefono()
{
	return telefono;
}

void Catedratico::setDireccion(string newval)
{
	direccion = newval;
}

string Catedratico::getDireccion()
{
	return direccion;
}

bool Catedratico::existeCatedratico(vector<Catedratico> catedraticos, int codigo)
{
	for (Catedratico catedratico : catedraticos)
	{
		if (codigo == catedratico.getCodigo())
		{
			return true;
		}
	}

	return false;
}

Catedratico Catedratico::obtenerCatedratico(vector<Catedratico> catedraticos, int codigo)
{
	for (Catedratico catedratico : catedraticos)
	{
		if (codigo == catedratico.getCodigo())
		{
			return catedratico;
		}
	}

	return Catedratico();
}

string Catedratico::toString()
{
	char separador = ',';
	return nombre + separador +
		apellido + separador +
		dpi + separador +
		to_string(telefono) + separador +
		direccion +
		"\n";
}
