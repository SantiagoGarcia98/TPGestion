#include <iostream>
#include "Persona.h"
#include "vendedor.h"
#include "cliente.h"
using namespace std;

int main()
{
Persona p;
Vendedor v;
Cliente c;

///c.Cargar();
///c.Mostrar();

v.Cargar();
v.Mostrar();

///p.Cargar();
///p.Mostrar();
    return 0;
}
