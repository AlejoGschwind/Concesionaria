#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <iostream>
#include "Lista.h"

using namespace std;

class Auto{
    public:
        Auto();
        Auto(int modelo, string marca, string patente, float precio, Lista<string> * lCarac);
        ~Auto();

        // Observadoras.
        int obtener_modelo() const;
        string obtener_patente() const;
        string obtener_marca() const;
        float obtener_precio() const;
        void listarCaracteristicas() const;
        void imprimir() const;

        // Modificadoras.
        void modificar_modelo(int modelo);
        void modificar_marca(string marca);
        void modificar_patente(string patente);
        void modificar_precio(float precio);
        void agregarCaracteristica(string caracteristica);

        // Operadores de comparacion.
        bool operator>=(const Auto & otroAuto) const;
        bool operator<(const Auto & otroAuto) const;
        bool operator==(const Auto & otroAuto) const;
        friend ostream& operator<<(ostream& os, const Auto & a);
    private:
        int modelo;
        string patente;
        string marca;
        float precio;
        Lista<string> * caracteristicas;
};

#endif // AUTO_H_INCLUDED
