#include "Auto.h"
#include<iostream>

using namespace std;


Auto::Auto(){
}


Auto::Auto(int modelo, string marca, string patente, float precio){
  this->modelo = modelo;
  this->marca = marca;
  this->patente = patente;
  this->precio = precio;
}

// Destructor
Auto::~Auto() {}

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

bool Auto::operator>=(const Auto & otroAuto) const {
  return (patente >= otroAuto.obtener_patente());
};

bool Auto::operator<(const Auto & otroAuto) const {
  return (patente < otroAuto.obtener_patente());
};

bool Auto::operator==(const Auto & otroAuto) const {
  return (patente == otroAuto.obtener_patente());
};


