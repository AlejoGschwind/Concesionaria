#include "Nodo.h"
#include <iostream>

using namespace std;

template <typename T>
Nodo<T>::Nodo() {
    izq = NULL;
    der = NULL;
}

template <typename T>
Nodo<T>::~Nodo() {
    delete izq;
    delete der;
}

template class Nodo<int>;
