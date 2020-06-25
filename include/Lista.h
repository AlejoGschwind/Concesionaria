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

        void iniciar_cursor();

        void avanzar_cursor();

        T obtener_cursor();

    private:
        Nodo * primero;
        Nodo * cursor;
        int cant;
};

#endif // LISTA_H
