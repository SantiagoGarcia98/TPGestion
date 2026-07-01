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
        menuListados();
        break;
    case 4:
        system("cls");
        menuConsultas();
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

void VentaMenu::menuListados()
{
    int opcion;

    do
    {
        system("cls");

        cout << "----- LISTADO DE VENTAS -----" << endl;
        cout << "1 - Listar ventas" << endl;
        cout << "2 - Mostrar venta completa" << endl;
        cout << "3 - Listar por fecha" << endl;
        cout << "4 - Listar por monto" << endl;
        cout << "0 - Volver" << endl;
        cout << "-----------------------------" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
        case 1:
            _ventaManager.listarVentas();
            break;
        case 2:
        {
            int idVenta;
            cout << "ID de la venta: ";
            cin >> idVenta;
            cout << endl;
            _ventaManager.mostrarVentaCompleta(idVenta);
            break;
        }
        case 3:
            _ventaManager.listarVentaPorFecha();
            break;
        case 4:
            _ventaManager.listarVentaPorMonto();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }

        if(opcion != 0)
            system("pause");

    }
    while(opcion != 0);
}

void VentaMenu::menuConsultas()
{
    int opcion;

    do
    {
        system("cls");

        cout << "----- CONSULTAS DE VENTAS -----" << endl;
        cout << "1 - Consultar por fechas" << endl;
        cout << "2 - Consultar por cliente" << endl;
        cout << "3 - Consultar por vendedor" << endl;
        cout << "4 - Consultar por auto vendido" << endl;
        cout << "0 - Volver" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
        case 1:
            _ventaManager.consultarVentasPorFechas();
            break;
        case 2:
            _ventaManager.consultarVentaPorCliente();
            break;
        case 3:
            _ventaManager.consultarVentaPorVendedor();
            break;
        case 4:
            _ventaManager.consultarVentaPorAutoVendido();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }

        if(opcion != 0)
            system("pause");

    }
    while(opcion != 0);
}
