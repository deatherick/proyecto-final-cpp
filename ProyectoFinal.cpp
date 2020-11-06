
#include "ProyectoFinal.h"
#include "Estudiante.h"
#include "Catedratico.h"
#include "Curso.h"

using namespace std;

bool isEmpty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

void LeerCursos(vector<Curso>& result)
{
    ifstream File("Cursos.csv", ios::app);
	
    string codigo, nombre, creditos;

    if (File.is_open())
    {
        while (File.good())
        {
            if (isEmpty(File))
            {
                return;
            }
            getline(File, codigo, ',');
            getline(File, nombre, ',');
            getline(File, creditos);

            result.emplace_back(Curso(codigo, nombre, creditos));
        }
    }
    else
    {
        cout << "Error al leer archivo" << endl;
    }
}

void LeerCatedraticos(vector<Catedratico>& result)
{
    ifstream File("Catedraticos.csv", ios::app);

    string codigo, nombre, apellido, dpi, telefono, direccion;

    if (File.is_open())
    {
        while (File.good())
        {
            if (isEmpty(File))
            {
                return;
            }
            getline(File, codigo, ',');
            getline(File, nombre, ',');
            getline(File, apellido, ',');
            getline(File, dpi, ',');
            getline(File, telefono, ',');
            getline(File, direccion);

            result.emplace_back(Catedratico(codigo, nombre, apellido, dpi, telefono, direccion));
        }
    }
    else
    {
        cout << "Error al leer archivo" << endl;
    }
}

void LeerEstudiantes(vector<Estudiante>& result)
{	
    ifstream File("Estudiantes.csv", ios::app);

    string carne, nombre, codigoCurso, examenParcial1, examenParcial2, tareas, examenFinal, examenRecuperacion;

    if (File.is_open())
    {
        while (File.good())
        {
            if(isEmpty(File))
            {
                return;
            }
            getline(File, carne, ',');
            getline(File, nombre, ',');
            getline(File, codigoCurso, ',');
            getline(File, examenParcial1, ',');
            getline(File, examenParcial2, ',');
            getline(File, tareas, ',');
            getline(File, examenFinal, ',');
            getline(File, examenRecuperacion);

            result.emplace_back(Estudiante(carne, nombre, codigoCurso, new string[]{ examenParcial1, examenParcial2 }, tareas, examenFinal, examenRecuperacion));
        }
    }
    else
    {
        cout << "Error al leer archivo" << endl;
    }
}

void InsertarCurso()
{
    vector<Curso> cursos{};

    LeerCursos(cursos);

    int codigo, creditos;
    string nombre;

    cout << "Ingrese el Codigo del curso #" << cursos.size() + 1 << ":" << endl;
    cin >> codigo;
    while (cin.fail())
    {
        cout << "Solo numeros son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> codigo;
    }

    cout << "Ingrese el nombre del curso #" << cursos.size() + 1 << ":" << endl;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese los creditos del curso #" << cursos.size() + 1 << ":" << endl;
    cin >> creditos;
    while (cin.fail())
    {
        cout << "Solo numeros son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> creditos;
    }

    cursos.emplace_back(Curso(codigo, nombre, creditos));

    ofstream File("Cursos.csv", ios::app);

    File << cursos[cursos.size() - 1].toString();

    cout << "El curso ha sido ingresado correctamente" << endl;
}

void InsertarCatedratico()
{
    vector<Catedratico> catedraticos{};

    LeerCatedraticos(catedraticos);

    string nombre, apellido, dpi, direccion;
    int codigo, telefono;

    cout << "Ingrese el codigo del catedratico #" << catedraticos.size() + 1 << ":" << endl;
    cin >> codigo;
    while (cin.fail())
    {
        cout << "Solo numeros son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> codigo;
    }

    cout << "Ingrese el nombre del catedratico #" << catedraticos.size() + 1 << ":" << endl;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el apellido del catedratico #" << catedraticos.size() + 1 << ":" << endl;
    getline(cin, apellido);

    cout << "Ingrese el DPI del catedratico #" << catedraticos.size() + 1 << ":" << endl;
    getline(cin, dpi);

    cout << "Ingrese el telefono del catedratico #" << catedraticos.size() + 1 << ":" << endl;
    cin >> telefono;
    while (cin.fail())
    {
        cout << "Solo numeros son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> telefono;
    }

    cout << "Ingrese la direccion del catedratico #" << catedraticos.size() + 1 << ":" << endl;
    cin.ignore();
    getline(cin, direccion);

    catedraticos.emplace_back(Catedratico(codigo, nombre, apellido, dpi, telefono, direccion));

    ofstream File("Catedraticos.csv", ios::app);

    File << catedraticos[catedraticos.size() - 1].toString();

    cout << "El catedratico ha sido ingresado correctamente" << endl;
}

