
#pragma once
#include "ClienteArchivo.h"

class ClienteManager {
private:
    ClienteArchivo _archivo;

public:
    ClienteManager();

    void cargarCliente();
    void listarClientesTodos();
    void eliminarCliente(); // baja lógica por ID
    void buscarClientePorDNI();
    void buscarClientePorApellido();
};
