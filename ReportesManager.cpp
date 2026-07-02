#include "ReportesManager.h"
#include <iostream>
#include <iomanip> /// Para fix de montos

using namespace std;

ReportesManager::ReportesManager()
{
  //ctor
}

void ReportesManager::facturacionMensualPorAnio(int anio)
{
    if(anio < 2000 || anio > 2100)
    {
        cout << "Anio invalido." << endl;
        return;
    }

    int cant = _repoVenta.getCantidadRegistros();

    if(cant == 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    float facturacion[12] = {0};

    for(int i=0; i<cant; i++)
    {
        Venta venta = _repoVenta.leer(i);

        if(!venta.getEstado())
            continue;

        if(venta.getFecha().getAnio() == anio)
        {
            int mes = venta.getFecha().getMes();

            facturacion[mes - 1] += venta.getMontoTotal();
        }
    }

    bool hayVentas = false; /// Validamos si hay ventas

    for(int i=0; i<12; i++)
    {
        if(facturacion[i] > 0)
        {
            hayVentas = true;
            break;
        }
    }

    if(!hayVentas)
    {
        cout << "No existen ventas registradas para el anio " << anio << "." << endl;
        return;
    }

    const char* meses[12] =
    {
        "Enero",
        "Febrero",
        "Marzo",
        "Abril",
        "Mayo",
        "Junio",
        "Julio",
        "Agosto",
        "Septiembre",
        "Octubre",
        "Noviembre",
        "Diciembre"
    };

    float total = 0;

    cout << fixed << setprecision(2); /// Fixear montos a notación decimal fija

    cout << endl;
    cout << "----- FACTURACION MENSUAL -----" << endl;
    cout << "Anio: " << anio << endl;
    cout << endl;

        for(int i=0; i<12; i++)
        {
            if(facturacion[i] > 0)
            {
                cout << meses[i] << ": $ " << facturacion[i] << endl;
            }

            total += facturacion[i];
        }

    cout << "-----------------------------" << endl;
    cout << "TOTAL: $ " << total << endl;
    cout << "-----------------------------" << endl;
}

void ReportesManager::facturacionTotalEntreFechas(Fecha desde, Fecha hasta)
{
    if(desde > hasta)
    {
        cout << "El rango de fechas es invalido." << endl;
        return;
    }

    int cant = _repoVenta.getCantidadRegistros();
    if(cant == 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    float total = 0;
    int cantidadVentas = 0;
    bool hayVentas = false;

    for(int i=0; i<cant; i++)
    {
        Venta venta = _repoVenta.leer(i);

        if(!venta.getEstado())
            continue;

        if(venta.getFecha() >= desde && venta.getFecha() <= hasta)
        {
            total += venta.getMontoTotal();
            cantidadVentas++;
            hayVentas = true;
        }
    }

    if(!hayVentas)
    {
        cout << "No existen ventas registradas en el rango de fechas ingresado." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    cout << "----- FACTURACION TOTAL -----" << endl << endl;

    cout << "Desde: ";
    desde.Mostrar();

    cout << "Hasta: ";
    hasta.Mostrar();

    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Cantidad de ventas: " << cantidadVentas << endl;
    cout << "Facturacion total: $ " << total << endl;
    cout << "-----------------------------" << endl;
}

void ReportesManager::facturacionPorVendedorEntreFechas(Fecha desde, Fecha hasta)
{
    if(desde > hasta)
    {
        cout << "El rango de fechas es invalido." << endl;
        return;
    }

    int cantVentas = _repoVenta.getCantidadRegistros();
    if(cantVentas == 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    int cantVendedores = _repoVendedor.getCantidadRegistros();
    if(cantVendedores == 0)
    {
        cout << "No hay vendedores registrados." << endl;
        return;
    }

    cout << "----- VENDEDORES DISPONIBLES -----" << endl << endl;

    for(int i=0; i<cantVendedores; i++)
    {
        Vendedor vendedor = _repoVendedor.leer(i);

        if(vendedor.getEstado())
        {
            cout << "Legajo: " << vendedor.getLegajo() << " - " << vendedor.getApellido() << ", " << vendedor.getNombre() << endl;
        }
    }

    cout << endl;

    int legajo;
    cout << "Ingrese legajo del vendedor: ";
    cin >> legajo;

    int idVendedor = -1;
    Vendedor vendedorSeleccionado;

    for(int i=0; i<cantVendedores; i++)
    {
        Vendedor vendedor = _repoVendedor.leer(i);

        if(vendedor.getEstado() && vendedor.getLegajo() == legajo)
        {
            idVendedor = vendedor.getIdVendedor();
            vendedorSeleccionado = vendedor;
            break;
        }
    }

    if(idVendedor == -1)
    {
        cout << "No existe un vendedor con ese legajo." << endl;
        return;
    }

    float total = 0;
    int cantidadVentas = 0;

    for(int i=0; i<cantVentas; i++)
    {
        Venta venta = _repoVenta.leer(i);

        if(!venta.getEstado())
            continue;

        if(venta.getIdVendedor() == idVendedor && venta.getFecha() >= desde && venta.getFecha() <= hasta)
        {
            total += venta.getMontoTotal();
            cantidadVentas++;
        }
    }

    if(cantidadVentas == 0)
    {
        cout << endl;
        cout << "El vendedor no registra ventas en el periodo seleccionado." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    cout << endl;
    cout << "----- FACTURACION POR VENDEDOR -----" << endl << endl;

    cout << "Vendedor: " << vendedorSeleccionado.getApellido() << ", " << vendedorSeleccionado.getNombre() << endl;
    cout << "Legajo: " << vendedorSeleccionado.getLegajo() << endl;
    cout << "Periodo: " << desde.toString() << " al " << hasta.toString() << endl;
    cout << "-----------------------------" << endl;
    cout << "Cantidad de ventas: " << cantidadVentas << endl;
    cout << "Facturacion total: $ " << total << endl;
    cout << "-----------------------------" << endl;
}

void ReportesManager::porcentajeVentasPorTipoPago(Fecha desde, Fecha hasta)
{
    if(desde > hasta)
    {
        cout << "El rango de fechas es invalido." << endl;
        return;
    }

    int cantVentas = _repoVenta.getCantidadRegistros();
    if(cantVentas == 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    int cantTiposPago = _repoTipoPago.getCantidadRegistros();
    if(cantTiposPago == 0)
    {
        cout << "No hay tipos de pago registrados." << endl;
        return;
    }

    int *cantidadPorTipo;
    cantidadPorTipo = new int[cantTiposPago]; /// Memoria dinámica
    if(cantidadPorTipo == nullptr)
    {
        cout << "Error al asignar memoria." << endl;
        return;
    }

    for(int i=0; i<cantTiposPago; i++)
    {
        cantidadPorTipo[i] = 0;
    }

    int totalVentas = 0;

    for(int i=0; i<cantVentas; i++)
    {
        Venta venta = _repoVenta.leer(i);

        if(!venta.getEstado())
            continue;

        if(venta.getFecha() >= desde && venta.getFecha() <= hasta)
        {
            int posTipo = _repoTipoPago.buscar(venta.getIdTipoPago());

            if(posTipo >= 0)
            {
                cantidadPorTipo[posTipo]++;
                totalVentas++;
            }
        }
    }

    if(totalVentas == 0)
    {
        cout << "No existen ventas registradas en el periodo seleccionado." << endl;
        delete[] cantidadPorTipo;
        return;
    }

    cout << "----- PORCENTAJE DE VENTAS POR TIPO DE PAGO -----" << endl << endl;

    cout << "Periodo: " << desde.toString() << " al " << hasta.toString() << endl << endl;

    cout << fixed << setprecision(1);

    for(int i=0; i<cantTiposPago; i++)
    {
        TipoPago tipo = _repoTipoPago.leer(i);

        if(!tipo.getEstado())
            continue;

        float porcentaje = (cantidadPorTipo[i] * 100.0f) / totalVentas;

        cout << tipo.getDescripcion() << ": " << cantidadPorTipo[i] << " ventas (" << porcentaje << "%)" << endl;
    }

    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "Total de ventas: " << totalVentas << endl;
    cout << "-----------------------------" << endl;

    delete[] cantidadPorTipo;
}

void ReportesManager::top5AutosVendidos(Fecha desde, Fecha hasta)
{

}

void ReportesManager::top5Vendedores(Fecha desde, Fecha hasta)
{

}
