#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
	char info;
	Nodo* sig;
};

const int tamanio = 40;

void push (Nodo*&p ,char v){
	Nodo* nuevo = new Nodo();
	nuevo->info= v;
	nuevo->sig= p;
}

char pop (Nodo*&p){
	Nodo*aux = p;
	char v = aux->info;
	p = aux->sig;
	delete aux;
	return v;
}

bool evaluar(char array[tamanio] , Nodo* p){
	for (int i=0;i<tamanio;i++){
		switch (array[i]){
			case '{' :cout<< "Hola capo1"<<endl;
				push (p, array[i]);
				break;
			case '[' :cout<< "Hola capo2"<<endl;
				push (p, array[i]);
				break;
			case '(' :cout<< "Hola capo3"<<endl;
				push (p, array[i]);
				break;
			case '}' :
				{
				char m = '{';cout<< "Hola capo4"<<endl;
				char u = pop (p);
				if (m != u){
					return false;
				}
				break;
				};
			case ']' :cout<< "Hola capo5"<<endl;
				{
				char j = '[';
				char y = pop (p);
				if (j != y){
					return false;
				}
				break;
				};
			case ')' :
				{
				char s = '(';
				char d = pop (p);
				if (s != d){
					return false;
				}
				};
		}
	}
    cout<< "Hola capo"<<endl;
	return true;
}

int main(){

	Nodo* p = NULL;

	char entrada1 [tamanio] = {'a','+','b','*','-','[','(','-','1','*','c',')','/','7',']','*','d'};
 char entrada2 [tamanio] = {'3','a','+','{','-','5','x','-','a','+','(','9','x','-','a','-','x',')',']','}'};

    if (evaluar (entrada1,p)==true){
    	cout<<"correcto"<<endl;
	}

	system("pause");
	return 0;
}


