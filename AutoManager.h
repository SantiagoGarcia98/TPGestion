#pragma once
#include "AutoArchivo.h"

class AutoManager
{
private:
    AutoArchivo _repoAuto;

    /// std::string validarMarca(); /// Marca no validaría, si modelo, ver
    bool validarAuto(Auto *pAutos, int cant, const char* marca, const char* modelo, int anio, int idActual); /// Definir

public:
    AutoManager(); ///
    bool cargarAuto(); /// OK
    bool modificarAuto(); /// OK
    bool eliminarAuto(); /// OK
    bool altaAuto(); /// OK
    void listarAutos(); /// Definir
    void listarAutosActivos(); /// Definir
    void listarAutosInactivos(); /// Definir
};
