#include "TipoPagoManager.h"
#include "TipoPago.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;


TipoPagoManager::TipoPagoManager()
{
  //ctor
}

bool TipoPagoManager::cargarTipoPago()
{
    int idTipoPago;
    int cantRegistros;

    TipoPago reg;
    TipoPago* pTiposPago;

    cout << "----- CARGA DE NUEVO TIPO DE PAGO -----" << endl;
    cout << endl;

    if(quiereCancelar()) return false;

    idTipoPago = _repoTipoPago.getNuevoID();
    cout << "ID: #" << idTipoPago << endl;

    cantRegistros = _repoTipoPago.getCantidadRegistros();
    pTiposPago = new TipoPago[cantRegistros];
    if (pTiposPago == nullptr)
    {
        cout << endl;
        cout << "Error en la asignacion dinamica de memoria. No se pudo guardar el registro." << endl;
        cout << endl;
        return false;
    }
    _repoTipoPago.leer(pTiposPago,cantRegistros);

    bool repetido;

    do
    {
        reg.cargar();

        repetido = tipoPagoExiste(pTiposPago, cantRegistros, reg);

        if(repetido)
        {
            cout << endl;
            cout << "Ya existe un tipo de pago con esa descripcion." << endl;
            cout << "Ingrese nuevamente los datos." << endl;
            cout << endl;
        }

    }
    while(repetido);

    reg.setIdTipoPago(idTipoPago);

    delete[] pTiposPago;

    return _repoTipoPago.guardar(reg);
}

bool TipoPagoManager::modificarTipoPago()
{
    int id;
    int pos;
    int cantRegistros;

    TipoPago reg;
    TipoPago* pTiposPago;

    cout << "----- ACTUALIZACION DE TIPO DE PAGO -----" << endl;

    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a modificar: ";
        cin >> id;
        id = validarPositivo(id);

        pos = _repoTipoPago.buscar(id);

        if(pos<0)
        {
            cout << endl;
            cout << "No existe un tipo de pago con ese ID." << endl;
            cout << endl;

            system("pause");
            system("cls");

            continue;
        }

        reg = _repoTipoPago.leer(pos);

        system("cls");

        cout << "----- DATOS DEL REGISTRO A MODIFICAR -----" << endl;
        reg.mostrar();
        cout << endl;

        if(confirmarAccion("Este es el registro a modificar?"))
        {
            break;
        }
    }

    system("cls");

    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;
    cout << endl;
    cout << "ID: #" << id << endl;

    cantRegistros = _repoTipoPago.getCantidadRegistros();
    pTiposPago = new TipoPago[cantRegistros];
    if(pTiposPago == nullptr)
    {
        cout << endl;
        cout << "Error en la asignacion dinamica de memoria... No se pudo guardar el registro..." << endl;
        cout << endl;
        return false;
    }

    _repoTipoPago.leer(pTiposPago,cantRegistros);

    bool repetido;
    bool estadoOriginal = reg.getEstado();

    do
    {
        reg.cargar();

        repetido = tipoPagoExiste(pTiposPago, cantRegistros, reg, id);

        if(repetido)
        {
            cout << endl;
            cout << "Ya existe un tipo de pago con esa descripcion." << endl;
            cout << endl;
        }

    }
    while(repetido);

    reg.setIdTipoPago(id);
    reg.setEstado(estadoOriginal);

    delete[] pTiposPago;

    return _repoTipoPago.guardar(pos,reg);
}

bool TipoPagoManager::eliminarTipoPago()
{
    int id;
    int pos;
    TipoPago reg;

    cout << "----- BAJA DE TIPO DE PAGO -----" << endl;

    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a eliminar: ";
        cin >> id;
        id = validarPositivo(id);

        pos = _repoTipoPago.buscar(id);

        if(pos<0)
        {
            cout << "No existe ese registro." << endl;
            continue;
        }

        reg = _repoTipoPago.leer(pos);
        cout << "----- DATOS DEL REGISTRO A DAR DE BAJA -----" << endl;
        reg.mostrar();

        if(!reg.getEstado())
        {
            cout << endl;
            cout << "El registro ya se encuentra dado de baja." << endl;

            return false;
        }
        cout << endl;

        if(confirmarAccion("Este es el registro a eliminar?"))
        {
            break;
        }
    }

    return _repoTipoPago.eliminar(pos);
}

bool TipoPagoManager::altaTipoPago()
{
    int id;
    int pos;

    TipoPago reg;

    cout << "----- ALTA DE TIPO DE PAGO -----" << endl;

    while(true)
    {
        cout << endl;
        cout << "Ingrese ID del registro a dar de alta: ";
        cin >> id;
        id = validarPositivo(id);

        pos = _repoTipoPago.buscar(id);

        if(pos<0)
        {
            cout << "No existe ese registro." << endl;
            continue;
        }

        reg = _repoTipoPago.leer(pos);
        cout << "----- DATOS DEL REGISTRO A DAR DE ALTA -----" << endl;
        reg.mostrar();

        if(reg.getEstado())
        {
            cout << endl;
            cout << "El registro ya se encuentra activo." << endl;

            return false;
        }
        cout << endl;

        if(confirmarAccion("Este es el registro a dar de alta?"))
        {
            break;
        }
    }

    return _repoTipoPago.alta(pos);
}

void TipoPagoManager::listarTiposPago() /// Listar todos los reg
{
    int cant = _repoTipoPago.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay registros." << endl;
        return;
    }

    for(int i=0;i<cant;i++)
    {
        TipoPago reg = _repoTipoPago.leer(i);
        reg.mostrar();
        cout << endl;
    }
}

void TipoPagoManager::listarTiposPagoActivos() /// Listar solo los reg activos
{
    int cant = _repoTipoPago.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay registros." << endl;
        return;
    }

    for(int i=0;i<cant;i++)
    {
        TipoPago reg = _repoTipoPago.leer(i);

        if(reg.getEstado())
        {
            reg.mostrar();
            cout << endl;
        }
    }
}

void TipoPagoManager::listarTiposPagoInactivos() /// Listar solo los reg inactivos
{
    int cant = _repoTipoPago.getCantidadRegistros();

    if(cant==0)
    {
        cout << "No hay autos registrados." << endl;
        return;
    }

    for(int i=0;i<cant;i++)
    {
        TipoPago reg = _repoTipoPago.leer(i);

        if(!reg.getEstado())
        {
            reg.mostrar();
            cout << endl;
        }
    }
}

bool TipoPagoManager::tipoPagoExiste(TipoPago* pTiposPago, int cant, const TipoPago& tipoBuscado, int idActual)
{
    for(int i=0; i<cant; i++)
    {
        if(pTiposPago[i].getIdTipoPago() != idActual &&
                _stricmp(pTiposPago[i].getDescripcion(), tipoBuscado.getDescripcion()) == 0) /// _stricmp para no distinguir mayúsculas de minusculas
        {
            return true;
        }
    }
    return false;
}
