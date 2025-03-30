//Implementación de la clase juego
//Implementa la lógica del juego
//Programador: daguilae
//Documentación Grupo 2 (Dulce Reyes)
//Marzo 2025
//Curso de Programaciòn I
#include "Juego.h"
#include <fstream>
#include <unistd.h>

// Genera un número aleatorio dentro de un rango dado
int Juego::aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

// Retorna una fila aleatoria dentro de los límites del tablero
int Juego::filaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

// Retorna una columna aleatoria dentro de los límites del tablero
int Juego::columnaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

// Constructor de la clase Juego
// Recibe un objeto Tablero y la cantidad de minas a colocar
Juego::Juego(Tablero tablero, int cantidadMinas)
{
    this->tablero = tablero;
    this->cantidadMinas = cantidadMinas;
    this->colocarMinasAleatoriamente(); // Llama a la función para distribuir minas
}

// Coloca minas de forma aleatoria en el tablero, asegurando que no se sobrepase el límite
void Juego::colocarMinasAleatoriamente()
{
    int x, y, minasColocadas = 0;

    while (minasColocadas < this->cantidadMinas)
    {
        x = this->columnaAleatoria();
        y = this->filaAleatoria();
        if (this->tablero.colocarMina(x, y)) // Solo incrementa el conteo si la mina fue colocada con éxito
        {
            minasColocadas++;
        }
    }
}

// Solicita al usuario ingresar la fila en la que desea jugar
int Juego::solicitarFilaUsuario()
{
    int fila = 0;
    cout << "Ingresa la FILA en la que desea jugar: ";
    cin >> fila;
    return fila - 1; // Se ajusta el valor para que coincida con los índices del array
}

// Solicita al usuario ingresar la columna en la que desea jugar
int Juego::solicitarColumnaUsuario()
{
    int columna = 0;
    cout << "Ingresa la COLUMNA en la que desea jugar: ";
    cin >> columna;
    return columna - 1; // Se ajusta el valor para que coincida con los índices del array
}

// Verifica si el jugador ha ganado
bool Juego::jugadorGana()
{
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
    return conteo == 0; // Si no quedan celdas seguras por descubrir, el jugador gana
}

// Inicia el ciclo principal del juego
void Juego::iniciar()
{
    int fila, columna;
    while (true)
    {
        this->tablero.imprimir(); // Muestra el tablero actual
        fila = this->solicitarFilaUsuario(); // Pide al usuario una fila
        columna = this->solicitarColumnaUsuario(); // Pide al usuario una columna

        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);
        if (!respuestaAUsuario) // Si el usuario pisa una mina, pierde
        {
            cout << "Perdiste el Juego\n";
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }

        if (this->jugadorGana()) // Si descubre todas las celdas seguras, gana
        {
            cout << "Ganaste el Juego\n";
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }
    }
}
