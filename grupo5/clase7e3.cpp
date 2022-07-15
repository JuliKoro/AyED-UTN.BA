/*
    Observacion: Esta muy bien, aunque podrian haber incluido la opcion de salir en el de la figura en lugar de
    preguntar si quiere seguir o no el usuario (no es un error es solo una manera de compactar codigo).
    Sigan asi que van bien!
    
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
using std::string; 
const char T='t';
float calcularArea (float lado){
    return M_PI * pow(lado,2);
}

float calcularArea(float lado,float ref){
    return lado*lado;
}

float calcularArea(char t,float lado,float ref){
    return (lado*lado)/2;
}

template <typename T> void imprimir(T&resultado, string figura){
    cout<<"La figura "<<figura<<" tiene un area de "<<resultado<<" Cm2"<<endl;
}

int main(){
    float resultado, lado, res;
    int cent=0;
    string figura;
    while (cent!=1 && cent!=2 && cent!=3 && cent==0){
    	cout<<"Elija la figura que quiera calcular (ingresando su respectivo numero):"<<endl;
    	cout<<"1-Circulo."<<endl<<"2-Cuadrado."<<endl<<"3-Triangulo."<<endl;
    	cin>>cent;
    	if (cent==1 || cent==2 || cent==3) {
    		cout<<"Ingrese dimension en Cm: ";
    		cin>>lado;
    	}
    	switch(cent){
    		case 1: 
    			figura="Circulo";
    			res = calcularArea(lado);
    			imprimir<float>(res, figura);
    			break;
    		case 2:
    			res=calcularArea(lado, lado);
    			figura="Cuadrado";
    			imprimir<float>(res, figura);
    			break;
    		case 3:
    			res=calcularArea(T,lado, lado);
    			figura="Triangulo";
    			imprimir<float>(res, figura);
    			break;
    		default: 
    			cout<<"Ingrese una opcion valida del menu."<<endl;
    	}
    	cout<<"Desea seguir? Presione 0, si quiere salir presione 9."<<endl;
    	cin>>cent;
    }
    return 0;
}
		

