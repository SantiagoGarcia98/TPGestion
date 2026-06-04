#include "Auto.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;


Auto::Auto()
{
    _idAuto = 0;
    strcpy(_marca, "");
    strcpy(_modelo, "");
    _anio = 1;
    _precio = 0;
    _stock = 0;
    _activo = true;
}

void Auto::cargar()
{
    string texto;
    int i;
    float f;

    cout << "Marca: " << endl;
    texto = cargarCadena();
    strncpy(_marca, texto.c_str(), sizeof(_marca) - 1);
    _marca[sizeof(_marca) - 1] = '\0';

    cout << "Modelo: " << endl;
    texto = cargarCadena();
    strncpy(_modelo, texto.c_str(), sizeof(_modelo) - 1);
    _modelo[sizeof(_modelo) - 1] = '\0';

    cout << "Anio: ";
    cin >> i;
    setAnio(i);
    cout << endl;

    cout << "Precio: ";
    cin >> f;
    setPrecio(f);
    cout << endl;

    cout << "Stock disponible: ";
    cin >> i;
    setStock(i);
}


void Auto::mostrar()
{
    cout << "Marca: " << _marca << endl;
    cout << "Modelo: " << _modelo << endl;
    cout << "Anio: " << _anio << endl;
    cout << "Precio: " << _precio << endl;
    cout << "Stock disponible: " << _stock << endl;
}

/// GETTERS
int Auto::getIdAuto()
{
    return _idAuto;
}

const char* Auto::getMarca()
{
    return _marca;
}

const char* Auto::getModelo()
{
    return _modelo;
}

int Auto::getAnio()
{
    return _anio;
}

float Auto::getPrecio()
{
    return _precio;
}

int Auto::getStock()
{
    return _stock;
}

bool Auto::getActivo()
{
    return _activo;
}

/// SETTERS
void Auto::setIdAuto(int id)
{
  _idAuto = id;
}

void Auto::setMarca(const char* m)
{
  strcpy(_marca, m);
}

void Auto::setModelo(const char* mo)
{
  strcpy(_modelo, mo);
}

void Auto::setAnio(int a)
{
  _anio = a;
}

void Auto::setPrecio(float p)
{
  _precio = p;
}

void Auto::setStock(int s)
{
  _stock = s;
}

void Auto::setActivo(bool ac)
{
  _activo = ac;
}
