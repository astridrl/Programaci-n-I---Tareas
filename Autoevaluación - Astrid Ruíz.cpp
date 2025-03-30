#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaración de Constantes
#define NUMERO_ALUMNOS 5
#define NOTAS_ALUMNOS 4
#define PARCIAL_UNO 5
#define PARCIAL_DOS 5
#define ACTIVIDADES 5
#define EXAMEN_FINAL 5
#define MAXIMA_LONGITUD_CADENA 100

struct Alumno {
    float parcialUno;
    float parcialDos;
    float actividades;
    float examenFinal;
    float promedio;
};
int parcialUno, parcialDos, actividades, examenFinal;

//Variables globales
char notas[NOTAS_ALUMNOS][MAXIMA_LONGITUD_CADENA][PARCIAL_UNO][PARCIAL_DOS][ACTIVIDADES][EXAMEN_FINAL]; //almacenar nombres de los equipos
int estadisticas[NOTAS_ALUMNOS][PARCIAL_UNO][PARCIAL_DOS][ACTIVIDADES][EXAMEN_FINAL];; // las estadisticas de las notas

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
void ingresarNotas() {
    cout << "Ingrese las notas del primer alumno " << NOTAS_ALUMNOS << endl;
    for(int i = 0; i < NOTAS_ALUMNOS; i++) {
        cout << "Notas " << (i + 1) << ": "; // alumno 1, alumno 2
        cout << "Ingrese la nota del primer parcial";
        cin >> parcialUno;
        cin >> notas[PARCIAL_UNO];
        cout << "Ingrese la nota del segundo parcial";
        cin >> parcialDos;
        cin >> notas[PARCIAL_DOS];
        cout << "Ingrese la nota de las actividades";
        cin >> actividades;
        cin >> notas[ACTIVIDADES];
        cout << "Ingrese la nota del examen final";
        cin >> examenFinal;
        cin >> notas[EXAMEN_FINAL];
    }
        cout << "Ingrese las notas del segundo alumno " << NOTAS_ALUMNOS << endl;
    for(int i = 0; i < NOTAS_ALUMNOS; i++) {
        cout << "Notas " << (i + 1) << ": "; // alumno 1, alumno 2
        cout << "Ingrese la nota del primer parcial";
        cin >> parcialUno;
        cin >> notas[PARCIAL_UNO];
        cout << "Ingrese la nota del segundo parcial";
        cin >> parcialDos;
        cin >> notas[PARCIAL_DOS];
        cout << "Ingrese la nota de las actividades"
        cin >> actividades;
        cin >> notas[ACTIVIDADES];
        cout << "Ingrese la nota del examen final";
        cin >> examenFinal;
        cin >> notas[EXAMEN_FINAL];
    }

        cout << "Ingrese las notas del tercer alumno " << NOTAS_ALUMNOS << endl;
    for(int i = 0; i < NOTAS_ALUMNOS; i++) {
        cout << "Notas " << (i + 1) << ": "; // alumno 1, alumno 2
        cout << "Ingrese la nota del primer parcial";
        cin >> parcialUno;
        cin >> notas[PARCIAL_UNO];
        cout << "Ingrese la nota del segundo parcial";
        cin >> parcialDos;
        cin >> notas[PARCIAL_DOS];
        cout << "Ingrese la nota de las actividades"
        cin >> actividades;
        cin >> notas[ACTIVIDADES];
        cout << "Ingrese la nota del examen final";
        cin >> examenFinal;
        cin >> notas[EXAMEN_FINAL];
    }
        cout << "Ingrese las notas del cuarto alumno " << NOTAS_ALUMNOS << endl;
    for(int i = 0; i < NOTAS_ALUMNOS; i++) {
        cout << "Notas " << (i + 1) << ": "; // alumno 1, alumno 2
        cout << "Ingrese la nota del primer parcial";
        cin >> parcialUno;
        cin >> notas[PARCIAL_UNO];
        cout << "Ingrese la nota del segundo parcial";
        cin >> parcialDos;
        cin >> notas[PARCIAL_DOS];
        cout << "Ingrese la nota de las actividades"
        cin >> actividades;
        cin >> notas[ACTIVIDADES];
        cout << "Ingrese la nota del examen final";
        cin >> examenFinal;
        cin >> notas[EXAMEN_FINAL];
    }
        cout << "Ingrese las notas del quinto alumno " << NOTAS_ALUMNOS << endl;
    for(int i = 0; i < NOTAS_ALUMNOS; i++) {
        cout << "Notas " << (i + 1) << ": "; // alumno 1, alumno 2
        cout << "Ingrese la nota del primer parcial";
        cin >> parcialUno;
        cin >> notas[PARCIAL_UNO];
        cout << "Ingrese la nota del segundo parcial";
        cin >> parcialDos;
        cin >> notas[PARCIAL_DOS];
        cout << "Ingrese la nota de las actividades"
        cin >> actividades;
        cin >> notas[ACTIVIDADES];
        cout << "Ingrese la nota del examen final";
        cin >> examenFinal;
        cin >> notas[EXAMEN_FINAL];
    }

    void estadisticas () {
    estadisticas[NOTAS_ALUMNOS] = notas[PARCIAL_UNO] * 0.20 +
                                  notas[PARCIAL_DOS] * 0.25 +
                                  notas [ACTIVIDADES] * 0.20 +
                                  notas [EXAMEN: FINAL]*0.35);


    cout << "Notas del primer alumno" << estadisticas[NOTAS_ALUMNOS] << endl;
}


