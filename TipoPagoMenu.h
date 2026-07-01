#pragma once
#include "TipoPagoManager.h"

class TipoPagoMenu
{
private:
    int _cantidadOpciones;
    TipoPagoManager _tipoPagoManager;

    void mostrarOpciones();
    int seleccionarOpcion();
    void ejecutarOpcion(int opcion);

    void menuListados();

public:
    TipoPagoMenu();

    void mostrar();
};
