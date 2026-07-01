#include <iostream>
#include "VendedorMenu.h"
using namespace std;

VendedorMenu::VendedorMenu() {
    _cantidadOpciones = 8;
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
    cout << "4- ELIMINAR VENDEDOR" << endl;
    cout << "5- BUSCAR POR APELLIDO" << endl;
    cout << "6- BUSCAR POR LEGAJO" << endl;
    cout << "7- BUSCAR POR DNI" << endl;
    cout << "8- BUSCAR POR FECHA DE CONTRATACION" << endl;
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
        case 4: _vendedorManager.eliminarVendedor(); break;
        case 5: _vendedorManager.buscarVendedorPorApellido(); break;
        case 6: _vendedorManager.buscarVendedorPorLegajo(); break;
        case 7: _vendedorManager.buscarVendedorPorDNI(); break;
        case 8: _vendedorManager.buscarFechaContratacion(); break;

    }
}

