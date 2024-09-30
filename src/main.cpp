#include <iostream>
#include "Cliente.h"
#include "Cola.h"

using namespace std;

void mostrarMenu() {
    cout << "Sistema de Colas de Atención al Cliente" << endl;
    cout << "1. Añadir un cliente a la cola" << endl;
    cout << "2. Atender al siguiente cliente" << endl;
    cout << "3. Mostrar el estado de la cola" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    Cola colaClientes;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int numeroCuenta;
                cout << "Ingrese el nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese el número de cuenta del cliente: ";
                cin >> numeroCuenta;
                Cliente nuevoCliente(nombre, numeroCuenta);
                colaClientes.agregarCliente(nuevoCliente);
                cout << "Cliente añadido a la cola." << endl;
                break;
            }
            case 2: {
                if (!colaClientes.estaVacia()) {
                    Cliente clienteAtendido = colaClientes.atenderCliente();
                    cout << "Atendiendo al cliente: " << clienteAtendido.getNombre() << " con número de cuenta: " << clienteAtendido.getNumeroCuenta() << endl;
                } else {
                    cout << "No hay clientes en la cola." << endl;
                }
                break;
            }
            case 3: {
                if (!colaClientes.estaVacia()) {
                    cout << "Clientes en la cola:" << endl;
                    // Aquí podrías implementar una función para mostrar todos los clientes en la cola
                } else {
                    cout << "No hay clientes en la cola." << endl;
                }
                break;
            }
            case 4:
                cout << "Saliendo del sistema." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
