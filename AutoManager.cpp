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

bool AutoManager::autoExiste(Auto *pAutos, int cant, const Auto& autoBuscado, int idActual)
{
    for(int i=0; i<cant; i++)
    {
        if(pAutos[i].getIdAuto() != idActual &&
                strcmp(pAutos[i].getMarca(), autoBuscado.getMarca()) == 0 &&
                strcmp(pAutos[i].getModelo(), autoBuscado.getModelo()) == 0 &&
                pAutos[i].getAnio() == autoBuscado.getAnio())
        {
            return true;
        }
    }
    return false;

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

    bool repetido;

    do
    {
        reg.cargar();

        repetido = autoExiste(pAutos, cantRegistros, reg);

        if(repetido)
        {
            cout << endl;
            cout << "Ya existe un auto con esa marca, modelo y anio." << endl;
            cout << "Ingrese nuevamente los datos." << endl;
            cout << endl;
        }

    }
    while(repetido);

    reg.setIdAuto(idAuto);

    delete [] pAutos;

    return _repoAuto.guardar(reg);
}

bool AutoManager::modificarAuto()
{
    int id, pos, cantRegistros;
    Auto reg;
    Auto *pAutos;

    cout << "----- ACTUALIZACIÓN DE AUTO -----" << endl;

    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a modificar: ";
        cin >> id;
        id = validarPositivo(id);

        pos = _repoAuto.buscar(id);

        if(pos<0)
        {
            cout << endl;
            cout << "No existe un auto registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            continue;
        }

        reg = _repoAuto.leer(pos);

        system("cls");
        cout << "----- DATOS DEL REGISTRO A MODIFICAR -----" << endl;
        reg.mostrar();
        cout << endl;

        if(confirmarAccion("Este es el registro a modificar?")) /// POSIBILIDAD DE SUMAR CONFIRMACIÓN DE ACCIÓN
        {
            break;
        }
    }

    system("cls");
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;

    cout << endl;
    cout << "ID: #" << id << endl;
/// reg.cargar();

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

    bool repetido;
    bool estadoOriginal = reg.getEstado();

    do
    {
        reg.cargar();

        repetido = autoExiste(pAutos, cantRegistros, reg, id);

        if(repetido)
        {
            cout << endl;
            cout << "Ya existe un auto con esa marca, modelo y anio." << endl;
            cout << "Ingrese nuevamente los datos." << endl;
            cout << endl;
        }

    }
    while (repetido);

    reg.setIdAuto(id);
    reg.setEstado(estadoOriginal);

    delete [] pAutos;

    return _repoAuto.guardar(pos, reg);

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

        int pos = _repoAuto.buscar(id);

        if(pos>=0)
        {
            reg = _repoAuto.leer(pos);
        }

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

        int pos = _repoAuto.buscar(id);

        if(pos>=0)
        {
            reg = _repoAuto.leer(pos);
        }

        while(reg.getIdAuto() == 0)
        {
            cout << endl;
            cout << "No existe un auto registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            system("pause");
            system("cls");
            cout << "Ingrese ID del registro a dar de alta: ";
            cin >> id;
            id = validarPositivo(id);

            int pos = _repoAuto.buscar(id);

            if(pos>=0)
            {
                reg = _repoAuto.leer(pos);
            }

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

        if (confirmarAccion("¿Este es el registro a dar de alta?")) break;
    }

    return _repoAuto.alta(id-1);
}

/// LISTADOS
/*
void AutoManager::listarAutos() /// Listar todos los reg
{
    int cant = _repoAuto.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay autos registrados." << endl << endl;
        return;
    }

    int opcion;
    cout << "1 - Listar activos" << endl;
    cout << "2 - Listar inactivos" << endl;
    cout << "3 - Listar todos" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - Salir" << endl;
    cout << "-------------------------" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    cout << endl;

     if(opcion == 0)
    {
        cout << "Saliendo del sub-menu..." << endl;
        return;
    }

    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);
        switch(opcion)
        {
        case 1:
            if(reg.getEstado())
            {
                reg.mostrar();
                cout << endl;
                encontro = true;
            }
            break;
        case 2:
            if(!reg.getEstado())
            {
                reg.mostrar();
                cout << endl;
                encontro = true;
            }
            break;
        case 3:
            reg.mostrar();
            cout << endl;
            encontro = true;
            break;
        default:
            cout << "Opcion invalida." << endl;
            return;
        }
    }

    if(!encontro)
    {
        switch(opcion)
        {
        case 1:
            cout << "No hay autos activos." << endl;
            break;
        case 2:
            cout << "No hay autos inactivos." << endl;
                break;
        }
    }
}
*/

void AutoManager::listarAutosActivos()
{
  int cant = _repoAuto.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay autos registrados." << endl << endl;
        return;
    }

    cout << endl;
    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);

        if(reg.getEstado())
        {
          reg.mostrar();
          cout << endl;
          encontro = true;
        }
    }

    if(!encontro)
    {
        cout << "No hay autos activos." << endl;
    }
}

void AutoManager::listarAutosInactivos()
{
    int cant = _repoAuto.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay autos registrados." << endl << endl;
        return;
    }

    cout << endl;
    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);

        if(!reg.getEstado())
        {
          reg.mostrar();
          cout << endl;
          encontro = true;
        }
    }

    if(!encontro)
    {
        cout << "No hay autos inactivos." << endl;
    }
}

