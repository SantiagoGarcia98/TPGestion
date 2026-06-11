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
