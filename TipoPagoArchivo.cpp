#include "TipoPagoArchivo.h"
#include <iostream>

using namespace std;

TipoPagoArchivo::TipoPagoArchivo(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int TipoPagoArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(TipoPago);
    fclose(pArchivo);
    return cantidad;
}

int TipoPagoArchivo::getNuevoID()
{
    int cant = getCantidadRegistros();
    if(cant==0) return 1;
    TipoPago ultimo = leer(cant-1);
    return ultimo.getIdTipoPago()+1;
}

int TipoPagoArchivo::buscar(int id)
{
    TipoPago reg;
    int pos = 0;

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg,sizeof(TipoPago),1,pArchivo))
    {
        if(reg.getIdTipoPago() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

TipoPago TipoPagoArchivo::leer(int pos)
{
    TipoPago reg;

    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"rb");
    if(pArchivo == nullptr) return reg;
    fseek(pArchivo,sizeof(TipoPago)*pos,SEEK_SET);
    fread(&reg,sizeof(TipoPago),1,pArchivo);
    fclose(pArchivo);
    return reg;
}

int TipoPagoArchivo::leer(TipoPago registros[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(registros,sizeof(TipoPago),cantidad,pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoPagoArchivo::guardar(TipoPago reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(TipoPago), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoPagoArchivo::guardar(int pos, TipoPago reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(),"rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo,sizeof(TipoPago)*pos,SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(TipoPago), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoPagoArchivo::eliminar(int pos)
{
    TipoPago reg = leer(pos);
    if(reg.getIdTipoPago()!=0)
    {
        reg.setEstado(false);
        return guardar(pos,reg);
    }
    return false;
}

bool TipoPagoArchivo::alta(int pos)
{
    TipoPago reg = leer(pos);
    if(reg.getIdTipoPago()!=0)
    {
        reg.setEstado(true);
        return guardar(pos,reg);
    }
    return false;
}
