//Implementaci�n del programa principal para el juego Buscaminas
//Controla el flujo de ejecuci�n, muestra el men� principal y gestiona la interacci�n con el usuario.
//Programador: daguilae
//Documentaci�n Grupo 2 (Dulce Mart�nez)
//Marzo 2025
//Curso de�Programaci�n�I

#include <iostream>
#include <unistd.h> //Biblioteca para la generar n�meros aleatorios
#include "Juego.h" // Clase Juego
#include "Config.h" // Clase Configuraci�n

using namespace std;

int main()
{
    //Definici�n de las configuraciones iniciales del juego
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    //Creaci�n de un objeto de configuraci�n del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    //Creaci�n de un objeto con el tablero configurado
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    srand(getpid()); //Inicializaci�n del generador de n�meros aleatorios
    int opciones; //Variable para almacenar al usuario
    bool repetir = true; //Bandera para controlar el bucle del men�
    do
    {
        system("cls"); //Limpia la patalla
        //Men� principal del juego
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones; //Captura la opci�n que ingres� el usuario
        switch (opciones)
        {
        case 1:
            {
                configuracionJuego.menuConfiguracion(); //Llama al men� de configuraci�n
                break;
            }
        case 2:
            {
                //Creaci�n de un nuevo juego con la configuraci�n actualizada
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar(); //Inicia el juego

                system("pause"); //Pausa la ejecuci�n para que el usuario vea la pantalla de continuar
                break;
            }
        case 3: repetir = false; //Sale del bucle y termina el programa
                break;
        }
    } while (repetir); //Repite el men� hasta que el usuario quiera salir
    system("cls"); //Limpia la pantalla
    return 0;
}
