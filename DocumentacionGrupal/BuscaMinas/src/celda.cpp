// Implementación de la clase Celda
//Programador: daguilae
//Documentación Grupo 2 (Dulce Martínez)
//Marzo 2025
//Curso de Programaciòn I
#include "Celda.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Celda::Celda()
{
}
// Constructor con parámetros para inicializar la celda
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;// Inicialmente la mina no está descubierta
}
// Establece la coordenada X
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}
// Establece la coordenada X
int Celda::getCoordenadaX()
{
    return this->coordenadaX;
}
// Establece la coordenada Y de la celda
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
// Devuelve la coordenada
int Celda::getCoordenadaY()
{
    return this->coordenadaY;
}
// Establece si la celda tiene una mina
bool Celda::setMina(bool estadoMina)
{
    if (this->getMina())  // Si ya tiene una mina, no se puede cambiar
    {
        return false;
    }
    else{
        this->mina = estadoMina;
        return true;
    }
}
// Devuelve si la celda tiene una mina o no
bool Celda::getMina()
{
    return this->mina;
}
// Establece si la mina ha sido descubierta
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;
}
// Devuelve si la mina ha sido descubierta o no
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;
}
// Imprime la información de la celda en consola
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n"; //Muestra coordenadas y el estado de la mina
}
