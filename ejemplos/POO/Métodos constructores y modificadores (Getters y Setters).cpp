//Métodos constructores y modificadores (Getters y Setters)

#include <iostream>
#include <stdlib.h>
using namespace std;

class Punto{
	private: //Atributos
		int x, y;
	public: //Metodos
		Punto(); //Contructor
		void setPunto(int, int); //Setter
		int getPuntoX(); //Getter
		int getPuntoY();
};

Punto::Punto(){
}

void Punto::setPunto(int _x, int _y){ //Establece valores a los atributos
	x = _x;
	y = _y;
}

int Punto::getPuntoX(){ //Muestra los valores de mis atributos
	return x;
}

int Punto::getPuntoY(){
	return y;
}

int main(){
	Punto punto1;
	
	punto1.setPunto(15,10);
	cout<<"Valor de X: "<<punto1.getPuntoX()<<endl;
	cout<<"Valor de Y: "<<punto1.getPuntoY()<<endl;
	
	system("pause");
	return 0;
}
