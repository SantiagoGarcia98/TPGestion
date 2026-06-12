#include "DetalleVenta.h"
#include <iostream>
#include <cstring>

using namespace std;


DetalleVenta::DetalleVenta()
{
  //ctor
}

void DetalleVenta::cargar()
{

}

void DetalleVenta::mostrar()
{

}

/// GETTERS
int DetalleVenta::getIdDetalleVenta()
{
    return _idDetalleVenta;
}

int DetalleVenta::getIdVenta()
{
    return _idVenta;
}

int DetalleVenta::getIdAuto()
{
    return _idAuto;
}

int DetalleVenta::getCantidad()
{
    return _cantidad;
}

float DetalleVenta::getPrecioHistorico()
{
    return _precioHistorico;
}

/// SETTERS
void DetalleVenta::setIdDetalleVenta(int id)
{
    _idDetalleVenta = id;
}

void DetalleVenta::setIdVenta(int id)
{
    _idVenta = id;
}

void DetalleVenta::setIdAuto(int id)
{
    _idAuto = id;
}

void DetalleVenta::setCantidad(int c)
{
    _cantidad = c;
}

void DetalleVenta::setPrecioHistorico(float p)
{
    _precioHistorico = p;
}
