#include "ClienteArchivo.h"
#include <string>
#include <cstring>


ClienteArchivo::ClienteArchivo( std::string  nombreArchivo)
: _nombreArchivo(nombreArchivo){
}
// guarda registro
bool ClienteArchivo::guardar( Cliente registro) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(pFile == nullptr) {

            return false;}
    bool ok = fwrite(&registro, sizeof(Cliente), 1, pFile);
    fclose(pFile);
    return ok;
}
// guarda, modifica sobreescribe
bool ClienteArchivo::guardar(int pos,  Cliente registro) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(pFile == nullptr) {
            return false;}
    fseek(pFile, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Cliente), 1, pFile);
    fclose(pFile);
    return ok;
}
// cliente por posicion
Cliente ClienteArchivo::leer(int pos) {
    Cliente reg;
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) {
        reg.setIdCliente(-1);
        return reg;
    }
    fseek(pFile, pos * sizeof(Cliente), SEEK_SET);
    if(!fread(&reg, sizeof(Cliente), 1, pFile)) {
        reg.setIdCliente(-1);
    }
    fclose(pFile);
    return reg;
}
// lee todos los clientes
int ClienteArchivo::leerTodos(Cliente vec[], int cantidad) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return 0;
    int leidos = fread(vec, sizeof(Cliente), cantidad, pFile);
    fclose(pFile);
    return leidos;
}
// cant de registros
int ClienteArchivo::getCantidadRegistros() {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) {
            return 0;}
    //POSICIONA EL CURSOR EN EL FINAL DEL ARCHIVO
    fseek(pFile, 0, SEEK_END);
    //FTELL DA EL BITE DONDE ESTA EL CURSOR ACTUALMENTE
    int cantidad = ftell(pFile) / sizeof(Cliente);
    fclose(pFile);
    return cantidad;
}

int ClienteArchivo::getNuevoID() {
    int cant = getCantidadRegistros();
    if(cant == 0) return 1;

    //lee el ultimo registro
    Cliente ult = leer(cant - 1);

    //si pudo leer
    if(ult.getIdCliente() == -1) return 1;
    return ult.getIdCliente() + 1;
}

int ClienteArchivo::buscarPorID(int id) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;
    Cliente reg;
    int pos = -1;
    while(fread(&reg, sizeof(Cliente), 1, pFile)) {
        if(reg.getIdCliente() == id) {
            pos = ftell(pFile)/sizeof(Cliente) - 1;
            break;
        }
    }
    fclose(pFile);
    return pos;
}

int ClienteArchivo::buscarPorDNI( char *dni) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;
    Cliente reg;
    int pos = -1;
    while(fread(&reg, sizeof(Cliente), 1, pFile)) {
        if(strcmp(reg.getDni(), dni) == 0) {
            pos = ftell(pFile)/sizeof(Cliente) - 1;
            break;
        }
    }
    fclose(pFile);
    return pos;
}

bool ClienteArchivo::eliminar(int pos) {
    Cliente cliente = leer(pos);
    if(cliente.getIdCliente() == -1) return false;
    cliente.setEstado(false);
    return guardar(pos, cliente);
}
