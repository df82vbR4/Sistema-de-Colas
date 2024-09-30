#ifndef COLA_H
#define COLA_H

#include <queue>
#include "Cliente.h"

using namespace std;

// Clase que representa una cola de clientes
class Cola {
private:
    queue<Cliente> colaClientes; // Cola de clientes

public:
    // Método para agregar un cliente a la cola
    void agregarCliente(const Cliente& cliente);

    // Método para atender al siguiente cliente en la cola
    Cliente atenderCliente();

    // Método que verifica si la cola está vacía
    bool estaVacia() const;
};

#endif // COLA_H
