#include "DetalleVentaArchivo.h"
#include <iostream>

using namespace std;


DetalleVentaArchivo::DetalleVentaArchivo(string nombreArchivo)
{
  _nombreArchivo = nombreArchivo;
}

int DetalleVentaArchivo::getCantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"rb");

    if(pArchivo==nullptr)
        return 0;

    fseek(pArchivo, 0, SEEK_END);

    int cant = ftell(pArchivo)/sizeof(DetalleVenta);

    fclose(pArchivo);

    return cant;
}

int DetalleVentaArchivo::getNuevoID()
{
    int cant = getCantidadRegistros();

    if(cant==0)
        return 1;

    DetalleVenta ultimo = leer(cant-1);

    return ultimo.getIdDetalleVenta()+1;
}

int DetalleVentaArchivo::buscar(int id)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"rb");

    if(pArchivo==nullptr)
        return -1;

    DetalleVenta reg;
    int pos=0;

    while(fread(&reg,sizeof(DetalleVenta),1,pArchivo))
    {
        if(reg.getIdDetalleVenta()==id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

DetalleVenta DetalleVentaArchivo::leer(int pos)
{
    DetalleVenta reg;

    FILE* pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return reg;

    fseek(pArchivo, sizeof(DetalleVenta)*pos, SEEK_SET);
    fread(&reg, sizeof(DetalleVenta), 1, pArchivo);

    fclose(pArchivo);

    return reg;
}

bool DetalleVentaArchivo::guardar(DetalleVenta reg)
{
    FILE *pArchivo=fopen(_nombreArchivo.c_str(),"ab");

    if(pArchivo==nullptr)
        return false;

    bool resultado = fwrite(&reg,sizeof(DetalleVenta),1,pArchivo);

    fclose(pArchivo);

    return resultado;
}

void DetalleVentaArchivo::listarPorVenta(int idVenta)
{
    FILE *pArchivo=fopen(_nombreArchivo.c_str(),"rb");

    if(pArchivo==nullptr)
        return;

    DetalleVenta reg;

    while(fread(&reg,sizeof(DetalleVenta),1,pArchivo))
    {
        if(reg.getIdVenta()==idVenta && reg.getEstado())
        {
            reg.mostrar();
            cout<<endl;
        }
    }
    fclose(pArchivo);
}

