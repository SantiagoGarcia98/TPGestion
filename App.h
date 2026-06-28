#pragma once
#include "clienteMenu.h" /// Dentro estará listados y consultas
#include "vendedorMenu.h" /// Dentro estará listados y consultas
#include "AutoMenu.h" /// Dentro estará listados y consultas
#include "VentaMenu.h" /// Dentro estará listados y consultas
#include "TipoPagoMenu.h" /// Dentro estará listados y consultas (si sumamos, no lo contemplamos en informe, VER)
/// #include "ReportesMenu.h" /// Aún no lo tenemos

class App
{
private:
    int _cantidadOpciones;
    ClienteMenu _clienteMenu;
    VendedorMenu _vendedorMenu;
    AutoMenu _autoMenu;
    VentaMenu _ventaMenu;
    TipoPagoMenu _tipoPagoMenu;
    /// ReportesMenu _reportesMenu;

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

public:
    App();
    void run();
};

/// Clase App