void InsertarEstudiante()
{
    vector<Estudiante> estudiantes{};
    LeerEstudiantes(estudiantes);

    vector<Curso> cursos{};
    LeerCursos(cursos);

	if(estudiantes.size() >= Estudiante::MAX_SIZE)
	{
        cout << "Se ha alcanzado el maximo de alumnos: " << Estudiante::MAX_SIZE << endl;
        return;
	}

    string carne, nombre;
    int codigoCurso;
	float examenParcial1, examenParcial2, tareas, examenFinal, examenRecuperacion;

    cout << "Ingrese el carne del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin >> carne;
	
    cout << "Ingrese el nombre del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el Codigo del curso del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin >> codigoCurso;
	while(!Curso::existeCurso(cursos, codigoCurso) || cin.fail())
	{    
        if (cin.fail())
        {
            cout << "Solo numeros son permitidos" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> codigoCurso;
        } else
        {
            cout << "No existe el Codigo del curso ingresado" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> codigoCurso;
        }
	}

    cout << "Ingrese el 1er Examen parcial del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin >> examenParcial1;
    while (cin.fail())
    {
        cout << "Solo numeros y decimales son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> examenParcial1;
    }

    cout << "Ingrese el 2do Examen parcial del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin >> examenParcial2;
    while (cin.fail())
    {
        cout << "Solo numeros y decimales son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> examenParcial2;
    }

    cout << "Ingrese el punteo de tareas del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin >> tareas;
    while (cin.fail())
    {
        cout << "Solo numeros y decimales son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> tareas;
    }

    cout << "Ingrese el Examen final del alumno #" << estudiantes.size() + 1 << ":" << endl;
    cin >> examenFinal;
    while (cin.fail())
    {
        cout << "Solo numeros y decimales son permitidos" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> examenFinal;
    }

	if(examenParcial1 + examenParcial2 + tareas + examenFinal < 61)
	{
        cout << "Ingrese el Examen de recuperacion del alumno #" << estudiantes.size() + 1 << ":" << endl;
        cin >> examenRecuperacion;
        while (cin.fail())
        {
            cout << "Solo numeros y decimales son permitidos" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> examenRecuperacion;
        }
	} else
	{
        examenRecuperacion = 0;
	}

    estudiantes.emplace_back(Estudiante(carne, nombre, codigoCurso, new float[]{ examenParcial1, examenParcial2 }, tareas, examenFinal, examenRecuperacion));   

    ofstream File("Estudiantes.csv", ios::app);
	
    File << estudiantes[estudiantes.size() - 1].toString();

    cout << "El alumno ha sido ingresado correctamente" << endl;
}

void BuscarPorCurso()
{
    int codigoCurso;

    vector<Curso> cursos{};
    LeerCursos(cursos);

    cout << "Ingrese el Codigo del curso:" << endl;
    cin >> codigoCurso;
    while (!Curso::existeCurso(cursos, codigoCurso) || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Solo numeros son permitidos" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> codigoCurso;
        }
        else
        {
            cout << "No existe el Codigo del curso ingresado" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> codigoCurso;
        }
    }

    Curso curso = Curso::obtenerCurso(cursos, codigoCurso);
    cout << "Codigo: " << curso.getCodigo() << endl;
    cout << "Nombre: " << curso.getNombre() << endl;
    cout << "Creditos: " << curso.getCreditos() << endl;
	
}

void BuscarPorEstudiante()
{
    string carne;

    vector<Estudiante> estudiantes{};
    LeerEstudiantes(estudiantes);

    cout << "Ingrese el Carne del estudiante:" << endl;
    cin >> carne;
    while (!Estudiante::existeEstudiante(estudiantes, carne))
    {
        cout << "No existe el carne del estudiante ingresado" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> carne;   
    }

    Estudiante estudiante = Estudiante::obtenerEstudiante(estudiantes, carne);
    cout << "Carne: " << estudiante.getCarne() << endl;
    cout << "Nombre: " << estudiante.getNombre() << endl;
    cout << "Codigo de curso: " << estudiante.getCodigoCurso() << endl;
    cout << "Parcial 1: " << estudiante.getExamenesParciales()[0] << endl;
    cout << "Parcial 2: " << estudiante.getExamenesParciales()[1] << endl;
    cout << "Tareas: " << estudiante.getTareas() << endl;
    cout << "Examen final: " << estudiante.getExamenFinal() << endl;
	if(estudiante.getExamenRecuperacion() > 0)
	{
        cout << "Examen recuperacion: " << estudiante.getExamenRecuperacion() << endl;
	}

}

