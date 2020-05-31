#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H
#include "Auto.h"
#include "Arbol.h"
#include "Nodo.h"

class Concesionaria {
    private:
        void listarModelo(Nodo<Auto> * cursor, int modelo);

        bool existeEnArbol(Nodo<Auto> * cursor, string patente);
    public:
        Concesionaria();
        ~Concesionaria();

        // Observadora.
        void listarPorModelo(int modelo);

        bool existePatente(string patente);

        void imprimirMayorPrecio();

        // Modificadora.
        void agregarAuto(int modelo, string marca, string patente, float precio, Lista<string> * lCarac);

    private:
        Arbol<Auto> autos;
        Nodo<Auto> * mayorPrecio;
        int cantidadAutos;
};

#endif // CONCESIONARIA_H
