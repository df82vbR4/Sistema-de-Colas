// Librerías necesarias para el programa
#include <iostream>       // Entrada y salida estándar
#include <string>         // Usar cadenas de texto
#include <queue>          // Usar la cola y cola de prioridades
#include <unordered_map>  // Usar mapas hash (hash maps)
#include <list>           // Usar listas enlazadas
#include <thread>         // Usar hilos (threads)
#include <chrono>         // Manejar el tiempo
#include <memory>         // Manejar punteros inteligentes (smart pointers)
#include <fstream>        // Manejar archivos
#include <sstream>        // Manipulación de cadenas en flujos
#include <functional>     // Usar objetos de función

using namespace std;

// Estructura para representar una Solicitud
struct Solicitud {
    int idSolicitud;        // ID único para la solicitud
    int idCliente;         // ID del cliente que realiza la solicitud
    string nombreCliente;   // Nombre del cliente
    string tipoSolicitud;   // Tipo de solicitud (VIP, Preferencial, Regular)
    string descripcion;     // Descripción de la solicitud
    string estado;          // Estado de la solicitud (Pendiente, En Proceso, Atendida)

    // Constructor para inicializar la solicitud
    Solicitud(int _idSolicitud, int _idCliente, string _nombreCliente, string _tipoSolicitud, string _descripcion)
        : idSolicitud(_idSolicitud), idCliente(_idCliente), nombreCliente(_nombreCliente), tipoSolicitud(_tipoSolicitud), descripcion(_descripcion), estado("Pendiente") {}
};

// Nodo para lista enlazada de solicitudes atendidas
class Nodo {
public:
    Solicitud solicitud;               // Solicitud contenida en el nodo
    unique_ptr<Nodo> siguiente;        // Puntero al siguiente nodo

    // Constructor para inicializar el nodo
    Nodo(Solicitud _solicitud) : solicitud(_solicitud), siguiente(nullptr) {}
};

// Clase para manejar el Banco
class Banco {
private:
    unique_ptr<Nodo> cabeza = nullptr; // Cabeza de la lista enlazada de solicitudes atendidas
    Nodo* cola = nullptr;               // Cola de la lista enlazada
    priority_queue<Solicitud, vector<Solicitud>, function<bool(Solicitud, Solicitud)>> colaSolicitudes; // Cola de prioridades
    unordered_map<int, string> estadoSolicitudes; // Mapa de estados de solicitudes
    int contadorSolicitudes = 1;       // Contador para ID de solicitudes

public:
    // Constructor de la clase Banco
    Banco() : colaSolicitudes([](Solicitud a, Solicitud b) {
        // Prioriza VIP > Preferencial > Regular
        if (a.tipoSolicitud == b.tipoSolicitud) {
            return a.idSolicitud > b.idSolicitud; // Si son del mismo tipo, prioriza por ID
        }
        // Establece la prioridad: VIP > Preferencial > Regular
        if (a.tipoSolicitud == "VIP") return false; // VIP tiene más prioridad que Preferencial y Regular
        if (a.tipoSolicitud == "Preferencial" && b.tipoSolicitud != "Preferencial") return false; // Preferencial tiene más prioridad que Regular
        return true; // Regular es el de menor prioridad
    }) {}

    // Método para agregar una solicitud
    void agregarSolicitud(int idCliente, string nombreCliente, string tipo, string descripcion) {
        Solicitud nuevaSolicitud(contadorSolicitudes++, idCliente, nombreCliente, tipo, descripcion);
        colaSolicitudes.push(nuevaSolicitud); // Agrega la nueva solicitud a la cola de prioridades
        estadoSolicitudes[nuevaSolicitud.idSolicitud] = "Pendiente"; // Establece el estado inicial
        cout << "Solicitud agregada: " << nuevaSolicitud.tipoSolicitud << " - ID: " << nuevaSolicitud.idSolicitud << endl;
    }

