#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "Fecha.h"
#include "VendedorManager.h"
#include "Funciones.h"
using namespace std;

VendedorManager::VendedorManager()
: _archivo("vendedores.dat") { }

void VendedorManager::cargarVendedor() {
    Vendedor v;
     if (!confirmarAccion(" Desea cargar nuevo Vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu...\n";
        return;
    }

    int id = _archivo.getNuevoID();
    v.setIdVendedor(id);
    cout << "Legajo Vendedor # " << id << endl;   //
    v.Cargar();
      if (!v.getEstado()) {
        cout << " No se guardara el vendedor.\n";
        return;
    }


    if (_archivo.guardar(v))
        cout << " Vendedor guardado correctamente.\n";
    else
        cout << "Error al guardar el vendedor.\n";
}
void VendedorManager::modificarVendedor() {
    int id;

    if (!confirmarAccion("Desea modificar los datos de un vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu...\n";
        return;
    }

    cout << "Legajo Vendedor a modificar: ";
    cin >> id;
    cin.ignore();

    int pos = _archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "Vendedor no encontrado.\n";
        return;
    }

    Vendedor v = _archivo.leer(pos);
    cout << "\n--- DATOS ACTUALES ---\n";
    v.Mostrar();

    cout << "\nSeleccione el dato que desea modificar:\n";
    cout << "1. DNI\n";
    cout << "2. Nombre\n";
    cout << "3. Apellido\n";
    cout << "4. Telefono\n";
    cout << "5. Email\n";
    cout << "6. Fecha de contratacion\n";
    cout << "7. Sueldo\n";
    cout << "8. Modificar TODOS los datos\n";
    cout << "0. Volver sin modificar\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;
    cin.ignore(); // limpiar salto de linea

    string texto;  // auxiliar para cargar cadenas

    switch (opcion) {
        case 0:
            cout << "Operacion cancelada. No se modifico el vendedor.\n";
            return;

        case 1: {
            do {
                cout << "Nuevo DNI (0 para cancelar): ";
                texto = cargarCadena();
                if (Volver(texto.c_str())) {
                    cout << "Modificacion cancelada.\n";
                    return;
                }
                if (!validarDNI((char*)texto.c_str())) {
                    cout << "DNI invalido. Reintente.\n";
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
                cout << "Modificacion cancelada.\n";
                return;
            }
            v.setNombre((char*)texto.c_str());
            break;
        }

        case 3: {
            cout << "Nuevo apellido (0 para cancelar): ";
            texto = cargarCadena();
            if (Volver(texto.c_str())) {
                cout << "Modificacion cancelada.\n";
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
                    cout << "Modificacion cancelada.\n";
                    return;
                }
                if (!esTelefonoValido((char*)texto.c_str())) {
                    cout << "Telefono invalido. Ingrese solo numeros (6–15 digitos).\n";
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
                cout << "Modificacion cancelada.\n";
                return;
            }

            v.setEmail((char*)texto.c_str());
            break;
        }

        case 6: {
            cout << "\n--- Nueva fecha de contratacion ---\n";
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
            cout << "\n--- Ingrese nuevamente todos los datos del vendedor ---\n";
            v.Cargar();
            if (!v.getEstado()) {
                cout << "Modificacion cancelada.\n";
                return;
            }
            break;
        }

        default:
            cout << "Opcion invalida.\n";
            return;
    }

    // Guarda los cambios (mantiene el ID)
    v.setIdVendedor(id);
    if (_archivo.guardar(pos, v))
        cout << " Vendedor modificado correctamente.\n";
    else
        cout << " Error al modificar el vendedor.\n";
}
void VendedorManager::listarVendedores() {
    int cant = _archivo.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay vendedores cargados.\n";
        return;
    }

    int opcion;
    cout << "1. Listar solo activos\n";
    cout << "2. Listar solo inactivos\n";
    cout << "3. Listar todos\n";
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
            cout << "Opcion invalida.\n";
            return;
        }
    }

    cout << "\n";

}
void VendedorManager::eliminarVendedor() {


    int id;
     if (!confirmarAccion(" Intenta ELIMINAR un Vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu...\n";
        return;
    }
    cout << "Legajo del vendedor a eliminar: ";
    cin >> id;

    int pos = _archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "Vendedor no encontrado.\n";
        return;
    }

    Vendedor v = _archivo.leer(pos);
    cout << "\n--- DATOS DEL VENDEDOR ---" << endl;
    v.Mostrar();

    char confirma;
    cout << "\n Esta seguro que desea eliminar este vendedor? (s/n): ";
    cin >> confirma;

    if (confirma == 's' || confirma == 'S') {
        v.setEstado(false);
        if (_archivo.guardar(pos, v))
            cout << " Vendedor marcado como INACTIVO correctamente.\n";
        else
            cout << "Error al actualizar el registro.\n";
    } else {
        cout << "Operacion cancelada.\n";
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
        cout << "No se encontraron vendedores con el apellido '" << apellido << "'.\n";
    }

    cout << endl;

}
