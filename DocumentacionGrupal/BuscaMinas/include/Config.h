//Declaración de la clase Config para la configuración del juego Buscaminas
//Almacena y gestiona los parámetros de configuración del juego
//Programador: daguilae
//Documentación Grupo 2 (Astrid Ruíz)
//Marzo 2025
//Curso de Programaciòn I

#ifndef CONFIG_H
#define CONFIG_H

//Declaración de la clase Config para gestionar la configuración del juego
class Config
{
    public:
        //Constructor de la clase Config
        //Definición de parametros del constructor:
        //filasTablero: Número de filas del tablero
        //columnasTablero: Número de columnas del tablero
        //minasTablero: Número de minas en el tablero
        //modoDesarrolladorTablero: Estado del modo del desarrollador
        //vidasTablero: Número de vidas del jugador
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);

        //Métodos para obtener y establecer nuevos valores

        //(get) Obtiene el número de filas del tablero
        // (set) Establece el número de filas del tablero, a traves de filasTablero y retorna el nuevo valor de filas
        int getfilasTablero();
        int setfilasTablero(int filasTablero);

        //(get) Obtiene el número de columnas del tablero
        // (set) Establece el número de columnas del tablero, a traves de columnasTablero y retorna el nuevo valor de columnas
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);

        //(get) Obtiene la cantidad de minas
        // (set) Establece la cantidad de minas en el tablero, a traves de minasTablero y retorna el nuevo número de minas
        int getminasTablero();
        int setminasTablero(int minasTablero);

        //(get) Obtiene el estado del modo desarrollador
        // (set) Establece el modo desarrollador, a través de modoDesarrollador y retorna el nuevo estado del modo desarrollador
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);

        ////(get) Obtiene la cantidad de minas
        // (set) Establece el número de vidas del jugador, a traves de vidasTablero y retorna el nuevo número de vidas
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);


        //Muestra el menú de configuración del Busca Minas
        //Permite al usuario modificar los parámetros de configuración a través del menú de la consola
        void menuConfiguracion();
    protected:

    private:
        //Atributos privados de configuración
        int filasTablero; //Numero de filas del tablero
        int columnasTablero; //Numero de columnas del tablero
        int minasTablero; //Catidad de minas del tablero
        bool modoDesarrolladorTablero; //Estado del modo desarrollador
        int vidasTablero; //Numero de vidas del jugador
};

#endif // CONFIG_H
