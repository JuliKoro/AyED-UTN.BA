#include <iostream>

using namespace std;

struct Nodo{
    char info;
    Nodo* sig;
};

void push(Nodo* &p, char v){
    Nodo* aux = new Nodo();
    aux->info = v;
    aux->sig = p;
    p = aux;
}

char pop(Nodo* &p){
    int x;
    Nodo* aux = p;
    x = aux->info;
    p = aux->sig;
    delete aux;
    return x;
}

bool evaluar(char entrada[], Nodo* p){
    for(int i=0; i<sizeof(entrada)/sizeof(entrada[0]); i++){
        if(entrada[i]=='('||entrada[i]=='['||entrada[i]=='{') push(p,entrada[i]);
        else if(p!=NULL){
                switch(entrada[i]){
                    case ')': if(pop(p)!='(') return false;
                        break;
                    case ']': if(pop(p)!='[') return false;
                        break;
                    case '}': if(pop(p)!='{') return false;
                        break;
                    default: break;
                }
        }
    }
    if (p==NULL) return true;
    else return false;
    }

int main()
{
    Nodo *p = NULL; //Tope de la pila

    char entrada1[]={'a','+','b','*','-','[','(','-','1','*','c',')','/','7',']','*','d'};
    char entrada2[]= {'3','a','+','{','-','5','x','-','a','+','(','9','x','-','a','-','x',')',']','}'};

    if (evaluar(entrada1,p)==true) cout<<"La entrada1 esta balanceada."<<endl;
    else cout<<"La entrada1 no esta balanceada."<<endl;

    if (evaluar(entrada2,p)==true) cout<<"La entrada2 esta balanceada."<<endl;
    else cout<<"La entrada2 no esta balanceada."<<endl;

    return 0;
}

