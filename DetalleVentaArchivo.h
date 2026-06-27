#pragma once
#include <string>
#include "DetalleVenta.h"


class DetalleVentaArchivo
{
private:
    std::string _nombreArchivo;

public:

    DetalleVentaArchivo(std::string nombreArchivo = "detalleventas.dat");

    int getCantidadRegistros();

    int getNuevoID();

    int buscar(int id);

    DetalleVenta leer(int pos);
    int leer(DetalleVenta vec[], int cantidad);
    int leerPorVenta(int idVenta, DetalleVenta vec[], int cantidad); /// DEFINIR

    bool guardar(DetalleVenta reg);
    bool guardar(int pos, DetalleVenta reg);

    void listarPorVenta(int idVenta); /// De
};
