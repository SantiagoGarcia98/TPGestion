#include <iostream>
#include "App.h"
#include "utils.h"

using namespace std;

App::App()
{
    _cantidadOpciones = 6;
}

void App::run()
{
    int opcion;
    do
    {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
    }
    while(opcion != 0);
}

void App::mostrarOpciones()
{
    cout << "---------------------- MENU PRINCIPAL ----------------------" << endl;
    cout << "1- CLIENTES" << endl;
    cout << "2- VENDEDORES" << endl;
    cout << "3- AUTOS" << endl;
    cout << "4- VENTAS" << endl;
    cout << "5- TIPOS DE PAGO" << endl;
    cout << "6- REPORTES" << endl;
    cout << "0- SALIR" << endl;
}

int App::seleccionOpcion()
{
    mostrarOpciones();
    return ingresarEntero("SELECCIONE UNA OPCION: ", 0, _cantidadOpciones);
}

void App::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _clienteMenu.mostrar();
        break;
    case 2:
        _vendedorMenu.mostrar();
        break;
    case 3:
        _autoMenu.mostrar();
        break;
    case 4:
        _ventaMenu.mostrar();
        break;
    case 5:
        _tipoPagoMenu.mostrar();
        break;
    case 6:
        _reportesMenu.mostrar();
        break;
    case 0:
        cout << "Saliendo... Gracias por utilizar el programa!" << endl << endl;
        break;
    }
}
