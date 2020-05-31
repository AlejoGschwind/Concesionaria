#include <iostream>
#include "Nodo.h"
#include "Auto.h"

using namespace std;

template <typename T>
Nodo<T>::Nodo() {
    izq = NULL;
    der = NULL;
}

template <typename T>
Nodo<T>::~Nodo() {
}

template class Nodo<int>;
template class Nodo<Auto>;
