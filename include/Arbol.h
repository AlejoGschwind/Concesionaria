#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Nodo.h"

using namespace std;

template <typename T>
class Arbol {
    private:

        void vaciarArbol(Nodo<T> *&cursor);

        Nodo<T> * insertarArbol(Nodo<T> *&cursor, Nodo<T> *&aAgregar);

        void enOrden(Nodo<T> * cursor);
    public:
        Arbol();   // Constructor
        ~Arbol();  // Destructor

        Nodo<T> * insertar(T elem);

        void mostrarEnOrden();

        Nodo<T> * obtenerRaiz();

    private:
        Nodo<T> * raiz;
};


#endif // ARBOL_H_INCLUDED
