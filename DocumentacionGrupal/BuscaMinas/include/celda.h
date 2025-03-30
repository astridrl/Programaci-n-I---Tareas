//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Programador: daguilae
//Documentación Grupo 2 (Dulce Martínez)
//Marzo 2025
//Curso de Programaciòn I
#ifndef CELDA_H
#define CELDA_H //Define clase celda

class Celda
{
    public:
        //Constructores
        Celda(); //Constructor
        Celda(int coordenadaX, int coordenadaY, bool estadoMina); //Constructor con parámetros
        //Métodos de acceso y modificación para coordenadas
        int setCoordenadaX(int coordenadaX); // Establece coordenada X
        int getCoordenadaX(); //Obtiene coordenada X
        int setCoordenadaY(int coordenadaY); //Establece coordenada Y
        int getCoordenadaY(); //Obtiene coordenada Y
        //Método de acceso y modificación para coordenadas
        bool setMina(bool estadoMina); //Establece si la celda contiene una mina
        bool getMina(); //Obtiene el estado de la mina
        bool setMinaDescubierta(bool minaDescubierta); //Establece si la mina ha sido descubierta
        bool getMinaDescubierta();//Obtiene si la mina ha sido descubierta
        //Imprime la información de la celda
        void imprimirCelda();
    protected:

    private:
        int coordenadaX, coordenadaY; // Coordenadas de la celda en el tablero
        bool mina, minaDescubierta;  // Estado de la celda
};

#endif // CELDA_H
