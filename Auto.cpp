#include "Auto.h"
#include "utils.h"
#include <iostream>
#include <cstring>
#include <iomanip> /// Para precio

using namespace std;

Auto::Auto()
{
    _idAuto = 0;
    strcpy(_marca, "");
    strcpy(_modelo, "");
    _anio = 1900;
    _precio = 0;
    _stock = 0;
    _estado = true;
}

void Auto::cargar()
{
    string texto;
    int i;
    float f;

    //cout << "----- NUEVO AUTO -----" << endl << endl;

    cout << "Marca: ";
    texto = cargarCadena();
    strncpy(_marca, texto.c_str(), sizeof(_marca) - 1);
    _marca[sizeof(_marca) - 1] = '\0';

    cout << "Modelo: ";
    texto = cargarCadena();
    strncpy(_modelo, texto.c_str(), sizeof(_modelo) - 1);
    _modelo[sizeof(_modelo) - 1] = '\0';

    cout << "Anio: ";
    cin >> i;
    setAnio(i);

    cout << "Precio: $ ";
    cin >> f;
    setPrecio(f);

    cout << "Stock disponible: ";
    cin >> i;
    setStock(i);
}


void Auto::mostrar() const
{
    cout << "ID: " << _idAuto << endl;
    cout << "Estado: "
         << (_estado ? "ACTIVO" : "INACTIVO")
         << endl;
    cout << "Marca: " << _marca << endl;
    cout << "Modelo: " << _modelo << endl;
    cout << "Anio: " << _anio << endl;
    cout << fixed << setprecision(2); /// Para precio
    cout << "Precio: $" << _precio << endl;
    cout << "Stock disponible: " << _stock << endl;
}

/// GETTERS
int Auto::getIdAuto() const
{
    return _idAuto;
}

const char* Auto::getMarca() const
{
    return _marca;
}

const char* Auto::getModelo() const
{
    return _modelo;
}

int Auto::getAnio() const
{
    return _anio;
}

float Auto::getPrecio() const
{
    return _precio;
}

int Auto::getStock() const
{
    return _stock;
}

bool Auto::getEstado() const
{
    return _estado;
}

/// SETTERS
void Auto::setIdAuto(int id)
{
  _idAuto = id;
}

void Auto::setMarca(const char* m)
{
  strncpy(_marca, m, sizeof(_marca) - 1);
  _marca[sizeof(_marca) - 1] = '\0';

  //strcpy(_marca, m);
}

void Auto::setModelo(const char* mo)
{
  strncpy(_modelo, mo, sizeof(_modelo) - 1);
  _modelo[sizeof(_modelo) - 1] = '\0';

  //strcpy(_modelo, mo);
}

void Auto::setAnio(int a)
{
    if(a>=1900 && a<=2026)
        _anio = a;
}

void Auto::setPrecio(float p)
{
    if(p>0)
        _precio = p;
}

void Auto::setStock(int s)
{
    if(s>=0)
        _stock = s;
}

void Auto::setEstado(bool est)
{
  _estado = est;
}
