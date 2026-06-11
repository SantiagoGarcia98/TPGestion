
#pragma once
#include "ClienteArchivo.h"

class ClienteManager {
private:
    ClienteArchivo _archivo;

public:
    ClienteManager();

    void cargarCliente();        // alta
    void listarClientesTodos();  // listar todos
    void eliminarCliente();      // baja lógica por ID

};
