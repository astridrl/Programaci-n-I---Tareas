//Implementa la clase tablero en el juego de buscaminas
//Libreria que se encarga de definir el tablero de buscaminas.
//Programador: daguilae
//Documentacion Grupo 2 (Britany Hernandez)
//Marzo 2025
//Curso de programacion I
#include "Tablero.h"
#include <sstream>
#include <iostream>

using namespace std;

Tablero::Tablero()//Contructor predeterminado
{
}
//Constructor que inicializa el tablero con el tamaño especificado por:
//alturaTablero define el numero de filas del tablero
//anchoTablero definde el numero de columnas del tablero
//modoDesarrollador para definir el modo en que se mostrara el tablero
//Indica si el modo desarrollados esta activado
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador)
{
    this->alturaTablero = alturaTablero;
    this->anchoTablero = anchoTablero;
    this->modoDesarrollador = modoDesarrollador;
    int x, y;
    //Inicializa el tablero con las celdas vacias
    for (y=0; y < this->alturaTablero; y++)
    {
        vector<Celda> fila;
        for (x=0; x < this->anchoTablero; x++)
        {
            fila.push_back((Celda(x, y, false)));
        }
        this->contenidoTablero.push_back(fila);
    }
}
//Obtiene y retorna el numero de filas del tablero o en otras palabras la altura
int Tablero::getAlturaTablero()
{
    return this->alturaTablero;//-------Apunta a la direccion en memoria RAM apunta al atributo del objeto
}
//Establece la altura que tendra el tablero
int Tablero::setAlturaTablero(int alturaTablero)
{
    this->alturaTablero = alturaTablero;
}
//Obtiene y retorna el numero de columas del tablero o de su ancho
int Tablero::getAnchoTablero()
{
    return this->anchoTablero;
}
//Establece el ancho que tendra el tablero
int Tablero::setAnchoTablero(int anchoTablero)
{
    this->anchoTablero = anchoTablero;
}
//Obtiene el estado del modo desarrollador
//Retorna true si el modo desarollador esta activado y false si no lo esta
bool Tablero::getModoDesarrollador()
{
    return this->modoDesarrollador;
}
//Establece el estado del modo desarrollador
//Activando o desactivando el modo desarrollador
bool Tablero::setModoDesarrollador(bool modoDesarrollador)
{
    this->modoDesarrollador = modoDesarrollador;
}
//Devuelve la representacion de la celda dependiendo de su estado
//Retorna el simbolo que indica el estado de la celda dependiendo
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)
{
    //Obtiene la celda accediendo a su posicion en contenidoTablero
    Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX);
    //Verifica si se muestra la celda si esta fue descubierta o si se usa el modo desarrollador esta activo
    if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)
    {
        if (celdaTemporal.getMina())//Devuelve * si la celda tiene una mina
        {
            return "*";
        }
        else
        {
            //Calcula las minas alrededor de la celda
            int cantidadCelda=this->minasCercanas(coordenadaY,coordenadaX);
            string cantidadCeldaString = " "; //Convierte el numero de minas cerca a string
            stringstream ss;
            ss << cantidadCelda;
            ss >> cantidadCeldaString;
            return cantidadCeldaString;//Devuelve el numero de minas cerca
        }
    }
    else//Si la celda no ha sido descubierta y el modo desarollador no esta activo
    {
        return "?";
        //return "." o "?";
    }
}
//Obtiene el total de minas cerca de una celda
int Tablero::minasCercanas(int filaTablero, int columnaTablero)
{
        int contadorTablero = 0; //Almacena las minas alrededor de la celda
        int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;
        //Definicion de los limites del tablero
        //Limite de filas--Primera fila
        if (filaTablero <= 0)
		{
			filaInicioTablero = 0;
		}
		else
		{
			filaInicioTablero = filaTablero - 1;
		}
		//Ultima fila del tablero
		if (filaTablero + 1 >= this->alturaTablero)
		{
			filaFinTablero = this->alturaTablero - 1;
		}
		else
		{
			filaFinTablero = filaTablero + 1;
		}
        //Inicio de las filas del tablero
		if (columnaTablero <= 0)
		{
			columnaInicioTablero = 0;
		}
		else
		{
			columnaInicioTablero = columnaTablero - 1;
		}
		//Ultima fila del tablero
		if (columnaTablero + 1 >= this->anchoTablero)
		{
			columnaFinTablero = this->anchoTablero - 1;
		}
		else
		{
			columnaFinTablero = columnaTablero + 1;
		}
		//Ciclo para recorrer el area alrededor de la celda en los parametros establecidos
		int m;
		for (m = filaInicioTablero; m <= filaFinTablero; m++)
		{
			int l;
			for (l = columnaInicioTablero; l <= columnaFinTablero; l++)
			{
				if (this->contenidoTablero.at(m).at(l).getMina())
				{
					contadorTablero++;
				}
			}
		}
		return contadorTablero;//Devuelve el total de minas alrededor
}
//Imprime los separadores y encabezados del tablero
//Imprime una linea de separacion en el encabezado
void Tablero::imprimirSeparadorEncabezado()
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			cout << "----";
			if (m + 2 == this->anchoTablero)
			{
				cout << "-";
			}
		}
		cout << "\n";
	}
