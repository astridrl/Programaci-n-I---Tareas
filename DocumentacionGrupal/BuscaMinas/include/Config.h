//Declaraci�n de la clase Config para la configuraci�n del juego Buscaminas
//Almacena y gestiona los par�metros de configuraci�n del juego
//Programador: daguilae
//Documentaci�n Grupo 2 (Astrid Ru�z)
//Marzo 2025
//Curso de Programaci�n I

#ifndef CONFIG_H
#define CONFIG_H

//Declaraci�n de la clase Config para gestionar la configuraci�n del juego
class Config
{
    public:
        //Constructor de la clase Config
        //Definici�n de parametros del constructor:
        //filasTablero: N�mero de filas del tablero
        //columnasTablero: N�mero de columnas del tablero
        //minasTablero: N�mero de minas en el tablero
        //modoDesarrolladorTablero: Estado del modo del desarrollador
        //vidasTablero: N�mero de vidas del jugador
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);

        //M�todos para obtener y establecer nuevos valores

        //(get) Obtiene el n�mero de filas del tablero
        // (set) Establece el n�mero de filas del tablero, a traves de filasTablero y retorna el nuevo valor de filas
        int getfilasTablero();
        int setfilasTablero(int filasTablero);

        //(get) Obtiene el n�mero de columnas del tablero
        // (set) Establece el n�mero de columnas del tablero, a traves de columnasTablero y retorna el nuevo valor de columnas
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);

        //(get) Obtiene la cantidad de minas
        // (set) Establece la cantidad de minas en el tablero, a traves de minasTablero y retorna el nuevo n�mero de minas
        int getminasTablero();
        int setminasTablero(int minasTablero);

        //(get) Obtiene el estado del modo desarrollador
        // (set) Establece el modo desarrollador, a trav�s de modoDesarrollador y retorna el nuevo estado del modo desarrollador
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);

        ////(get) Obtiene la cantidad de minas
        // (set) Establece el n�mero de vidas del jugador, a traves de vidasTablero y retorna el nuevo n�mero de vidas
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);


        //Muestra el men� de configuraci�n del Busca Minas
        //Permite al usuario modificar los par�metros de configuraci�n a trav�s del men� de la consola
        void menuConfiguracion();
    protected:

    private:
        //Atributos privados de configuraci�n
        int filasTablero; //Numero de filas del tablero
        int columnasTablero; //Numero de columnas del tablero
        int minasTablero; //Catidad de minas del tablero
        bool modoDesarrolladorTablero; //Estado del modo desarrollador
        int vidasTablero; //Numero de vidas del jugador
};

#endif // CONFIG_H
