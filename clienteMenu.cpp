#include <iostream>
#include "ClienteMenu.h"
using namespace std;

ClienteMenu::ClienteMenu() {
    _cantidadOpciones = 6;
}

void ClienteMenu::mostrar() {
    int opcion;
    do {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    } while (opcion != 0);
}

void ClienteMenu::mostrarOpciones() {
    cout << "===== MENU CLIENTES =====" << endl;
    cout << "1- CARGAR CLIENTE" << endl;
    cout << "2- LISTAR CLIENTES" << endl;
    cout << "3- ELIMINAR CLIENTE" << endl;
    cout << "4- BUSCAR CLIENTE" <<endl;
    cout << "0- SALIR" << endl;
}

int ClienteMenu::seleccionOpcion() {
    int opcion;
    mostrarOpciones();
    cout << "--------------------------------" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > _cantidadOpciones) {
        cout << "Opcion incorrecta..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    return opcion;
}

void ClienteMenu::ejecutarOpcion(int opcion) {

    switch (opcion) {

        case 1: _clienteManager.cargarCliente(); break;
        case 2: _clienteManager.listarClientes(); break;
        case 3: _clienteManager.eliminarCliente(); break;
        case 4:
        int opcionBuscar;
        do{
        system("cls");
        opcionBuscar = seleccionOpcionBuscar();
        ejecutarOpcionBuscar(opcionBuscar);
        if(opcionBuscar != 0)
        {
            system("pause");
        }
         } while(opcionBuscar != 0);break;
            break;
        case 0:
            cout << "Saliendo del menu clientes..." << endl;
            break;
    }
}
void ClienteMenu::mostrarOpcionesBuscar(){
    cout << "====== BUSCAR CLIENTE ======" << endl;
    cout << "1- Buscar por apellido" << endl;
    cout << "2- Buscar por ID" << endl;
    cout << "3- Buscar por DNI" << endl;
    cout << "0- Volver" << endl;
}

int ClienteMenu::seleccionOpcionBuscar(){
    int opcion;

    mostrarOpcionesBuscar();

    cout << "Opcion: ";
    cin >> opcion;

    while(opcion < 0 || opcion > 4)
    {
        cout << "Opcion incorrecta." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }

    return opcion;
}
void ClienteMenu::ejecutarOpcionBuscar(int opcion)
{
    switch(opcion)
    {
    case 1:
        _clienteManager.buscarClientePorApellido();
        break;

    case 2:
       _clienteManager.buscarClientePorID();
        break;

    case 3:
        _clienteManager.buscarClientePorDNI();
        break;
    case 0:
        break;
    }
}
