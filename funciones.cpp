#include <iostream>
#include <cstring>
#include <string>
#include "funciones.h"


using namespace std;


bool validarDNI(char* dni) {
    int tam = strlen(dni);


    if (tam == 0) {
        cout << "ERROR: El DNI no puede estar vacio." << endl;
        return false;
    }


    for (int i = 0; i < tam; i++) {
        if (!isdigit(dni[i])) {
            cout << "ERROR: El DNI solo puede contener numeros." << endl;
            return false;
        }
    }


    if (tam < 7 || tam > 8) {
        cout << "ERROR: El DNI debe tener entre 7 y 8 digitos." << endl;
        return false;
    }

    return true;
}


bool esTelefonoValido( char *tel) {
    int tamtel = strlen(tel);


    if (tamtel < 6 || tamtel > 15) return false;


    for (int i = 0; i < tamtel; i++) {
        if (!isdigit(tel[i])) return false;
    }

    return true;
}

bool Volver(const char* texto) {

    return strcmp(texto, "0") == 0;
}

bool confirmarAccion(const char* mensaje ) {
    cout << mensaje;
    string respuesta = cargarCadena();


    while (respuesta.empty() ||/// que no este vacio
          (respuesta[0] != 's' && respuesta[0] != 'S' &&
           respuesta[0] != 'n' && respuesta[0] != 'N')) {

        cout << "Opcion invalida. Ingrese 's' o 'n': ";
        respuesta = cargarCadena();
    }

    return (respuesta[0] == 's' || respuesta[0] == 'S');
}

