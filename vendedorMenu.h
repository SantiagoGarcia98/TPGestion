#pragma once
#include "VendedorArchivo.h"
#include "VendedorManager.h"

class VendedorMenu {
private:
    int _cantidadOpciones;
    VendedorManager _vendedorManager;
    VendedorArchivo _archivo;

public:
    VendedorMenu();
    void mostrar();
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
    void mostrarOpcionesListar();
    int seleccionOpcionListar();
    void ejecutarOpcionListar(int opcion);
    void mostrarOpcionesBuscar();
    int seleccionOpcionBuscar();
    void ejecutarOpcionBuscar(int opcion);
};
