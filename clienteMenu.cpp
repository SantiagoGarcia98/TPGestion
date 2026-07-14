#include <iostream>
#include "ClienteMenu.h"
#include "utils.h"
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
    cout << "------ MENU CLIENTES ------" << endl;
    cout << "1- CARGAR CLIENTE" << endl;
    cout << "2- LISTAR CLIENTES" << endl;
    cout << "3- DAR BAJA CLIENTE" << endl;
    cout << "4- DAR ALTA CLIENTE" << endl;
    cout << "5- MODIFICAR CLIENTE"<<endl;
    cout << "6- BUSCAR CLIENTE" <<endl;
    cout << "0- SALIR" << endl;
}
int ClienteMenu::seleccionOpcion() {
     int opcion;
    mostrarOpciones();
    return ingresarOpcion(0, _cantidadOpciones);
}
void ClienteMenu::ejecutarOpcion(int opcion) {

    switch (opcion) {

        case 1: _clienteManager.cargarCliente(); break;
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
         } while(opcionListar != 0);break;
            break;
        case 3: _clienteManager.bajaCliente(); break;
        case 4: _clienteManager.altaCliente(); break;
        case 5: _clienteManager.modificarCliente(); break;
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
            break;
        case 0:
            cout << "Saliendo del menu clientes..." << endl;
            break;
    }
}
void ClienteMenu::mostrarOpcionesBuscar(){
    cout << "------ BUSCAR CLIENTE ------" << endl;
    cout << "1- Buscar por apellido" << endl;
    cout << "2- Buscar por ID" << endl;
    cout << "3- Buscar por DNI" << endl;
    cout << "0- Volver" << endl;
}
int ClienteMenu::seleccionOpcionBuscar(){
    int opcion;

    mostrarOpcionesBuscar();

    return ingresarOpcion(0, _cantidadOpciones);
}
void ClienteMenu::ejecutarOpcionBuscar(int opcion){
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

void ClienteMenu::mostrarOpcionesListar(){
    cout << "---- OPCIONES DE LISTADO ----"<<endl;
    cout << "1. Listar clientes ACTIVOS"<<endl;
    cout << "2. Listar clientes INACTIVOS"<<endl;
    cout << "3. Listar TODOS los clientes"<<endl;
    cout << "4. Lista de clientes ordenados por apellido alfabeticamente"<<endl;
    cout << "5. Lista de clientes ordenados por DNI ascendente"<<endl;
    cout << "0. Volver al menu anterior"<<endl;
}
int ClienteMenu::seleccionOpcionListar(){
    int opcion;

    mostrarOpcionesListar();

    return ingresarOpcion(0, _cantidadOpciones);

}
void ClienteMenu::ejecutarOpcionListar(int opcion){
    int cant = _archivo.getCantidadRegistros();
    if (opcion == 0)
    {
        cout << "Volviendo al menu:..." << endl;
        return;
    }
     system("cls");
     if (opcion == 4){
             _clienteManager.listarClientesOrdenadosxapellido();
             return;}
     system("cls");
    if (opcion == 5){
             _clienteManager.listarClientesPorDni();
             return;}
    system("cls");
    cout << "---- LISTADO DE CLIENTES ----"<<endl;
    bool hayClientes = false;// todavia no sabemos el estado del los clientes

    for (int i = 0; i < cant; i++){
        Cliente c = _archivo.leer(i);

        switch (opcion)
        {
        case 1:
            if (c.getEstado())
            {
                c.Mostrar();
                hayClientes = true;
            }
            break;

        case 2:
            if (!c.getEstado())
            {
                c.Mostrar();
                hayClientes = true;
            }
            break;

        case 3:
            c.Mostrar();
            hayClientes = true;
            break;
          default:
            cout << "Opcion invalida.\n";
            return;
        }}

    if (!hayClientes){
        if (opcion == 1)
            cout << "No hay clientes activos.";
        else if (opcion == 2)
            cout << "No hay clientes inactivos.";
    }


}
