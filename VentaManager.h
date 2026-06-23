#pragma once

#include "VentaArchivo.h"
#include "ClienteArchivo.h"
#include "AutoArchivo.h"
#include "TipoPagoArchivo.h"
#include "DetalleVentaArchivo.h"

class VentaManager
{
private:
    VentaArchivo _archivo;
    ClienteArchivo _clientes;
    AutoArchivo _autos;
    TipoPagoArchivo _pagos;

    DetalleVentaArchivo _detalles;

public:
    VentaManager();

    void nuevaVenta();
    void listarVentas();
};
