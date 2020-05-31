#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista {
    private:
        struct Nodo {
            T elem;
            Nodo * sig;
        };

        void vaciarLista();

        void insertarLista(Nodo *&cursor, Nodo * aAgregar, int pos);

        T obtenerElemento(const Nodo * cursor, int pos) const;

        Nodo * crearNodo(T elem);

    public:
        // Constructor.
        Lista();
        // Destructor.
        ~Lista();

        int logitud() const;

        T obtener(int pos) const;

        void agregar(T elem, int pos);

        void impirmir() const;



    private:
        Nodo * primero;
        int cant;
};

#endif // LISTA_H
