#include <iostream>
#include <algorithm>
#include <fstream>
#include "Auto.h"
#include "Lista.h"
#include "Concesionaria.h"
#include "SegmentTree.h"

using namespace std;

/**
 * Abre el archivo seg�n el origen, procesa las l�neas del mismo y
 * almacena la informaci�n resultante en el contenedor pasado por referencia.
 **/
void segunda_parte();
void procesar_archivo_entrada(string origen, Concesionaria & c);
void procesar_archivo_entrada2(string origen, Lista<Auto> modelos[]);
void mostrar_autos(Lista<Auto> modelos[], unsigned int cantidad_modelos);

void primera_parte();

int main() {
    int opt;
    do {
        system("clear");
        cout << "0) Salir." << endl
        << "1) Parte 1 del trbajo." << endl
        << "2) Parte 2 del trabajo." << endl
        << "Ingrese una opcion: ";
        cin >> opt;
        switch (opt) {
        case 1:
            system("clear");
            primera_parte();
            break;
        case 2:
            system("clear");
            segunda_parte();
            break;
        default:
            break;
        }
    } while (opt != 0);

    //mostrar_autos(modelos, CANTIDAD_MODELOS); // Para Mostrar todos los modelos.

    return 0;
}

void primera_parte() {
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
            transform(patente.begin(), patente.end(), patente.begin(), ::toupper);
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
}

void segunda_parte() {
    // Estructura de almacenamiento.
    const unsigned int CANTIDAD_MODELOS = 21;

    Lista<Auto> modelos[CANTIDAD_MODELOS]; // Desde 2000 hasta 2020 [0,1,2,3...,19,20] cada indice coresponde a modelo - 2000.

    procesar_archivo_entrada2("autos.csv", modelos);

    SegmentTree s(modelos, CANTIDAD_MODELOS);

    int modelo1 = 2000;
    int modelo2 = 2020;
    int opt;
    do {
        cout << "0) Atras." << endl
        << "1) Obtener mayor y menor precio entre modelos." << endl
        << "2) Limpiar pantalla." << endl
        << "Ingrese una opcion: ";
        cin >> opt;
        switch (opt) {
        case 1:
            system("clear");
            do {
                if (modelo1 > modelo2 )
                    cout << "Rango invalido! Intente nuevamente." << endl;
                cout << "Modelos entre 2000 y 2020." << endl
                << "Ingrese un modelo: ";
                cin >> modelo1;
                cout << "Ingrese otro modelo mayor: ";
                cin >> modelo2;
                system("clear");
            } while ( modelo1 > modelo2 );
            s.obtener_mayor_menor_precio_entre_modelos(modelo1, modelo2);
            break;
        case 2:
            system("clear");
            break;
        default:
            system("clear");
            break;
        }
    } while (opt != 0);


}

//Comentarios: atoi y atof requieren un char * para converter a n�mero, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen, Concesionaria & c) {
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        //int cantidad_autos = atoi(linea.c_str());

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

void procesar_archivo_entrada2(string origen, Lista<Auto> modelos[]) {
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        //int cantidad_autos = atoi(linea.c_str());

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

            Auto a = Auto(modelo, marca, patente, precio, lCarac);

            modelos[modelo - 2000].agregar(a, 0);

        }
    }
}

void mostrar_autos(Lista<Auto> modelos[], unsigned int cantidad_modelos) {
    for (unsigned int i = 0; i < cantidad_modelos; i++) {
        modelos[i].iniciar_cursor();
        for (unsigned int j = 0; j < modelos[i].logitud(); j ++) {
            modelos[i].obtener_cursor().imprimir();
            modelos[i].avanzar_cursor();
        }
    }
}

