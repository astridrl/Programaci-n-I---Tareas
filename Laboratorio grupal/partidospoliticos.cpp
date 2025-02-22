#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Declaracion de constantes
#define NOMBRES_CANDIDATOS 5
#define RONDAS 5
#define MAX_VOTOS 50
#define MIN_VOTOS 0
#define MAXIMA_LONGITUD_CADENA 100

//variables globales
char candidatos[NOMBRES_CANDIDATOS][MAXIMA_LONGITUD_CADENA];
int resultados[NOMBRES_CANDIDATOS][RONDAS];

//funciones
void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void ingresarPartidos();
void llenarResultados();
void imprimirLinea();
void imprimirTabla();
void calcularEstadisticas();

int main() {
    srand(getpid());
    llamaCiclo();
    return 0;
}

void llamaCiclo() {
    char opcion;
    bool repetir = true;
    do {
        system("cls");
        cout << "\n*** Sistema de Elección de Candidatos ***\n\n";
        ingresarPartidos();
        llenarResultados();
        imprimirTabla();
        calcularEstadisticas();

        do {
            cout << "\n¿Desea generar otra elección (s/n)? ";
            cin >> opcion;
        } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

        if (opcion == 'n' || opcion == 'N') {
            repetir = false;
        }
    } while (repetir);
}

int busquedaAleatorios(int minimo, int maximo) { //numeros aleatorios en un rango especifico
    return minimo + rand() % (maximo - minimo + 1);
}

void ingresarPartidos() {
    cout << "Ingrese los nombres de los 5 candidatos:\n";
    for (int i = 0; i < NOMBRES_CANDIDATOS; i++) {
        cout << "Candidato " << i + 1 << ": "; //cantidato 1 , cantidato 2 , etc
        cin >> candidatos[i];
    }
}

//simula la votación distribuyendo los 50 votos aleatoriamente entre los candidatos para cada ronda
void llenarResultados() {
    for (int j = 0; j < RONDAS; j++) {
        int votosRestantes = MAX_VOTOS;

        // Reiniciar votos para esta ronda
        for (int i = 0; i < NOMBRES_CANDIDATOS; i++) {
            resultados[i][j] = 0;
        }

        // Distribuir los 50 votos entre los candidatos
        while (votosRestantes > 0) {
            int candidato = busquedaAleatorios(0, NOMBRES_CANDIDATOS - 1);
            resultados[candidato][j]++;
            votosRestantes--;
        }
    }
}

void imprimirLinea() {
    cout << "+---------------";
    for(int i = 0; i < RONDAS; i++) {
        cout << "+---------";
    }
    cout << "+\n";
}

void imprimirTabla() {
    cout << "\nRESULTADOS DE LA ELECCIÓN\n";
    imprimirLinea();
    cout << "| Candidato      ";
    for (int i = 0; i < RONDAS; i++) {
        cout << "| Ronda " << i + 1 << " ";
    }
    cout << "|\n";
    imprimirLinea();

    for (int i = 0; i < NOMBRES_CANDIDATOS; i++) {
        cout << "| " << left << setw(14) << candidatos[i];
        for (int j = 0; j < RONDAS; j++) {
            cout << "| " << setw(7) << resultados[i][j] << " ";
        }
        cout << "|\n";
    }
    imprimirLinea();
}

void calcularEstadisticas() {
    int votosTotales[NOMBRES_CANDIDATOS] = {0};
    int votosMaximos = 0, votosMinimo = MAX_VOTOS * RONDAS;
    int ganador = 0, perdedor = 0;

    for (int i = 0; i < NOMBRES_CANDIDATOS; i++) {
        for (int j = 0; j < RONDAS; j++) {
            votosTotales[i] += resultados[i][j];
        }
        if (votosTotales[i] > votosMaximos) {
            votosMaximos = votosTotales[i];
            ganador = i;
        }
        if (votosTotales[i] < votosMinimo) {
            votosMinimo = votosTotales[i];
            perdedor = i;
        }
    }

    cout << "\nRESULTADOS FINALES:\n";
    cout << "====================================\n";
    cout << "GANADOR: " << candidatos[ganador] << " con " << votosMaximos << " votos totales\n";
    cout << "ÚLTIMO LUGAR: " << candidatos[perdedor] << " con " << votosMinimo << " votos totales\n";
    cout << "====================================\n";
}
