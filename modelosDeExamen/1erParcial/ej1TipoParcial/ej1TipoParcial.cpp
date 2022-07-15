//Observacion: excelente

#include <iostream>
using namespace std;

struct Nodo {
	char info;
	Nodo* sig;	
};

const int tamanio =40;

void push (Nodo*&p ,char v){
	Nodo* nuevo = new Nodo();
	nuevo->info= v;
	nuevo->sig= p;	
	p = nuevo;	
}

char pop (Nodo*&p){
	Nodo*aux = p;
	char v = aux->info;
	p = aux->sig;
	delete aux;
	return v;
}

bool evaluar(char array[tamanio] , Nodo* p){
	int centinela=0;
	for (int i=0;i<tamanio;i++){
		switch (array[i]){
			case '{' :
				push (p, array[i]);
				break;
			case '[' :
				push (p, array[i]);
				break;
			case '(' :
				push (p, array[i]);
				break;
			case '}' :
				{
				if (p == NULL) {
					centinela = 1;
				} else { 
					char s = pop (p);
					if (s != '{'){
					centinela = 1;
					}			
				}
				break;
				}
			case ']' :
				{
				if (p == NULL) {
					centinela = 1;
				} else { 
					char s = pop (p);
					if (s != '['){
					centinela = 1;
					}			
				}
				break;
				}
			case ')' :
				{
				if (p == NULL) {
					centinela = 1;
				} else { 
					char s = pop (p);
					if (s != '('){
					centinela = 1;
					}			
				}
				break;
				}
		}
	}
	if (centinela == 0){
		return true;
	}else{
		return false;
	}	
}

int main(){
	Nodo* p = NULL;
	
	char entrada1 [tamanio] = {'a','+','b','*','-','[','(','-','1','*','c',')','/','7',']','*','d'};
//  char entrada2 [tamanio] = {'3','a','+','{','-','5','x','-','a','+','(','9','x','-','a','-','x',')',']','}'};
    
    if (evaluar (entrada1,p)){
    	cout<<"correcto"<<endl;
	}else{
		cout<<"incorrecto"<<endl;
	}
	return 0;
}
