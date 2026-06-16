#pragma once

class Auto
{
private:
    int _idAuto;
    char _marca[30];
    char _modelo[30];
    int _anio;
    float _precio;
    int _stock; /// Archivo
    bool _estado;

public:
    Auto();
    //virtual ~Auto();

    void cargar();
    void mostrar();

    int getIdAuto();
    const char* getMarca();
    const char* getModelo();
    int getAnio();
    float getPrecio();
    int getStock();
    bool getEstado();

    void setIdAuto(int id);
    void setMarca(const char* m);
    void setModelo(const char* mo);
    void setAnio(int a);
    void setPrecio(float p);
    void setStock(int s);
    void setEstado(bool est);
};
