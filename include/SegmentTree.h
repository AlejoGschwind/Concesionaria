#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include "Auto.h"
#include "Lista.h"


class SegmentTree {
    private:
        struct NodoS {
            Auto mayor_precio;
            Auto menor_precio;

            int indice_menor;
            int indice_mayor;

            NodoS * izq;
            NodoS * der;
        };

        Auto obtener_mayor_precio_arreglo(Lista<Auto> modelos[], int iIzq, int iDer);

        Auto obtener_menor_precio_arreglo(Lista<Auto> modelos[], int iIzq, int iDer);

        NodoS * construir_segment_tree(Lista<Auto> modelos[], NodoS * raiz, int iIzq, int iDer);

        Auto obtener_mayor_precio(NodoS * izq, NodoS * der);

        Auto obtener_menor_precio(NodoS * izq, NodoS * der);

        void busqueda_rangos(NodoS * raiz, unsigned int iIzq, unsigned int iDer);

        void mostrar_segment_tree(NodoS * cursor, int);

    public:
        SegmentTree(Lista<Auto> modelos[], int cantidad_modelos);

        ~SegmentTree();

        void obtener_mayor_menor_precio_entre_modelos(unsigned int menor_modelo, unsigned int mayor_modelo);




    private:
        NodoS * raiz;
};

#endif // SEGMENTTREE_H
