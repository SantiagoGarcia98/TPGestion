#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "Fecha.h"
#include "VendedorManager.h"
#include "utils.h"
using namespace std;

VendedorManager::VendedorManager()
: _archivo("vendedores.dat") { }

void VendedorManager::cargarVendedor() {
    Vendedor v;
     if (!confirmarAccion(" Desea cargar nuevo Vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu..."<<endl;
        return;
    }

    int id = _archivo.getNuevoID();
    v.setIdVendedor(id);
    cout << "Legajo Vendedor # " << id+1000 << endl;   //
    v.Cargar();
      if (!v.getEstado()) {
        cout << " No se guardara el vendedor."<<endl;
        return;
    }


    if (_archivo.guardar(v))
        cout << " Vendedor guardado correctamente."<<endl;
    else
        cout << "Error al guardar el vendedor."<<endl;
}
void VendedorManager::modificarVendedor() {
    int id;

    if (!confirmarAccion("Desea modificar los datos de un vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu..."<<endl;
        return;
    }

    cout << "Legajo Vendedor a modificar: ";
    cin >> id;
    cin.ignore();

    int pos = _archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "Vendedor no encontrado."<<endl;
        return;
    }

    Vendedor v = _archivo.leer(pos);
    cout << "--- DATOS ACTUALES ---"<<endl;
    v.Mostrar();

    cout << "\nSeleccione el dato que desea modificar:"<<endl;
    cout << "1. DNI "<<endl;
    cout << "2. Nombre "<<endl;
    cout << "3. Apellido "<<endl;
    cout << "4. Telefono "<<endl;
    cout << "5. Email "<<endl;
    cout << "6. Fecha de contratacion "<<endl;
    cout << "7. Sueldo "<<endl;
    cout << "8. Modificar TODOS los datos "<<endl;
    cout << "0. Volver sin modificar "<<endl;
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;
    cin.ignore(); // limpiar salto de linea

    string texto;  // auxiliar para cargar cadenas

    switch (opcion) {
        case 0:
            cout << "Operacion cancelada. No se modifico el vendedor."<<endl;
            return;

        case 1: {
            do {
                cout << "Nuevo DNI (0 para cancelar): ";
                texto = cargarCadena();
                if (Volver(texto.c_str())) {
                    cout << "Modificacion cancelada. "<<endl;
                    return;
                }
                if (!validarDNI((char*)texto.c_str())) {
                    cout << "DNI invalido. Reintente. "<<endl;
                    texto.clear();
                }
            } while (texto.empty());
            v.setDni((char*)texto.c_str());
            break;
        }

        case 2: {
            cout << "Nuevo nombre (0 para cancelar): ";
            texto = cargarCadena();
            if (Volver(texto.c_str())) {
                cout << "Modificacion cancelada. "<<endl;
                return;
            }
            v.setNombre((char*)texto.c_str());
            break;
        }

        case 3: {
            cout << "Nuevo apellido (0 para cancelar): ";
            texto = cargarCadena();
            if (Volver(texto.c_str())) {
                cout << "Modificacion cancelada. "<<endl;
                return;
            }
            v.setApellido((char*)texto.c_str());
            break;
        }

        case 4: {
            do {
                cout << "Nuevo telefono (0 para cancelar): ";
                texto = cargarCadena();
                if (Volver(texto.c_str())) {
                    cout << "Modificacion cancelada. "<<endl;
                    return;
                }
                if (!esTelefonoValido((char*)texto.c_str())) {
                    cout << "Telefono invalido. Ingrese solo numeros (6–15 digitos)."<<endl;
                    texto.clear();
                }
            } while (texto.empty());
            v.setTelefono((char*)texto.c_str());
            break;
        }

        case 5: {
            cout << "Nuevo email (0 para cancelar): ";
            texto = cargarCadena();
            if (Volver(texto.c_str())) {
                cout << "Modificacion cancelada. "<<endl;
                return;
            }

            v.setEmail((char*)texto.c_str());
            break;
        }

        case 6: {
            cout << "--- Nueva fecha de contratacion ---"<<endl;
    Fecha nuevaFecha;
    nuevaFecha.Cargar();
    v.setFechaContratacion(nuevaFecha);
    break;
        }

        case 7: {
            cout << "Nuevo sueldo (0 para cancelar): ";
            float sueldo;
            cin >> sueldo;
            cin.ignore();
            if (sueldo == 0) {
                cout << "Modificacion cancelada.\n";
                return;
            }
            v.setSueldo(sueldo);
            break;
        }

        case 8: {
            cout << "--- Ingrese nuevamente todos los datos del vendedor ---"<<endl;
            v.Cargar();
            if (!v.getEstado()) {
                cout << "Modificacion cancelada."<<endl;
                return;
            }
            break;
        }

        default:
            cout << "Opcion invalida. "<<endl;
            return;
    }

    // Guarda los cambios (mantiene el ID)
    v.setIdVendedor(id);
    if (_archivo.guardar(pos, v))
        cout << " Vendedor modificado correctamente."<<endl;
    else
        cout << " Error al modificar el vendedor."<<endl;
}
void VendedorManager::listarVendedores() {
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay vendedores cargados."<<endl;
        return;
    }

    int opcion;
    cout << "1. ACTIVOS "<<endl;
    cout << "2. INACTIVOS "<<endl;
    cout << "3. LISTAR TODOS "<<endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    system("cls");

    for (int i = 0; i < cant; i++) {
        Vendedor v = _archivo.leer(i);

        switch (opcion) {
        case 1:
            if (v.getEstado()) v.Mostrar();
            break;
        case 2:
            if (!v.getEstado()) v.Mostrar();
            break;
        case 3:
            v.Mostrar();
            break;
        default:
            cout << "Opcion invalida."<<endl;
            return;
        }
    }

    cout << "\n";

}
void VendedorManager::eliminarVendedor() {


    int id;
     if (!confirmarAccion(" Intenta ELIMINAR un Vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu..."<<endl;
        return;
    }
    cout << "Legajo del vendedor a eliminar: ";
    cin >> id;

    int pos = _archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "Vendedor no encontrado."<<endl;
        return;
    }

    Vendedor v = _archivo.leer(pos);
    cout << "--- DATOS DEL VENDEDOR ---" << endl;
    v.Mostrar();

    char confirma;
    cout << " Esta seguro que desea eliminar este vendedor? (s/n): ";
    cin >> confirma;

    if (confirma == 's' || confirma == 'S') {
        v.setEstado(false);
        if (_archivo.guardar(pos, v))
            cout << " Vendedor marcado como INACTIVO correctamente."<<endl;
        else
            cout << "Error al actualizar el registro."<<endl;
    } else {
        cout << "Operacion cancelada."<<endl;
    }
}

void VendedorManager::buscarVendedorPorApellido() {
    char apellido[50];
    cout << "Ingrese Apellido del vendedor: ";
    cin >> apellido;

    int cant = _archivo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < cant; i++) {
        Vendedor v = _archivo.leer(i);

        ///sstrcmpi compara My  y min
        if (strcmpi(v.getApellido(), apellido) == 0 && v.getEstado()) {
            v.Mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron vendedores con el apellido '" << apellido << "'."<<endl;
    }

    cout << endl;

}
void VendedorManager::buscarVendedorPorLegajo()
{
    int legajo;
    cout << "Ingrese el legajo: ";
    cin >> legajo;

    int id = legajo - 1000;

    int cant = _archivo.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        Vendedor v = _archivo.leer(i);

        if (v.getIdVendedor() == id)
        {
            v.Mostrar();
            return;
        }
    }

    cout << "No existe un vendedor con ese legajo." << endl;
}
