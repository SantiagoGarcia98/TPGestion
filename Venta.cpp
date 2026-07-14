#include "Venta.h"
#include <iostream>
#include <iomanip> /// Para fix de montos

using namespace std;


Venta::Venta()
{
    _idVenta = 0;
    _idCliente = 0;
    _idVendedor = 0;
    _idTipoPago = 0;
    _montoTotal = 0;
    _estado = true;
}

void Venta::cargar()
{
    /// A Manager
}

void Venta::mostrar()
{
    ///
    cout << "ID Venta: #" << _idVenta << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();

    cout << "Cliente: #" << _idCliente << endl;
    cout << "Vendedor: #" << _idVendedor << endl;
    cout << "Tipo Pago: #" << _idTipoPago << endl;

    cout << fixed << setprecision(2); /// Fixear montos a notación decimal fija

    cout << "Monto Total: $" << _montoTotal << endl;

    cout << "Estado: " << (_estado ? "ACTIVA" : "CANCELADA") << endl;
}

/// GETTERS
int Venta::getIdVenta() const
{
    return _idVenta;
}

Fecha Venta::getFecha() const
{
    return _fecha;
}

int Venta::getIdCliente() const
{
    return _idCliente;
}

int Venta::getIdVendedor() const
{
    return _idVendedor;
}

int Venta::getIdTipoPago() const
{
    return _idTipoPago;
}

float Venta::getMontoTotal() const
{
    return _montoTotal;
}

bool Venta::getEstado() const
{
    return _estado;
}

/// SETTERS
void Venta::setIdVenta(int id){
    _idVenta = id;
}

void Venta::setFecha(Fecha f){
    _fecha = f;
}

void Venta::setIdCliente(int id){
    _idCliente = id;
}

void Venta::setIdVendedor(int id){
    _idVendedor = id;
}

void Venta::setIdTipoPago(int id){
    _idTipoPago = id;
}

void Venta::setMontoTotal(float m)
{
    if(m > 0)
    {
        _montoTotal = m;
    }
}

void Venta::setEstado(bool e){
    _estado = e;
}
