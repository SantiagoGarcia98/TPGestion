#pragma once
#include "AutoManager.h"

class AutoMenu
{
private:
    int _cantidadOpciones;
    AutoManager _autoManager;
    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

public:
    AutoMenu();
    void mostrar();
};
