#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <iostream>
#include "Lista.h"

using namespace std;

class Auto{
    public:
        Auto();
        Auto(int,string,string,float);
        ~Auto();
        int obtener_modelo()const;
        string obtener_patente()const;
        string obtener_marca()const;
        float obtener_precio()const;
        //string Listar_Caracteristicas();
        void modificar_modelo(int modelo);
        void modificar_marca(string marca);
        void modificar_patente(string patente);
        void modificar_precio(float precio);

        // Operadores de comparacion a1 == a2
        bool operator>=(const Auto & otroAuto) const;
        bool operator<(const Auto & otroAuto) const;
        bool operator==(const Auto & otroAuto) const;
    private:
        int modelo;
        string patente;
        string marca;
        float precio;
        Lista<string> caracteristicas;
};

#endif // AUTO_H_INCLUDED
