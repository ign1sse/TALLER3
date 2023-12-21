#include "../include/Nodo.h"

// Constructor
Nodo::Nodo(int id, string nombre, string tipo) {
    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
};

// Destructor
Nodo::~Nodo() {
    
};

// Getters
int Nodo::getId() {
    return this->id;
};

string Nodo::getNombre() {
    return this->nombre;
};

string Nodo::getTipo() {
    return this->tipo;
};