#include "VentaManager.h"
#include "utils.h"
#include <iostream>

using namespace std;

VentaManager::VentaManager()
{

}


void VentaManager::nuevaVenta()
{
    cout << "----- NUEVA VENTA -----" << endl;

    if(!confirmarAccion("Desea iniciar una venta?"))
        return;

    Venta venta;

    // -----------------------------
    // 1. ID y fecha
    // -----------------------------
    int idVenta = _archivo.getNuevoID();
    venta.setIdVenta(idVenta);

    Fecha hoy; // suponiendo que tiene constructor default con fecha actual
    venta.setFecha(hoy);

    cout << "ID Venta: " << idVenta << endl;

    // -----------------------------
    // 2. CLIENTE (buscar o alta)
    // -----------------------------
    char dni[12];
    cout << "DNI Cliente: ";
    cin.ignore(); ///
    cin.getline(dni, 12);

    int posCliente = _clientes.buscarPorDNI(dni);

    Cliente cliente;

    if(posCliente >= 0)
    {
        cliente = _clientes.leer(posCliente);
        cout << "Cliente encontrado:" << endl;
        cliente.Mostrar();
    }
    else
    {
        cout << "Cliente no encontrado. Se procedera a dar de alta." << endl;

        cliente.setIdCliente(_clientes.getNuevoID());
        cliente.Cargar();

        _clientes.guardar(cliente);
    }

    venta.setIdCliente(cliente.getIdCliente());

    // -----------------------------
    // 3. VENDEDOR (simple por ID)
    // -----------------------------
    int idVendedor;
    cout << "ID Vendedor: ";
    cin >> idVendedor;

    venta.setIdVendedor(idVendedor);

    // -----------------------------
    // 4. TIPO PAGO
    // -----------------------------
    int idPago;
    cout << "ID Tipo de Pago: ";
    cin >> idPago;

    venta.setIdTipoPago(idPago);

    // -----------------------------
    // 5. DETALLES DE VENTA
    // -----------------------------
    float total = 0;
    char continuar = 's';

    while(continuar == 's' || continuar == 'S')
    {
        DetalleVenta det;

        det.setIdDetalleVenta(_detalles.getNuevoID());
        det.setIdVenta(idVenta);

        int idAuto;
        cout << "ID Auto: ";
        cin >> idAuto;

        int posAuto = _autos.buscar(idAuto);

        if(posAuto < 0)
        {
            cout << "Auto no encontrado." << endl;
            continue;
        }

        Auto autoSel = _autos.leer(posAuto);

        int cant;
        cout << "Cantidad: ";
        cin >> cant;

        // -----------------------------
        // VALIDACION STOCK
        // -----------------------------
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

        _detalles.guardar(det);

        // descontar stock
        _autos.descontarStock(idAuto, cant);

        total += subtotal;

        cout << "Agregar otro auto? (s/n): ";
        cin >> continuar;
    }

    // -----------------------------
    // 6. TOTAL FINAL
    // -----------------------------
    venta.setMontoTotal(total);
    venta.setEstado(true);

    // -----------------------------
    // 7. GUARDAR VENTA
    // -----------------------------
    _archivo.guardar(venta);

    cout << "Venta registrada correctamente." << endl;
    cout << "Total: $" << total << endl;
}
