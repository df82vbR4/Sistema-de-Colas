#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

using namespace std;

// Clase que representa un nodo en la lista enlazada
template <typename T>
class Nodo {
public:
    T dato;           // Dato almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo

    // Constructor que inicializa el dato y el puntero al siguiente nodo
    Nodo(const T& dato) : dato(dato), siguiente(nullptr) {}
};

// Clase que representa una lista enlazada
template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor que inicializa la lista vacía
    ListaEnlazada();

    // Destructor que libera la memoria de los nodos
    ~ListaEnlazada();

    // Método para agregar un dato a la lista
    void agregar(const T& dato);

    // Método para eliminar un dato de la lista
    void eliminar(const T& dato);

    // Método para buscar un dato en la lista
    bool buscar(const T& dato) const;
};

#include "ListaEnlazada.cpp"

#endif // LISTAENLAZADA_H
