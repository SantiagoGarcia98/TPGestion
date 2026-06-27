#include "VentaManager.h"
#include "DetalleVenta.h"
#include "utils.h"
#include "fecha.h"
#include <iostream>

using namespace std;

VentaManager::VentaManager()
{

}


bool VentaManager::cargarVenta()
{
    cout << "----- NUEVA VENTA -----" << endl;

    if(!confirmarAccion("Desea iniciar una venta?"))
        return false; /// VER si está ok

    Venta venta;

    /// -----------------------------
    /// 1. ID y fecha
    /// -----------------------------
    int idVenta = _repoVenta.getNuevoID();
    venta.setIdVenta(idVenta);

    Fecha fecha; /// Ver constructor que esté por default con fecha actual por ej y sino opción de ingresar fecha manual
    fecha.Cargar();
    venta.setFecha(fecha);

    cout << "ID Venta: " << idVenta << endl;

    /// -----------------------------
    /// 2. Cliente (buscar o alta)
    /// -----------------------------
    char dni[12]; /// Mejor acá que DNI sea int, permite cargar iniciando "0" o mejor comparación
    cout << "DNI Cliente: ";
    cin.ignore(); ///
    cin.getline(dni, 12);

    int posCliente = _repoCliente.buscarPorDNI(dni);

    Cliente cliente;

    if(posCliente >= 0)
    {
        cliente = _repoCliente.leer(posCliente);
        cout << "Cliente encontrado:" << endl;
        cliente.Mostrar();
    }
    else
    {
        cout << "Cliente no encontrado. Se procedera a dar de alta." << endl;

        cliente.setIdCliente(_repoCliente.getNuevoID());
        cliente.Cargar();

        _repoCliente.guardar(cliente);
    }

    venta.setIdCliente(cliente.getIdCliente());

    /// -----------------------------
    /// 3. VENDEDOR (simple por ID o puede ser por legajo)
    /// -----------------------------
    int idVendedor;
    cout << "ID Vendedor: ";
    cin >> idVendedor;

    int pos=_repoVendedor.buscarPorID(idVendedor);

    if(pos==-1)
    {
        cout<<"Vendedor inexistente";
        return false; /// VER SI ESTÁ OK
    }

    Vendedor vend = _repoVendedor.leer(pos);

    if(!vend.getEstado())
    {
        cout<<"El vendedor se encuentra inactivo";
        return false; /// VER SI ESTÁ OK
    }

    venta.setIdVendedor(idVendedor);

    /// -----------------------------
    /// 4. TIPO PAGO
    /// -----------------------------
    int idPago;
    cout << "ID Tipo de Pago: ";
    cin >> idPago;

    int posPago = _repoTipoPagos.buscar(idPago);

    if(posPago==-1)
    {
        cout << "Tipo de pago inexistente." << endl;
        return false; /// VER SI ESTÁ OK
    }

    venta.setIdTipoPago(idPago);

    /// -----------------------------
    /// 5. DETALLES DE VENTA
    /// -----------------------------
    float total = 0;
    char continuar = 's';

    while(continuar == 's' || continuar == 'S')
    {
        DetalleVenta det;

        det.setIdDetalleVenta(_repoDetalle.getNuevoID());
        det.setIdVenta(idVenta);

        int idAuto;
        cout << "ID Auto: ";
        cin >> idAuto;

        int posAuto = _repoAuto.buscar(idAuto);

        if(posAuto < 0)
        {
            cout << "Auto no encontrado." << endl;
            continue;
        }

        Auto autoSel = _repoAuto.leer(posAuto);

        int cant;
        cout << "Cantidad: ";
        cin >> cant;

        /// -----------------------------
        /// VALIDACION STOCK
        /// -----------------------------
        if(autoSel.getStock() < cant)
        {
            cout << "Stock insuficiente. Disponible: "
                 << autoSel.getStock() << endl;
            continue;
        }

        float precio = autoSel.getPrecio();

        det.setIdAuto(idAuto);
        det.setCantidad(cant);
        det.setPrecioHistorico(precio);

        float subtotal = precio * cant;
        det.setSubtotal(subtotal);

        det.setEstado(true);

        _repoDetalle.guardar(det);

        /// Descontar stock
        _repoAuto.descontarStock(idAuto, cant);

        total += subtotal;

        cout << "Agregar otro auto? (s/n): ";
        cin >> continuar;
    }

    /// -----------------------------
    /// 6. TOTAL FINAL
    /// -----------------------------
    venta.setMontoTotal(total);
    venta.setEstado(true);

    /// -----------------------------
    /// 7. GUARDAR VENTA
    /// -----------------------------
    return _repoVenta.guardar(venta);

    cout << "Venta registrada correctamente." << endl;
    cout << "Total: $ " << total << endl;
}

bool VentaManager::modificarVenta() /// Definir
{

}

bool VentaManager::eliminarVenta() /// Definir
{

}

bool VentaManager::altaVenta() /// Definir
{

}

void VentaManager::listarVentas() /// Definir
{

}

void VentaManager::mostrarVentaCompleta(int idVenta) /// Definir
{

}

void VentaManager::consultarVentas()
{

}
