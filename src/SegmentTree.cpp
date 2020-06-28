#include "SegmentTree.h"
#include "Auto.h"
#include "Lista.h"

SegmentTree::SegmentTree(Lista<Auto> modelos [], int cantidad_modelos) {
    //NodoS * nuevo = new NodoS();

    raiz = construir_segment_tree(modelos, raiz, 0, cantidad_modelos - 1);

}

SegmentTree::~SegmentTree() {

}

SegmentTree::NodoS * SegmentTree::construir_segment_tree(Lista<Auto> modelos [], NodoS * S, int iIzq, int iDer) {
    if (iIzq < iDer) { // =
        int iMedio = (iDer + iIzq) / 2;
        NodoS * izq = construir_segment_tree(modelos, S, iIzq, iMedio);
        NodoS * der = construir_segment_tree(modelos, S, iMedio + 1, iDer);

        S = new NodoS();
        S->izq = izq;
        S->der = der;
        S->mayor_precio = obtener_mayor_precio(izq, der);
        S->menor_precio = obtener_menor_precio(izq, der);
        S->indice_menor = iIzq;
        S->indice_mayor = iDer;
        return S;
    } else {
        NodoS * nuevo = new NodoS();

        nuevo->izq = NULL;
        nuevo->der = NULL;
        nuevo->mayor_precio = obtener_mayor_precio_arreglo(modelos, iIzq, iDer);
        nuevo->menor_precio = obtener_menor_precio_arreglo(modelos, iIzq, iDer);
        nuevo->indice_menor = iIzq;
        nuevo->indice_mayor = iDer;
        //cout << "[" << S->indice_menor << " , "<< S->indice_mayor << "]" << endl;
        return nuevo;
    }
}


Auto SegmentTree::obtener_mayor_precio_arreglo(Lista<Auto> modelos[], int iIzq, int iDer) {
    Auto * mayorPrecio = NULL;
    for (unsigned int i = iIzq; i <= iDer ; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j++) {
            if ( ( mayorPrecio == NULL) || ( (*mayorPrecio).obtener_precio() < modelos[i].obtener_cursor().obtener_precio()) ) {
                mayorPrecio = (&modelos[i].obtener_cursor());
            }
            modelos[i].avanzar_cursor();
        }
    }
    //(*mayorPrecio).imprimir();
    return *(mayorPrecio);
}

Auto SegmentTree::obtener_menor_precio_arreglo(Lista<Auto> modelos[], int iIzq, int iDer) {
    Auto * menorPrecio = NULL;
    for (unsigned int i = iIzq; i <= iDer ; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j++) {
            if ( menorPrecio == NULL || ( (*menorPrecio).obtener_precio() > modelos[i].obtener_cursor().obtener_precio()) )
                menorPrecio = (&modelos[i].obtener_cursor());
            modelos[i].avanzar_cursor();
        }
    }
    return *(menorPrecio);
}

Auto SegmentTree::obtener_mayor_precio(NodoS * izq, NodoS * der) {
    if (izq->mayor_precio.obtener_precio() < der->mayor_precio.obtener_precio()) {
        return der->mayor_precio;
    }
    else {
        return izq->mayor_precio;
    }
}

Auto SegmentTree::obtener_menor_precio(NodoS * izq, NodoS * der) {
    if (izq->menor_precio.obtener_precio() > der->menor_precio.obtener_precio())
        return der->menor_precio;
    else
        return izq->menor_precio;
}

void SegmentTree::busqueda_rangos(NodoS * cursor, unsigned int iIzq, unsigned int iDer) {
    if (cursor != NULL) {
        if ( (iIzq == cursor->indice_menor) && (iDer == cursor->indice_mayor) ) {
            cursor->mayor_precio.imprimir();
            cursor->menor_precio.imprimir();
        }
        busqueda_rangos(cursor->izq, iIzq, iDer);
        busqueda_rangos(cursor->der, iIzq, iDer);
    }
}

void SegmentTree::mostrar_segment_tree(NodoS * cursor, int nivel) {
    if (cursor != NULL) {
        mostrar_segment_tree(cursor->izq, nivel + 1);
        for (int i=0; i < nivel; i++ )
            cout << "\t";
        cout << "[" << cursor->indice_menor  << "," << cursor->indice_mayor << "]" << endl;
        mostrar_segment_tree(cursor->der,  nivel + 1);
    }
}

void SegmentTree::obtener_mayor_menor_precio_entre_modelos(unsigned int menor_modelo, unsigned int mayor_modelo) {
    if ( menor_modelo > mayor_modelo)
        cout << "Error: Ingrese obtener_mayor_precio_entre_modelos(menor_modelo, mayor_modelo)" << endl;
    else {
        unsigned int iIzq = menor_modelo - 2000;
        unsigned int iDer = mayor_modelo - 2000;
        //cout << iIzq << endl;
        //cout << iDer << endl;
        busqueda_rangos(raiz, iIzq, iDer);
        int nivel = 0;
        mostrar_segment_tree(raiz, nivel);

       // cout << raiz->izq << endl;
       // cout << raiz->izq->izq << endl;
    }
}

