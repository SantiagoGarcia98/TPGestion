#pragma once
#include <string>
#include "Vendedor.h"

class VendedorArchivo {
private:
    std::string _nombreArchivo;

public:
    VendedorArchivo(std::string nombreArchivo = "vendedores.dat");

    bool guardar(Vendedor registro);
    bool guardar(int pos, Vendedor registro);
    Vendedor leer(int pos);
    int leerTodos(Vendedor vec[], int cantidad);
    int getCantidadRegistros();
    int getNuevoID();
    int buscarPorID(int id);
    int buscarPorDNI(char *dni);
    int buscarPorApellido(const char *apellido);
    bool eliminar(int pos);
};