    // Método para atender la siguiente solicitud
    void atenderSolicitud() {
        if (colaSolicitudes.empty()) {
            cout << "No hay solicitudes en espera." << endl;
            return; // Sale si no hay solicitudes
        }

        Solicitud solicitudActual = colaSolicitudes.top(); // Obtiene la solicitud en la cima de la cola
        colaSolicitudes.pop(); // Elimina la solicitud de la cola
        solicitudActual.estado = "Atendida"; // Actualiza el estado a "Atendida"
        estadoSolicitudes[solicitudActual.idSolicitud] = "Atendida"; // Actualiza el estado en el mapa

        // Crear nuevo nodo para la solicitud atendida
        auto nuevoNodo = make_unique<Nodo>(solicitudActual);
        if (!cabeza) {
            cabeza = move(nuevoNodo); // Si la lista está vacía, establece cabeza
            cola = cabeza.get(); // Inicializa cola también
        } else {
            cola->siguiente = move(nuevoNodo); // Agrega el nodo a la cola
            cola = cola->siguiente.get(); // Mueve la cola al siguiente nodo
        }

        cout << "Atendiendo solicitud ID: " << solicitudActual.idSolicitud << " - Cliente: " << solicitudActual.nombreCliente << endl;

        // Simulando tiempo de atención
        int tiempoAtencion = determinarTiempoAtencion(solicitudActual);
        cuentaRegresiva(tiempoAtencion); // Llama al método para simular la cuenta regresiva
        
        solicitudActual.estado = "Atendida"; // Actualiza el estado a "Atendida"
        estadoSolicitudes[solicitudActual.idSolicitud] = "Atendida";
        cout << "Solicitud ID: " << solicitudActual.idSolicitud << " - Estado: Atendida" << endl;

        // Manejo especial para reclamos
        if (solicitudActual.tipoSolicitud == "Reclamo de Cobro No Reconocido") {
            cout << "Reclamo de " << solicitudActual.descripcion << " ha sido procesado. Su reclamo procede." << endl;
            cout << "Reversión del cargo realizada exitosamente." << endl;
        }
    }

    // Método para mostrar el historial de solicitudes atendidas
    void mostrarHistorial() {
        if (!cabeza) {
            cout << "No hay historial de solicitudes." << endl;
            return; // Sale si no hay historial
        }

        cout << "\nHistorial de solicitudes atendidas:\n";
        for (Nodo* actual = cabeza.get(); actual != nullptr; actual = actual->siguiente.get()) {
            cout << "ID: " << actual->solicitud.idSolicitud << " - Cliente: " << actual->solicitud.nombreCliente << " - Estado: " << actual->solicitud.estado << endl;
        }
    }

    // Método para consultar el estado de una solicitud
    void consultarEstado(int idSolicitud) {
        if (estadoSolicitudes.find(idSolicitud) != estadoSolicitudes.end()) {
            cout << "Estado de la solicitud ID " << idSolicitud << ": " << estadoSolicitudes[idSolicitud] << endl;
        } else {
            cout << "La solicitud con ID " << idSolicitud << " no existe." << endl;
        }
    }

    // Método para cargar historial desde un archivo
    void cargarHistorialDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo) {
            cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
            return; // Sale si hay error al abrir el archivo
        }

        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue; // Salta líneas vacías

            int idCliente;
            string nombreCliente, tipoSolicitud, descripcion;
            istringstream iss(linea);

            // Procesa la línea
            if (!(iss >> idCliente >> nombreCliente >> tipoSolicitud >> descripcion)) {
                cerr << "Error al procesar la línea: " << linea << endl;
                continue; // Continúa con la siguiente línea si hay un error
            }
            agregarSolicitud(idCliente, nombreCliente, tipoSolicitud, descripcion); // Agrega la solicitud
        }

        archivo.close(); // Cierra el archivo
    }

    // Método para determinar el tiempo de atención
    int determinarTiempoAtencion(const Solicitud& solicitud) {
        if (solicitud.tipoSolicitud == "Activación de Tarjeta") return 3; // 3 segundos
        if (solicitud.tipoSolicitud == "Reposición de Tarjeta") return 5; // 5 segundos
        if (solicitud.tipoSolicitud == "Reclamo de Cobro No Reconocido") return 10; // 10 segundos
        return 2; // Tiempo por defecto
    }

    // Método para simular cuenta regresiva de atención
    void cuentaRegresiva(int segundos) {
        for (int i = segundos; i > 0; --i) {
            cout << "Atendiendo... " << i << " segundos restantes" << endl;
            this_thread::sleep_for(chrono::seconds(1)); // Simula el tiempo de espera
        }
    }
};

