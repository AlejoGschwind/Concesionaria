#include<iostream>
#include "Auto.h"
#include "Lista.h"

using namespace std;

Auto::Auto(){
}

Auto::Auto(int modelo, string marca, string patente, float precio, Lista<string> caracteristicas){
  this->modelo = modelo;
  this->marca = marca;
  this->patente = patente;
  this->precio = precio;
  this->caracteristicas = caracteristicas;
}

// Destructor
Auto::~Auto() {
    caracteristicas.~Lista();
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

void Auto::listarCaracteristicas() {
    cout << "\t..:Caracteristicas:.." << endl;
    for (int i=0; i < caracteristicas.logitud(); i++)
        cout << "\t\t- " << caracteristicas.obtener(i) << endl;
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
    this->caracteristicas.agregar(caracteristica, caracteristicas.logitud());
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


