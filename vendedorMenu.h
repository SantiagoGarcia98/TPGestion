#pragma once
#include "VendedorManager.h"

class VendedorMenu {
private:
    int _cantidadOpciones;
    VendedorManager _vendedorManager;

public:
    VendedorMenu();
    void mostrar();
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
    void mostrarOpcionesBuscar();
    int seleccionOpcionBuscar();
    void ejecutarOpcionBuscar(int opcion);
};
