#include <iostream>
#include <fstream>
#include "Auto.h"
#include "Lista.h"
#include "Concesionaria.h"

using namespace std;

/**
 * Abre el archivo seg�n el origen, procesa las l�neas del mismo y
 * almacena la informaci�n resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen, Concesionaria & c);

int main() {
    Concesionaria c;

    procesar_archivo_entrada("autos.csv", c);

    string patente;
    Auto amp;
    int modelo;
    int opt;
    system("clear");
    do {
        cout << "0) Salir." << endl
        << "1) Existe Patente." << endl
        << "2) Mayor precio." << endl
        << "3) Listar modelo." << endl
        << "Ingrese una opcion: ";
        cin >> opt;
        switch (opt) {
        case 1:
            system("clear");
            cout << "Ingrese una patente: ";
            cin >> patente;
            if (c.existePatente(patente))
                cout << "Existe un auto con la patente " << patente << endl;
            else
                cout << "No existe un auto con la patente " << patente << endl;
            break;
        case 2:
            system("clear");
            cout << "Auto de mayor precio:" << endl;
            c.imprimirMayorPrecio();
            break;
        case 3:
            system("clear");
            cout << "Ingrese un modelo: ";
            cin >> modelo;
            c.listarPorModelo(modelo);
            break;
        default:
            break;
        }
    } while (opt != 0);
    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a n�mero, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen, Concesionaria & c) {
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_autos = atoi(linea.c_str());

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posici�n del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            int modelo = atoi(linea.substr(pos_inicial, pos_final).c_str());

            //Segunda posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string marca = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string patente = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            Lista<string> * lCarac = new Lista<string>();
            //Auto a(modelo, marca, patente, precio);
            //a.imprimir();

            //Desde esta posici�n hasta el final se encuentra un n�mero variable de caracteristicas.
            string caracteristicas = linea.substr(pos_final + 1, linea.size());
            int pos_inicial_guion = 0, pos_final_guion = 0;
            while (pos_final_guion != -1) {
                pos_final_guion = caracteristicas.find('-', pos_inicial_guion);
                string caracteristica = caracteristicas.substr(pos_inicial_guion, pos_final_guion - pos_inicial_guion);
                pos_inicial_guion = pos_final_guion + 1;

                (*lCarac).agregar(caracteristica, 0);

            }

            c.agregarAuto(modelo, marca, patente, precio, lCarac);

        }
    }
}
