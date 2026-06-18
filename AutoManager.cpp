#include "AutoManager.h"
#include "Auto.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;


AutoManager::AutoManager()
{
  //ctor
}

bool AutoManager::cargarAuto()
{
      int idAuto, cantRegistros;
      Auto reg;
      Auto *pAutos;

      cout << "----- CARGA DE NUEVO AUTO -----" << endl;
      cout << endl;

      if(quiereCancelar()) return false;

      idAuto = _repoAuto.getNuevoID();
      cout << "ID: #" << idAuto << endl;

      reg.cargar();

      /*
      cantRegistros = _repoAuto.getCantidadRegistros();
      pAutos = new Auto[cantRegistros];
      if (pAutos == nullptr)
      {
          cout << endl;
          cout << "Error en la asignacion dinamica de memoria. No se pudo guardar el registro." << endl;
          cout << endl;
          return false;
      }
      _repoAuto.leer(pAutos, cantRegistros);
      */

      reg.setIdAuto(idAuto);
      /// reg.setModelo(validarModelo(); VER
      /// VER

      /*
      delete [] pAutos;
      */

      return _repoAuto.guardar(reg);
}

bool AutoManager::modificarAuto()
{
    int id, cantRegistros;
    Auto reg;
    Auto *pAutos;

    cout << "----- ACTUALIZACIÓN DE AUTO -----" << endl;

    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a modificar: ";
        cin >> id;
        id = validarPositivo(id);
        reg = _repoAuto.leer(id - 1);
        while(reg.getIdAuto() == 0)
        {
            cout << endl;
            cout << "No existe un auto registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            cout << "Ingrese ID del registro a modificar: ";
            cin >> id;
            id = validarPositivo(id);
            reg = _repoAuto.leer(id - 1);
        }
        system("cls");
        cout << "----- DATOS DEL REGISTRO A MODIFICAR -----" << endl;
        reg.mostrar();
        cout << endl;
        if (confirmarAccion("Este es el registro a modificar?")) break; /// POSIBILIDAD DE SUMAR CONFIRMACIÓN DE ACCIÓN
    }

    system("cls");
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;

    cout << endl;
    cout << "ID: #" << id << endl;
    reg.cargar();

    /*
    cantRegistros = _repoAuto.getCantidadRegistros();
    pAutos = new Auto[cantRegistros];
    if(pAutos == nullptr)
    {
        cout << endl;
        cout << "Error en la asignacion dinamica de memoria... No se pudo guardar el registro..." << endl;
        cout << endl;
        return false;
    }
    _repoAuto.leer(pAutos, cantRegistros);
    */


    /// reg.setModelo(validarAuto(); VER
    /// VER

    /*
    delete [] pAutos;
    */

    return _repoAuto.guardar(id-1, reg);

    /// Agregar para no modificar autos dado de baja
}

bool AutoManager::eliminarAuto()
{
    int id;
    Auto reg;

    cout << "-------- BAJA DE AUTO --------" << endl;
    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a eliminar: ";
        cin >> id;
        id = validarPositivo(id);
        reg = _repoAuto.leer(id - 1);
        while(reg.getIdAuto() == 0)
        {
            cout << endl;
            cout << "No existe un auto registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            cout << "Ingrese ID del registro a eliminar: ";
            cin >> id;
            id = validarPositivo(id);
            reg = _repoAuto.leer(id - 1);
        }
        system("cls");
        cout << "----- DATOS DEL REGISTRO A DAR DE BAJA -----" << endl;
        reg.mostrar();
        if(!reg.getEstado())
        {
            cout << endl;
            cout << "El registro ya se encuentra dado de baja..." << endl;
            return false;
        }
        cout << endl;
        if (confirmarAccion("Este es el registro a eliminar?")) break;
    }

    return _repoAuto.eliminar(id-1);
}

bool AutoManager::altaAuto()
{
    int id;
    Auto reg;

    cout << "-------- ALTA DE AUTO --------" << endl;
    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a dar de alta: ";
        cin >> id;
        id = validarPositivo(id);
        reg = _repoAuto.leer(id - 1);
        while(reg.getIdAuto() == 0)
        {
            cout << endl;
            cout << "No existe un auto registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            cout << "Ingrese ID del registro a eliminar: ";
            cin >> id;
            id = validarPositivo(id);
            reg = _repoAuto.leer(id - 1);
        }
        system("cls");
        cout << "----- DATOS DEL REGISTRO A DAR DE ALTA -----" << endl;
        reg.mostrar();
        if(reg.getEstado())
        {
            cout << endl;
            cout << "El registro ya se encuentra dado de alta..." << endl;
            return false;
        }
        cout << endl;
        if (confirmarAccion("Este es el registro a dar de alta?")) break;
    }

    return _repoAuto.alta(id-1);
}

void AutoManager::listarAutos()
{

}

void AutoManager::listarAutosActivos()
{

}

void AutoManager::listarAutosInactivos()
{

}


bool AutoManager::bool validarAuto(Auto *pAutos, int cant, const char* marca, const char* modelo, int anio, int idActual)
{
    for(int i=0; i<cant, i++)
    {
        if(pAutos[i].getIdAuto() == idActual)
    }
}
