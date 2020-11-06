
#include "ProyectoFinal.h"
#include "Estudiante.h"

using namespace std;

int CONTADOR = 0;

bool isEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void LeerEstudiantes(vector<Estudiante>& result)
{
    // Object to write in file
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

            CONTADOR++;
        }
    }
    else
    {
        cout << "Error al leer archivo" << endl;
    }
}

void InsertarEstudiante()
{
    vector<Estudiante> estudiantes{};

    LeerEstudiantes(estudiantes);

	if(estudiantes.size() >= Estudiante::MAX_SIZE)
	{
        cout << "Se ha alcanzado el maximo de alumnos: " << Estudiante::MAX_SIZE << endl;
        return;
	}

    string carne, nombre;
    int codigoCurso;
	float examenParcial1, examenParcial2, tareas, examenFinal, examenRecuperacion;

    cout << "Ingrese el carne del alumno:" << endl;
    cin >> carne;
	
    cout << "Ingrese el nombre del alumno:" << endl;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el Codigo del curso del alumno:" << endl;
    cin >> codigoCurso;
    while (std::cin.fail())
    {
        std::cout << "Invalid Entry\nEnter 0-9" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> codigoCurso;
    }

    cout << "Ingrese el 1er Examen parcial del alumno:" << endl;
    cin >> examenParcial1;
    while (std::cin.fail())
    {
        std::cout << "Invalid Entry\nEnter 0-9" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> examenParcial1;
    }

    cout << "Ingrese el 2do Examen parcial del alumno:" << endl;
    cin >> examenParcial2;

    cout << "Ingrese el punteo de tareas del alumno:" << endl;
    cin >> tareas;

    cout << "Ingrese el Examen final del alumno:" << endl;
    cin >> examenFinal;

    cout << "Ingrese el Examen de recuperacion del alumno:" << endl;
    cin >> examenRecuperacion;

    estudiantes.emplace_back(Estudiante(carne, nombre, codigoCurso, new float[]{ examenParcial1, examenParcial2 }, tareas, examenFinal, examenRecuperacion));
    CONTADOR++;

    ofstream File("Estudiantes.csv", ios::app);
	
    File << estudiantes[CONTADOR -1].toString();
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

            system("pause>nul"); // Pausa
            break;

        case 2:
            // Lista de instrucciones de la opción 2                

            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3               
            InsertarEstudiante();
            system("pause>nul"); // Pausa
            break;
        default: ;
        }
    } while (opcion != 4);            // En vez de 5 pones el número de la opción de SALIDA
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

            system("pause>nul"); // Pausa
            break;
        }
    } while (opcion != 3);            // En vez de 5 pones el número de la opción de SALIDA        
    return 0;
}

