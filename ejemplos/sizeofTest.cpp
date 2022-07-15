#include <iostream>

using namespace std;

int main()
{int tamanio=20;
float arr[tamanio];
cout<<"Ingrese muestras de algo: "<<endl;
for(int c=0; c<5; c++){
    cin>>arr[c];
}
tamanio = sizeof(arr) / sizeof (int);
cout<<"Tamanio de arr: "<<tamanio<<endl;

}
