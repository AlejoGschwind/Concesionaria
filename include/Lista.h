#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista {
    private:
        struct Nodo {
            T elem;
            Nodo * sig;
        };

        void vaciarLista( Nodo *& cursor);

        void insertarLista(Nodo *&cursor, Nodo * aAgregar, int pos);

        T obtenerElemento(const Nodo * cursor, int pos);

        Nodo * crearNodo(T elem);

    public:
        // Constructor.
        Lista();
        // Destructor.
        ~Lista();

        int logitud();

        T obtener(int pos);

        void agregar(T elem, int pos);



    private:
        Nodo * primero;
        int cant;
};

#endif // LISTA_H
