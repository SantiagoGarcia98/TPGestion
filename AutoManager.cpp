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

      reg.setIdAuto(idAuto);
      /// reg.setModelo(validarModelo(); VER
      /// VER

      delete [] pAutos;
      return _repoAuto.guardar(reg);
}

bool AutoManager::modificarAuto()
{
    int id, idAuto, cantRegistros;
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


    /// reg.setModelo(validarModelo(); VER
    /// VER

    delete [] pAutos;
    return _repoAuto.guardar(id-1, reg);

    /// Agregar para no modificar autos dado de baja
}

bool AutoManager::eliminarAuto()
{

}

bool AutoManager::altaAuto()
{

}
