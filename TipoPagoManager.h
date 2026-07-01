#pragma once
#include "TipoPagoArchivo.h"
#include "VentaArchivo.h"
#include <cstring>

class TipoPagoManager
{
private:
    TipoPagoArchivo _repoTipoPago;
    VentaArchivo _repoVenta;

    bool tipoPagoExiste(TipoPago* pTiposPago, int cant, const TipoPago& tipoBuscado, int idActual = 0);

public:
    TipoPagoManager();

    bool cargarTipoPago();
    bool modificarTipoPago();

    bool eliminarTipoPago();
    bool altaTipoPago();

    void listarTiposPago();
    void listarTiposPagoActivos();
    void listarTiposPagoInactivos();
};
