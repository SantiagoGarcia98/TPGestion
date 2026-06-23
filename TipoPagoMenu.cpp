#include <iostream>
#include "TipoPagoMenu.h"
#include "utils.h"

using namespace std;

TipoPagoMenu::TipoPagoMenu()
{
    _cantidadOpciones = 7;
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
    cout << "5 - LISTAR TIPOS DE PAGO" << endl;
    cout << "6 - LISTAR TIPOS DE PAGO ACTIVOS" << endl;
    cout << "7 - LISTAR TIPOS DE PAGO INACTIVOS" << endl;
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
        cout << "----- LISTADO DE TIPOS DE PAGO -----" << endl;
        _tipoPagoManager.listarTiposPago();
        break;
    case 6:
        system("cls");
        cout << "----- LISTADO DE TIPOS DE PAGO ACTIVOS -----" << endl;
        _tipoPagoManager.listarTiposPagoActivos();
        break;
    case 7:
        system("cls");
        cout << "----- LISTADO DE TIPOS DE PAGO INACTIVOS -----" << endl;
        _tipoPagoManager.listarTiposPagoInactivos();
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
