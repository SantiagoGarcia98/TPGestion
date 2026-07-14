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
    int const anioBase = 2010, anioTope = 2026, stockMin = 1, stockMax = 100;

    //cout << "----- NUEVO AUTO -----" << endl << endl;

    cout << "Marca: ";
    texto = cargarCadena();
    strncpy(_marca, texto.c_str(), sizeof(_marca) - 1);
    _marca[sizeof(_marca) - 1] = '\0';

    cout << "Modelo: ";
    texto = cargarCadena();
    strncpy(_modelo, texto.c_str(), sizeof(_modelo) - 1);
    _modelo[sizeof(_modelo) - 1] = '\0';

    /// Año

    /*do
    {
        cout << "Anio: ";
        cin >> i;

        if(i < anioBase || i > anioTope)
        {
            cout << "Ingrese un anio valido (" << anioBase << " - " << anioTope << ")" << endl;
        }
    }
    while(i < anioBase || i > anioTope);

    setAnio(i);
    */

    i = ingresarEntero("Anio: ", anioBase, anioTope);
    setAnio(i);

    /// Precio

    /*
    do
    {
        cout << "Precio: $";
        cin >> f;

        if(f <= 0)
        {
            cout << "El precio debe ser mayor a cero." << endl;
        }

    }
    while(f <= 0);

    setPrecio(f);
    */

    f = ingresarFloat("Precio: $", 0.01f);
    setPrecio(f);

    /// Stock

    /*
    do
    {
        cout << "Stock inicial: ";
        cin >> i;

        if(i <= 0)
        {
            cout << "El stock inicial debe ser mayor a cero." << endl;
        }

    }
    while(i <= 0);

    setStock(i);
    */

    i = ingresarEntero("Stock inicial: ", stockMin, stockMax);
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

void Auto::setEstado(bool est)
{
    _estado = est;
}
