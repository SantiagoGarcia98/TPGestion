#include <iostream>
#include "App.h"

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
    cout << "--------- MENU PRINCIPAL ---------" << endl;
    cout << "1- CLIENTES" << endl;
    cout << "2- VENDEDORES" << endl;
    cout << "3- AUTOS" << endl;
    cout << "4- VENTAS" << endl;
    cout << "5- TIPOS DE PAGO" << endl;
    cout << "6- REPORTES" << endl;
    cout << "----------------------------------" << endl;
    cout << "0- SALIR" << endl;
}

int App::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "--------------------" << endl;
    cout << "SELECCIONE UNA OPCION: ";
    cin >> opcion;
    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "---------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl;
        cout << "---------------" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
    }
    return opcion;
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
    /*case 6:
        _reportesMenu.mostrar();
        break;*/
    case 0:
        cout << "Saliendo... Gracias por utilizar el programa!" << endl;
        cout << endl;
        cout << endl;
        break;
    }
}
