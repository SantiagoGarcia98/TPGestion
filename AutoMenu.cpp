#include <iostream>
#include "AutoMenu.h"
#include "utils.h"

using namespace std;


AutoMenu::AutoMenu()
{
    _cantidadOpciones = 7;
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
    cout << "----- MENU AUTOS -----" << endl;
    cout << "1 - NUEVO AUTO" << endl;
    cout << "2 - MODIFICAR AUTO" << endl;
    cout << "3 - ELIMINAR AUTO" << endl;
    cout << "4 - ALTA AUTO" << endl;
    cout << "5 - LISTAR AUTOS" << endl;
    cout << "6 - LISTAR SOLO AUTOS ACTIVOS" << endl;
    cout << "7 - LISTAR SOLO AUTOS INACTIVOS" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------" << endl;
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
        cout << "----- LISTADO DE AUTOS -----" << endl;
        _autoManager.listarAutos();
        //
        break;
    case 6:
        system("cls");
        cout << "----- LISTADO DE AUTOS ACTIVOS -----" << endl;
        _autoManager.listarAutosActivos();
        //
        break;
    case 7:
        system("cls");
        cout << "----- LISTADO DE AUTOS INACTIVOS -----" << endl;
        _autoManager.listarAutosInactivos();
        //
        break;
    case 0:
        system("cls");
        cout << "Saliendo del menu..." << endl;
        break;
    }
}

int AutoMenu::seleccionarOpcion()
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
