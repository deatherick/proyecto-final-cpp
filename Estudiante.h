#pragma once
#include <string>
#include <vector>
using namespace std;

class Estudiante
{
public:
	static const int SIZE = 2;
	static const int MAX_SIZE = 25;

private:
    string carne;
    string nombre;
    int codigoCurso;
    float examenesParciales[SIZE];
    float tareas;
    float examenFinal;
    float examenRecuperacion;

    float notaTotal;

public:
	Estudiante();
	Estudiante(const string& carne, const string& nombre, int codigo_curso, float examenes_parciales[], float tareas,
           float examen_final, float examen_recuperacion);
	Estudiante(const string& carne, const string& nombre, string codigo_curso, string examenes_parciales[], string tareas,
           string examen_final, string examen_recuperacion);

    void setCarne(string newval);
    string getCarne();

    void setNombre(string newval);
    string getNombre();

    void setCodigoCurso(int newval);
    int getCodigoCurso();

    void setExamenesParciales(float* newval);
    float* getExamenesParciales();

    void setTareas(float newval);
    float getTareas();

    void setExamenFinal(float newval);
    float getExamenFinal();

    void setExamenRecuperacion(float newval);
    float getExamenRecuperacion();

    float getNotaTotal();

	static bool existeEstudiante(vector<Estudiante> estudiantes, string carne);

	static Estudiante obtenerEstudiante(vector<Estudiante> estudiantes, string carne);

    string toString();
};

