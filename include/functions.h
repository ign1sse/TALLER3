#pragma once
// Incluir las librerías necesarias
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "Nodo.h" // Para usar la clase Nodo
#include "Arista.h" // Para usar la clase Arista

using namespace std;

// Función para buscar un elemento en un vector de enteros
// Recibe como parámetros el vector y el elemento a buscar
// Retorna true si el elemento se encuentra en el vector y false en caso contrario
bool buscar(vector<int> &vector, int elemento) {
    // Recorremos el vector
    for (int i = 0; i < vector.size(); i++) {
        // Si el elemento es igual al elemento del vector
        if (elemento == vector[i]) {
            // Retornamos true
            return true;
        }
    }
    // Retornamos false
    return false;
}

// Definimos la función que calcula la ruta más corta entre dos nodos usando Bellman-Ford.
// Recibe como parámetros el grafo, el nodo de origen y el nodo de destino.
// Retorna un vector con los nodos que forman la ruta más corta.
vector<int> bellmanFord(vector<Nodo> &nodos, vector<Arista> &aristas, int origen, int destino, int pesoArchivo) {
    // Verificamos que el origen y el destino sean clientes y sean distintos
    if (nodos[origen].getTipo() != "cliente" || nodos[destino].getTipo() != "cliente" || origen == destino) {
        // Retornamos un vector vacío
        cout << "Error: el origen y el destino deben ser clientes y deben ser distintos" << endl;
        return vector<int>();
    }
    // Creamos un vector que almacenará la ruta más corta
    vector<int> ruta;
    // Una vez el cliente envíe la información al router, el router sólo puede enviar la información
    // a otro router hasta llegar al router de destino, por lo tanto, la ruta más corta siempre
    // tendrá la forma cliente -> router -> router -> ... -> router -> cliente

    // Agregamos el nodo de destino a la ruta
    ruta.push_back(destino);
    // Obtenemos el router conectado al cliente de destino
    int routerDestino;
    for (int i = 0; i < aristas.size(); i++) {
        // Si la arista conecta al cliente de destino con un router
        if (aristas[i].getOrigen() == destino && nodos[aristas[i].getDestino()].getTipo() == "router") {
            // Agregamos el router a la ruta
            // ruta.push_back(aristas[i].getDestino());
            // Guardamos el router de destino
            routerDestino = aristas[i].getDestino();
            // Terminamos el ciclo
            break;
        }
    }
    // Obtenemos el router conectado al cliente de origen
    int routerOrigen;
    for (int i = 0; i < aristas.size(); i++) {
        // Si la arista conecta al cliente de origen con un router
        if (aristas[i].getOrigen() == origen && nodos[aristas[i].getDestino()].getTipo() == "router") {
            // Guardamos el router de origen
            routerOrigen = aristas[i].getDestino();
            // Terminamos el ciclo
            break;
        }
    }
    // Si el router de destino es distinto al router de origen calculamos
    // el camino más corto para llegar desde el router de origen al router de destino
    if (routerDestino != routerOrigen) {
        // Inicializamos un vector de distancias con un valor infinito para todos los nodos
        vector<int> distancias(nodos.size(), INT_MAX);
        // La distancia del nodo de origen a sí mismo es 0
        distancias[routerOrigen] = 0;

        // Relajamos las aristas V-1 veces
        for (int i = 0; i < nodos.size() - 1; i++) {
            for (int j = 0; j < aristas.size(); j++) {
                int u = aristas[j].getOrigen();
                int v = aristas[j].getDestino();
                int peso = aristas[j].getPeso(pesoArchivo);
                if (distancias[u] != INT_MAX && distancias[u] + peso < distancias[v]) {
                    distancias[v] = distancias[u] + peso;
                }
            }
        }

        // Verificamos si hay un ciclo negativo
        for (int i = 0; i < aristas.size(); i++) {
            int u = aristas[i].getOrigen();
            int v = aristas[i].getDestino();
            int peso = aristas[i].getPeso(pesoArchivo);
            if (distancias[u] != INT_MAX && distancias[u] + peso < distancias[v]) {
                cout << "Error: hay un ciclo negativo en el grafo" << endl;
                return vector<int>();
            }
        }

        // Reconstruimos la ruta más corta
        int nodoActual = routerDestino;
        while (nodoActual != routerOrigen) {
            ruta.push_back(nodoActual);
            for (int i = 0; i < aristas.size(); i++) {
                if (aristas[i].getDestino() == nodoActual && distancias[aristas[i].getOrigen()] + aristas[i].getPeso(pesoArchivo) == distancias[nodoActual]) {
                    nodoActual = aristas[i].getOrigen();
                    break;
                }
            }
        }
    }
    // Agregamos el router de origen a la ruta
    ruta.push_back(routerOrigen);
    // Agregamos el nodo de origen a la ruta
    ruta.push_back(origen);

    // Invertimos la ruta
    reverse(ruta.begin(), ruta.end());
    // Retornamos la ruta
    return ruta;
}

// Función que calcula el tiempo que toma recorrer una ruta
double tiempoRuta(vector<Arista> &aristas, vector<int> ruta, int pesoArchivo) {
    double tiempo = 0;
    // Obtenemos el tiempo que tarda pasar por cada conexión.
    // Para ello obtenemos las aristas que conectan cada punto de la ruta
    // y usamos la función getPeso(pesoArchivo) que retorna el tiempo
    // que toma recorrer dicha arista
    for (int i = 0; i < ruta.size() - 1; i++) {
        for (int j = 0; j < aristas.size(); j++) {
            if (aristas[j].getOrigen() == ruta[i] && aristas[j].getDestino() == ruta[i + 1]
            || aristas[j].getOrigen() == ruta[i + 1] && aristas[j].getDestino() == ruta[i]) {
                tiempo += aristas[j].getPeso(pesoArchivo);
                break;
            }
        }
    }
    return tiempo;
}