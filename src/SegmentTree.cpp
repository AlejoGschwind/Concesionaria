#include "SegmentTree.h"
#include "Auto.h"
#include "Lista.h"

SegmentTree::SegmentTree(Lista<Auto> modelos [], int cantidad_modelos) {
    raiz = new NodoS;
    raiz->der = NULL;
    raiz->izq = NULL;
    raiz = construir_segment_tree(modelos, raiz, 0, cantidad_modelos - 1);
    raiz->izq->mayor_precio.imprimir();
    raiz->der->mayor_precio.imprimir();
}

SegmentTree::~SegmentTree() {

}

SegmentTree::NodoS * SegmentTree::construir_segment_tree(Lista<Auto> modelos [], NodoS * S, int iIzq, int iDer) {
    if (iIzq == iDer) {
        NodoS * nuevo = new NodoS();

        nuevo->izq = NULL;
        nuevo->der = NULL;
        nuevo->mayor_precio = obtener_mayor_precio_arreglo(modelos, iIzq, iDer);
        nuevo->menor_precio = obtener_menor_precio_arreglo(modelos, iIzq, iDer);
        nuevo->indice_menor = iIzq;
        nuevo->indice_mayor = iDer;
        return nuevo;
    } else {
        int iMedio = (iDer + iIzq) / 2;
        NodoS * izq = construir_segment_tree(modelos, S, iIzq, iMedio);
        NodoS * der = construir_segment_tree(modelos, S, iMedio + 1, iDer);

        S->izq = izq;
        S->der = der;
        S->mayor_precio = obtener_mayor_precio(izq, der);
        S->menor_precio = obtener_menor_precio(izq, der);
        S->indice_menor = iIzq;
        S->indice_mayor = iDer;
        return S;
    }
}


Auto SegmentTree::obtener_mayor_precio_arreglo(Lista<Auto> modelos[], int iIzq, int iDer) {
    Auto mayorPrecio;
    for (unsigned int i = iIzq; i <= iDer ; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j++) {
            if ( mayorPrecio.obtener_precio() < modelos[i].obtener_cursor().obtener_precio() )
                mayorPrecio = modelos[i].obtener_cursor();
            modelos[i].avanzar_cursor();
        }
    }
    return mayorPrecio;
}

Auto SegmentTree::obtener_menor_precio_arreglo(Lista<Auto> modelos[], int iIzq, int iDer) {
    Auto menorPrecio;
    for (unsigned int i = iIzq; i <= iDer ; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j++) {
            if ( menorPrecio.obtener_precio() > modelos[i].obtener_cursor().obtener_precio() )
                menorPrecio = modelos[i].obtener_cursor();
            modelos[i].avanzar_cursor();
        }
    }
    return menorPrecio;
}

Auto SegmentTree::obtener_mayor_precio(NodoS * izq, NodoS * der) {
    if (izq->mayor_precio.obtener_precio() < der->mayor_precio.obtener_precio())
        return der->mayor_precio;
    else
        return izq->mayor_precio;
}

Auto SegmentTree::obtener_menor_precio(NodoS * izq, NodoS * der) {
    if (izq->menor_precio.obtener_precio() > der->menor_precio.obtener_precio())
        return der->menor_precio;
    else
        return izq->menor_precio;
}

SegmentTree::NodoS * SegmentTree::busqueda_rangos(NodoS * cursor, unsigned int iIzq, unsigned int iDer) {
    if (cursor != NULL) {
        cout << "1-----" << endl;
        //cursor->mayor_precio.imprimir();
        //cursor->izq->mayor_precio.imprimir();
        cout << "1-----" << endl;
        cursor->der->mayor_precio.imprimir();
        cursor->der->menor_precio.imprimir();
        //busqueda_rangos(cursor->izq, iIzq, iDer);
        cout << "2-----" << endl;
        //if (cursor->indice_menor == iIzq && cursor->indice_mayor == iDer)
        //    return cursor;
        //busqueda_rangos(cursor->der, iIzq, iDer);
    }
}

void SegmentTree::obtener_mayor_menor_precio_entre_modelos(unsigned int menor_modelo, unsigned int mayor_modelo) {
    if ( menor_modelo > mayor_modelo)
        cout << "Error: Ingrese obtener_mayor_precio_entre_modelos(menor_modelo, mayor_modelo)" << endl;
    else {
        unsigned int iIzq = menor_modelo - 2000;
        unsigned int iDer = mayor_modelo - 2000;
        NodoS * nodoConRangos = busqueda_rangos(raiz, iIzq, iDer);
        //nodoConRangos->mayor_precio.imprimir();
        //nodoConRangos->menor_precio.imprimir();
    }
}

