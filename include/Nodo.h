#pragma once
#include <iostream>

using namespace std;

// Clase que representa un nodo de la red
class Nodo {
    private:
        int id; // Identificador del nodo
        string nombre; // Nombre del nodo
        string tipo; // Tipo del nodo (cliente o router)
    public:
        Nodo(int, string, string);
        ~Nodo();
        int getId();
        string getNombre();
        string getTipo();
};