
#pragma once
#include "ClienteArchivo.h"

class ClienteManager {
private:
    ClienteArchivo _archivo;

public:
    ClienteManager();

    void cargarCliente();
    void listarClientes();
    void eliminarCliente(); // baja lógica por ID
    void buscarClientePorDNI();
    void buscarClientePorApellido();
    void buscarClientePorID();
    void listarClientesOrdenadosxapellido();
    void listarClientesPorDni();
};
