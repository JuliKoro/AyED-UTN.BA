# Clase 20 - Ejericio 1:
El sistema operativo de un televisor “inteligente” guarda una lista de fuentes activas (canales), cuyo origen son direcciones de Internet. Cada nodo de la lista contiene un Canal con los siguientes datos: ID (número de canal), la fuente (URL) y la velocidad en Mbps (de 0 a 256). Incorporar al sistema operativo las funcionalidades:
1. Agregar canales ordenados por ID
2. Eliminar canales cuya velocidad sea inferior a 5
3. Buscar un canal por ID
4. Listar todos los canales de la lista.

## Casos de prueba:
A. Agregar los siguientes canales (en el orden que se muestra a continuación):
22, http://youtv.com/channel22, 15
12, http://vivideo.tv/canal12, 67
77, https://localtv.us/stream/news, 4
4, http://movies.tv/drama, 0
87, https://news.tv/rumania, 127

B. Eliminar de la lista todos los canales que no alcancen el nivel mínimo de calidad (inactivos o que no alcancen los 5 Mbps de velocidad).

C. Buscar el canal 22 y mostrar la fuente (URL) por pantalla.