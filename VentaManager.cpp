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
    cout << "---------- NUEVA VENTA ----------" << endl << endl;

    if(!confirmarAccion("Desea iniciar una venta?"))
        return false; /// VER si está ok

    Venta venta;

    /// -----------------------------
    /// 1. ID y fecha
    /// -----------------------------
    int idVenta = _repoVenta.getNuevoID();
    venta.setIdVenta(idVenta);

    cout << endl;
    cout << "--- DATOS ---" << endl;

    Fecha fecha; /// Ver constructor que esté por default con fecha actual por ej y sino opción de ingresar fecha manual
    fecha.Cargar();
    venta.setFecha(fecha);

    cout << endl;
    cout << "ID Venta: " << idVenta << endl;

    /// -----------------------------
    /// 2. Cliente (buscar o alta)
    /// -----------------------------
    char dni[12]; /// Mejor acá que DNI sea char a int, permite cargar iniciando "0" o mejor comparación

    cout << endl;
    cout << "DNI Cliente: ";
    cin.ignore(); ///
    cin.getline(dni, 12);

    int posCliente = _repoCliente.buscarPorDNI(dni);

    Cliente cliente;

    if(posCliente >= 0)
    {
        cliente = _repoCliente.leer(posCliente);

        if(!cliente.getEstado()) /// Validación de estado de cliente, estaría ok que si es false lo lleve a posibilidad de dar de alta
        {
            cout << "El cliente se encuentra inactivo." << endl;
            return false;
        }

        cout << "Cliente encontrado:" << endl;
        cliente.Mostrar();
    }
    else
    {
        cout << "Cliente no encontrado. Se procedera a dar de alta." << endl;

        cliente.setIdCliente(_repoCliente.getNuevoID());
        cliente.Cargar();

        if(!_repoCliente.guardar(cliente))
        {
            cout << "Error al guardar el cliente." << endl;
            return false;
        }
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

    DetalleVenta *detalles;
    detalles = new DetalleVenta[50];
    int cantidadDetalles = 0;

    float total = 0;
    char continuar = 's';

    while(continuar == 's' || continuar == 'S')
    {
        DetalleVenta det;

        det.setIdDetalleVenta(_repoDetalle.getNuevoID() + cantidadDetalles);
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

        if(!autoSel.getEstado()) /// Validación de estado de auto, estaría ok que si se encuentra inactivo llevarlo a flujo a preguntar si quiere activarlo
        {
            cout << "El auto se encuentra inactivo.";
            continue;
        }

        int cant;
        do
        {
            cout << "Cantidad de autos: ";
            cin >> cant;

            if(cant <= 0)
            {
              cout << "Cantidad invalida";
            }
        } while(cant <= 0);

        /// -----------------------------
        /// VALIDACION STOCK
        /// -----------------------------
        if(autoSel.getStock() < cant)
        {
            cout << "Stock insuficiente. Disponible: " << autoSel.getStock() << endl;
            continue;
        }

        float precio = autoSel.getPrecio();
        float subtotal = precio * cant;

        det.setIdAuto(idAuto);
        det.setCantidad(cant);
        det.setPrecioHistorico(precio);
        det.setSubtotal(subtotal);
        det.setEstado(true);

        if(cantidadDetalles >= 50)
        {
            cout << "Se alcanzo el maximo de autos por venta." << endl;
            break;
        }

        detalles[cantidadDetalles] = det;
        cantidadDetalles++;

        total += subtotal;

        cout << "Agregar otro auto? (S/N): ";
        cin >> continuar;
    }

    /// -----------------------------
    /// Validar que haya al menos un detalle
    /// -----------------------------
    if(cantidadDetalles == 0)
    {
        cout << "Debe agregar al menos un auto." << endl;

        delete[] detalles;
        return false;
    }

    /// -----------------------------
    /// 6. TOTAL FINAL
    /// -----------------------------
    venta.setMontoTotal(total);
    venta.setEstado(true);

    /// -----------------------------
    /// 7. GUARDAR VENTA
    /// -----------------------------

    if(!_repoVenta.guardar(venta))
    {
        cout << "Error al guardar la venta." << endl;
        delete [] detalles;
        return false;
    }

    /// -----------------------------
    /// 8. Guardar detalles
    /// -----------------------------
    for(int i = 0; i < cantidadDetalles; i++)
    {
        if(!_repoDetalle.guardar(detalles[i]))
        {
            cout << "Error al guardar un detalle." << endl;

            delete[] detalles;
            return false;
        }
    }

    /// -----------------------------
    /// 9. Descontar stock
    /// -----------------------------
    for(int i = 0; i < cantidadDetalles; i++)
    {
        _repoAuto.descontarStock(detalles[i].getIdAuto(),detalles[i].getCantidad());
    }

    delete[] detalles;

    cout << endl;
    cout << "Venta registrada correctamente." << endl;
    cout << "Total: $" << total << endl;

    return true;

}