//Imprime el separador entre las filas del tablero
	void Tablero::imprimirSeparadorFilas()
	{
		int m;
		for (m = 0; m <= this->anchoTablero; m++)
		{
			if (m <= 1)
			{
				cout << "|---";
			}
			else
			{
				cout << "+---";
			}
			if (m == this->anchoTablero)
			{
				cout << "+";
			}
		}
		cout << "\n";
	}
//Imprieme el encabezado del tablero
	void Tablero::imprimirEncabezado()
	{
		this->imprimirSeparadorEncabezado();
		cout << "|   ";
		int l;
		for (l = 0; l < this->anchoTablero; l++)
		{
			cout << "| " << l + 1 << " ";
			if (l + 1 == this->anchoTablero)
			{
				cout << "|";
			}
		}
		cout << "\n";
	}
//Imprime el tablero
	void Tablero::imprimir()
	{
		this->imprimirEncabezado();
		this->imprimirSeparadorEncabezado();
		int x, y;
		for (y = 0; y < this->alturaTablero; y++)
		{
			cout << "| " << y + 1 << " ";
			for (x = 0; x < this->anchoTablero; x++)
			{
				cout << "| " << this->getRepresentacionMina(x, y) << " ";
				if (x + 1 == this->anchoTablero)
				{
					cout << "|";
				}
			}
			cout << "\n";
			this->imprimirSeparadorFilas();
		}
	}
//Coloca una mina en una celda especifica en el tablero
    bool Tablero::colocarMina(int x, int y)
	{
		return this->contenidoTablero.at(y).at(x).setMina(true);
	}
//Descubre el contenido de una celda especifica
    bool Tablero::descubrirMina(int x, int y)
	{
		this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);
		Celda celda = this->contenidoTablero.at(y).at(x);
		if (celda.getMina()) //Evalua si la celda contiene una mina
		{
			return false;//Si la celda tiene una mina el jugador a perdido
		}
		return true;//Si la celda no tiene una mina
	}
//Cuenta cuantas celdas no tienen minas y aun no han sido descubiertas
	int Tablero::contarCeldasSinMinasYSinDescubrir()
	{
		int x, y, contador = 0;
		for (y = 0; y < this->alturaTablero; y++)
		{
			for (x = 0; x < this->anchoTablero; x++)
			{
				Celda celdaTemporal = this->contenidoTablero.at(y).at(x);
				//Verificacion de que la celda no haya sido descubrierta y que no tenga mina
				if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())
				{
					contador++;
				}
			}
		}
		return contador;//Retorna la cantidad de celdas sin mina y sin descubrir
	}
