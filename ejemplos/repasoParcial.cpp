#include <iostream>

using namespace std;

int main()
{
   int nro=1, suma=0;
   float cont=0, prom;
   cout<<"Ingrese nros enteros pra realizar un promedio."<<endl;
   cout<<"Finalice la entrada de datos con un 0"<<endl;
   while(nro>0){
        cin>>nro;
        suma=suma+nro;
        cont++;
   }
   prom=suma/(cont-1);
   cout<<"Promedio: "<<prom;
   return 0;
}
