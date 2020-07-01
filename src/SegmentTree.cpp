#include "SegmentTree.h"
#include "Auto.h"
#include "Lista.h"

SegmentTree::SegmentTree(Lista<Auto> modelos [], unsigned int cantidad_modelos) {
    raiz = construir_segment_tree(modelos, raiz, 0, cantidad_modelos - 1);
}

SegmentTree::~SegmentTree() {
    vaciar_ST(raiz);
    raiz = NULL;
}

void SegmentTree::vaciar_ST(NodoS *& cursor) {
    if (cursor != NULL) {
        vaciar_ST(cursor->izq);
        vaciar_ST(cursor->der);
        delete cursor;
    }
};

SegmentTree::NodoS * SegmentTree::construir_segment_tree(Lista<Auto> modelos [], NodoS * S, unsigned int iIzq, unsigned int iDer) {
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
        return nuevo;
    }
}


Auto SegmentTree::obtener_mayor_precio_arreglo(Lista<Auto> modelos[], unsigned int iIzq, unsigned int iDer) {
    /**
     * Tomamos el primer auto para comparar.
     * Porque si utilizamos punteros asignariamos una direccion de memoria temporal.
     * mayorPrecio = (&modelos[i].obtener_cursor());
     */
    modelos[0].iniciar_cursor();
    Auto mayorPrecio = modelos[0].obtener_cursor();

    for (unsigned int i = iIzq; i <= iDer ; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j++) {
            if ( mayorPrecio.obtener_precio() < modelos[i].obtener_cursor().obtener_precio())
                mayorPrecio = modelos[i].obtener_cursor();
            modelos[i].avanzar_cursor();
        }
    }
    return mayorPrecio;
}

Auto SegmentTree::obtener_menor_precio_arreglo(Lista<Auto> modelos[], unsigned int iIzq, unsigned int iDer) {
    /**
     * Tomamos el primer auto para comparar.
     * Porque si utilizamos punteros asignariamos una direccion de memoria temporal.
     * menorPrecio = (&modelos[i].obtener_cursor());
     */
    modelos[0].iniciar_cursor();
    Auto menorPrecio = modelos[0].obtener_cursor();

    for (unsigned int i = iIzq; i <= iDer ; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j++) {
            if ( menorPrecio.obtener_precio() > modelos[i].obtener_cursor().obtener_precio())
                menorPrecio = modelos[i].obtener_cursor();
            modelos[i].avanzar_cursor();
        }
    }
    return menorPrecio;
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

void SegmentTree::busqueda_rangos(NodoS * cursor, unsigned int iIzq, unsigned int iDer, Lista<Auto> & mayores, Lista<Auto> & menores) {
    if (cursor != NULL) {
        if ( (iIzq <= cursor->indice_menor) && (iDer >= cursor->indice_mayor) ) {
            mayores.agregar(cursor->mayor_precio, 0);
            menores.agregar(cursor->menor_precio, 0);
        } else if ( (iIzq > cursor->indice_mayor) || (iDer < cursor->indice_menor) ) {
            return;
        } else {
            busqueda_rangos(cursor->izq, iIzq, iDer, mayores, menores);
            busqueda_rangos(cursor->der, iIzq, iDer, mayores, menores);
        }
    }
}

/// DEV
void SegmentTree::mostrar_segment_tree(NodoS * cursor, unsigned int nivel) {
    if (cursor != NULL) {
        mostrar_segment_tree(cursor->izq, nivel + 1);
        for (unsigned int i=0; i < nivel; i++ )
            cout << "\t";
        cout << "[" << cursor->indice_menor  << "," << cursor->indice_mayor << "]" << endl;
        mostrar_segment_tree(cursor->der,  nivel + 1);
    }
}

Auto SegmentTree::mayor_lista(Lista<Auto> l) {
    l.iniciar_cursor();
    Auto mayor_auto = l.obtener_cursor();
    for (unsigned int i = 0; i < l.logitud(); i++) {
        if ( l.obtener_cursor().obtener_precio() > mayor_auto.obtener_precio() )
            mayor_auto = l.obtener_cursor();
        l.avanzar_cursor();
    }
    return mayor_auto;
}

Auto SegmentTree::menor_lista(Lista<Auto> l) {
    l.iniciar_cursor();
    Auto menor_auto = l.obtener_cursor();
    for (unsigned int i = 0; i < l.logitud(); i++) {
        if ( l.obtener_cursor().obtener_precio() < menor_auto.obtener_precio() )
            menor_auto = l.obtener_cursor();
        l.avanzar_cursor();
    }
    return menor_auto;
}

void SegmentTree::obtener_mayor_menor_precio_entre_modelos(unsigned int menor_modelo, unsigned int mayor_modelo) {
    if ( menor_modelo > mayor_modelo)
        cout << "Error: Ingrese obtener_mayor_precio_entre_modelos(menor_modelo, mayor_modelo)" << endl;
    else {
        unsigned int iIzq = menor_modelo - 2000;
        unsigned int iDer = mayor_modelo - 2000;

        Lista<Auto> mayores;
        Lista<Auto> menores;

        busqueda_rangos(raiz, iIzq, iDer, mayores, menores);

        Auto mayor_auto = mayor_lista(mayores);
        Auto menor_auto = menor_lista(menores);

        cout << "El auto de mayor precio entre el modelo " << menor_modelo << " y " << mayor_modelo << endl;
        mayor_auto.imprimir();

        cout << "El auto de menor precio entre el modelo " << menor_modelo << " y " << mayor_modelo << endl;
        menor_auto.imprimir();

        /// DEV
        int nivel = 0;
        mostrar_segment_tree(raiz, nivel);

        int e;
        cin >> e;
    }
}

