# App de mensajería

## Descripción

El programa trata de una "aplicación de mensajería", donde un cliente desea saber el tiempo que demora un mensaje en llegar a otro cliente. Para ello, se tienen dos tipos de nodos: clientes y routers. Los clientes son los nodos que envían y reciben mensajes, mientras que los routers son los nodos que se encargan de enrutar los mensajes entre los clientes. Cada conexión (arista) tiene una velocidad de conexión y una distancia de conexión. La velocidad de conexión es la velocidad de transmisión de datos que tiene el nodo, mientras que la distancia es la cantidad de segundos que tarda un "paquete" en enviarse a destino. El usuario de la plataforma debe entregar el peso del archivo que desea enviar (lo que afecta a la velocidad de conexión). Por ejemplo, si desde el cliente con id 0 (300 mb de velocidad) deseo enviar un archivo de 1200 mb, entonces el archivo debe ser particionado en 4 partes, debido a que la conexión solo acepta 300 mb como máximo. La distancia también afecta el tiempo de conexión, ya que entrega la información de cuantos segundos se demora en enviar un archivo. Siguiendo con el ejemplo anterior, si la misma persona desea enviar el archivo de 1200 mb, entonces debe dividirse en 4 partes, cada parte se demora 1 segundo en generar la conexión con el router con id 10, por lo tanto, solo para que el archivo completo llegue al router, se demorara un tiempo total de 4 segundos. El usuario además tiene que ser capaz de conocer la ruta que esta tomando el archivo y conocer los tiempos entre cada nodo que se comunica.

## Instalación

Para ejecutar este programa se necesita tener instalado el compilador de C++ y el editor de código de su preferencia. Los pasos son los siguientes:

- Clonar o descargar el repositorio de GitHub donde se encuentra el código fuente del programa.
- Abrir la terminal y ejecutar el siguiente comando:

g++ -o main.exe main.cpp src/Nodo.cpp src/Arista.cpp

- Ejecutar el archivo 'main.exe' generado por el compilador.

## Uso

Al iniciar el programa, se le pedirá al usuario que ingrese el nodo origen y el nodo destino al que se quiere enviar el mensaje. Además, se le pedirá al usuario el tamaño o peso en mb de dicho mensaje. Luego de ingresar estos datos y presionar enter, el programa entregará el camino más corto entre estos nodos y el tiempo que tarda en hacer este recorrido.

## Licencia

Este proyecto está bajo la licencia MIT.

## Contribuidores

Este proyecto fue creado por Ignacio Hernández (20.282.411-0) y Pedro Olmos (19.452.501-K).