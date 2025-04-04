#include <iostream>
#include <cstdlib>
using namespace std;

//Funciones
bool autenticarUsuario();
void menuPrincipal();
void menuCatalogos();
void menuProcesos();
void menuReportes();
void menuConfiguracion();

int main() {
    if (autenticarUsuario()) {
        menuPrincipal(); // Si la autenticaci�n es exitosa, muestra el men� principal
    } else {
        cout << "Demasiados intentos fallidos. Saliendo del sistema..." << endl;
        system("pause"); // Evita que la consola se cierre inmediatamente
    }
    return 0;
}

// Funci�n para autenticaci�n del usuario
bool autenticarUsuario() {
    string usuarioCorrecto = "admin";
    string contrasenaCorrecta = "1234";
    string usuario, contrasena;
    int intentos = 3;

    do {
        system("cls"); // Limpia la pantalla
        cout << "\t\tAutenticaci�n de usuario" << endl;
        cout << "\t\tUsuario: ";
        cin >> usuario;
        cout << "\t\tContrase�a: ";
        cin >> contrasena;

        if (usuario == usuarioCorrecto && contrasena == contrasenaCorrecta) {
            cout << "\t\tAutenticaci�n exitosa. Bienvenido, " << usuario << "!\n" << endl;
            return true;
        } else {
            intentos--;
            cout << "\t\tUsuario o contrase�a incorrectos. Intentos restantes: " << intentos << endl;
            system("pause");
        }
    } while (intentos > 0);

    return false; // Si se acaban los intentos, se bloquea el acceso
}

// Funci�n del men� principal
void menuPrincipal() {
    int opciones;
    do {
        system("cls"); // Limpia la pantalla
        cout << "\n\n\t\tCuentas por Cobrar - Men�" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Menu de Catalogos" << endl;
        cout << "\t\t2. Menu de Procesos" << endl;
        cout << "\t\t3. Menu de Reportes" << endl;
        cout << "\t\t4. Menu de Configuracion" << endl;
        cout << "\t\t5. Salir" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                menuCatalogos();
                break;
            case 2:
                menuProcesos();
                break;
            case 3:
                menuReportes();
                break;
            case 4:
                menuConfiguracion();
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opci�n no v�lida. Intente de nuevo" << endl;
        }
    } while (opciones != 5); // Repite el men� hasta que el usuario quiera salir

}

// Men� de Cat�logos
void menuCatalogos() {
    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\tMenu de Catalogos" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Registrar Cliente" << endl;
        cout << "\t\t2. Registrar Proveedor" << endl;
        cout << "\t\t3. Registrar Acreedor" << endl;
        cout << "\t\t4. Volver al menu principal" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
    } while (opcion != 4); // Regresa al men� principal cuando elige "Volver"
}

// Men� de Procesos
void menuProcesos() {
    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\tMenu Procesos" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Registro de Factura" << endl;
        cout << "\t\t2. Gestionar pagos a Proveedor o Acreedor" << endl;
        cout << "\t\t3. Gestionar cobro a Cliente" << endl;
        cout << "\t\t4. Gestionar transacciones bancarias" << endl;
        cout << "\t\t5. Volver al menu principal" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
    } while (opcion != 5);
}

// Men� de Reportes
void menuReportes() {
    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\tMenu Reportes" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Listado Cuentas por Pagar" << endl;
        cout << "\t\t2. Listado Cuentas por Cobrar" << endl;
        cout << "\t\t3. Reporte de Pagos Realizados" << endl;
        cout << "\t\t4. Reporte de Ingresos Recibidos" << endl;
        cout << "\t\t5. Reporte de Transacciones Bancarias" << endl;
        cout << "\t\t6. Volver al menu principal" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
    } while (opcion != 6);
}

// Men� de Configuraci�n
void menuConfiguracion() {
    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\tMenu Configuracion" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Configurar tipo de cambio" << endl;
        cout << "\t\t2. Definir pol�ticas de cr�dito y pago" << endl;
        cout << "\t\t3. Configurar facturas" << endl;
        cout << "\t\t4. Configuraci�n de Impuestos" << endl;
        cout << "\t\t5. Administraci�n" << endl;
        cout << "\t\t6. Volver al menu principal" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
    } while (opcion != 6);
}
