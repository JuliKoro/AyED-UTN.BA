//Observacion: Excelente

#include <iostream>
#include <string>
using namespace std;
using std::string;

struct URL {
	string info;
	URL* sgte;
};

string pop(URL* &p){
	string x;
	URL* aux = p;
	x = aux->info;
	p = aux->sgte;
	delete aux;
	return x;
}

void push(URL* &p, string v){
	URL* aux = new URL();
	aux -> info = v;
	aux -> sgte = p;
	p = aux;
 	return;
}

bool empty(URL* p){
	return p==NULL?1:0;
}

int main(){
	URL* p = NULL;

	int temp=7;
	while (temp != 0){
		cout<<"Elige la opcion que desea realizar: "<<endl;
		cout<<"1. Ingrese nueva URL."<<endl;
		cout<<"2. Para retroceder."<<endl;
		cout<<"0. Para salir."<<endl;
		cin>>temp;
		switch (temp){
				case 1: 
					{
					string dato;
					cout<<"Ingrese la url "<<endl;
					cin>>dato;
					push(p,dato);
					}
					break;
				case 2:
					if(!empty(p)){
						pop(p);
					}
					if(empty(p)){
						cout<<"Pila vacia"<<endl;
					}else{
						cout<<pop(p)<<endl;
					}
					break;
					
				case 0:
					break;
					
				default:
					cout<<"Ingrese una de las opciones por favor"<<endl;
					
		}
	}
	

	return 0;
}

