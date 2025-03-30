#include "campeonato.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

campeonato::campeonato() {
    equipos.resize(NUMERO_EQUIPOS);
    resultados = vector<vector<vector<int>>>(NUMERO_EQUIPOS, vector<vector<int>>(NUMERO_EQUIPOS, vector<int>(2, 0)));

    // Inicializar matriz de resultados en el constructor
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < NUMERO_EQUIPOS; j++) {
            resultados[i][j][0] = 0;
            resultados[i][j][1] = 0;
        }
    }
}

// Gets
int campeonato::getNumeroEquipos() const {
    return NUMERO_EQUIPOS;
}

equipo campeonato::getEquipo(int indice) const {
    if (indice >= 0 && indice < NUMERO_EQUIPOS) {
        return equipos[indice];
    }
    return equipo(); // Retornar equipo vacío si el índice está fuera de rango
}

int campeonato::getResultado(int equipoLocal, int equipoVisitante, int tipo) const {
    if (equipoLocal >= 0 && equipoLocal < NUMERO_EQUIPOS &&
        equipoVisitante >= 0 && equipoVisitante < NUMERO_EQUIPOS &&
        (tipo == 0 || tipo == 1)) {
        return resultados[equipoLocal][equipoVisitante][tipo];
    }
    return -1; // Error
}

// Generar número aleatorio
int campeonato::generarResultadoAleatorio() const {
    return MINIMO_GOLES + rand() / (RAND_MAX / (MAXIMO_GOLES - MINIMO_GOLES + 1) + 1);
}

// Ingresar equipos
void campeonato::ingresarEquipos() {
    cout << "Ingrese los nombres de los " << NUMERO_EQUIPOS << " equipos:" << endl;

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        string nombre;
        cout << "Equipo " << (i + 1) << ": ";
        cin >> nombre;
        equipos[i] = equipo(nombre);
    }
}

// Generar partidos
void campeonato::generarPartidos() {
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < NUMERO_EQUIPOS; j++) {
            if (i != j) {
                int golesIda = generarResultadoAleatorio();
                int golesVuelta = generarResultadoAleatorio();

                resultados[i][j][0] = golesIda;
                resultados[i][j][1] = golesVuelta;

                resultados[j][i][0] = golesVuelta;
                resultados[j][i][1] = golesIda;
            }
        }
    }
}

// Calcular estadísticas
void campeonato::calcularEstadisticas() {
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        equipos[i].resetearEstadisticas();
    }

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = 0; j < NUMERO_EQUIPOS; j++) {
            if (i != j) {
                equipos[i].registrarPartido(resultados[i][j][0], resultados[i][j][1]);
            }
        }
    }
}

// Método para imprimir resultados de partidos
void campeonato::imprimirResultadosPartidos() const {
    cout << "\nTabla de RESULTADOS de los Partidos:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Equipo"
              << "| " << setw(12) << left << "Equipo"
              << "| " << setw(9) << left << "Resultado" << "|" << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = i + 1; j < NUMERO_EQUIPOS; j++) {
            cout << "| " << setw(12) << left << equipos[i].getNombre()
                     << "| " << setw(12) << left << equipos[j].getNombre()
                     << "| " << setw(2) << resultados[i][j][0] << "-"
                     << setw(6) << left << resultados[i][j][1] << "|" << endl;
        }
    }
    cout << "--------------------------------------------------" << endl;
}

// Método para imprimir tabla de posiciones
void campeonato::imprimirTabla() const {
    cout << "Tabla de Posiciones:" << endl;

     // Imprimir línea superior
    cout << "+--------";
    for (int i = 0; i < 7; i++) {
    cout << "+---------";
    }
    cout << "+\n";

    // Imprimir encabezados
    cout << setw(8) << left << "Equipo";
    cout << setw(9) << left << "PJ";
    cout << setw(9) << left << "PG";
    cout << setw(9) << left << "PE";
    cout << setw(9) << "PP";
    cout << setw(9) << "GF";
    cout << setw(9) << "GC";
    cout << setw(9) << "Pts tot" << endl;

    // Imprimir línea
    cout << "+--------";
    for (int i = 0; i < 7; i++) {
    cout << "+---------";
    }
    cout << "+\n";

    int maxPuntos = -1, minPuntos = 999;
    int campeon = 0, ultimo = 0;

    // Imprimir datos de cada equipo
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        cout << "!" << setw(9) << equipos[i].getNombre();
        cout << setw(9) << equipos[i].getPartidosJugados();
        cout << setw(9) << equipos[i].getPartidosGanados();
        cout << setw(9) << equipos[i].getPartidosEmpatados();
        cout << setw(9) << equipos[i].getPartidosPerdidos();
        cout << setw(9) << equipos[i].getGolesFavor();
        cout << setw(9) << equipos[i].getGolesContra();
        cout << setw(9) << equipos[i].getPuntosTotales();
        cout << endl;

        // Imprimir línea
        cout << "+--------";
        for (int i = 0; i < 7; i++) {
            cout << "+---------";
        }
        cout << "+\n";

        // Actualizar campeón y último lugar
        if (equipos[i].getPuntosTotales() > maxPuntos) {
            maxPuntos = equipos[i].getPuntosTotales();
            campeon = i;
        }
        if (equipos[i].getPuntosTotales() < minPuntos) {
            minPuntos = equipos[i].getPuntosTotales();
            ultimo = i;
        }
    }

    cout << "Campeón: " << equipos[campeon].getNombre() << " con " << maxPuntos << " puntos" << endl;
    cout << "Desciende: " << equipos[ultimo].getNombre() << " con " << minPuntos << " puntos" << endl;
}

// Inicio del campeonato
void campeonato::iniciarCampeonato() {
    // Limpiar estadísticas
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        equipos[i].resetearEstadisticas();
    }

    // Generar resultados de partidos
    generarPartidos();

    // Calcular estadísticas
    calcularEstadisticas();

    // Mostrar resultados
    imprimirResultadosPartidos();
    cout << endl;

    // Mostrar tabla de posiciones
    imprimirTabla();
}

// Destructor
campeonato::~campeonato() {
}
