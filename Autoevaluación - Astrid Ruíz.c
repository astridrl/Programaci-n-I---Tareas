#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaración de Constantes
#define NOTAS_ALUMNOS 5
#define MAXIMO_GOLES 10
#define MINIMO_GOLES 0
#define MAXIMA_LONGITUD_CADENA 100

//Variables globales
char notas[NOTAS_ALUMNOS][MAXIMA_LONGITUD_CADENA]; //almacenar nombres de los equipos
int estadisticas[NOTAS_ALUMNOS][4]; // las estadisticas de las notas

//Declaración de Prototipos de Función
void llamaCiclo(); //Funciòn que controla el Ciclo comparativo de datos por todas las facultades
void llenarResultados();
void calcularEstadisticas();
void ingresarNotas();
void imprimirResultadosPartidos(); //

int main() {
    llamaCiclo();
    return 0;
}

void llamaCiclo() {
    char opcion; //almacenar las respuestas del usuario
    bool repetir = true;

    do {
        system("cls");
        cout << "* NOTAS DE ALUMNOS *" << endl << endl;

        }
        //llamadas a las funciones
        ingresarNotas();
        llenarResultados();
        calcularEstadisticas();

        cout << "Desea ingresar nuevamente notas (s/n)? ";
        cin >> opcion;
        if (opcion == 'n') {
            repetir = false;
        }
    } while (repetir);
}

//solicitar las notas
void ingresarEquipos() {
    cout << "Ingrese las notas del primer alumnos " << NOTAS_ALUMNOS << endl;
    for(int i = 0; i < NOTAS_ALUMNOS; i++) {
        cout << Alumno " << (i + 1) << ": "; // alumno 1, alumno 2
        cin >> notas[i]; // Almacena cada nombre en la matriz equipos
    }
}




