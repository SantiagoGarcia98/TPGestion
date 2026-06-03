#pragma once
#include "Persona.h"
#include "Fecha.h"
class Vendedor : public Persona {
private:
    int _IdVendedor;
    int _legajo;
    Fecha _FechaContratacion;
    Fecha _FechaBaja;
    float _Sueldo;


public:
    Vendedor();
    void setIdVendedor(int id);
    void setLegajo (int legajo);
    void setSueldo(float s);
    void setFechaContratacion(Fecha f);
    void setFechaBaja(Fecha fb);

    int getIdVendedor();
    int getLegajo();
    float getSueldo();
    Fecha getFechaContratacion();
    Fecha getFechaBaja();
    void Cargar();
    void Mostrar();
};
