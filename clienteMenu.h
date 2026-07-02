#pragma once
#include "ClienteManager.h"

class ClienteMenu {
private:
    int _cantidadOpciones;
    ClienteManager _clienteManager;
public:
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
    void mostrarOpciones();
    ClienteMenu();
    void mostrar();
    void mostrarOpcionesBuscar();
    int seleccionOpcionBuscar();
    void ejecutarOpcionBuscar(int opcion);
};
