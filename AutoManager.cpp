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
      /// reg.setModelo(reg.getModelo);
      /// VER

      delete [] pAutos;
      return _repoAuto.guardar(reg);
}

bool AutoManager::modificarAuto()
{
/*
    int idAuto, cantRegistros;
      Auto reg;
      Auto *pAutos;

      cout << "----- ACTUALIZACIÓN DE AUTO -----" << endl;

      while(true)
      {
          cout << endl;
          if
      }
*/
}

bool AutoManager::eliminarAuto()
{

}

bool AutoManager::altaAuto()
{

}
