#pragma once
#include <string>
#include "TipoPago.h"

class TipoPagoArchivo
{
private:
    std::string _nombreArchivo;

public:
    TipoPagoArchivo(std::string nombreArchivo = "tipospago.dat");

    int getCantidadRegistros();
    int getNuevoID();

    int buscar(int id);

    TipoPago leer(int pos);
    int leer(TipoPago registros[], int cantidad);

    bool guardar(TipoPago reg);
    bool guardar(int pos, TipoPago reg);

    bool eliminar(int pos);
    bool alta(int pos);
};
