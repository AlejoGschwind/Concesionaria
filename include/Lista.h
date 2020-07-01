#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista {
    private:
        struct Nodo {
            T elem;
            Nodo * sig;
        };

        void vaciarLista(Nodo *& p);

        void insertarLista(Nodo *&cursor, Nodo * aAgregar, unsigned int pos);

        T obtenerElemento(const Nodo * cursor, unsigned int pos) const;

        Nodo * crearNodo(T elem);

    public:
        // Constructor.
        Lista();
        // Destructor.
        ~Lista();

        unsigned int logitud() const;

        T obtener(unsigned int pos) const;

        void agregar(T elem, unsigned int pos);

        void impirmir() const;

        void iniciar_cursor();

        void avanzar_cursor();

        T obtener_cursor();

    private:
        Nodo * primero;
        Nodo * cursor;
        unsigned int cant;
};

#endif // LISTA_H
