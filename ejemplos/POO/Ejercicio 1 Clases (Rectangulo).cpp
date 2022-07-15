//Ejercicio Clases: Rectangulo
#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangulo{
	private:
		float largo, ancho;
	public:
		Rectangulo(float, float);
		float perimetro();
		float area();
};

Rectangulo::Rectangulo(float _largo, float _ancho){ //Constructor
	largo = _largo;
	ancho = _ancho;
}

float Rectangulo::perimetro(){
	return 2*(largo+ancho);
}

float Rectangulo::area(){
	return largo*ancho;
}

int main(){
	Rectangulo r1(10,5);
	Rectangulo r2(20,5);
	Rectangulo r3(12.5,7.25);
	
	cout<<"Perimetro del rectangulo 1: "<<r1.perimetro()<<" Cm."<<endl;
	cout<<"Area del rectangulo 2: "<<r2.area()<<" Cm2."<<endl;
	cout<<"Perimetro del rectangulo 3: "<<r3.perimetro()<<" Cm."<<endl;
	cout<<"Area del rectangulo 2: "<<r3.area()<<" Cm2."<<endl;
	
	system("pause");
	return 0;
}
