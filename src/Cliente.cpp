#include "Cliente.h"

Cliente::Cliente(const string& nombre, int numeroCuenta)
    : nombre(nombre), numeroCuenta(numeroCuenta) {}

string Cliente::getNombre() const {
    return nombre;
}

int Cliente::getNumeroCuenta() const {
    return numeroCuenta;
}
