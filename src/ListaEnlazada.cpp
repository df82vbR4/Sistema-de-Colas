#include "ListaEnlazada.h"
#include <iostream>

template <typename T>
ListaEnlazada<T>::ListaEnlazada() : cabeza(nullptr) {}

template <typename T>
ListaEnlazada<T>::~ListaEnlazada() {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
void ListaEnlazada<T>::agregar(const T& dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

template <typename T>
void ListaEnlazada<T>::eliminar(const T& dato) {
    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        if (anterior == nullptr) {
            cabeza = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
    }
}

template <typename T>
bool ListaEnlazada<T>::buscar(const T& dato) const {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == dato) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}
