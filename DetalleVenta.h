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

    void mostrar() const;

    int getIdDetalleVenta() const;
    int getIdVenta() const;
    int getIdAuto() const;
    int getCantidad() const;
    float getPrecioHistorico() const;
    float getSubtotal() const;
    bool getEstado() const;

    void setIdDetalleVenta(int id);
    void setIdVenta(int id);
    void setIdAuto(int id);
    void setCantidad(int c);
    void setPrecioHistorico(float p);
    void setSubtotal(float sub);
    void setEstado(bool e);
};
