#include <iostream>
#include "utils.h"

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
    int opcion;
    cout << mensaje << endl;
    cin >> opcion;
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
        cout << "¡CARGA EXITOSA!" << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA CARGA..." << endl;
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

bool confirmarAccion(string mensaje)
{
    char respuesta;
    cout << mensaje << " (S/N): ";
    cin >> respuesta;

    while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
    {
        cout << endl;
        cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
        cout << endl;
        cout << mensaje << " (S/N): ";
        cin >> respuesta;
    }
    return (respuesta == 's' || respuesta == 'S');
}
