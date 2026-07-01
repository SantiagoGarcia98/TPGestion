#include <iostream>
#include "VendedorMenu.h"
using namespace std;

VendedorMenu::VendedorMenu() {
    _cantidadOpciones = 9;
}

void VendedorMenu::mostrar() {
    int opcion;
    do {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    } while (opcion != 0);
}

void VendedorMenu::mostrarOpciones() {

    cout << "===== MENU VENDEDORES =====" << endl;
    cout << "1- CARGAR VENDEDOR" << endl;
    cout << "2- LISTAR VENDEDORES" << endl;
    cout << "3- MODIFICAR VENDEDOR" << endl;
    cout << "4- DAR DE BAJA VENDEDOR" << endl;
    cout << "5- DAR DE ALTA VENDEDOR" << endl;
    cout << "6- BUSCAR VENDEDOR" << endl;
    cout << "0- SALIR" << endl;
}

int VendedorMenu::seleccionOpcion() {
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

void VendedorMenu::ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1: _vendedorManager.cargarVendedor(); break;
        case 2: _vendedorManager.listarVendedores(); break;
        case 3: _vendedorManager.modificarVendedor(); break;
        case 4: _vendedorManager.BajaVendedor(); break;
        case 5: _vendedorManager.altaVendedor(); break;
        case 6:
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
    }
}
void VendedorMenu::mostrarOpcionesBuscar(){
    cout << "====== BUSCAR VENDEDOR ======" << endl;
    cout << "1- Buscar por apellido" << endl;
    cout << "2- Buscar por legajo" << endl;
    cout << "3- Buscar por DNI" << endl;
    cout << "4- Buscar por fecha de contratacion" << endl;
    cout << "0- Volver" << endl;
}

int VendedorMenu::seleccionOpcionBuscar(){
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
void VendedorMenu::ejecutarOpcionBuscar(int opcion)
{
    switch(opcion)
    {
    case 1:
        _vendedorManager.buscarVendedorPorApellido();
        break;

    case 2:
        _vendedorManager.buscarVendedorPorLegajo();
        break;

    case 3:
        _vendedorManager.buscarVendedorPorDNI();
        break;

    case 4:
        _vendedorManager.buscarFechaContratacion();
        break;

    case 0:
        break;
    }
}

