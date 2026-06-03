#pragma once
#include <string>

class Fecha {
public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    void setDia(int dia);

    int getMes();
    void setMes(int mes);

    int getAnio();
    void setAnio(int anio);

    std::string toString();
    void Cargar();
    void Mostrar();

    bool esBisiesto(int anio);
    bool esFechaValida(int dia, int mes, int anio);

private:
    int _dia;
    int _mes;
    int _anio;
};
