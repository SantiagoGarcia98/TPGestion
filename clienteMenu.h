#pragma once
#include "ClienteManager.h"

class ClienteMenu {
private:
    int _cantidadOpciones;
    ClienteManager _clienteManager;
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
    void mostrarOpciones();

public:
    ClienteMenu();
    void mostrar();
};