bool VentaManager::eliminarVenta() /// Definir
{
    int idVenta;

    cout << "ID de venta a cancelar: ";
    cin >> idVenta;

    int posVenta = _repoVenta.buscar(idVenta);

    if(posVenta == -1)
    {
        cout << "La venta no existe." << endl;
        return false;
    }

    Venta venta = _repoVenta.leer(posVenta);

    if(!venta.getEstado())
    {
        cout << "La venta ya se encuentra cancelada." << endl;
        return false;
    }

    cout << endl;
    mostrarVentaCompleta(idVenta);
    cout << endl;

    cout << "ATENCION: la cancelacion devolvera el stock y la venta no podra reactivarse." << endl;

    if(!confirmarAccion("Confirma cancelar la venta?"))
        return false;

    int cantDetalles = _repoDetalle.getCantidadRegistros();

    for(int i = 0; i < cantDetalles; i++)
    {
        DetalleVenta det = _repoDetalle.leer(i);

        if(det.getIdVenta() == idVenta && det.getEstado())
        {
            _repoAuto.reponerStock(det.getIdAuto(),det.getCantidad());

            _repoDetalle.eliminar(i);
        }
    }

    if(!_repoVenta.eliminar(posVenta))
    {
        cout << "No se pudo cancelar la venta." << endl;
        return false;
    }

    cout << endl;
    cout << "La venta fue cancelada correctamente." << endl;
    cout << "Una venta cancelada no puede reactivarse." << endl;

    return true;
}


/// LISTADOS
void VentaManager::listarVentas() /// Definir
{
    int cant = _repoVenta.getCantidadRegistros();

    if(cant == 0)
    {
        cout << "No hay ventas registradas.\n";
        return;
    }

    int opcion;

    cout << "1 - Listar activas\n";
    cout << "2 - Listar inactivas\n";
    cout << "3 - Listar todas\n";
    cout << "Opcion: ";
    cin >> opcion;

    cout << endl;

    for(int i=0; i<cant; i++)
    {
        Venta v = _repoVenta.leer(i);

        switch(opcion)
        {
        case 1:
            if(v.getEstado())
                v.mostrar();
                cout << endl;
            break;

        case 2:
            if(!v.getEstado())
                v.mostrar();
                cout << endl;
            break;

        case 3:
            v.mostrar();
            cout << endl;
            break;

        default:
            cout << "Opcion invalida.";
            return;
        }
    }
}

void VentaManager::mostrarVentaCompleta(int idVenta) /// Definir
{
    int pos = _repoVenta.buscar(idVenta);

    if(pos == -1)
    {
        cout << "Venta inexistente.";
        return;
    }

    Venta venta = _repoVenta.leer(pos);

    cout << "===== VENTA =====" << endl;
    venta.mostrar();

    cout << endl;
    cout << "===== CLIENTE =====" << endl;

    int posCliente = _repoCliente.buscarPorID(venta.getIdCliente());

    if(posCliente >= 0)
    {
        Cliente c = _repoCliente.leer(posCliente);
        c.Mostrar();
    }

    cout << "===== VENDEDOR =====";

    int posVendedor = _repoVendedor.buscarPorID(venta.getIdVendedor());

    if(posVendedor >= 0)
    {
        Vendedor v = _repoVendedor.leer(posVendedor);
        v.Mostrar();
    }

    cout << "===== DETALLES =====";

    _repoDetalle.listarPorVenta(idVenta);
}

void VentaManager::listarVentaPorFecha() /// Ordenada por fecha de más reciente a más antigua
{

    int cant = _repoVenta.getCantidadRegistros();

    if(cant <= 0)
    {
      cout << "No hay ventas registradas." << endl;
      return;
    }

    Venta *vec;
    vec = new Venta[cant];

    _repoVenta.leer(vec, cant);

    // Ordena de más reciente a más antiguo
    for(int i=0; i<cant; i++)
    {
      for(int x=i+1; x<cant; x++)
      {
        if(vec[i].getFecha() < vec[x].getFecha())
        {
          Venta aux = vec[i];
          vec[i] = vec[x];
          vec[x] = aux;
        }
      }
    }

    cout << "----- VENTAS ORDENADAS POR FECHA -----" << endl;

    for(int i=0; i<cant; i++)
    {
        if(vec[i].getEstado())
        {
          vec[i].mostrar();
          cout << endl;
        }
    }

    delete[] vec;
}

void VentaManager::listarVentaPorMonto() /// Ordenadas por monto total de manera descendente
{
    int cant = _repoVenta.getCantidadRegistros();

    if(cant <= 0)
    {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    Venta *vec = new Venta[cant];
    if(vec==nullptr) return;

    int leidos = _repoVenta.leer(vec, cant);

    for(int i=0; i<leidos-1; i++)
    {
        for(int x=i+1; x<leidos; x++)
        {
            if(vec[x].getMontoTotal() > vec[i].getMontoTotal())
            {
                Venta aux = vec[i];
                vec[i] = vec[x];
                vec[x] = aux;
            }
        }
    }

    cout << "----- VENTAS ORDENADAS POR MONTO -----" << endl;

    for(int i=0; i<leidos; i++)
    {
        if(vec[i].getEstado())
        {
            vec[i].mostrar();
            cout << endl;
        }
    }

    delete[] vec;
}


/// CONSULTAS

void VentaManager::consultarVentasPorFechas()
{

}

void VentaManager::consultarVentaPorCliente()
{

}

void VentaManager::consultarVentaPorVendedor()
{

}

void VentaManager::consularVentaPorAutoVendido()
{

}
