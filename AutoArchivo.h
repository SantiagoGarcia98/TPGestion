#pragma once
#include <string>
#include "Auto.h"

class AutoArchivo
{
private:
    std::string _nombreArchivo;

public:
    AutoArchivo(std::string nombreArchivo = "autos.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Auto leer(int pos);
    int leer(Auto autos[], int cantidad);
    bool guardar(Auto reg);
    bool guardar(int pos, Auto reg);
    bool eliminar(int pos);
    bool alta(int pos);
};
