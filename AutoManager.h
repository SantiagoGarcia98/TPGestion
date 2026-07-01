#pragma once
#include "AutoArchivo.h"

class AutoManager
{
private:
    AutoArchivo _repoAuto;

    /// std::string validarMarca(); /// Marca no validaría, si modelo, ver
    ///Auto validarAuto(Auto *pAutos, int cant, const char* marca, const char* modelo, int anio, int idActual); /// Definir QUEDE ACÁ
    bool autoExiste(Auto *pAutos, int cant, const Auto& autoBuscado, int idActual = 0);

public:
    AutoManager(); ///

    bool cargarAuto(); /// OK
    bool modificarAuto(); /// OK

    bool eliminarAuto(); /// OK
    bool altaAuto(); /// OK

    /// LISTADOS
    void listarAutos(); /// OK, permite listar activos, inactivos, todos
    void ordenadosPorMarcaYModelo(); /// Ok
    void ordenadosPorAnio(); /// OK, de más nuevo a más antiguo
    void ordenadosPorPrecio(); /// OK, de manera descendente

    /// CONSULTAS
    void consultarAutoPorMarcaYModelo(); /// OK
    void consultarAutoPorAnio(); /// OK
    void consultarAutoPorRangoPrecio(); /// OK
    void consultarAutoPorDisponibilidad(); /// OK
};
