#include "equipo.h"


equipo::equipo() {
    nombre = "";
    resetearEstadisticas();
}

equipo::equipo(const string nombre) {
    this->nombre = nombre;
    resetearEstadisticas();
}

equipo::~equipo() {}


// Metodos get
string equipo::getNombre() const {
    return nombre;
}

int equipo::getPartidosJugados() const {
    return partidosJugados;
}

int equipo::getPartidosGanados() const {
    return partidosGanados;
}

int equipo::getPartidosEmpatados() const {
    return partidosEmpatados;
}

int equipo::getPartidosPerdidos() const {
    return partidosPerdidos;
}

int equipo::getGolesFavor() const {
    return golesFavor;
}

int equipo::getGolesContra() const {
    return golesContra;
}

int equipo::getPuntosTotales() const {
    return puntosTotales;
}

// Set
void equipo::setNombre(const string nombre) {
    this->nombre = nombre;
}

// Método para registrar un partido
void equipo::registrarPartido(int golesFavor, int golesContra) {
    //Incrementar partidos
    partidosJugados++;

    //Actualizar goles
    this->golesFavor += golesFavor;
    this->golesContra += golesContra;

    //Actualizar resultado y puntos
    if (golesFavor > golesContra) {
        // Victoria
        partidosGanados++;
        puntosTotales += 3;
    } else if (golesFavor < golesContra) {
        // Derrota
        partidosPerdidos++;
    } else {
        // Empate
        partidosEmpatados++;
        puntosTotales += 1;
    }
}


// Método para resetear estadísticas
void equipo::resetearEstadisticas() {
    partidosJugados = 0;
    partidosGanados = 0;
    partidosEmpatados = 0;
    partidosPerdidos = 0;
    golesFavor = 0;
    golesContra = 0;
    puntosTotales = 0;
}
