#include <iostream>
#include "Concesionaria.h"
#include "Auto.h"
#include "Nodo.h"

using namespace std;

Concesionaria::Concesionaria() {
    this->cantidadAutos = 0;
    this->mayorPrecio = NULL;
}

Concesionaria::~Concesionaria() {
    autos.~Arbol();
}

/// Privadas
void Concesionaria::listarModelo(Nodo<Auto> * cursor, int modelo) {
    if ( cursor != NULL) {
        listarModelo(cursor->izq, modelo);
        if (cursor->elem.obtener_modelo() == modelo)
            cursor->elem.imprimir();
        listarModelo(cursor->der, modelo);
    }
}

bool Concesionaria::existeEnArbol(Nodo<Auto> * cursor, string patente) {
    if (cursor == NULL)
        return false;
    else
        if (cursor->elem.obtener_patente() == patente)
            return true;
        else {
            if (cursor->elem.obtener_patente() > patente)
                return existeEnArbol(cursor->izq, patente);
            else
                return existeEnArbol(cursor->der, patente);
        }
}

/// Publicas

void Concesionaria::agregarAuto(int modelo, string marca, string patente, float precio, Lista<string> * lCarac) {
    Auto * a = new Auto(modelo, marca, patente, precio, lCarac);

    Nodo<Auto> * agregado = autos.insertar((*a));

    if ( mayorPrecio == NULL )
        mayorPrecio = agregado;
    else
        if ( mayorPrecio->elem.obtener_precio() < precio)
            mayorPrecio = agregado;

    cantidadAutos++;

}

bool Concesionaria::existePatente(string patente) {
    return existeEnArbol(autos.obtenerRaiz(), patente);
}

void Concesionaria::imprimirMayorPrecio() {
    mayorPrecio->elem.imprimir();
}

void Concesionaria::listarPorModelo(int modelo) {
    listarModelo(autos.obtenerRaiz(), modelo);
}
