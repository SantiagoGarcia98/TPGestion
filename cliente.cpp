#include <iostream>
#include "Cliente.h"
#include "persona.h"

using namespace std;

Cliente::Cliente() {
    _IdCliente = 0;
}

void Cliente::setIdCliente(int id) {
    _IdCliente = id; }


int Cliente::getIdCliente() {
    return _IdCliente; }


void Cliente::Cargar() {
    Persona::Cargar();

}

void Cliente::Mostrar() {
    cout << "==============================" << endl;
    cout << "ID Cliente: " << _IdCliente << endl;
    Persona::Mostrar();  // muestra los datos comunes de persona
    cout << "==============================" << endl;

    }


