#pragma once

class DetalleVenta
{
private:
    int _idDetalleVenta;
    int _idVenta;
    int _idAuto;
    int _cantidad;
    float _precioHistorico;
    float _subtotal;
    bool _estado;

public:
    DetalleVenta();

    void cargar();
    void mostrar();

    int getIdDetalleVenta();
    int getIdVenta();
    int getIdAuto();
    int getCantidad();
    float getPrecioHistorico();
    float getSubtotal();
    bool getEstado();

    void setIdDetalleVenta(int id);
    void setIdVenta(int id);
    void setIdAuto(int id);
    void setCantidad(int c);
    void setPrecioHistorico(float p);
    void setSubtotal(float sub);
    void setEstado(bool e);
};
