#include "../include/Arista.h"

// Constructor
Arista::Arista(int origen, int destino, double velocidad, double distancia) {
    this->origen = origen;
    this->destino = destino;
    this->velocidad = velocidad;
    this->distancia = distancia;
};

// Destructor
Arista::~Arista() {
    
};

// Getters
int Arista::getOrigen() {
    return this->origen;
};

int Arista::getDestino() {
    return this->destino;
};

double Arista::getVelocidad() {
    return this->velocidad;
};

double Arista::getDistancia() {
    return this->distancia;
};

// Calculamos el peso de la arista en base al peso del archivo
double Arista::getPeso(double pesoArchivo) {
    // El peso de la arista es el tiempo que demora el archivo completo en llegar a destino
    return (ceil(pesoArchivo/velocidad)) * distancia;
};