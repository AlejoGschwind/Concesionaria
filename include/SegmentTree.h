#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include "Auto.h"
#include "Lista.h"


class SegmentTree {
    private:
        struct NodoS {
            Auto mayor_precio;
            Auto menor_precio;

            unsigned int indice_menor;
            unsigned int indice_mayor;

            NodoS * izq;
            NodoS * der;
        };

        void vaciar_ST(NodoS *& cursor);

        Auto obtener_mayor_precio_arreglo(Lista<Auto> modelos[], unsigned int iIzq, unsigned int iDer);

        Auto obtener_menor_precio_arreglo(Lista<Auto> modelos[], unsigned int iIzq, unsigned int iDer);

        NodoS * construir_segment_tree(Lista<Auto> modelos[], NodoS * raiz, unsigned int iIzq, unsigned int iDer);

        Auto obtener_mayor_precio(NodoS * izq, NodoS * der);

        Auto obtener_menor_precio(NodoS * izq, NodoS * der);

        void busqueda_rangos(NodoS * raiz, unsigned int iIzq, unsigned int iDer, Lista<Auto> & mayores, Lista<Auto> & menores);

        void mostrar_segment_tree(NodoS * cursor, unsigned int nivel);

        Auto mayor_lista(Lista<Auto> l);

        Auto menor_lista(Lista<Auto> l);

    public:
        SegmentTree(Lista<Auto> modelos[], unsigned int cantidad_modelos);

        ~SegmentTree();

        void obtener_mayor_menor_precio_entre_modelos(unsigned int menor_modelo, unsigned int mayor_modelo);




    private:
        NodoS * raiz;
};

#endif // SEGMENTTREE_H
