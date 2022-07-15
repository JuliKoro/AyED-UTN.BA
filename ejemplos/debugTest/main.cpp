#include <iostream>

using namespace std;

int main()
{
    int n, cantPares;
    cout<< "Ingresar numero: ";
    cin>>n;
    while(n!=0){
        if(n%2==0) cantPares++;
        cout<<"Ingresar numero: ";
        cin>>n;
    }
    cout<<endl<<"Cantidad de pares: "<<cantPares;
    return 0;
}
