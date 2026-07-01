#include "VendedorArchivo.h"
#include "Vendedor.h"
#include <cstdio>
#include <cstring>

VendedorArchivo::VendedorArchivo(std::string nombreArchivo)
: _nombreArchivo(nombreArchivo) {}

bool VendedorArchivo::guardar(Vendedor registro) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) return false;
    bool ok = fwrite(&registro, sizeof(Vendedor), 1, pFile);
    fclose(pFile);
    return ok;
}

bool VendedorArchivo::guardar(int pos, Vendedor registro) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == nullptr) return false;
    fseek(pFile, pos * sizeof(Vendedor), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Vendedor), 1, pFile);
    fclose(pFile);
    return ok;
}

Vendedor VendedorArchivo::leer(int pos) {
    Vendedor reg;
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        reg.setIdVendedor(-1);
        return reg;
    }
    fseek(pFile, pos * sizeof(Vendedor), SEEK_SET);
    if (!fread(&reg, sizeof(Vendedor), 1, pFile)) {
        reg.setIdVendedor(-1);
    }
    fclose(pFile);
    return reg;
}

int VendedorArchivo::leerTodos(Vendedor vec[], int cantidad) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) return 0;
    int leidos = fread(vec, sizeof(Vendedor), cantidad, pFile);
    fclose(pFile);
    return leidos;
}

int VendedorArchivo::getCantidadRegistros() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) return 0;
    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(Vendedor);
    fclose(pFile);
    return cantidad;
}

int VendedorArchivo::getNuevoID() {
    int cant = getCantidadRegistros();
    if (cant == 0) return 1;
    Vendedor ult = leer(cant - 1);
    if (ult.getIdVendedor() == -1) return 1;
    return ult.getIdVendedor() + 1;
}

int VendedorArchivo::buscarPorID(int id) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) return -1;
    Vendedor reg;
    int pos = -1;
    while (fread(&reg, sizeof(Vendedor), 1, pFile)) {
        if (reg.getIdVendedor() == id) {
            pos = ftell(pFile) / sizeof(Vendedor) - 1;
            break;
        }
    }
    fclose(pFile);
    return pos;
}

bool VendedorArchivo::eliminar(int pos) {
    Vendedor vendedor = leer(pos);
    if (vendedor.getIdVendedor() == -1) return false;
    vendedor.setEstado(false);
    return guardar(pos, vendedor);
}
