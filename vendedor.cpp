#include "vendedor.h"
#include <iomanip>
#include <iostream>

using namespace std;
Vendedor::Vendedor() {
    _IdVendedor = 0;
    _Sueldo = 0;
}

void Vendedor::setIdVendedor(int id) {
    _IdVendedor = id; }

void Vendedor::setLegajo(int legajo) {
    _legajo = legajo; }

void Vendedor::setSueldo(float s) {
     _Sueldo = s; }
void Vendedor::setFechaContratacion(Fecha f) {
    _FechaContratacion = f; }
void Vendedor::setFechaBaja(Fecha fb) {
    _FechaBaja = fb; }
int Vendedor::getIdVendedor() {
    return _IdVendedor; }

float Vendedor::getSueldo() {
    return _Sueldo; }
    Fecha Vendedor::getFechaContratacion() {
         return _FechaContratacion; }

void Vendedor::Cargar() {
    // === Datos generales de Persona ===
    Persona::Cargar();
    if (!_Estado) {   // si Persona fue cancelada
        //cout << //"Carga cancelada. Volviendo al menu...\n";
        return;
    }

    // === Fecha de contratación ===
    cout << "\nFecha de contratacion: " << endl;
    _FechaContratacion.Cargar();

    // === Sueldo ===
    cout << "\nSueldo (ingrese 0 para cancelar): ";
    cin >> _Sueldo;
    cin.ignore();

    if (_Sueldo == 0) {
        cout << "Carga cancelada por el usuario.\n";
        _Estado = false;
        return;
    }

    _Estado = true;

}

void Vendedor::Mostrar() {
    cout << "==============================" << endl;
    cout << "ID Vendedor: " << _IdVendedor << endl;
    Persona::Mostrar();
    cout << "Fecha Contratacion: ";
    _FechaContratacion.Mostrar();
    cout << fixed << setprecision(2);
    cout << "Sueldo: $" << _Sueldo << endl;
    cout << "==============================" << endl;
}
