
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
    void eliminarVendedor();
    void buscarVendedorPorApellido();
};
