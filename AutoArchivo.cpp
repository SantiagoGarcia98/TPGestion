#include "AutoArchivo.h"
#include <iostream>

using namespace std;

AutoArchivo::AutoArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool AutoArchivo::actualizarStock(int idAuto, int cantidad)
{
    int pos = buscar(idAuto);

    if(pos<0)
        return false;

    Auto reg = leer(pos);
    reg.setStock(cantidad);
    return guardar(pos, reg);
}

bool AutoArchivo::descontarStock(int idAuto, int cantidad)
{
    int pos = buscar(idAuto);

    if(pos<0)
        return false;

    Auto reg = leer(pos);

    if(reg.getStock() < cantidad)
        return false;

    reg.setStock(reg.getStock() - cantidad);
    return guardar(pos, reg);
}

bool AutoArchivo::reponerStock(int idAuto, int cantidad)
{
    int pos = buscar(idAuto);

    if(pos<0)
        return false;

    Auto reg = leer(pos);
    reg.setStock(reg.getStock() + cantidad);
    return guardar(pos, reg);
}

int AutoArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Auto);
    fclose(pArchivo);
    return cantidad;
}

/*
int AutoArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}
*/

int AutoArchivo::getNuevoID()
{
    int cant = getCantidadRegistros();
    if(cant==0) return 1;
    Auto ultimo = leer(cant-1);
    return ultimo.getIdAuto()+1;
}

int AutoArchivo::buscar(int id)
{
    Auto reg;
    int pos = 0;

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg, sizeof(Auto), 1, pArchivo))
    {
        if(reg.getIdAuto() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Auto AutoArchivo::leer(int pos)
{
    Auto reg;

    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return reg;
    fseek(pArchivo, sizeof(Auto) * pos, SEEK_SET);
    fread(&reg, sizeof(Auto), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int AutoArchivo::leer(Auto autos[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(autos, sizeof(Auto), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool AutoArchivo::guardar(Auto reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Auto), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool AutoArchivo::guardar(int pos, Auto reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Auto) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Auto), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool AutoArchivo::eliminar(int pos)
{
    Auto reg = leer(pos);
    if(reg.getIdAuto() != 0)
    {
        reg.setEstado(false);
        return guardar(pos, reg);
    }
    return false;
}

bool AutoArchivo::alta(int pos)
{
    Auto reg = leer(pos);
    if(reg.getIdAuto() != 0)
    {
        reg.setEstado(true);
        return guardar(pos, reg);
    }
    return false;
}
