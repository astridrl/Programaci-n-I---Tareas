#include <iostream>
#include <cstdlib>
//Este programa permite calcular y evaluar su propio IMC
//Febrero 2025 Astrid
using namespace std;

int main()
{
    //Variables operadores
    float pesoEnLibras=0;
    float alturaEnPulgadas=0;
    float pesoEnKilogramos=0;
    float alturaEnMetros=0;
    float resultadoCalculadora;
    int opcionSeleccionada;
    char salidaMenu;
    //inicia el ciclo
    do
    {
        system("cls"); //parametro para limpiar la pantalla
        //Ingreso de datos
        opcionSeleccionada=0;
        resultadoCalculadora=0;
        cout << "Calculadora IMC" << endl;
        //Menu de opciones en calculadora
        cout << "Seleccione una opcion para calcular su Índice de masa corporal: " <<endl;
        cout << "1. IMC (peso en libras y altura en pulgadas)" << endl;
        cout << "2. IMC (peso en kilogramos y altura en metros)" << endl;
        cin >> opcionSeleccionada;
        // Estructuras condicionales
        if (opcionSeleccionada == 1) //== comparar si son iguales
        {
            cout << "Ingrese su peso en libras" << endl;
            cin >> pesoEnLibras;
            cout << "Ingrese su altura en pulgadas" << endl;
            cin >> alturaEnPulgadas;
        }
        else if (opcionSeleccionada == 2)
        {
            cout << "Ingrese su peso en kilogramos" << endl;
            cin >> pesoEnKilogramos;
            cout << "Ingrese su altura en metros" << endl;
            cin >> alturaEnMetros;
        }

        switch  (opcionSeleccionada)
        {
            case 1:
                resultadoCalculadora = (pesoEnLibras * 703) / (alturaEnPulgadas*alturaEnPulgadas); // formulas aplicadas
                break;
            case 2:
                resultadoCalculadora = pesoEnKilogramos / (alturaEnMetros*alturaEnMetros);
                break;
            default:
                cout << "Error opcion seleccionada" << endl;
        }

        cout << "El resultado de su calculo es: " << resultadoCalculadora << endl;

// Estructura condicional
// Datos con los cuales se evalua el IMC
        if (resultadoCalculadora < 18.5) {
        cout << "Bajo peso." << endl;
      } else if (resultadoCalculadora >=18.5 && resultadoCalculadora<=24.9) {
        cout << "Peso normal." << endl;
      } else if (resultadoCalculadora >=25 && resultadoCalculadora<=29.9) {
        cout << "Sobrepeso." << endl;
      } else {
        cout << "Obesidad I." << endl;
  }
        cout << "Desea realizar otra operacion Si=S o No=N" << endl;
        cin >> salidaMenu;
    } while (salidaMenu == 's' || salidaMenu == 'S');
    return 0;
}
