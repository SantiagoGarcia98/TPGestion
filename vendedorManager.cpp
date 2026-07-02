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
    cout << "ID Vendedor a modificar: ";
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

    cout << "Seleccione el dato que desea modificar:"<<endl;
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
    cout << "--- OPCIONES DE LISTADO ---"<<endl;
    cout << "1. ACTIVOS "<<endl;
    cout << "2. INACTIVOS "<<endl;
    cout << "3. LISTAR TODOS "<<endl;
    cout << "4. Lista de vendedores ordenados por apellido alfabeticamente"<<endl;
    cout << "0. Volver al menu anterior"<<endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    system("cls");
    if (opcion == 0)
    {
        cout << "Volviendo al menu:..." << endl;
        return;
    }
     system("cls");
    if (opcion == 4){
             listarVendedorOrdenadosxapellido();
             return;}
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
void VendedorManager::BajaVendedor() {


    int id;
     if (!confirmarAccion(" Intenta dar de BAJA un Vendedor? (s/n): ")) {
        cout << "Operacion cancelada. Volviendo al menu..."<<endl;
        return;
    }
    cout << "ID del vendedor : ";
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
    cout << " Esta seguro que desea dar de baja este vendedor? (s/n): ";
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
void VendedorManager::altaVendedor(){
    int id;

    if (!confirmarAccion("¿Desea dar de alta un vendedor? (s/n): "))
    {
        cout << "Operacion cancelada. Volviendo al menu..." << endl;
        return;
    }

    cout << "ID del vendedor a dar de alta: ";
    cin >> id;

    int pos = _archivo.buscarPorID(id);

    if (pos == -1)
    {
        cout << "Vendedor no encontrado." << endl;
        return;
    }

    Vendedor v = _archivo.leer(pos);

    cout << "--- DATOS DEL VENDEDOR ---" << endl;
    v.Mostrar();

    if (v.getEstado())
    {
        cout << "El vendedor ya se encuentra ACTIVO." << endl;
        return;
    }

    char confirma;
    cout << "¿Confirma el alta de este vendedor? (s/n): ";
    cin >> confirma;

    if (confirma == 's' || confirma == 'S')
    {
        v.setEstado(true);

        if (_archivo.guardar(pos, v))
            cout << "Vendedor dado de ALTA correctamente." << endl;
        else
            cout << "Error al actualizar el registro." << endl;
    }
    else
    {
        cout << "Operacion cancelada." << endl;
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
void VendedorManager::buscarVendedorPorLegajo(){
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
void VendedorManager::buscarVendedorPorDNI(){
    char dni[9];

    cout << "Ingrese el DNI: ";
    cin >> dni;

    int cant = _archivo.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        Vendedor v = _archivo.leer(i);

        if (strcmp(v.getDni(), dni) == 0)
        {
            cout << "Vendedor encontrado:\n";
            v.Mostrar();
            return;
        }
    }

    cout << "No existe un vendedor con ese DNI." << endl;
}

void VendedorManager::buscarFechaContratacion()
{
    int dia, mes, anio;

    cout << "Ingrese la fecha de ingreso" << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;

    int cant = _archivo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < cant; i++)
    {
        Vendedor v = _archivo.leer(i);
        Fecha f = v.getFechaContratacion();

        if (f.getDia() == dia &&
            f.getMes() == mes &&
            f.getAnio() == anio)
        {
            v.Mostrar();
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "No hay vendedores con esa fecha de ingreso." << endl;
    }
}
void VendedorManager::listarVendedorOrdenadosxapellido(){
    int cant = _archivo.getCantidadRegistros();
    Vendedor *vec = new Vendedor[cant];
    for(int i = 0; i < cant; i++){
        vec[i] = _archivo.leer(i);
    }
    Vendedor aux;
    for(int i = 0; i < cant - 1; i++){
        for(int j = i + 1; j < cant; j++)
        {
            if(strcmp(vec[i].getApellido(), vec[j].getApellido()) > 0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for(int i = 0; i < cant; i++){
        vec[i].Mostrar();
    }
    delete[] vec;

}
