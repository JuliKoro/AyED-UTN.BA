#include <iostream>
using namespace std;


int busquedaBinaria(const int lista[], int longitud, int objetivo) {
	int primero = 0;
	int ultimo = longitud - 1;
	int medio;
	bool encontrado = false;
	while (primero <= ultimo && !encontrado) {
		medio = (primero + ultimo) / 2;
		if (lista[medio] == objetivo)
			encontrado = true;
		else if (objetivo > lista[medio])
			primero = medio + 1;
		else
			ultimo = medio - 1;
	}
	if (encontrado)
		return medio;
	else
		return -1;
}

int main(int argc, char** argv) {

	int lista[20]= {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
	int longitud = 10;

	int objetivo = 21;
	
	int resultado = busquedaBinaria(lista,longitud,objetivo);
	
	cout << objetivo << ": ";
	resultado == -1? cout << "No es parte": cout << "esta en la posicion " << resultado;
	cout << " del array";

	return 0;
}
