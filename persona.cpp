#include "persona.h"
#include "funciones.h"
#include <cstring>
#include <iostream>


using namespace std;

Persona::Persona()
{
    strcpy(_DNI, "");
    strcpy(_Nombre, "");
    strcpy(_Apellido, "");
    strcpy(_Telefono, "");
    strcpy(_Email, "");
    _Estado = true;
}
// Setters
void Persona::setNombre( char *n)
{
    strcpy(_Nombre, n);
}
void Persona::setApellido( char *a)
{
    strcpy(_Apellido, a);
}
void Persona::setDni( char* d)
{

    if (validarDNI(d))
    {
        strcpy(_DNI, d);
    }
    else
    {
        strcpy(_DNI, "");// dejo vacio
    }

}
void Persona::setTelefono( char* t)
{
    strcpy(_Telefono, t);
}
void Persona::setEmail( char *e)
{
    strcpy(_Email, e);
}
void Persona::setFechaNacimiento(Fecha f) {
    _FechaNacimiento=f; }
void Persona::setEstado(bool est)
{
    _Estado = est;
}

// Getters
char *Persona::getNombre()
{
    return _Nombre;
}
char *Persona::getApellido()
{
    return _Apellido;
}
char *Persona::getDni()
{
    return _DNI;
}
char *Persona::getTelefono()
{
    return _Telefono;
}
char *Persona::getEmail()
{
    return _Email;

}
Fecha Persona::getFechaNacimiento() {
         return _FechaNacimiento;
}

bool Persona::getEstado()
{
    return _Estado;
}



void Persona::Cargar()
{

    // --- DNI ---
    do
    {
        cout << "DNI (0 para cancelar): ";
        cin.getline(_DNI, 12);

        if (Volver(_DNI))
        {
            cout << "Carga cancelada por el usuario.\n";
            _Estado = false;
            return;
        }

        if (!validarDNI(_DNI))
        {
            cout << "ERROR: DNI invalido. Reintente.\n";
            strcpy(_DNI, "");// el campo se deja en blanco para repetir
            continue; //
        }
        //Verificar si ya existe en el sistema (en clientes o vendedores)

        break;
    }
    while (strlen(_DNI) == 0);

    // --- NOMBRE ---
    cout << "Nombre (0 para cancelar): ";
    cin.getline(_Nombre, 50);
    if (Volver(_Nombre))
    {
        cout << "Carga cancelada por el usuario.\n";
        _Estado = false;
        return;
    }

    // --- APELLIDO ---
    cout << "Apellido (0 para cancelar): ";
    cin.getline(_Apellido, 50);
    if (Volver(_Apellido))
    {
        cout << "Carga cancelada por el usuario.\n";
        _Estado = false;
        return;
    }

    // --- TELÉFONO ---
    do
    {
        cout << "Telefono (0 para cancelar): ";
        cin.getline(_Telefono, 20);

        if (Volver(_Telefono))
        {
            cout << "Carga cancelada por el usuario.\n";
            _Estado = false;
            return;
        }

        if (!esTelefonoValido(_Telefono))
        {
            cout << "Telefono invalido. Ingrese solo numeros (6–15 digitos).\n";
            strcpy(_Telefono, "");
        }

    }
    while (strlen(_Telefono) == 0);

    // --- EMAIL ---
    cout << "Email (0 para cancelar): ";
    cin.getline(_Email, 50);
    if (Volver(_Email))
    {
        cout << "Carga cancelada por el usuario.\n";
        _Estado = false;
        return;
    }

    _Estado = true;
}

void Persona::Mostrar()
{
    cout << "Nombre:   " << _Nombre << endl;
    cout << "Apellido: " << _Apellido << endl;
    cout << "DNI:      " << _DNI << endl;
    cout << "Telefono: " << _Telefono << endl;
    cout << "Email:    " << _Email << endl;
    cout << "Estado:   " << (_Estado ? "Activo" : "Inactivo") << endl;
}
