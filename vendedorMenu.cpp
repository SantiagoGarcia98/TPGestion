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
        case 2:
            int opcionListar;
        do{
        system("cls");
        opcionListar = seleccionOpcionListar();
        ejecutarOpcionListar(opcionListar);
        if(opcionListar != 0)
        {
            system("pause");
        }

        } while(opcionListar !=0);break;
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
void VendedorMenu::ejecutarOpcionBuscar(int opcion){
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

void VendedorMenu::mostrarOpcionesListar(){
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay vendedores cargados."<<endl;
        return;
    }
    cout << "--- OPCIONES DE LISTADO ---"<<endl;
    cout << "1. ACTIVOS "<<endl;
    cout << "2. INACTIVOS "<<endl;
    cout << "3. LISTAR TODOS "<<endl;
    cout << "4. Lista de vendedores ordenados por apellido alfabeticamente"<<endl;
    cout << "5. Lista de vendedores ordenados por fecha de contratacion"<<endl;
    cout << "0. Volver al menu anterior"<<endl;
    cout << "Seleccione una opcion: ";
}
int VendedorMenu::seleccionOpcionListar(){
    int opcion;

    mostrarOpcionesListar();

    cout << "Opcion: ";
    cin >> opcion;

    while(opcion < 0 || opcion > 5)
    {
        cout << "Opcion incorrecta." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }

    return opcion;

}
void VendedorMenu::ejecutarOpcionListar(int opcion){
    int cant = _archivo.getCantidadRegistros();
    if (opcion == 0)
    {
        cout << "Volviendo al menu:..." << endl;
        return;
    }
     system("cls");
    if (opcion == 4){
             _vendedorManager.listarVendedorOrdenadosxapellido();
             return;}
     system("cls");
     if (opcion == 5){
            _vendedorManager.listarFechaContratacion();
             return;}
     system("cls");

    for (int i = 0; i < cant; i++) {
        Vendedor v = _archivo.leer(i);

        switch (opcion) {
        case 1:
            if (v.getEstado()) v.Mostrar();
            break;
        case 2:
            if (!v.getEstado()) v.Mostrar();
            break;
        case 3:
            v.Mostrar();
            break;
        default:
            cout << "Opcion invalida."<<endl;
            return;
        }
    }

}
