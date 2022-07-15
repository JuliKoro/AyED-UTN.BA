#include <iostream>
using namespace std;
const int SIZE = 6;

struct Alumno {
	int legajo;
	string nombre;
	int nota;
};

Alumno crearAlumno(int le, string nom, int nota) {
	Alumno a;
	a.legajo = le;
	a.nombre = nom;
	a.nota = nota;
	return a;
}

template <typename T>
void mostrar(T arr[], int length, void (*mostrarFila)(T)) {
	for(int i=0; i<length; i++) {
		mostrarFila(arr[i]);
	}
	return;
}

void mostrarAlumno(Alumno a) {
	cout << a.legajo << ", " << a.nombre << ", "<< a.nota << endl;
}

int main() {

	Alumno arr[SIZE];
	arr[0] = crearAlumno(30,"Esteban",5);
	arr[1] = crearAlumno(10,"Ignacio",8);
	arr[2] = crearAlumno(20,"Diego",7);
	arr[3] = crearAlumno(60,"Pedro",10);
	arr[4] = crearAlumno(40,"Gustavo",2);
	arr[5] = crearAlumno(50,"Carlos",4);

	mostrar<Alumno>(arr,SIZE,mostrarAlumno);

	return 0;
}
