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

    bool cargarVenta(); /// Nueva venta, acá va toda la lógica, creo que 1ro en memoria y luego paso a archivo, VER ESTO
    bool modificarVenta(); /// Definir

    bool eliminarVenta(); /// Definir
    bool altaVenta(); /// Definir

    void listarVentas(); /// Definir
    void mostrarVentaCompleta(int idVenta); /// Definir

    void consultarVentas();
};
