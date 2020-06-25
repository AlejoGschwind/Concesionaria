#include "Lista.h"
#include "Auto.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
Lista<T>::Lista() {
    primero = NULL;
    cursor = NULL;
    cant = 0;
}

template <typename T>
Lista<T>::~Lista() {
    vaciarLista();
}

/// Privados

/**
 * Vacia la lista por compelo.
 */
template <typename T>
void Lista<T>::vaciarLista() {
    Nodo * cursor;
    while ( primero != NULL ) {
        cursor = primero->sig;
        delete primero;
        primero = cursor;
    }
    primero = NULL;
}

/**
 * Inserta un nodo en la posicion pasada por paramentro.
 * (pos >=0 and <= cant)
 */
template <typename T>
void Lista<T>::insertarLista(Nodo *&cursor, Nodo * aAgregar, int pos) {
    if ( cursor == NULL or pos == 0 ) {
        aAgregar->sig = cursor;
        cursor = aAgregar;
    } else {
        if ( pos == 1) {
            aAgregar->sig = cursor->sig;
            cursor->sig = aAgregar;
        } else
            insertarLista(cursor->sig, aAgregar, pos - 1);
    }
}

template <typename T>
void Lista<T>::impirmir() const {
    Nodo * cursor = primero;
    while ( cursor != NULL) {
        cout << cursor->elem << endl;
        cursor = cursor->sig;
    }
}

/**
 * Retorna el elemento de determinada posicion.
 * (pos >=0 and < cant)
 */
template <typename T>
T Lista<T>::obtenerElemento(const Nodo * cursor, int pos) const {
    if ( pos == 0 )
        return cursor->elem;
    else
        return obtenerElemento(cursor->sig, pos - 1);
}

/**
 * Crea un nuevo nodo y retorna un puntero al nuevo nodo.
 */
template <typename T>
typename Lista<T>::Nodo * Lista<T>::crearNodo(T elem) {
    Nodo * nuevo = new Nodo();
    nuevo->elem = elem;
    nuevo->sig = NULL;
    return nuevo;
}

/// Publicos

/**
 * Verifica que pos sea valida.
 * Agrega un nuevo nodo a la lista.
 * Actualiza la logitud de la lista.
 */
template <typename T>
void Lista<T>::agregar(T elem, int pos) {
    assert(pos>=0 and pos<= cant); /// Error: pos invalida.
    Nodo * aAgregar = crearNodo(elem);
    insertarLista(primero, aAgregar, pos);
    cant += 1;
}

/**
 * Devuelve la logitud de la lista.
 */
template <typename T>
int Lista<T>::logitud() const {
    return cant;
}

/**
 * Verifica que pos sea valida.
 * Devuelve el elemento de la posicion pasada por paramentro.
 */
template <typename T>
T Lista<T>::obtener(int pos) const {
    assert(pos>=0 and pos< cant); /// Error: pos invalida.
    return obtenerElemento(primero, pos);
}


/**
 * Metodos para trabajar con la lista fuera de la clase.
 * Inicializa el cursor en el primer elemento
 */
template <typename T>
void Lista<T>::iniciar_cursor() {
    cursor = primero;
};

/**
 * Avanza una posicion con el cursor
 */
template <typename T>
void Lista<T>::avanzar_cursor() {
    cursor = cursor->sig;
};

/**
 * Devuele el elemento al cual apunta el cursor.
 */
template <typename T>
T Lista<T>::obtener_cursor() {
    return cursor->elem;
};

template class Lista<string>;
template class Lista<Auto>;



