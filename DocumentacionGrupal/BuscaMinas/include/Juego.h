//Declaración de la clase juego para el buscaminas
//Define la estructura de la clase Juego para implementar Buscaminas.
//Programador: daguilae
//Documentación Grupo 2 (Dulce Reyes)
//Marzo 2025
//Curso de Programaciòn I
#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"

// Clase que maneja la lógica del juego de Buscaminas.
class Juego
{
private:
    Tablero tablero;  // Representa el tablero del juego.
    int cantidadMinas; // Número total de minas en el tablero.

    // Genera un número aleatorio dentro de un rango determinado.
    // param minimo Valor mínimo del rango.
    // param maximo Valor máximo del rango.
    // return Número aleatorio dentro del rango especificado.
    int aleatorio_en_rango(int minimo, int maximo);

    // Obtiene una fila aleatoria dentro del tablero.
    // return Índice de la fila seleccionada aleatoriamente.
    int filaAleatoria();

    // Obtiene una columna aleatoria dentro del tablero.
    // return Índice de la columna seleccionada aleatoriamente.
    int columnaAleatoria();

public:
    // Constructor de la clase Juego.
    // param tablero Tablero en el que se jugará.
    // param cantidadMinas Número de minas a colocar en el tablero.
    Juego(Tablero tablero, int cantidadMinas);

    // Coloca minas en posiciones aleatorias dentro del tablero.
    void colocarMinasAleatoriamente();

    // Solicita al usuario una fila en la que desea jugar.
    // return Índice de la fila ingresada por el usuario.
    int solicitarFilaUsuario();

    // Solicita al usuario una columna en la que desea jugar.
    // return Índice de la columna ingresada por el usuario.
    int solicitarColumnaUsuario();

    // Verifica si el jugador ha descubierto todas las celdas sin minas, determinando si gana.
    // return true si el jugador gana, false si aún no lo ha logrado.
    bool jugadorGana();

    // Inicia el ciclo del juego, permitiendo al usuario interactuar con el tablero.
    void iniciar();

    // Dibuja la portada del juego a partir de un archivo de texto.
    // param nombreArchivo Nombre del archivo que contiene la portada.
    void dibujarPortada(string nombreArchivo);
};

#endif // JUEGO_H
