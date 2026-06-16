#include "TipoPago.h"
#include "utils.h"
#include "cstring"
#include <iostream>


using namespace std;


TipoPago::TipoPago()
{
  //ctor
}

void TipoPago::cargar()
{

}

void TipoPago::mostrar()
{

}

/// GETTERS
int TipoPago::getIdTipoPago()
{
    return _idTipoPago;
}

const char* TipoPago::getDescripcion()
{
    return _descripcion;
}

bool TipoPago::getEstado()
{
    return _estado;
}

/// SETTERS
void TipoPago::setIdTipoPago(int id)
{
    _idTipoPago = id;
}

void TipoPago::setDescripcion(const char* d)
{
    strcpy(_descripcion,d);
}

void TipoPago::setEstado(bool e)
{
    _estado = e;
}
