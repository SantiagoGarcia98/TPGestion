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
    void mostrar() const;

    int getIdAuto() const;
    const char* getMarca() const;
    const char* getModelo() const;
    int getAnio() const;
    float getPrecio() const;
    int getStock() const;
    bool getEstado() const;

    void setIdAuto(int id);
    void setMarca(const char* m);
    void setModelo(const char* mo);
    void setAnio(int a);
    void setPrecio(float p);
    void setStock(int s);
    void setEstado(bool est);
};
