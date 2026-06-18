#pragma once
#include "fecha.h"

class Venta
{
private:
    int _idVenta;
    Fecha _fecha;
    int _idCliente;
    int _idVendedor;
    int _idTipoPago;
    float _montoTotal;
    bool _estado;

public:
    Venta();

    void cargar();
    void mostrar();

    int getIdVenta();
    Fecha getFecha();
    int getIdCliente();
    int getIdVendedor();
    int getIdTipoPago();
    float getMontoTotal();
    bool getEstado();

    void setIdVenta(int id);
    void setFecha(Fecha f);
    void setIdCliente(int id);
    void setIdVendedor(int id);
    void setIdTipoPago(int id);
    void setMontoTotal(float m);
    void setEstado(bool e);
};
