#pragma once
#include <string>
#include <vector>

using namespace std;

class Curso
{
public:
	Curso();
	Curso(int codigo, const string& nombre, int creditos);
	Curso(const string& codigo, const string& nombre, const string& creditos);

private:
	int codigo;
	string nombre;
	int creditos;

public:
	void setCodigo(int newval);
	int getCodigo();

	void setNombre(string newval);
	string getNombre();

	void setCreditos(int newval);
	int getCreditos();

	static bool existeCurso(vector<Curso> cursos, int codigoCurso);

	static Curso obtenerCurso(vector<Curso> cursos, int codigoCurso);

	string toString();
};

