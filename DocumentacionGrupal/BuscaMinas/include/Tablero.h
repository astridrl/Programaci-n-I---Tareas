//Implementa la clase tablero en el juego de buscaminas
//Libreria que se encarga de definir el tablero de buscaminas.
//Programador: daguilae
//Documentacion Grupo 2 (Britany Hernandez)
//Marzo 2025
//Curso de programacion I
#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include "Celda.h"

//Aqui se administran la estructura de las celdas,la gestion de las minas y su descubrimiento
//Tambien incluye el estado del tablero con respecto a las configuraciones

using namespace std;

//Definicion de la clase tablero que se encarga de representar al tablero del juego
class Tablero
{
    public:
        //Contructores de la clase tablero
        Tablero();//Constructor predeterminado
        //Constructor que inicializa el tablero con el tamaño establecido y el modo especificados
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);

        //Metodos Get & Set para las dimenciones del tablero
        int getAlturaTablero();
        int setAlturaTablero(int alturaTablero);
        int getAnchoTablero();
        int setAnchoTablero(int anchoTablero);

        //Metodo para gestionar el modo desarrollador
        bool getModoDesarrollador();//Devuelve si el modo desarrollador esta activo
        bool setModoDesarrollador(bool modoDesarrollador);//Activa o desactiva el modo desarrollador

        // Metodos para imprimir el tablero
        void imprimirSeparadorEncabezado();
        void imprimirSeparadorFilas();
        void imprimirEncabezado();
        void imprimir();

        bool colocarMina(int x, int y);//Coloca una mina en una celda especifica en el tablero
        bool descubrirMina(int x, int y);//Descubre el contenido de una celda

        //Cuenta cuantas celdas no tienen minas y aun no han sido descubiertas
        int contarCeldasSinMinasYSinDescubrir();

    protected:

    private:
        int alturaTablero, anchoTablero;//Numero de filas y numero de columnas en el tablero
        bool modoDesarrollador;//Muestra el contenido sin ocultar en el tablero
        vector<vector<Celda> > contenidoTablero;//Celdas que conforman el tablero

        //Devuelve la representacion de la celda dependiendo de su estado
        string getRepresentacionMina(int x, int y);
        //Obtiene el total de minas cerca de una celda
        int minasCercanas(int fila, int columna);
};

#endif // TABLERO_H
