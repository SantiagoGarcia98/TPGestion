#include "Venta.h"
//#include "utils.h"
#include <iostream>

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
    ///
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
    cout << "Monto Total: $" << _montoTotal << endl;

    cout << "Estado: " << _estado << endl;

}

/// GETTERS
int Venta::getIdVenta(){
    return _idVenta;
}

Fecha Venta::getFecha(){
    return _fecha;
}

int Venta::getIdCliente(){
    return _idCliente;
}

int Venta::getIdVendedor(){
    return _idVendedor;
}

int Venta::getIdTipoPago(){
    return _idTipoPago;
}

float Venta::getMontoTotal(){
    return _montoTotal;
}

bool Venta::getEstado(){
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
