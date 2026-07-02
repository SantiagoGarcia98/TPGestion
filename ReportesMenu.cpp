#include <iostream>
#include "ReportesMenu.h"

using namespace std;

ReportesMenu::ReportesMenu()
{
    _cantidadOpciones = 6;
}

void ReportesMenu::mostrarOpciones()
{
    cout << "----------------------------------- REPORTES -----------------------------------" << endl;

    cout << "1 - FACTURACION MENSUAL POR ANIO" << endl;
    cout << "2 - FACTURACION TOTAL EN UN RANGO DE FECHAS DETERMINADO" << endl;
    cout << "3 - FACTURACION POR VENDEDOR EN UN RANGO DE FECHAS DETERMINADO" << endl;
    cout << "4 - PORCENTAJE DE VENTAS POR TIPO DE PAGO EN UN RANGO DE FECHAS DETERMINADO" << endl;
    cout << "5 - TOP 5 AUTOS MAS VENDIDOS EN UN RANGO DE FECHAS DETERMINADO" << endl;
    cout << "6 - TOP 5 VENDEDORES CON MAS VENTAS REALIZADAS EN UN RANGO DE FECHAS DETERMINADO" << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

int ReportesMenu::seleccionarOpcion()
{
    int opcion;

    mostrarOpciones();
    cout << endl;
    cout << "SELECCIONE UNA OPCION: ";
    cin >> opcion;

    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Opcion incorrecta." << endl;
        cout << "Vuelva a intentarlo." << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
    }

    return opcion;
}

void ReportesMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
    {
        system("cls");
        int anio;
        cout << "Ingrese el anio: ";
        cin >> anio;
        cout << endl;
        _reportesManager.facturacionMensualPorAnio(anio);
        break;
    }
    case 2:
    {
        system("cls");

        Fecha desde, hasta;

        cout << "-------- FACTURACION ENTRE FECHAS --------" << endl;

        cout << "Fecha desde: " << endl;
        desde.Cargar();

        cout << endl;
        cout << "Fecha hasta:" << endl;
        hasta.Cargar();

        cout << endl;

        _reportesManager.facturacionTotalEntreFechas(desde, hasta);
        break;
    }
    case 3:
    {
        system("cls");

        Fecha desde, hasta;

        cout << "----- FACTURACION POR VENDEDOR -----" << endl << endl;

        cout << "Fecha desde:" << endl;
        desde.Cargar();
        cout << endl;
        cout << "Fecha hasta:" << endl;
        hasta.Cargar();
        cout << endl;

        _reportesManager.facturacionPorVendedorEntreFechas(desde, hasta);
        break;
    }
    case 4:
    {
        system("cls");

        Fecha desde, hasta;

        cout << "----- PORCENTAJE DE VENTAS POR TIPO DE PAGO -----" << endl << endl;

        cout << "Fecha desde:" << endl;
        desde.Cargar();
        cout << endl;
        cout << "Fecha hasta:" << endl;
        hasta.Cargar();
        cout << endl;

        _reportesManager.porcentajeVentasPorTipoPago(desde, hasta);
        break;
    }
    case 5:
    {
        system("cls");

        Fecha desde, hasta;

        cout << "-------- TOP 5 AUTOS MAS VENDIDOS --------" << endl << endl;

        cout << "Fecha desde:" << endl;
        desde.Cargar();
        cout << endl;
        cout << "Fecha hasta:" << endl;
        hasta.Cargar();

        cout << endl;

        _reportesManager.top5AutosVendidos(desde, hasta);
        break;
    }
    case 6:
    {
        system("cls");

        Fecha desde, hasta;

        cout << "--------------- TOP 5 VENDEDORES ---------------" << endl << endl;

        cout << "Fecha desde:" << endl;
        desde.Cargar();
        cout << endl;
        cout << "Fecha hasta:" << endl;
        hasta.Cargar();

        cout << endl;

        _reportesManager.top5Vendedores(desde, hasta);
        break;
    }
    case 0:
        cout << "Saliendo del menu..." << endl;
        break;
    }
}

void ReportesMenu::mostrar()
{
  int opcion;

    do
    {
        system("cls");
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
        system("pause");
    }
    while(opcion != 0);
}
