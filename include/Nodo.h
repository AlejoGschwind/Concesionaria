#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
    public:
        Nodo();
        ~Nodo();
        T elem;
        Nodo * izq;
        Nodo * der;
};

#endif // NODO_H
