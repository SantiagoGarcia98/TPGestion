#pragma once
#include "AutoArchivo.h"

class AutoManager
{
private:
    AutoArchivo _repoAuto;

    /// std::string validarMarca(); /// Marca no validaría, si modelo, ver
    std::string validarModelo(); /// Definir

public:
    AutoManager(); ///
    bool cargarAuto(); /// OK
    bool modificarAuto(); /// OK
    bool eliminarAuto(); /// OK
    bool altaAuto(); /// OK
};