void BuscarPorCatedratico()
{
    int codigoCatedratico;

    vector<Catedratico> catedraticos{};
    LeerCatedraticos(catedraticos);

    cout << "Ingrese el Codigo del catedratico:" << endl;
    cin >> codigoCatedratico;
    while (!Catedratico::existeCatedratico(catedraticos, codigoCatedratico) || cin.fail())
    {
        if (cin.fail())
        {
            cout << "Solo numeros son permitidos" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> codigoCatedratico;
        }
        else
        {
            cout << "No existe el Codigo del catedratico ingresado" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> codigoCatedratico;
        }
    }

    Catedratico catedratico = Catedratico::obtenerCatedratico(catedraticos, codigoCatedratico);
    cout << "Codigo: " << catedratico.getCodigo() << endl;
    cout << "Nombre: " << catedratico.getNombre() << endl;
    cout << "Apellido: " << catedratico.getApellido() << endl;
    cout << "DPI: " << catedratico.getDpi() << endl;
    cout << "Telefono: " << catedratico.getTelefono() << endl;
    cout << "Direccion: " << catedratico.getDireccion() << endl;

}

void EstudiantesAprobados()
{
    vector<Estudiante> estudiantes{};
    LeerEstudiantes(estudiantes);
    cout << "Estudiantes Aprobados" << endl;
    for (Estudiante estudiante : estudiantes)
    {
	    if(estudiante.getNotaTotal() > 60)
	    {
            cout << "Carne: " << estudiante.getCarne() << ", Nombre: " << estudiante.getNombre() << ", Nota: " << estudiante.getNotaTotal() << endl;
	    }
    }
}

void EstudiantesReprobados()
{
    vector<Estudiante> estudiantes{};
    LeerEstudiantes(estudiantes);
    cout << "Estudiantes Reprobados" << endl;
    for (Estudiante estudiante : estudiantes)
    {
        if (estudiante.getNotaTotal() < 61)
        {
            cout << "Carne: " << estudiante.getCarne() << ", Nombre: " << estudiante.getNombre() << ", Nota: " << estudiante.getNotaTotal() << endl;
        }
    }
}

void IngresoDatos() {
    int opcion;

    do {
        system("cls");        // Para limpiar la pantalla

        // Texto del menú que se verá cada vez

        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Cursos" << endl;
        cout << "2. Catedraticos" << endl;
        cout << "3. Estudiantes" << endl;
        cout << "4. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1  
            system("cls");        // Para limpiar la pantalla
            InsertarCurso();
            system("pause>nul"); // Pausa
            break;

        case 2:
            // Lista de instrucciones de la opción 2  
            system("cls");        // Para limpiar la pantalla
            InsertarCatedratico();
            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3 
            system("cls");        // Para limpiar la pantalla
            InsertarEstudiante();
            system("pause>nul"); // Pausa
            break;
        default: ;
        }
    } while (opcion != 4);            // En vez de 5 pones el número de la opción de SALIDA
}

void Reportes() {
    int opcion;

    do {
        system("cls");        // Para limpiar la pantalla

        // Texto del menú que se verá cada vez

        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Por Curso" << endl;
        cout << "2. Por Estudiante" << endl;
        cout << "3. Por Catedratico" << endl;
        cout << "4. Estudiantes que aprobaron los cursos" << endl;
        cout << "5. Estudiantes que reprobaron los cursos" << endl;
        cout << "6. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1 
            system("cls");        // Para limpiar la pantalla
            BuscarPorCurso();
            system("pause>nul"); // Pausa
            break;

        case 2:
            // Lista de instrucciones de la opción 2  
            system("cls");        // Para limpiar la pantalla
            BuscarPorEstudiante();
            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3  
            system("cls");        // Para limpiar la pantalla
            BuscarPorCatedratico();
            system("pause>nul"); // Pausa
            break;
        case 4:
            // Lista de instrucciones de la opción 4 
            system("cls");        // Para limpiar la pantalla
            EstudiantesAprobados();
            system("pause>nul"); // Pausa
            break;
        case 5:
            // Lista de instrucciones de la opción 5 
            system("cls");        // Para limpiar la pantalla
            EstudiantesReprobados();
            system("pause>nul"); // Pausa
            break;
        default:;
        }
    } while (opcion != 6);            // En vez de 5 pones el número de la opción de SALIDA
}

int main()
{
    int opcion;

    do {
        system("cls");        // Para limpiar la pantalla

        // Texto del menú que se verá cada vez

        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Ingreso de Datos" << endl;
        cout << "2. Reportes" << endl;
        cout << "3. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1                
            IngresoDatos();
            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            Reportes();
            break;
        }
    } while (opcion != 3);            // En vez de 5 pones el número de la opción de SALIDA        
    return 0;
}

