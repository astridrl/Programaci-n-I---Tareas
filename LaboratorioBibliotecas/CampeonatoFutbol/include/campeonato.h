#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include "equipo.h"
#include <vector>

using namespace std;

class campeonato
{
    public:
        campeonato();
        virtual ~campeonato();

    // Métodos
    void ingresarEquipos();
    void generarPartidos();
    void calcularEstadisticas();
    void imprimirResultadosPartidos() const;
    void imprimirTabla() const;
    void iniciarCampeonato();

    //Metodos get
    int getNumeroEquipos() const;
    equipo getEquipo(int indice) const;
    int getResultado(int equipoLocal, int equipoVisitante, int tipo) const;


    protected:

    private:
        const int NUMERO_EQUIPOS = 6;
        const int MAXIMO_GOLES = 10;
        const int MINIMO_GOLES = 0;

        vector<equipo> equipos;
        vector<vector<vector<int>>> resultados; // [ida][vuelta]
        // Métodos
        int generarResultadoAleatorio() const;
};

#endif // CAMPEONATO_H