// Clase para manejar la cola de clientes en la fila presencial
class ColaClientes {
private:
    queue<int> clientes; // Cola para manejar los IDs de los clientes

public:
    // Método para cargar clientes desde un archivo
    void cargarClientesDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo) {
            cerr << "Error al abrir el archivo de clientes: " << nombreArchivo << endl;
            return; // Sale si hay error al abrir el archivo
        }

        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue; // Salta líneas vacías

            int idCliente;
            string nombreCliente, tipoCliente;
            istringstream iss(linea);

            // Procesa la línea
            if (!(iss >> idCliente >> nombreCliente >> tipoCliente)) {
                cerr << "Error al procesar la línea: " << linea << endl;
                continue; // Continúa con la siguiente línea si hay un error
            }

            clientes.push(idCliente); // Agrega el ID del cliente a la cola
            cout << "Cliente agregado: " << nombreCliente << " (ID: " << idCliente << ", Tipo: " << tipoCliente << ")" << endl;
        }

        archivo.close(); // Cierra el archivo
    }

    // Método para atender al siguiente cliente en la fila presencial
    void atenderCliente(Banco& banco) {
        if (clientes.empty()) {
            cout << "No hay clientes en la cola." << endl;
            return; // Sale si no hay clientes en la cola
        }

        int idCliente = clientes.front(); // Obtiene el ID del siguiente cliente
        clientes.pop(); // Elimina el cliente de la cola
        cout << "Atendiendo cliente ID: " << idCliente << endl;
    }
};

int main() {
    Banco banco; // Instancia del banco
    ColaClientes cola; // Instancia de la cola de clientes en la fila presencial

    // Cargar historial y clientes desde archivos
    // banco.cargarHistorialDesdeArchivo("historial.txt");
    // cola.cargarClientesDesdeArchivo("clientes.txt");

    // Agregar solicitudes de prueba
    banco.agregarSolicitud(1, "Juan", "VIP", "Activación de Tarjeta");
    banco.agregarSolicitud(2, "Jorge", "Regular", "Reposición de Tarjeta");
    banco.agregarSolicitud(3, "Ana", "VIP", "Reclamo de Cobro No Reconocido");
    banco.agregarSolicitud(4, "Pedro", "Regular", "Activación de Tarjeta");
    banco.agregarSolicitud(5, "Sofia", "Regular", "Activación de Tarjeta");
    banco.agregarSolicitud(6, "Luis", "Preferencial", "Reposición de Tarjeta");
    banco.agregarSolicitud(7, "Carlos", "VIP", "Activación de Tarjeta");
    banco.agregarSolicitud(8, "Laura", "Preferencial", "Reclamo de Cobro No Reconocido");
    banco.agregarSolicitud(9, "Maria", "Preferencial", "Reposición de Tarjeta");

    // Interacción con el usuario
    int opcion;
    do {
        cout << "\nMenu:\n1. Agregar Solicitud (Virtual)\n2. Atender Solicitud (Virtual)\n3. Mostrar Historial (Transacciones Virtuales)\n4. Consultar Estado (Transacciones Virtuales)\n5. Atender Cliente (Presencial)\n6. Salir\nElija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int idCliente;
                string nombreCliente, tipo, descripcion;
                cout << "Ingrese ID de cliente: ";
                cin >> idCliente;
                cout << "Ingrese nombre de cliente: ";
                cin >> nombreCliente;
                cout << "Ingrese tipo de solicitud (VIP, Preferencial, Regular): ";
                cin >> tipo;
                cout << "Ingrese descripción: ";
                cin.ignore(); // Ignora el salto de línea
                getline(cin, descripcion);
                banco.agregarSolicitud(idCliente, nombreCliente, tipo, descripcion); // Agrega la solicitud
                break;
            }
            case 2:
                banco.atenderSolicitud(); // Atiende la siguiente solicitud
                break;
            case 3:
                banco.mostrarHistorial(); // Muestra el historial de solicitudes
                break;
            case 4: {
                int idSolicitud;
                cout << "Ingrese ID de solicitud: ";
                cin >> idSolicitud;
                banco.consultarEstado(idSolicitud); // Consulta el estado de la solicitud
                break;
            }
            case 5:
                cola.atenderCliente(banco); // Atiende al siguiente cliente en la cola
                break;
            case 6:
                cout << "Saliendo del programa..." << endl; // Mensaje de salida
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl; // Mensaje de error
        }
    } while (opcion != 6);

    return 0; // Fin del programa
}