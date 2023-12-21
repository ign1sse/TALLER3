#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Arista {
    private:
        int origen; // Identificador del nodo de origen
        int destino; // Identificador del nodo de destino
        double velocidad; // Velocidad de conexión
        double distancia; // Distancia de conexión
    public:
        Arista(int, int, double, double);
        ~Arista();
        int getOrigen();
        int getDestino();
        double getVelocidad();
        double getDistancia();
        double getPeso(double);
};