#pragma once
#include "Cliente.h"
#include <string>

class ClienteArchivo {
private:
    std::string _nombreArchivo;
public:
    ClienteArchivo( std::string  nombreArchivo = "clientes.dat");

    bool guardar( Cliente registro);
    bool guardar(int pos,  Cliente registro);

    Cliente leer(int pos);
    int leerTodos(Cliente vec[], int cantidad);

    int getCantidadRegistros();
    int getNuevoID();
    int buscarPorID(int id);
    int buscarPorDNI( char *dni);

    bool eliminar(int pos); // baja lógica
};