void AutoManager::listarTodosLosAutos()
{
  int cant = _repoAuto.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay autos registrados." << endl << endl;
        return;
    }

    cout << endl;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);
        reg.mostrar();
        cout << endl;
    }
}



void AutoManager::ordenadosPorMarcaYModelo()
{
    int cant = _repoAuto.getCantidadRegistros();

    if(cant == 0)
    {
        cout << "No hay autos registrados." << endl;
        return;
    }

    Auto *vec;
    vec = new Auto[cant];

    _repoAuto.leer(vec, cant);

    for(int i=0; i<cant-1; i++)
    {
        for(int x=i+1; x<cant; x++)
        {
            bool intercambiar = false;

            if(strcmp(vec[i].getMarca(), vec[x].getMarca()) > 0)
            {
                intercambiar = true;
            }
            else if(strcmp(vec[i].getMarca(), vec[x].getMarca()) == 0)
            {
                if(strcmp(vec[i].getModelo(), vec[x].getModelo()) > 0)
                {
                    intercambiar = true;
                }
            }

            if(intercambiar)
            {
                Auto aux = vec[i];
                vec[i] = vec[x];
                vec[x] = aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {
        vec[i].mostrar();
        cout << endl;
    }

    delete[] vec;
}

void AutoManager::ordenadosPorAnio()
{
    int cant = _repoAuto.getCantidadRegistros();

    if(cant == 0)
    {
        cout << "No hay autos registrados." << endl;
        return;
    }

    Auto *vec;
    vec = new Auto[cant];

    _repoAuto.leer(vec, cant);

    for(int i=0; i<cant-1; i++)
    {
        for(int x=i+1; x<cant; x++)
        {
            if(vec[i].getAnio()<vec[x].getAnio())
            {
                Auto aux = vec[i];
                vec[i] = vec[x];
                vec[x] = aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {
        vec[i].mostrar();
        cout << endl;
    }

    delete[] vec;
}

void AutoManager::ordenadosPorPrecio()
{
    int cant = _repoAuto.getCantidadRegistros();

    if(cant == 0)
    {
        cout << "No hay autos registrados." << endl;
        return;
    }

    Auto *vec;
    vec = new Auto[cant];

    _repoAuto.leer(vec, cant);

    for(int i=0; i<cant-1; i++)
    {
        for(int x=i+1; x<cant; x++)
        {
            if(vec[i].getPrecio()<vec[x].getPrecio())
            {
                Auto aux = vec[i];
                vec[i] = vec[x];
                vec[x] = aux;
            }
        }
    }

    for(int i=0; i<cant; i++)
    {
        vec[i].mostrar();
        cout << endl;
    }

    delete[] vec;
}


/// CONSULTAS

void AutoManager::consultarAutoPorMarcaYModelo()
{
    char marca[30];
    char modelo[30];

    cout << "Marca: ";
    cin.ignore();
    cin.getline(marca, 30);

    cout << "Modelo: ";
    cin.getline(modelo, 30);
    cout << endl << endl;

    int cant = _repoAuto.getCantidadRegistros();

    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);

        if(reg.getEstado() && strcmp(reg.getMarca(), marca) == 0 && strcmp(reg.getModelo(), modelo) == 0)
        {
            reg.mostrar();
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro)
    {
        cout << "No se encontraron autos con esa marca y modelo." << endl;
    }
}

void AutoManager::consultarAutoPorAnio()
{
    int anio;
    cout << "Anio: ";
    cin >> anio;
    cout << endl << endl;

    int cant = _repoAuto.getCantidadRegistros();

    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);

        if(reg.getEstado() && reg.getAnio() == anio)
        {
            reg.mostrar();
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro)
    {
        cout << "No se encontraron autos para ese anio." << endl;
    }
}

void AutoManager::consultarAutoPorRangoPrecio()
{
    float precioMin;
    float precioMax;

    cout << "Precio minimo: $ ";
    cin >> precioMin;

    cout << "Precio maximo: $ ";
    cin >> precioMax;

    if(precioMin > precioMax)
    {
        cout << "Rango de precios invalido." << endl;
        return;
    }

    cout << endl << endl;

    int cant = _repoAuto.getCantidadRegistros();

    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);

        if(reg.getEstado() && reg.getPrecio() >= precioMin && reg.getPrecio() <= precioMax)
        {
            reg.mostrar();
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro)
    {
        cout << "No se encontraron autos en ese rango de precios." << endl;
    }
}

void AutoManager::consultarAutoPorDisponibilidad()
{
    int opcion;
    cout << "1 - Disponibles" << endl;
    cout << "2 - Sin stock" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    cout << endl << endl;

    int cant = _repoAuto.getCantidadRegistros();

    bool encontro = false;

    for(int i=0; i<cant; i++)
    {
        Auto reg = _repoAuto.leer(i);

        if(!reg.getEstado())
            continue;

        if(opcion == 1 && reg.getStock() > 0)
        {
            reg.mostrar();
            cout << endl;
            encontro = true;
        }

        if(opcion == 2 && reg.getStock() == 0)
        {
            reg.mostrar();
            cout << endl;
            encontro = true;
        }
    }

    if(!encontro)
    {
        cout << "No se encontraron autos." << endl;
    }
}
