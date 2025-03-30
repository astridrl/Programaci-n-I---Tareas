#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaraci�n de Constantes
#define NUMERO_EQUIPOS 6
#define MAXIMO_GOLES 10
#define MINIMO_GOLES 0
#define MAXIMA_LONGITUD_CADENA 100

//Variables globales
char equipos[NUMERO_EQUIPOS][MAXIMA_LONGITUD_CADENA]; //almacenar nombres de los equipos
int resultados[NUMERO_EQUIPOS][NUMERO_EQUIPOS][2]; // [ida][vuelta][goles] //almacena goles de cada partido ida y vuelta
//almacenar estadisticas
int estadisticas[NUMERO_EQUIPOS][7]; // partidos [partidos jugados,ganados,empatados,perdidos,golesFavor,golesContra,puntosTotales]

//Declaraci�n de Prototipos de Funci�n
void llamaCiclo(); //Funci�n que controla el Ciclo comparativo de datos por todas las facultades
int busquedaAleatorios(int minimo, int maximo);  //Funci�n que permite obtener valores aleatorios en las notas de cada alumno
void llenarResultados();
void calcularEstadisticas();
void imprimirLinea();
void imprimirTabla();
void ingresarEquipos();
void imprimirResultadosPartidos(); // imprimir tabla de resultados

int main() {
    srand(getpid()); //Proceso preparativo para generaci�n de valores aleatorios
    llamaCiclo();
    return 0;
}

void llamaCiclo() {
    char opcion; //almacenar las respuestas del usuario
    bool repetir = true;

    do {
        system("cls");
        cout << "* Campeonato de Futbol *" << endl << endl;

        // Reiniciar matriz de estad�sticas
        for(int i = 0; i < NUMERO_EQUIPOS; i++) {
            for(int j = 0; j < 7; j++) {
                estadisticas[i][j] = 0;
            }
        }
        //llamadas a las funciones
        ingresarEquipos();
        llenarResultados();
        calcularEstadisticas();

         // Imprimir tabla de resultados de partidos
        imprimirResultadosPartidos();
        cout << endl;

        // Imprimir tabla de posiciones
        imprimirTabla();


        cout << "Desea generar otro campeonato (s/n)? ";
        cin >> opcion;
        if (opcion == 'n') {
            repetir = false;
        }
    } while (repetir);
}
//n�mero aleatorio
int busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
//solicitar los nombres de los equipos
void ingresarEquipos() {
    cout << "Ingrese los nombres de los " << NUMERO_EQUIPOS << " equipos:" << endl;
    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        cout << "Equipo " << (i + 1) << ": "; // equipo 1, equipo 2
        cin >> equipos[i]; // Almacena cada nombre en la matriz equipos
    }
}

void llenarResultados() {
    for(int i = 0; i < NUMERO_EQUIPOS; i++) { //primer equipo
        for(int j = 0; j < NUMERO_EQUIPOS; j++) { //equipo contrincante
              if(i != j) {  // Evita que un equipo juegue contra s� mismo
                //generar los goles aleatorios para los goles de ida y vuelta
                int golesIda = busquedaAleatorios(MINIMO_GOLES, MAXIMO_GOLES);
                int golesVuelta = busquedaAleatorios(MINIMO_GOLES, MAXIMO_GOLES);

                // Partido de ida
                resultados[i][j][0] = golesIda; // equipo i
                resultados[i][j][1] = golesVuelta; //goles que recibe el equipo j

                // Partido de vuelta
                resultados[j][i][0] = golesVuelta; // el equipo i
                resultados[j][i][1] = golesIda; //el equipo j
            }
        }
    }
}
// El resultado del partido de ida se guarda como resultados[i][j][0] (goles del equipo i como local y goles del equipo j como visitante),
//y el resultado del partido de vuelta se guarda en resultados[j][i][0] (goles de j como local y goles de i como visitante).

void calcularEstadisticas() {
    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        for(int j = 0; j < NUMERO_EQUIPOS; j++) {
            if(i != j) { //verificar que no sea mismo equipo
                // partidos jugados
                estadisticas[i][0]++;

                // Actualizar goles
                estadisticas[i][4] += resultados[i][j][0]; // suma Goles a favor del equipo i con los goles obtenidos del partido contra el equipo j
                estadisticas[i][5] += resultados[i][j][1]; // Goles en contra
                // // El [4] y [5] representan las columnas de la matriz estadisticas que almacenan:

                // Actualizar resultados
                if(resultados[i][j][0] > resultados[i][j][1]) { //si el equipo i gan� el partido
                    estadisticas[i][1]++; // suma una victoria
                    estadisticas[i][6] += 3; // Suma 3 puntos
                }
                else if(resultados[i][j][0] < resultados[i][j][1]) { //perdi�
                    estadisticas[i][3]++; // Suma una derrota
                }
                else {
                    estadisticas[i][2]++;// Suma un empate
                    estadisticas[i][6] += 1; // Suma 1 punto
                }
            }
        }
    }
}

void imprimirLinea() {
    cout << "+--------";
    for(int i = 0; i < 7; i++) {
        cout << "+---------";
    }
    cout << "+\n";
}

void imprimirResultadosPartidos() {
    cout << "\nTabla de RESULTADOS de los Partidos:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Equipo"
         << "| " << setw(12) << left << "Equipo"
         << "| " << setw(9) << left << "Resultado" << "|" << endl;
    cout << "--------------------------------------------------" << endl;

    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        for(int j = i + 1; j < NUMERO_EQUIPOS; j++) {
            cout << "| " << setw(12) << left << equipos[i]
                 << "| " << setw(12) << left << equipos[j]
                 << "| " << setw(2) << resultados[i][j][0] << "-"
                 << setw(6) << left << resultados[i][j][1] << "|" << endl;
        }
    }
    cout << "--------------------------------------------------" << endl;
}

void imprimirTabla() {
    cout << "Tabla de Posiciones:" << endl;
    imprimirLinea();
    cout << setw(8) << left << "Equipo";
    cout << setw(9) << left << "PJ";
    cout << setw(9) << left << "PG";
    cout << setw(9) << left << "PE";
    cout << setw(9) << "PP";
    cout << setw(9) << "GF";
    cout << setw(9) << "GC";
    cout << setw(9) << "Pts tot" << endl;
    imprimirLinea();

    int maxPuntos = -1, minPuntos = 999;
    int campeon = 0, ultimo = 0;

    for(int i = 0; i < NUMERO_EQUIPOS; i++) {
        cout << "!" << setw(9) << equipos[i];
        for(int j = 0; j < 7; j++) {
            cout << setw(9) << estadisticas[i][j];
        }
        cout << endl;
        imprimirLinea();

        if(estadisticas[i][6] > maxPuntos) {
            maxPuntos = estadisticas[i][6];
            campeon = i;
        }
        if(estadisticas[i][6] < minPuntos) {
            minPuntos = estadisticas[i][6];
            ultimo = i;
        }
    }

    cout << "Campe�n: " << equipos[campeon] << " con " << maxPuntos << " puntos" << endl;
    cout << "Desciende: " << equipos[ultimo] << " con " << minPuntos << " puntos" << endl;
}
