#include <iostream>
#include "Persona.h"
#include "vendedor.h"
#include "cliente.h"
#include "clienteManager.h"
#include "vendedorManager.h"
#include "Auto.h"
#include "AutoArchivo.h"
#include "AutoManager.h"
#include "AutoMenu.h"

using namespace std;

int main()
{
//ClienteManager p;
VendedorManager v;
AutoMenu m;

///p.cargarCliente();
///p.listarClientesTodos();
///p.eliminarCliente();
///v.cargarVendedor();
v.listarVendedores();
///v.eliminarVendedor();
///v.buscarVendedorPorApellido();
///v.modificarVendedor();
m.mostrar();



return 0;
}
