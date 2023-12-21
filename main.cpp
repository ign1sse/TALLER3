// Incluir las librerías necesarias
#include "include/functions.h" // Para usar las funciones

using namespace std;

// Función principal
int main() {
    // Creamos los vectores que almacenarán la información del grafo
    vector<Nodo> nodos;
    vector<Arista> aristas;
    // Creamos las variables que almacenarán la información de los archivos
    string id, nombre, tipo, origen, destino, velocidad, distancia;
    // Creamos las variables que almacenarán la información del usuario
    int idOrigen, idDestino;
    double peso;
    // Creamos las variables que almacenarán la información del grafo
    int cantidadNodos, cantidadAristas;

    // Abrimos el archivo servidores.csv
    ifstream archivoServidores("servidores.csv");
    // Abrimos el archivo conexiones.csv
    ifstream archivoConexiones("conexiones.csv");

    // Leemos la primera línea del archivo servidores.csv
    getline(archivoServidores, id, ',');
    getline(archivoServidores, nombre, ',');
    getline(archivoServidores, tipo, '\n');

    // Leemos la primera línea del archivo conexiones.csv
    getline(archivoConexiones, origen, ',');
    getline(archivoConexiones, destino, ',');
    getline(archivoConexiones, velocidad, ',');
    getline(archivoConexiones, distancia, '\n');

    // Leemos el resto del archivo servidores.csv
    while (getline(archivoServidores, id, ',')) {
        getline(archivoServidores, nombre, ',');
        getline(archivoServidores, tipo, '\n');
        // Creamos un nodo con la información leída
        Nodo nodo(stoi(id), nombre, tipo);
        // Agregamos el nodo al vector de nodos
        nodos.push_back(nodo);
    }

    // Leemos el resto del archivo conexiones.csv
    while (getline(archivoConexiones, origen, ',')) {
        getline(archivoConexiones, destino, ',');
        getline(archivoConexiones, velocidad, ',');
        getline(archivoConexiones, distancia, '\n');
        // Creamos una arista con la información leída
        Arista arista(stoi(origen), stoi(destino), stod(velocidad), stod(distancia));
        // Agregamos la arista al vector de aristas
        aristas.push_back(arista);
    }

    // Cerramos el archivo servidores.csv
    archivoServidores.close();
    // Cerramos el archivo conexiones.csv
    archivoConexiones.close();

    // Calculamos la cantidad de nodos
    cantidadNodos = nodos.size();
    // Calculamos la cantidad de aristas
    cantidadAristas = aristas.size();

    // Pedimos al usuario el id del cliente de origen
    cout << "Ingrese el id del cliente de origen: ";
    cin >> idOrigen;
    // Pedimos al usuario el id del cliente de destino
    cout << "Ingrese el id del cliente de destino: ";
    cin >> idDestino;
    // Pedimos al usuario el peso del archivo en mb
    cout << "Ingrese el peso del archivo en mb: ";
    cin >> peso;

    // Calculamos la ruta más corta entre el cliente de origen y el cliente de destino
    vector<int> rutaCorta = bellmanFord(nodos, aristas, idOrigen, idDestino, peso);

    // Mostramos la ruta más corta en el siguiente formato (id1 -> id2 -> id3 -> ... -> idn)
    cout << "La ruta mas corta es: ";
    for (int i = 0; i < rutaCorta.size(); i++) {
        cout << rutaCorta[i];
        if (i != rutaCorta.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    // Mostramos el tiempo que toma recorrer la ruta más corta
    cout << "Tiempo de ruta: " << tiempoRuta(aristas, rutaCorta, peso) << " segundos" << endl;

    // Terminamos el programa
    return 0;
}