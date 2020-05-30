#include <iostream>
#include <fstream>
#include "Auto.h"
#include "Arbol.h"
#include "Lista.h"
#include "Nodo.h"

using namespace std;

/**
 * Abre el archivo seg�n el origen, procesa las l�neas del mismo y
 * almacena la informaci�n resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen);
void mostrarArbol(Nodo<int> * cursor) {
    if ( cursor != NULL ) {
        mostrarArbol(cursor->izq);
        cout << cursor->elem << endl;
        mostrarArbol(cursor->der);
    }
}

int main()
{
    /** Prueba LISTA
    Lista<string> nombres;
    nombres.agregar("Alejo", 0);
    nombres.agregar("Alvaro", 1);
    nombres.agregar("Pedro", 2);
    nombres.agregar("Roberto", 3);
    nombres.agregar("Juan", 4);

    cout << "\t..:Nombres:.." << endl;
    for (int i = 0; i < nombres.logitud(); i++)
        cout << nombres.obtener(i) << endl;
    */

    /** Prueba ARBOL
     *
     */
    Arbol<int> enteros;

    enteros.insertar(5);
    enteros.insertar(7);
    enteros.insertar(40);
    enteros.insertar(2);
    enteros.insertar(3);
    enteros.insertar(8);
    enteros.insertar(6);
    enteros.insertar(1);

    mostrarArbol(enteros.obtenerRaiz());

    // enteros.mostrarEnOrden();


    //procesar_archivo_entrada("autos.csv");
    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a n�mero, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_autos = atoi(linea.c_str());
        // cout << "Se cargar�n " << cantidad_autos << " autos." << endl;

        // Arbol<Auto> autos;

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

            //TODO: Informacion general del auto. ✔️

            // cout << a.obtener_modelo()
            // << "-"<< a.obtener_marca()
            // <<"-"<< a.obtener_patente()
            // <<"-"<< a.obtener_precio() <<endl;
            // Lista<string> caracteristicas;

            // cout << arb.obtener_raiz().obtener_modelo() << endl;

            //Desde esta posici�n hasta el final se encuentra un n�mero variable de caracteristicas.
            string caracteristicas = linea.substr(pos_final + 1, linea.size());
            int pos_inicial_guion = 0, pos_final_guion = 0;
            while (pos_final_guion != -1) {
                pos_final_guion = caracteristicas.find('-', pos_inicial_guion);
                string caracteristica = caracteristicas.substr(pos_inicial_guion, pos_final_guion - pos_inicial_guion);
                pos_inicial_guion = pos_final_guion + 1;

                // caracteristicas.agregar(caracteristica);
                //TO DO: Nueva caracteristica encontrada.
                // cout << "  - " << caracteristica << endl;
            }
            Auto a = Auto(modelo, marca, patente, precio);
            //autos.agregar(a);

        }

        Auto a1;
        a1.modificar_patente("HRM111");
        //cout << autos.existeElemento(a1) << endl;
        /*
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
            << "4) Listar todos." << endl
            << "Ingrese una opcion: ";
            cin >> opt;
            switch (opt) {
            case 1:
                system("clear");
                cout << "Ingrese una patente: ";
                cin >> patente;
                if (autos.existe_patente(patente))
                    cout << "Existe un auto con la patente " << patente << endl;
                else
                    cout << "No existe un auto con la patente " << patente << endl;
                break;
            case 2:
                system("clear");
                amp = autos.mayor_precio();
                cout << "Auto de mayor precio:" << endl
                << amp.obtener_modelo() << ' '
                << amp.obtener_marca() << ' '
                << amp.obtener_patente() << ' '
                << amp.obtener_precio() << endl;
                break;
            case 3:
                system("clear");
                cout << "Ingrese un modelo: ";
                cin >> modelo;
                autos.listar_modelo(modelo);
                break;
            case 4:
                system("clear");
                cout << "Todos los autos: " << endl;
                autos.mostrar_arbol();
                break;
            default:
                break;
            }
        } while (opt != 0);
        */
    }
}
