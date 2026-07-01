#include "VentaArchivo.h"
#include <cstdio> ///

using namespace std;

VentaArchivo::VentaArchivo(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int VentaArchivo::getCantidadRegistros()
{
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    int cant = ftell(pArchivo) / sizeof(Venta);
    fclose(pArchivo);
    return cant;
}

int VentaArchivo::getNuevoID()
{
    int cant = getCantidadRegistros();

    if(cant==0)
        return 1;

    Venta ultimo = leer(cant-1);

    return ultimo.getIdVenta()+1;
}

int VentaArchivo::buscar(int id)
{
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;

    Venta reg;
    int pos = 0;

    while(fread(&reg, sizeof(Venta), 1, pArchivo))
    {
        if(reg.getIdVenta() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }

    fclose(pArchivo);
    return -1;
}

Venta VentaArchivo::leer(int pos)
{
    Venta reg;

    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return reg;

    fseek(pArchivo, sizeof(Venta)*pos, SEEK_SET);
    fread(&reg, sizeof(Venta), 1, pArchivo);

    fclose(pArchivo);

    return reg;
}

int VentaArchivo::leer(Venta vec[], int cant)
{
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;

    int resultado = fread(vec, sizeof(Venta), cant, pArchivo);
    fclose(pArchivo);

    return resultado;
}

bool VentaArchivo::guardar(Venta reg)
{
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return -1;
    bool resultado = fwrite(&reg, sizeof(Venta), 1, pArchivo);

    fclose(pArchivo);
    return resultado;
}

bool VentaArchivo::guardar(int pos, Venta reg)
{
    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return -1;

    fseek(pArchivo, sizeof(Venta)*pos, SEEK_SET);

    bool resultado = fwrite(&reg, sizeof(Venta), 1, pArchivo);

    fclose(pArchivo);
    return resultado;
}

bool VentaArchivo::eliminar(int pos)
{
    Venta reg = leer(pos);

    if(reg.getIdVenta() == 0)
        return false;

    reg.setEstado(false);

    return guardar(pos, reg);
}

bool VentaArchivo::alta(int pos)
{
    Venta reg = leer(pos);

    if(reg.getIdVenta() == 0)
        return false;

    reg.setEstado(true);

    return guardar(pos, reg);
}

bool VentaArchivo::existeTipoPagoEnVentas(int idTipoPago)
{
    int cant = getCantidadRegistros();

    for(int i=0; i<cant; i++)
    {
        Venta reg = leer(i);

        if(reg.getEstado() && reg.getIdTipoPago() == idTipoPago)
        {
            return true;
        }
    }
    return false;
}
