#include "Curso.h"

Curso::Curso()
{
}

Curso::Curso(const int codigo, const string& nombre, int creditos): codigo(codigo),
                                                                    nombre(nombre),
                                                                    creditos(creditos)
{
}

Curso::Curso(const string& codigo, const string& nombre, const string& creditos)
    : codigo(stoi(codigo)),
    nombre(nombre),
    creditos(stoi(creditos))
{
}

void Curso::setCodigo(int newval)
{
    codigo = newval;
}

int Curso::getCodigo()
{
    return codigo;
}

void Curso::setNombre(string newval)
{
    nombre = newval;
}

string Curso::getNombre()
{
    return nombre;
}

void Curso::setCreditos(int newval)
{
    creditos = newval;
}

int Curso::getCreditos()
{
    return creditos;
}

bool Curso::existeCurso(vector<Curso> cursos, int codigoCurso)
{
	for (Curso curso : cursos)
	{
		if (codigoCurso == curso.getCodigo())
		{
			return true;
		}
	}

	return false;
}

Curso Curso::obtenerCurso(vector<Curso> cursos, int codigoCurso)
{
	for (Curso curso : cursos)
	{
		if (codigoCurso == curso.getCodigo())
		{
			return curso;
		}
	}

	return Curso();
}

string Curso::toString()
{
	char separador = ',';
	return to_string(codigo) + separador +
		nombre + separador +
		to_string(creditos) +
		"\n";
}

