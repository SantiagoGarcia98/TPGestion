#pragma once
#include "AutoArchivo.h"

class AutoManager
{
private:
    AutoArchivo _repoAuto;

    /// std::string validarMarca();
    std::string validarModelo();

public:
    AutoManager(); ///
    bool cargarAuto(); /// OK
    bool modificarAuto(); /// OK
    bool eliminarAuto(); /// Definir
    bool altaAuto(); /// Definir
};
