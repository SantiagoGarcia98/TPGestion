#pragma once


class TipoPago
{
private:
    int _idTipoPago;
    char _descripcion[30];
    bool _estado;

public:
    TipoPago();

    void cargar();
    void mostrar();

    int getIdTipoPago();
    const char* getDescripcion();
    bool getEstado();

    void setIdTipoPago(int id);
    void setDescripcion(const char* d);
    void setEstado(bool e);
};
