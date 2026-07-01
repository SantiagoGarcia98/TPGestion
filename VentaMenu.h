#pragma once
#include "VentaManager.h"


class VentaMenu
{
private:
    int _cantidadOpciones;
    VentaManager _ventaManager;

    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    void menuListados();
    void menuConsultas();

public:
    VentaMenu();

    void mostrar();
};
