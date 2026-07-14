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
        strcpy(_DNI, "");
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
    do{
    cout << "DNI (0 para cancelar): ";
    cin.getline(_DNI, 12);

    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR: El DNI es demasiado largo. Reingrese."<<endl;
        strcpy(_DNI, "");
        continue;
    }

    if (Volver(_DNI)){
        cout << "Carga cancelada por el usuario."<<endl;
        _Estado = false;
        return;
    }

    bool soloNumeros = true;

    for (int i = 0; _DNI[i] != '\0'; i++){
        if (!isdigit(_DNI[i]))
        {
            soloNumeros = false;
            break;
        }
    }

    if (!soloNumeros){
        cout << "ERROR: El DNI solo puede contener numeros."<<endl;
        strcpy(_DNI, "");
        continue;
    }

    if (!validarDNI(_DNI)){
        cout << "ERROR: DNI invalido. Reintente."<<endl;
        strcpy(_DNI, "");
        continue;
    }

    break;

} while (strlen(_DNI) == 0);
    cout << "Nombre (0 para cancelar): ";
    cin.getline(_Nombre, 50);
    if (Volver(_Nombre)){
        cout << "Carga cancelada por el usuario."<<endl;
        _Estado = false;
        return;
    }

    cout << "Apellido (0 para cancelar): ";
    cin.getline(_Apellido, 50);
    if (Volver(_Apellido)){
        cout << "Carga cancelada por el usuario."<<endl;
        _Estado = false;
        return;
    }

    do{
        cout << "Telefono (0 para cancelar): ";
        cin.getline(_Telefono, 20);

        if (Volver(_Telefono))
        {
            cout << "Carga cancelada por el usuario."<<endl;
            _Estado = false;
            return;
        }

        if (!esTelefonoValido(_Telefono))
        {
            cout << "Telefono invalido. Ingrese solo numeros (6 a 15 digitos)."<<endl;
            strcpy(_Telefono, "");
        }

    }
    while (strlen(_Telefono) == 0);

    cout << "Email (0 para cancelar): ";
    cin.getline(_Email, 50);
    if (Volver(_Email)){
        cout << "Carga cancelada por el usuario."<<endl;
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
