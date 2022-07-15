#include <iostream>
using namespace std;

void ordenamientoBurbuja(int list[], int tamanio) {
	int temp;
	int iteracion;
	int indice;
	for (iteracion = 1; iteracion < tamanio; iteracion++) {
		for (indice = 0; indice < tamanio - iteracion; indice++)
			if (list[indice] > list[indice + 1]) {
				temp = list[indice];
				list[indice] = list[indice + 1];
				list[indice + 1] = temp;
			}
	}
}

void mostrar(int list[], int tamanio) {
	for(int i = 0; i<tamanio; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}


int main(int argc, char** argv) {

	int list[10] = {16,30,24,7,62,45,5,55};

	//int tamanio = sizeof(list)/sizeof(int);
	int tamanio = 8;

	mostrar(list,tamanio);

	ordenamientoBurbuja(list,tamanio);

	mostrar(list,tamanio);

	return 0;
}
