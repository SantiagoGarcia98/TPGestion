#pragma once

class TipoPago
{
private:
    int _idTipoPago;
    char _descripcion[30]; /// Efectivo - Transferencia bancaria - Tarjeta de débito - Tarjeta de Crédito - Financiación
    bool _estado;

public:
    TipoPago();

    void cargar();
    void mostrar() const;

    int getIdTipoPago() const;
    const char* getDescripcion() const;
    bool getEstado() const;

    void setIdTipoPago(int id);
    void setDescripcion(const char* d);
    void setEstado(bool e);
};
