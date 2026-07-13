#pragma once
#include "ClienteManager.h"

class ClienteMenu {
private:
    int _cantidadOpciones;
    ClienteManager _clienteManager;
    ClienteArchivo _archivo;
public:
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
    void mostrarOpciones();
    ClienteMenu();
    void mostrar();
    void mostrarOpcionesListar();
    int seleccionOpcionListar();
    void ejecutarOpcionListar(int opcion);
    void mostrarOpcionesBuscar();
    int seleccionOpcionBuscar();
    void ejecutarOpcionBuscar(int opcion);
};
