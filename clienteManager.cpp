#include "ClienteManager.h"
#include "Cliente.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

ClienteManager::ClienteManager()
    : _archivo("clientes.dat")
{ }

void ClienteManager::cargarCliente()
{

    if (!confirmarAccion("Desea cargar un nuevo cliente? (s/n): "))
    {
        cout << "Operacion cancelada. Volviendo al menu...\n";
        return;
    }

    Cliente c;
    int id = _archivo.getNuevoID();
    c.setIdCliente(id);

    cout << "ID Cliente # " << id << endl;

    c.Cargar(); // se cargan los datos heredados de Persona
    // se valida que en Persona no haya quedado en estado false, cancelando la carga, en ese caso no guarda el registro.
    if (!c.getEstado())
    {
        cout << "No se guardara el cliente.\n";

        return;
    }


    if (_archivo.guardar(c))
    {
        cout << "Cliente guardado correctamente.\n";
    }
    else
    {
        cout << "Error al guardar el cliente.\n";
    }


}


void ClienteManager::listarClientes()
{

    int cant = _archivo.getCantidadRegistros();
    if (cant == 0)
    {
        cout << "No hay clientes cargados.";
        return;
    }


    cout << "--- OPCIONES DE LISTADO ---"<<endl;
    cout << "1. Listar clientes ACTIVOS"<<endl;
    cout << "2. Listar clientes INACTIVOS"<<endl;
    cout << "3. Listar TODOS los clientes"<<endl;
    cout << "4. Lista de clientes ordenados por apellido alfabeticamente"<<endl;
    cout << "5. Lista de clientes ordenados por DNI ascendente"<<endl;
    cout << "0. Volver al menu anterior\n"<<endl;
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;
    cin.ignore();

    if (opcion == 0)
    {
        cout << "Volviendo al menu:...";
        return;
    }
     system("cls");
    if (opcion == 4){
             listarClientesOrdenadosxapellido();
             return;}
     system("cls");
    if (opcion == 5){
             listarClientesPorDni();
             return;}
    system("cls");
    cout << "--- LISTADO DE CLIENTES ---"<<endl;
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




void ClienteManager::eliminarCliente()
{
    char dni[12];

    if (!confirmarAccion("Intenta eliminar un cliente? (s/n): "))
    {
        cout << "Operacion cancelada. Volviendo al menu"<<endl;
        return;
    }

    string texto;
    do
    {
        cout << "Ingrese DNI del cliente a eliminar (0 para cancelar): ";
        texto = cargarCadena();

        if (Volver(texto.c_str()))   // permite volver al menú
        {
            cout << "Operacion cancelada por el usuario."<<endl;
            return;
        }

        if (!validarDNI((char*)texto.c_str()))
        {
            cout << "DNI invalido. Reintente."<<endl;
            texto.clear();
        }
    }
    while (texto.empty());

    strcpy(dni, texto.c_str());

    int pos = _archivo.buscarPorDNI(dni);
    if (pos == -1)
    {
        cout << "Cliente no encontrado."<<endl;
        return;
    }

    Cliente c = _archivo.leer(pos);
    cout << "--- DATOS DEL CLIENTE ---" << endl;
    c.Mostrar();

    char confirma;
    cout << "Esta seguro que desea eliminar este cliente? (s/n): "<< endl;
    cin >> confirma;

    if (confirma == 's' || confirma == 'S')
    {
        c.setEstado(false);
        if (_archivo.guardar(pos, c))
            cout << "Cliente marcado como INACTIVO correctamente."<< endl;
        else
            cout << "Error al actualizar el registro."<< endl;
    }
    else
    {
        cout << "Operacion cancelada."<< endl;
    }
}
void ClienteManager::buscarClientePorDNI()
{
    char dni[9];

    cout << "Ingrese el DNI: ";
    cin >> dni;

    int cant = _archivo.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        Cliente c = _archivo.leer(i);

        if (strcmp(c.getDni(), dni) == 0)
        {
            cout << "cliente encontrado:\n";
            c.Mostrar();
            return;
        }
    }

    cout << "No existe un cliente con ese DNI." << endl;
}

void ClienteManager::buscarClientePorApellido()
{
    char apellido[50];
    cout << "Ingrese apellido del cliente"<< endl;
    cin >> apellido;

    int cant = _archivo.getCantidadRegistros();
    bool encontrado = false;

    for (int i=0 ; i<cant ; i++)
    {
        Cliente c = _archivo.leer(i);
        if (strcmpi(c.getApellido(), apellido) == 0 && c.getEstado())   // si le saco el c.getestado , puede buscar todos y no solo los activos
        {
            c.Mostrar();
            encontrado = true;
        }
    }

    if(!encontrado)
    {
        cout << "Nose se encontraron clientes con el apellido" << apellido << endl;
    }
}
void ClienteManager::buscarClientePorID()
{
    int id;
    cout << "Ingrese ID del cliente: ";
    cin >> id;

    int pos = _archivo.buscarPorID(id);
    if (pos=-1)
    {
        cout << "cliente no encontrado. \n";
    }
    Cliente c = _archivo.leer(pos);
    c.Mostrar();

}


void ClienteManager::listarClientesOrdenadosxapellido()
{
    int cant = _archivo.getCantidadRegistros();
    Cliente *vec = new Cliente[cant];
    for(int i = 0; i < cant; i++){
        vec[i] = _archivo.leer(i);
    }
    Cliente aux;
    for(int i = 0; i < cant - 1; i++){
        for(int j = i + 1; j < cant; j++)
        {
            if(strcmp(vec[i].getApellido(), vec[j].getApellido()) > 0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for(int i = 0; i < cant; i++){
        vec[i].Mostrar();
    }
    delete[] vec;
}
void ClienteManager::listarClientesPorDni()
{
    int cant = _archivo.getCantidadRegistros();
    Cliente *vec = new Cliente[cant];

    for (int i = 0; i < cant; i++)
    {
        vec[i] = _archivo.leer(i);
    }
    Cliente aux;
    for (int i = 0; i < cant - 1; i++)
    {
        for (int j = i + 1; j < cant; j++)
        {
            if (strcmp(vec[i].getDni(), vec[j].getDni()) > 0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for (int i = 0; i < cant; i++)
    {
        vec[i].Mostrar();
    }
    delete[] vec;
}








