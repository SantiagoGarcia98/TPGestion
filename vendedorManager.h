
#pragma once
#include "VendedorArchivo.h"

class VendedorManager {
private:
    VendedorArchivo _archivo;

public:
    VendedorManager();
    void cargarVendedor();
    void listarVendedores();
    void modificarVendedor();
    void BajaVendedor();
    void altaVendedor();
    void buscarVendedorPorApellido();
    void buscarVendedorPorLegajo();
    void buscarVendedorPorDNI();
    void buscarFechaContratacion();
    void listarVendedorOrdenadosxapellido();
    void listarFechaContratacion();

};
