using namespace std;

class Estudiante
{
public:static const int SIZE = 2;
static const int MAX_SIZE = 25;

    string carne;
    string nombre;
    int codigoCurso;
    float examenesParciales[SIZE];
    float tareas;
    float examenFinal;
    float examenRecuperacion;

	Estudiante();
    Estudiante(const string& carne, const string& nombre, int codigo_curso, float examenes_parciales[], float tareas,
        float examen_final, float examen_recuperacion)
        : carne(carne),
        nombre(nombre),
        codigoCurso(codigo_curso),
        examenesParciales(),
        tareas(tareas),
        examenFinal(examen_final),
        examenRecuperacion(examen_recuperacion)
    {
        this->examenesParciales[0] = examenes_parciales[0];
        this->examenesParciales[1] = examenes_parciales[1];
    }
    Estudiante(const string& carne, const string& nombre, string codigo_curso, string examenes_parciales[], string tareas,
        string examen_final, string examen_recuperacion)
        : carne(carne),
        nombre(nombre),
        codigoCurso(stoi(codigo_curso)),
        examenesParciales(),
        tareas(stof(tareas)),
        examenFinal(stof(examen_final)),
        examenRecuperacion(stof(examen_recuperacion))
    {

        this->examenesParciales[0] = stof(examenes_parciales[0]);
        this->examenesParciales[1] = stof(examenes_parciales[1]);
    }

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

    string toString();
};

void Estudiante::setCarne(string newval)
{
    carne = newval;
}

string Estudiante::getCarne()
{
    return carne;
}

void Estudiante::setNombre(string newval)
{
    nombre = newval;
}

string Estudiante::getNombre()
{
    return nombre;
}

void Estudiante::setCodigoCurso(int newval)
{
    codigoCurso = newval;
}

int Estudiante::getCodigoCurso()
{
    return codigoCurso;
}

void Estudiante::setExamenesParciales(float* newval)
{
    for (int i = 0; i < SIZE; i++)
    {
        examenesParciales[i] = newval[i];
    }
}

float* Estudiante::getExamenesParciales()
{
    return examenesParciales;
}

void Estudiante::setTareas(float newval)
{
    tareas = newval;
}

float Estudiante::getTareas()
{
    return tareas;
}

void Estudiante::setExamenFinal(float newval)
{
    examenFinal = newval;
}

float Estudiante::getExamenFinal()
{
    return examenFinal;
}

void Estudiante::setExamenRecuperacion(float newval)
{
    examenRecuperacion = newval;
}

float Estudiante::getExamenRecuperacion()
{
    return examenRecuperacion;
}

string Estudiante::toString()
{
    char separador = ',';
    return carne + separador +
        nombre + separador +
        to_string(codigoCurso) + separador +
        to_string(examenesParciales[0]) + separador +
        to_string(examenesParciales[1]) + separador +
        to_string(tareas) + separador +
        to_string(examenFinal) + separador +
        to_string(examenRecuperacion) +
        "\n";
}