#include "Cola.h"

void Cola::agregarCliente(const Cliente& cliente) {
    colaClientes.push(cliente);
}

Cliente Cola::atenderCliente() {
    if (!colaClientes.empty()) {
        Cliente cliente = colaClientes.front();
        colaClientes.pop();
        return cliente;
    }
    // Manejar el caso en que la cola esté vacía
    return Cliente("", -1); // Cliente inválido
}

bool Cola::estaVacia() const {
    return colaClientes.empty();
}
