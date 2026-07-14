#include <iostream>
#include "utils.h"
#include <cstring>

using namespace std;

std::string cargarCadena()
{
    std::string texto;

    if(std::cin.peek() == '\n')
    {
        std::cin.ignore();
    }

    std::getline(std::cin, texto);

    return texto;
}



bool quiereCancelar(string mensaje)
{
    cout << mensaje << endl;

    int opcion = ingresarEntero("0 - Cancelar\n1 - Continuar\nOpcion: ", 0, 1);

    if(opcion == 0)
    {
        cout << endl;
        cout << "Operacion cancelada..." << endl;
        return true;
    }

    return false;
}


int validarPositivo(int num)
{
    while(num <= 0)
    {
        cout << "El valor solo puede ser positivo... Intentelo nuevamente..." << endl;
        cout << "Ingrese un valor positivo: " << endl;
        cin >> num;
    }
    return num;
}

void validarCarga(bool resultado)
{
    if(resultado)
    {
        cout << endl;
        cout << "CARGA EXITOSA!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA CARGA!" << endl;
        cout << endl;
    }
}

void validarModificacion(bool resultado)
{
    if(resultado)
    {
        cout << endl;
        cout << "¡MODIFICACION EXITOSA!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA MODIFICACION..." << endl;
        cout << endl;
    }
}

void validarBaja(bool resultado)
{
    if(resultado)
    {
        cout << endl;
        cout << "¡BAJA EXITOSA!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA BAJA..." << endl;
        cout << endl;
    }
}

void validarAlta(bool resultado)
{
    if(resultado)
    {
        cout << endl;
        cout << "¡ALTA EXITOSA!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "NO SE PUDO REALIZAR EL ALTA..." << endl;
        cout << endl;
    }
}



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


bool confirmarAccion(const char* mensaje)
{
    string respuesta;

    while(true)
    {
        cout << mensaje << " (S/N): ";
             respuesta = cargarCadena();

        if (!respuesta.empty())
        {
            if (respuesta[0] == 's' || respuesta[0] == 'S')
                return true;

            if (respuesta[0] == 'n' || respuesta[0] == 'N')
                return false;
        }

        cout << "Opcion invalida. Ingrese 's' o 'n'" << endl;
        cout << endl;
    }

}


int ingresarOpcion(int minimo, int maximo)
{
    string texto;
    int opcion;
    bool esNumero;

    while(true)
    {
        cout << "Seleccione una opcion: ";
        texto = cargarCadena();

        esNumero = true;

        if(texto.empty())
        {
            esNumero = false;
        }

        for(int i=0; i<texto.size(); i++)
        {
            if(texto[i] < '0' || texto[i] > '9')
            {
                esNumero = false;
                break;
            }
        }

        if(!esNumero)
        {
            cout << "------------------------------------------------------" << endl;
            cout << "Debe ingresar un numero." << endl << endl;
            continue;
        }

        opcion = stoi(texto);

        if(opcion >= minimo && opcion <= maximo)
        {
            return opcion;
        }

        cout << "------------------------------------------------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl << endl;
    }
}

int ingresarEntero(string mensaje, int minimo, int maximo)
{
    string texto;
    int numero;
    bool esNumero;

    while(true)
    {
        cout << mensaje;
        texto = cargarCadena();

        esNumero = true;

        if(texto.empty())
        {
            esNumero = false;
        }

        for(int i=0; i<texto.size(); i++)
        {
            if(texto[i] < '0' || texto[i] > '9')
            {
                esNumero = false;
                break;
            }
        }

        if(!esNumero)
        {
            cout << "Debe ingresar un numero." << endl << endl;
            continue;
        }

        numero = stoi(texto);

        if(numero < minimo || numero > maximo)
        {
            cout << "El valor debe estar entre "
                 << minimo << " y " << maximo << "." << endl << endl;
            continue;
        }

        return numero;
    }
}

float ingresarFloat(string mensaje, float minimo)
{
    string texto;
    float numero;
    bool esNumero;

    while(true)
    {
        cout << mensaje;
        texto = cargarCadena();

        esNumero = true;
        int cantidadPuntos = 0;

        if(texto.empty())
        {
            esNumero = false;
        }

        for(int i=0; i<texto.size(); i++)
        {
            if(texto[i] == '.')
            {
                cantidadPuntos++;

                if(cantidadPuntos > 1)
                {
                    esNumero = false;
                    break;
                }
            }
            else
            {
                if(texto[i] < '0' || texto[i] > '9')
                {
                    esNumero = false;
                    break;
                }
            }
        }

        if(!esNumero)
        {
            cout << "Debe ingresar un numero valido." << endl << endl;
            continue;
        }

        numero = stof(texto);

        if(numero < minimo)
        {
            cout << "El valor debe ser mayor o igual a "
                 << minimo << "." << endl << endl;
            continue;
        }

        return numero;
    }

}
