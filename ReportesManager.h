#pragma once

#include "VentaArchivo.h"
#include "DetalleVentaArchivo.h"
#include "vendedorArchivo.h"
#include "clienteArchivo.h"
#include "AutoArchivo.h"
#include "TipoPagoArchivo.h"

class ReportesManager
{
private:
    VentaArchivo _repoVenta;
    DetalleVentaArchivo _repoDetalle;
    VendedorArchivo _repoVendedor;
    ClienteArchivo _repoCliente;
    AutoArchivo _repoAuto;
    TipoPagoArchivo _repoTipoPago;

public:
    ReportesManager();

    /// 1 a 3
    void facturacionMensualPorAnio(int anio); /// OK, Se ingresa un año y muestra factuación para cada mes
    void facturacionTotalEntreFechas(Fecha desde, Fecha hasta); /// OK
    void facturacionPorVendedorEntreFechas(Fecha desde, Fecha hasta); /// OK

    /// 4 a 6
    void porcentajeVentasPorTipoPago(Fecha desde, Fecha hasta); /// OK
    void top5AutosVendidos(Fecha desde, Fecha hasta); /// OK
    void top5Vendedores(Fecha desde, Fecha hasta); /// OK
};
