#pragma once
#include <string>
#include "Venta.h"

class VentaArchivo
{
private:
    std::string _nombreArchivo;

public:
    VentaArchivo(std::string nombreArchivo = "ventas.dat");

    int getCantidadRegistros();
    int getNuevoID();

    int buscar(int id); /// por ID

    Venta leer(int pos);
    int leer(Venta vec[], int cant);

    bool guardar(Venta reg);
    bool guardar(int pos, Venta reg);

    bool eliminar(int pos);
    bool alta(int pos);

    bool existeTipoPagoEnVentas(int idTipoPago);
};
