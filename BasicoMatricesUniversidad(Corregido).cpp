#include <iostream>
#include <iomanip>
using namespace std;

// Declaración de Constantes
#define NUMERO_ALUMNOS 5
#define MAXIMA_NOTA 20.0

// Estructura para almacenar las notas de un alumno
struct Alumno {
    float parcialUno;
    float parcialDos;
    float actividades;
    float examenFinal;
    float promedio;
};

// Prototipos de función
void ingresarNotas(Alumno alumnos[], int numAlumnos);
void calcularPromedios(Alumno alumnos[], int numAlumnos);
void mostrarResultados(const Alumno alumnos[], int numAlumnos);

int main() {
    Alumno alumnos[NUMERO_ALUMNOS];
    char opcion;

    do {
        system("cls");
        cout << "* NOTAS DE ALUMNOS *\n\n";

        ingresarNotas(alumnos, NUMERO_ALUMNOS);
        calcularPromedios(alumnos, NUMERO_ALUMNOS);
        mostrarResultados(alumnos, NUMERO_ALUMNOS);

        cout << "\nDesea ingresar nuevamente notas (s/n)? ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return 0;
}

void ingresarNotas(Alumno alumnos[], int numAlumnos) {
    for(int i = 0; i < numAlumnos; i++) {
        cout << "\nIngrese las notas del alumno " << (i + 1) << ":\n";

        cout << "Ingrese la nota del primer parcial: ";
        cin >> alumnos[i].parcialUno;

        cout << "Ingrese la nota del segundo parcial: ";
        cin >> alumnos[i].parcialDos;

        cout << "Ingrese la nota de las actividades: ";
        cin >> alumnos[i].actividades;

        cout << "Ingrese la nota del examen final: ";
        cin >> alumnos[i].examenFinal;
    }
}

void calcularPromedios(Alumno alumnos[], int numAlumnos) {
    for(int i = 0; i < numAlumnos; i++) {
        alumnos[i].promedio = (alumnos[i].parcialUno * 0.25 +
                              alumnos[i].parcialDos * 0.25 +
                              alumnos[i].actividades * 0.20 +
                              alumnos[i].examenFinal * 0.30);
    }
}

void mostrarResultados(const Alumno alumnos[], int numAlumnos) {
    cout << "\nRESULTADOS:\n";
    cout << setfill('-') << setw(60) << "-" << endl;
    cout << setfill(' ');
    cout << setw(10) << "Alumno"
         << setw(10) << "Parcial 1"
         << setw(10) << "Parcial 2"
         << setw(10) << "Activ."
         << setw(10) << "Final"
         << setw(10) << "Promedio" << endl;
    cout << setfill('-') << setw(60) << "-" << endl;
    cout << setfill(' ');

    for(int i = 0; i < numAlumnos; i++) {
        cout << setw(10) << i + 1
             << setw(10) << alumnos[i].parcialUno
             << setw(10) << alumnos[i].parcialDos
             << setw(10) << alumnos[i].actividades
             << setw(10) << alumnos[i].examenFinal
             << setw(10) << fixed << setprecision(2) << alumnos[i].promedio << endl;
    }
}





