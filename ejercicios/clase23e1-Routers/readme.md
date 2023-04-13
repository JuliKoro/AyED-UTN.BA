# Clase 23 - Ejericio 1: Routers
El sistema operativo de un router configurado como maestro (master) permite, a través de una API[^*], enviar una serie de comandos a sus routers esclavos (slave). La especificación dice que el router debe implementar una función **_configurar()_** que lea desde un archivo binario (proporcionado) registros con los siguientes atributos:
| **id** (router destino) | **sec** (secuencia) | **comando** |
| ----------- | ----------- |
| entero (0-9) | entero | cadena de caracteres [25] |

Esa función debe actualizar los elementos de una estructura array (id routers) de punteros a listas de comandos ordenados según el campo “secuencia”.

## Se pide:
Crear la función **_configurar()_** que deberá: 
1. leer los comandos del archivo binario,
2. actualizar un array de listas con los comandos dirigidos a cada router (máximo = 10 routers). Los comandos deberán ser enlazados en el orden del dato **secuencia**. Crear las estructuras necesarias.