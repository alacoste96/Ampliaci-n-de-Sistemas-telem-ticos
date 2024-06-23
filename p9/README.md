# P9-Threads-Boost

## Práctica 9 de la asignatura ampliación de sistemas telemáticos.

### Compilación y ejecución:

```bash
g++ -Wall -Wshadow tcp-server.cpp -o tcp-server -lboost_system
g++ -Wall -Wshadow tcp-client.cpp -o tcp-client -lboost_system
./tcp-server
./tcp-client
```

### Funcionamiento general:

Los 2 archivos subidos [tcp-client.cpp](https://github.com/clases-julio/p9-chat-boost-alacoste2017/blob/main/tcp-client.cpp) y [tcp-server.cpp](https://github.com/clases-julio/p9-chat-boost-alacoste2017/blob/main/tcp-server.cpp) son 2 programas en C++ que corresponden a un cliente y un servidor respectivamente.

Al ejecutarse el servidor y diferentes clientes en distintas terminales, se pueden enviar mensajes entre los clientes. Como un chat de comunicación.

Al ejecutarse el servidor, éste escucha en la dirección IP 127.0.0.1 y en el puerto 1234. Los clientes al ejecutarse se contectan a esta IP y puerto. Al hacerlo entran en el lobby/grupo de chat. En ese momento desde la terminal se pueden escribir mensajes que serán enviados al servidor y éste los enviará al resto de clientes conectados actualmente en el lobby.

**En el servidor**: por cada cliente que se conecta, crea un hilo de ejecución para él guardando un puntero compartido al socket creado (shared_ptr) en un vector (variable global) para que todos los hilos puedan acceder y enviar lo que un cliente escribe a todos los demás. A medida que estos hilos terminan su ejecución (el cliente se desconecta) se van eliminando también del vector de punteros compartidos a sockets.

**En el cliente**: tras conectarse con éxito al servidor, crea un hilo de ejecución que sólo se encarga de leer del socket e imprimir los mensajes que le llegan del servidor por pantalla. Por otro lado, en el hilo principal lo único que hace es pedir líneas desde la terminal para enviarlos por el socket al servidor.

Cada vez que se conecta un cliente, el servidor manda un mensaje a los clientes conectados avisando de que un nuevo cliente se ha conectado. Así como que enviará un mensaje a cada cliente cuando uno se desconecta. Los nombres de los clientes son números que corresponden al puerto por el que se conectaron al servidor.

### Peculiaridades:

Aunque no lo hayamos dado en clase, hago uso de la librería "mutex" para evitar problemas de concurrencia entre hilos y proporcionar mecanismos de sincronización entre ellos. Soy consciente que para una práctica minimalista como ésta no iba a ser necesario, pero considero que no es una buena práctica de programación hacerlo así. Y de paso aprendo más cosas.

Nótese que los problemas de concurrencia en este caso si se diesen, se darían en el servidor ya que todos los hilos comparten la variable global "clients" que corresponde a un vector de "shared_ptr" a sockets. Debido a esto, como cada hilo creado por el servidor se encarga de la lectura de un socket de un cliente y de enviar el mensaje leído al resto de clientes; a medida que se conectan más clientes y que los hilos tienen que acceder de forma más frecuente a dicha variable, es posible que en cierto momento lleguen a chocar y que se produzca un error indefinido.

Por ello, verás que cuando se van a enviar mensajes al resto de clientes, cuando se va a desconectar a un cliente (lo que implica eliminar un socket de dicho vector) o cuando se conecta un cliente nuevo (hay que añadir un socket al vector), antes de hacerlo, en cada una de las 3 funciones añado: *std::lock_guard < std::mutex > guard(clients_mutex);*. Esto garantiza que el código dentro de la función no sea ejecutada concurrentemente por múltiples hilos. Automáticamente cuando se sale del ámbito de la función, se desbloquea y por ende otro hilo puede ejecutar la función. Así nos aseguramos que no habrá problemas de concurrencia. 