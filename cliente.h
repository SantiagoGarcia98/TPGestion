#pragma once

class Cliente : public Persona {
private:
    int _IdCliente;

public:
    Cliente();

    void setIdCliente(int id);
    int getIdCliente();
    void Cargar() ;
    void Mostrar() ;


};

