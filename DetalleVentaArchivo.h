#pragma once
#include <string>
#include "DetalleVenta.h"

class DetalleVentaArchivo
{
private:
    std::string _nombreArchivo;

public:

    DetalleVentaArchivo(std::string nombreArchivo = "detalleventas.dat");

    int getCantidadRegistros(); /// Ok

    int getNuevoID(); /// Ok

    int buscar(int id); /// Ok

    DetalleVenta leer(int pos); /// Ok
    int leer(DetalleVenta vec[], int cantidad); /// Ok
    int leerPorVenta(int idVenta, DetalleVenta vec[], int cantidad); /// Ok

    bool guardar(DetalleVenta reg); /// Ok
    bool guardar(int pos, DetalleVenta reg); /// Ok

    bool eliminar(int pos); /// Ok

    void listarPorVenta(int idVenta); /// Ok
};
