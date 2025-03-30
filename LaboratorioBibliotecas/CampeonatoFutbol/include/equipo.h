#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>

using namespace std;

class equipo
{
    public:
        equipo();
        virtual ~equipo();
        equipo (const string nombre);

        //Metodos get
        string getNombre() const;
        int getPartidosJugados() const;
        int getPartidosGanados() const;
        int getPartidosEmpatados() const;
        int getPartidosPerdidos() const;
        int getGolesFavor() const;
        int getGolesContra() const;
        int getPuntosTotales() const;

        //Metodos set
        void setNombre(const string nombre);

        //Actualizar estadisticas
        void registrarPartido(int golesFavor, int golesContra);

        //resetear estadísticas
        void resetearEstadisticas();

    protected:

    private:
        string nombre;
        int partidosJugados;
        int partidosGanados;
        int partidosEmpatados;
        int partidosPerdidos;
        int golesFavor;
        int golesContra;
        int puntosTotales;

};

#endif // EQUIPO_H
