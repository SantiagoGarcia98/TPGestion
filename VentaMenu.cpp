/// DEFINIR

#include "VentaMenu.h"
#include <iostream>
#include "utils.h"

using namespace std;


VentaMenu::VentaMenu()
{
    _cantidadOpciones = 4;
}

void VentaMenu::mostrar()
{
    int opcion;
    do
    {
        system("cls");
        opcion = seleccionarOpcion();
        //system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    }
    while(opcion != 0);
}

void VentaMenu::mostrarOpciones()
{
    cout << "----- MENU VENTA -----" << endl;
    cout << "1 - NUEVA VENTA" << endl;
    cout << "2 - ELIMINAR VENTA" << endl;
    cout << "3 - LISTADO DE VENTAS" << endl; /// Dentro va listado de ventas del informe, son 2 + 2 que sume en VentaManager
    cout << "4 - CONSULTAS DE VENTAS" << endl; /// Dentro va consultas de ventas del informe, son 4 (también en VentaManager)
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------" << endl;
}

void VentaMenu::ejecutarOpcion(int opcion)
{
    bool resultado;

    switch(opcion)
    {
    case 1:
      system("cls");
        resultado = _ventaManager.cargarVenta();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _ventaManager.eliminarVenta();
        validarBaja(resultado);
        break;
    case 3:
        system("cls");
        cout << "----- LISTADO DE VENTAS -----" << endl;
        _ventaManager.listarVentas(); /// Acá realmente debería llevar a submenu de LISTADOS
        break;
    case 4:
        system("cls");
        cout << "----- CONSULTA DE VENTAS -----" << endl;
        _ventaManager.consultarVentasPorFechas(); /// Acá realmente debería llevar a submenu de CONSULTAS
        //validarAlta(resultado);
        break;
    case 0:
        system("cls");
        cout << "Saliendo del menu..." << endl;
        break;
    }
}

int VentaMenu::seleccionarOpcion()
{
    int opcion;

    mostrarOpciones();
    cout << "--------------------" << endl;
    cout << "SELECCIONE UNA OPCION: ";
    cin >> opcion;

    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "---------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl;
        cout << "---------------" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
    }
    return opcion;
}

