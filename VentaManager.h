#pragma once

#include "VentaArchivo.h"
#include "ClienteArchivo.h"
#include "vendedorArchivo.h"
#include "AutoArchivo.h"
#include "TipoPagoArchivo.h"
#include "DetalleVentaArchivo.h"

class VentaManager
{
private:
    VentaArchivo _repoVenta;
    ClienteArchivo _repoCliente;
    VendedorArchivo _repoVendedor;
    AutoArchivo _repoAuto;
    TipoPagoArchivo _repoTipoPagos;

    DetalleVentaArchivo _repoDetalle;

public:
    VentaManager();

    void nuevaVenta(); /// Acá va toda la lógica (sería el Cargar()), creo que 1ro en memoria y luego paso a archivo, ver
    void listarVentas();
    void mostrarVentaCompleta(int idVenta);
};
