//Implementación del programa principal para el juego Buscaminas
//Controla el flujo de ejecución, muestra el menú principal y gestiona la interacción con el usuario.
//Programador: daguilae
//Documentación Grupo 2 (Dulce Martínez)
//Marzo 2025
//Curso de Programaciòn I

#include <iostream>
#include <unistd.h> //Biblioteca para la generar números aleatorios
#include "Juego.h" // Clase Juego
#include "Config.h" // Clase Configuración

using namespace std;

int main()
{
    //Definición de las configuraciones iniciales del juego
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;
    const int MINASENTABLERO = 3;
    const bool MODODESARROLLADOR = true;
    const int VIDASTABLERO = 3;
    //Creación de un objeto de configuración del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    //Creación de un objeto con el tablero configurado
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    srand(getpid()); //Inicialización del generador de números aleatorios
    int opciones; //Variable para almacenar al usuario
    bool repetir = true; //Bandera para controlar el bucle del menú
    do
    {
        system("cls"); //Limpia la patalla
        //Menú principal del juego
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones; //Captura la opción que ingresó el usuario
        switch (opciones)
        {
        case 1:
            {
                configuracionJuego.menuConfiguracion(); //Llama al menú de configuración
                break;
            }
        case 2:
            {
                //Creación de un nuevo juego con la configuración actualizada
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar(); //Inicia el juego

                system("pause"); //Pausa la ejecución para que el usuario vea la pantalla de continuar
                break;
            }
        case 3: repetir = false; //Sale del bucle y termina el programa
                break;
        }
    } while (repetir); //Repite el menú hasta que el usuario quiera salir
    system("cls"); //Limpia la pantalla
    return 0;
}
