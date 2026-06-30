#include "DetalleVenta.h"
#include <iostream>
#include <cstring>

using namespace std;


DetalleVenta::DetalleVenta()
{
    _idDetalleVenta=0;
    _idVenta=0;
    _idAuto=0;
    _cantidad=0;
    _precioHistorico=0;
    _subtotal=0;
    _estado=true;
}

void DetalleVenta::mostrar() const
{
    cout << "ID Detalle: " << _idDetalleVenta << endl;
    cout << "ID Auto: " << _idAuto << endl;
    cout << "Cantidad: " << _cantidad << endl;
    cout << "Precio: $" << _precioHistorico << endl;
    cout << "Subtotal: $" << _subtotal << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}

/// GETTERS
int DetalleVenta::getIdDetalleVenta() const
{
    return _idDetalleVenta;
}

int DetalleVenta::getIdVenta() const
{
    return _idVenta;
}

int DetalleVenta::getIdAuto() const
{
    return _idAuto;
}

int DetalleVenta::getCantidad() const
{
    return _cantidad;
}

float DetalleVenta::getPrecioHistorico() const
{
    return _precioHistorico;
}

float DetalleVenta::getSubtotal() const
{
    return _subtotal;
}

bool DetalleVenta::getEstado() const
{
    return _estado;
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

void DetalleVenta::setSubtotal(float sub)
{
    _subtotal = sub;
}

void DetalleVenta::setEstado(bool e)
{
    _estado = e;
}
