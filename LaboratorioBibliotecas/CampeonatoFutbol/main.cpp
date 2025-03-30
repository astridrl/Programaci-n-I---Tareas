#include <cstdlib>
#include <ctime>
#include <iostream>
#include "campeonato.h"

using namespace std;

int main()
{
    // Inicializar la semilla para los números aleatorios
    srand(time(0));

    char opcion;
    bool repetir = true;
    campeonato campeonato;

    // Solicitar nombres de equipos
    campeonato.ingresarEquipos();

    do {
        system("cls");
        cout << "* Campeonato de Futbol *" << endl << endl;

        // Iniciar un nuevo campeonato
        campeonato.iniciarCampeonato();

        cout << "Desea generar otro campeonato (s/n)? ";
        cin >> opcion;
        if (opcion == 'n') {
            repetir = false;
        }
    } while (repetir);

    return 0;
}
