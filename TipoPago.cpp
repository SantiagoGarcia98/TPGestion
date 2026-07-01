#include "TipoPago.h"
#include "utils.h"
#include "cstring"
#include <iostream>

using namespace std;


TipoPago::TipoPago()
{
  ///ctor
  _idTipoPago = 0;
  strcpy(_descripcion, "");
  _estado = true;
}

void TipoPago::cargar()
{
    string texto;

    cout << "Descripcion: ";
    texto = cargarCadena();
    strncpy(_descripcion, texto.c_str(), sizeof(_descripcion)-1);
    _descripcion[sizeof(_descripcion)-1] = '\0';
}

void TipoPago::mostrar()const
{
    cout << "ID: " << _idTipoPago << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Estado: "
         << (_estado ? "ACTIVO" : "INACTIVO")
         << endl;
}

/// GETTERS
int TipoPago::getIdTipoPago() const
{
    return _idTipoPago;
}

const char* TipoPago::getDescripcion() const
{
    return _descripcion;
}

bool TipoPago::getEstado() const
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
    strncpy(_descripcion, d, sizeof(_descripcion)-1);
    _descripcion[sizeof(_descripcion)-1] = '\0';
}

void TipoPago::setEstado(bool e)
{
    _estado = e;
}
