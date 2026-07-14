#include <iostream>
#include "AutoMenu.h"
#include "utils.h"

using namespace std;


AutoMenu::AutoMenu()
{
    _cantidadOpciones = 6;
}

void AutoMenu::mostrar()
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

void AutoMenu::mostrarOpciones()
{
    cout << "--------------------- MENU AUTOS ---------------------" << endl;
    cout << "1 - CARGAR AUTO" << endl;
    cout << "2 - MODIFICAR AUTO" << endl;
    cout << "3 - DAR DE BAJA AUTO" << endl;
    cout << "4 - DAR DE ALTA AUTO" << endl;
    cout << "5 - LISTADO DE AUTOS" << endl;
    cout << "6 - CONSULTA DE AUTOS" << endl;
    cout << "0 - SALIR" << endl;
    cout << "------------------------------------------------------" << endl;
}

void AutoMenu::ejecutarOpcion(int opcion)
{
    bool resultado;

    switch(opcion)
    {
    case 1:
      system("cls");
        resultado = _autoManager.cargarAuto();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _autoManager.modificarAuto();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _autoManager.eliminarAuto();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _autoManager.altaAuto();
        validarAlta(resultado);
        break;
    case 5:
        system("cls");
        menuListados();
        break;
    case 6:
        system("cls");
        menuConsultas();
        break;
    case 0:
        system("cls");
        cout << "Saliendo del menu..." << endl;
        break;
    }
}

/*
int AutoMenu::seleccionarOpcion()
{
    int opcion;

    mostrarOpciones();
    cout << "SELECCIONE UNA OPCION: ";
    cin >> opcion;

    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
    }
    return opcion;
}
*/

int AutoMenu::seleccionarOpcion()
{
    mostrarOpciones();
    return ingresarEntero("SELECCIONE UNA OPCION: ", 0, _cantidadOpciones);
}


void AutoMenu::menuListados()
{
    int opcion;

    do
    {
        system("cls");

        cout << "---------- LISTADOS DE AUTOS ----------" << endl;
        cout << "1 - Activos" << endl;
        cout << "2 - Inactivos" << endl;
        cout << "3 - Todos" << endl;
        cout << "4 - Ordenados por marca y modelo alfabeticamente" << endl;
        cout << "5 - Ordenados por anio de manera descendente" << endl;
        cout << "6 - Ordenados por precio de manera descendente" << endl;
        cout << "0 - Volver" << endl << endl;
        /*
        cout << "Opcion: ";
        cin >> opcion;
        */
        opcion = ingresarEntero("Opcion: ", 0, 6);
        cout << endl;

        switch(opcion)
        {
        case 1:
            _autoManager.listarAutosActivos();
            break;
        case 2:
            _autoManager.listarAutosInactivos();
            break;
        case 3:
            _autoManager.listarTodosLosAutos();
            break;
        case 4:
            _autoManager.ordenadosPorMarcaYModelo();
            break;
        case 5:
            _autoManager.ordenadosPorAnio();
            break;
        case 6:
            _autoManager.ordenadosPorPrecio();
            break;
        case 0:
            break;
        }

        if(opcion != 0)
            system("pause");

    } while(opcion != 0);
}

void AutoMenu::menuConsultas()
{
    int opcion;

    do
    {
        system("cls");

        cout << "---------- CONSULTAS DE AUTOS ----------" << endl;
        cout << "1 - Buscar por marca y modelo" << endl;
        cout << "2 - Buscar por anio" << endl;
        cout << "3 - Buscar por rango de precios" << endl;
        cout << "4 - Buscar por disponibilidad" << endl;
        cout << "0 - Volver" << endl << endl;
        /*
        cout << "Opcion: ";
        cin >> opcion;
        */
        opcion = ingresarEntero("Opcion: ", 0, 4);
        cout << endl;

        switch(opcion)
        {
        case 1:
            _autoManager.consultarAutoPorMarcaYModelo();
            break;
        case 2:
            _autoManager.consultarAutoPorAnio();
            break;
        case 3:
            _autoManager.consultarAutoPorRangoPrecio();
            break;
        case 4:
            _autoManager.consultarAutoPorDisponibilidad();
            break;
        case 0:
            break;
        }

        if(opcion != 0)
            system("pause");

    } while(opcion != 0);
}
