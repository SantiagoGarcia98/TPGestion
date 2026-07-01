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

    bool cargarVenta(); /// OK - Nueva venta, acá va toda la lógica, creo que 1ro en memoria y luego paso a archivo, VER ESTO
    /// bool modificarVenta();   NO APLICA: tener en cuenta que son txt históricas. Para preservar la integridad de la info, una venta no se modifica, de ser necesarrio se cancela y se genera una nueva.

    bool eliminarVenta(); /// Ok, al intentar eliminar mencionar "Una venta eliminada no puede reactivarse"
    /// bool altaVenta();   NO APICA: no sería lógico a nivel negocio dar de alta una venta ya eliminada - ELIMINAR

    /// LISTADOS
    void listarVentas(); /// OK
    void mostrarVentaCompleta(int idVenta); /// OK, muestra todo el detalle de la venta
    void listarVentaPorFecha(); /// Ordenada por fecha
    void listarVentaPorMonto(); /// OK, Ordenadas por monto total de manera descendente

    /// CONSULTAS
    void consultarVentasPorFechas(); /// Por rango de fechas
    void consultarVentaPorCliente(); /// Por cliente (dni podrías ser)
    void consultarVentaPorVendedor(); /// Por vendedor (legajo podría ser)
    void consularVentaPorAutoVendido(); /// Por vehiculo vendido
};
