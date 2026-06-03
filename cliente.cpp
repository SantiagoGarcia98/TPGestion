#include <iostream>
#include "Persona.h"
#include "Cliente.h"
using namespace std;

Cliente::Cliente() {
    _IdCliente = 0;
}
//SETTERS
//asignamos ID
void Cliente::setIdCliente(int id) {
    _IdCliente = id; }

    //GETTERS
//Devuelve ID
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


