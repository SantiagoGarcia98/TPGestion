#include <iostream>
#include <cstring>
#include <string>
#include "funciones.h"


using namespace std;


bool validarDNI(char* dni) {
    int tam = strlen(dni);

    // Verificar que no esté vacío
    if (tam == 0) {
        cout << "ERROR: El DNI no puede estar vac" << char(161) << "o." << endl;
        return false;
    }

    // Verificar que todos los caracteres sean números
    for (int i = 0; i < tam; i++) {
        if (!isdigit(dni[i])) {
            cout << "ERROR: El DNI solo puede contener n" << char(163) << "meros." << endl;
            return false;
        }
    }

    // Verificar el largo después de confirmar que son números
    if (tam < 7 || tam > 8) {
        cout << "ERROR: El DNI debe tener entre 7 y 8 d" << char(161) << "gitos." << endl;
        return false;
    }

    return true;
}


bool esTelefonoValido( char *tel) {
    int tamtel = strlen(tel);

    // Entre 6 y 15 d gitos
    if (tamtel < 6 || tamtel > 15) return false;

    // Solo n meros permitidos
    for (int i = 0; i < tamtel; i++) {
        if (!isdigit(tel[i])) return false;
    }

    return true;
}

bool Volver(const char* texto) {
    // Retorna true si el usuario escribió "0"
    return strcmp(texto, "0") == 0;
}
