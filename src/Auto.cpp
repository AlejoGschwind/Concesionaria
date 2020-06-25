#include<iostream>
#include "Auto.h"
#include "Lista.h"

using namespace std;

Auto::Auto(){
}

Auto::Auto(int modelo, string marca, string patente, float precio, Lista<string> * lCarac){
  this->modelo = modelo;
  this->marca = marca;
  this->patente = patente;
  this->precio = precio;
  this->caracteristicas = lCarac;
}

// Destructor
Auto::~Auto() {
    //(*caracteristicas).~Lista();
}

// Observadoras
int Auto::obtener_modelo() const {
  return modelo;
}

string Auto::obtener_marca() const {
  return marca;
}

string Auto::obtener_patente() const {
  return patente;
}

float Auto::obtener_precio() const {
  return precio;
}

void Auto::listarCaracteristicas() const {
    cout << "\t..:Caracteristicas:.." << endl;
    for (int i=0; i < (*caracteristicas).logitud(); i++)
        cout << "\t- " << (*caracteristicas).obtener(i) << endl;
}

void Auto::imprimir() const {
    cout << endl;
    cout << "\t..:::::::::::::::::.." << endl;
    cout << endl;
    cout << "\t" << "Patente: " << patente << endl;
    cout << "\t" << "Modelo: " << modelo << endl;
    cout << "\t" << "Marca: " << marca << endl;
    cout << "\t" << "Precio: " << precio << endl;
    cout << endl;
    (*this).listarCaracteristicas();
}

// Modificadoras
void Auto::modificar_modelo(int modelo) {
    this->modelo = modelo;
}

void Auto::modificar_marca(string marca) {
    this->marca = marca;
}

void Auto::modificar_patente(string patente) {
    this->patente = patente;
}

void Auto::modificar_precio(float precio) {
    this->precio = precio;
}

void Auto::agregarCaracteristica(string caracteristica) {
    (*caracteristicas).agregar(caracteristica, (*caracteristicas).logitud());
}

bool Auto::operator>=(const Auto & otroAuto) const {
  return (patente >= otroAuto.obtener_patente());
};

bool Auto::operator<(const Auto & otroAuto) const {
  return (patente < otroAuto.obtener_patente());
};

bool Auto::operator==(const Auto & otroAuto) const {
  return (patente == otroAuto.obtener_patente());
};

ostream& operator<<(ostream & os, const Auto & a) {
    a.imprimir();
    return os;
}


