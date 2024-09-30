#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

// Clase que representa a un cliente en el sistema de colas
class Cliente {
private:
    string nombre; // Nombre del cliente
    int numeroCuenta;   // Número de cuenta del cliente

public:
    // Constructor que inicializa el nombre y el número de cuenta del cliente
    Cliente(const string& nombre, int numeroCuenta);

    // Método que devuelve el nombre del cliente
    string getNombre() const;

    // Método que devuelve el número de cuenta del cliente
    int getNumeroCuenta() const;
};

#endif // CLIENTE_H
