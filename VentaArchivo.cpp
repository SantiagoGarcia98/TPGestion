#include "Venta.h"
//#include "utils.h"
#include <iostream>

using namespace std;


Venta::Venta()
{
    _idVenta = 0;
    _idCliente = 0;
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

void Venta::setIdTipoPago(int id){
    _idTipoPago = id;
}

void Venta::setMontoTotal(float m){
    _montoTotal = m;
}
void Venta::setEstado(bool e){
    _estado = e;
}

#include <iostream>

using namespace std;

int main()
{


 return 0;
}#include "VentaArchivo.h"

VentaArchivo::VentaArchivo()
{
  //ctor
}

VentaArchivo::~VentaArchivo()
{
  //dtor
}
