#include <iostream>
using namespace std;

int main(){
    float primerNumero, segundoNumero, total;
    int operacionElegida;

    cout << "Seleccione la operaci�n que desea realizar" << endl;
    cout << "1 = Suma"<<endl;
    cout << "2 = Resta"<<endl;
    cout << "3 = Multiplicaci�n"<<endl;
    cout << "4 = Divisi�n"<<endl;
    cin >> operacionElegida;

    cout << "Ingrese el primer n�mero" <<endl;
    cin >> primerNumero;
    cout << "Ingrese el segundo n�mero" <<endl;
    cin >> segundoNumero;

    switch(operacionElegida){
        case 1:
        total = primerNumero + segundoNumero;
        cout << "El resultado de la suma es" << total << endl;
        break;

        case 2:
        total = primerNumero - segundoNumero;
        cout << "El resultado de la resta es" << total << endl;
        break;

        case 3:
        total = primerNumero * segundoNumero;
        cout << "El resultado de la multiplicaci�n es" << total << endl;
        break;

        case 4:
        total = primerNumero / segundoNumero;
        cout << "El resultado de la divisi�n es" << total << endl;
        break;
    }
    return 0;

}
