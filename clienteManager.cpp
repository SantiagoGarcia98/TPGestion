#include "ClienteManager.h"
#include "Cliente.h"
#include "utils.h"
#include <iostream>

#include <cstring>// para strcpy, strlen

using namespace std;

ClienteManager::ClienteManager()
    : _archivo("clientes.dat")// inicio archivo
{ }

void ClienteManager::cargarCliente() {

    if (!confirmarAccion("Desea cargar un nuevo cliente? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu...\n";
        return;
    }

    Cliente c;
    int id = _archivo.getNuevoID(); // analiza archivo y genera nuevo ID
    c.setIdCliente(id);// asigno id

    cout << "ID Cliente # " << id << endl;

    c.Cargar(); // se cargan los datos heredados de Persona
                // se valida que en Persona no haya quedado en estado false, cancelando la carga, en ese caso no guarda el registro.
    if (!c.getEstado()) {
        cout << "No se guardara el cliente.\n";

        return;
    }

    // Guarda sólo si el cliente tiene estado activo
    if (_archivo.guardar(c)) {
        cout << "Cliente guardado correctamente.\n";
    } else {
        cout << "Error al guardar el cliente.\n";
    }


}


void ClienteManager::listarClientesTodos(){

 int cant = _archivo.getCantidadRegistros();
                for (int i = 0; i < cant; i++) {
                Cliente c = _archivo.leer(i);
                if(c.getEstado())
                c.Mostrar();
                }

}




void ClienteManager::eliminarCliente() {
    char dni[12];

    if (!confirmarAccion("Intenta eliminar un cliente? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu"<<endl;
        return;
    }

    string texto;
    do {
        cout << "Ingrese DNI del cliente a eliminar (0 para cancelar): ";
        texto = cargarCadena();

        if (Volver(texto.c_str())) { // permite volver al menú
            cout << "Operacion cancelada por el usuario.\n";
            return;
        }

        if (!validarDNI((char*)texto.c_str())) {
            cout << "DNI invalido. Reintente.\n";
            texto.clear();
        }
    } while (texto.empty());

    strcpy(dni, texto.c_str());

    int pos = _archivo.buscarPorDNI(dni);
    if (pos == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Cliente c = _archivo.leer(pos);
    cout << "\n--- DATOS DEL CLIENTE ---" << endl;
    c.Mostrar();

    char confirma;
    cout << "\nEsta seguro que desea eliminar este cliente? (s/n): ";
    cin >> confirma;

    if (confirma == 's' || confirma == 'S') {
        c.setEstado(false);
        if (_archivo.guardar(pos, c))
            cout << "Cliente marcado como INACTIVO correctamente.\n";
        else
            cout << "Error al actualizar el registro.\n";
    } else {
        cout << "Operacion cancelada.\n";
    }
}



