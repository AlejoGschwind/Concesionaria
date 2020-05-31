#include <iostream>
#include <typeinfo>
#include "Arbol.h"
#include "Auto.h"

using namespace std;

// Constructor
template <typename T>
Arbol<T>::Arbol() {
    raiz = NULL;
}

template <typename T>
Arbol<T>::~Arbol() {
    vaciarArbol(raiz);
    raiz = NULL;
}

/// PRIVADOS

/**
 * Vacia el arbol por completo.
 */
template <typename T>
void Arbol<T>::vaciarArbol(Nodo<T> *&cursor) {
    if (cursor != NULL) {
        vaciarArbol(cursor->izq);
        vaciarArbol(cursor->der);
        delete cursor;
    }
}

/**
 * Inserta Nodo ordenado al Arbol.
 */
template <typename T>
Nodo<T> * Arbol<T>::insertarArbol(Nodo<T> *&cursor, Nodo<T> *&aAgregar) {
    if ( cursor == NULL ) {
        cursor = aAgregar;
        return cursor;
    } else
        if ( cursor->elem >= aAgregar->elem )
            insertarArbol(cursor->izq, aAgregar);
        else
            insertarArbol(cursor->der, aAgregar);
}

template <typename T>
void Arbol<T>::enOrden(Nodo<T> * cursor) {
    if ( cursor != NULL ) {
        enOrden(cursor->izq);
        cout << cursor->elem << endl;
        enOrden(cursor->der);
    }
}

/// PUBLICOS
template <typename T>
Nodo<T> * Arbol<T>::insertar(T elem) {
    Nodo<T> * nuevo = new Nodo<T>;
    nuevo->elem = elem;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return insertarArbol(raiz, nuevo);
}

template <typename T>
void Arbol<T>::mostrarEnOrden() {
    enOrden(raiz);
}

template <typename T>
Nodo<T> * Arbol<T>::obtenerRaiz() {
    return raiz;
}

template class Arbol<int>;
template class Arbol<Auto>;
