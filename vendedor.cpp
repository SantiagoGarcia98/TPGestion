#include "vendedor.h"
#include <iomanip>
#include <iostream>

using namespace std;
Vendedor::Vendedor() {
    _IdVendedor = 0;
    _Sueldo = 0;
}

void Vendedor::setIdVendedor(int id) {
    _IdVendedor = id;
    _legajo = id+1000; }
void Vendedor::setSueldo(float s) {
     _Sueldo = s; }
void Vendedor::setFechaContratacion(Fecha f) {
    _FechaContratacion = f; }
void Vendedor::setFechaBaja(Fecha fb) {
    _FechaBaja = fb; }
int Vendedor::getIdVendedor() {
    return _IdVendedor; }
int Vendedor::getLegajo(){
    return _legajo;}
float Vendedor::getSueldo() {
    return _Sueldo; }
    Fecha Vendedor::getFechaContratacion() {
         return _FechaContratacion; }

void Vendedor::Cargar() {
    Persona::Cargar();
    if (!_Estado) {   // si Persona fue cancelada
        //cout << //"Carga cancelada. Volviendo al menu...\n";
        return;
    }


    cout << "\nFecha de contratacion: " << endl;
    _FechaContratacion.Cargar();


    cout << "\nSueldo (ingrese 0 para cancelar): "<<endl;

    cin >> _Sueldo;

    cin.ignore();

    if (_Sueldo == 0) {
        cout << "Carga cancelada por el usuario."<<endl;
        _Estado = false;
        return;
    }

    _Estado = true;

}

void Vendedor::Mostrar() {
    cout << "==============================" << endl;
    cout << "ID Vendedor: " << _IdVendedor << endl;
    cout << "Legajo vendedor: " << _legajo <<endl;
    Persona::Mostrar();
    cout << "Fecha Contratacion: ";
    _FechaContratacion.Mostrar();
    cout << fixed << setprecision(2);
    cout << "Sueldo: $" << _Sueldo << endl;
    cout << "==============================" << endl;
}
