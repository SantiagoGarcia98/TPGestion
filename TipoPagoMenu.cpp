#include <iostream>
#include "TipoPagoMenu.h"
#include "utils.h"

using namespace std;

TipoPagoMenu::TipoPagoMenu()
{
    _cantidadOpciones = 5;
}

void TipoPagoMenu::mostrar()
{
    int opcion;
    do
    {
        system("cls");
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
        system("pause");
    } while(opcion != 0);
}

void TipoPagoMenu::mostrarOpciones()
{
    cout << "----- MENU TIPOS DE PAGO -----" << endl;

    cout << "1 - NUEVO TIPO DE PAGO" << endl;
    cout << "2 - MODIFICAR TIPO DE PAGO" << endl;
    cout << "3 - ELIMINAR TIPO DE PAGO" << endl;
    cout << "4 - ALTA TIPO DE PAGO" << endl;
    cout << "5 - LISTADOS DE TIPOS DE PAGO" << endl;
    cout << "------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "------------------------------" << endl;
}



void TipoPagoMenu::ejecutarOpcion(int opcion)
{
    bool resultado;

    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _tipoPagoManager.cargarTipoPago();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _tipoPagoManager.modificarTipoPago();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _tipoPagoManager.eliminarTipoPago();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _tipoPagoManager.altaTipoPago();
        validarAlta(resultado);
        break;
    case 5:
        system("cls");
        menuListados();
        break;
    case 0:
        system("cls");
        cout << "Saliendo del menu..." << endl;
        break;
    }
}

int TipoPagoMenu::seleccionarOpcion()
{
    int opcion;

    mostrarOpciones();
    cout << "--------------------" << endl;
    cout << "SELECCIONE UNA OPCION: ";
    cin >> opcion;

    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "------------------------------" << endl;
        cout << "Opcion incorrecta." << endl;
        cout << "Vuelva a intentarlo." << endl;
        cout << "------------------------------" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
    }
    return opcion;
}

void TipoPagoMenu::menuListados()
{
    int opcion;

    do
    {
        system("cls");

        cout << "----- LISTADOS DE TIPOS DE PAGO -----" << endl;
        cout << "1 - Listar todos" << endl;
        cout << "2 - Listar activos" << endl;
        cout << "3 - Listar inactivos" << endl;
        cout << "0 - Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
        case 1:
            _tipoPagoManager.listarTiposPago();
            break;

        case 2:
            _tipoPagoManager.listarTiposPagoActivos();
            break;

        case 3:
            _tipoPagoManager.listarTiposPagoInactivos();
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
