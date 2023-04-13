#include <iostream>

using namespace std;

void invertir(int[],int,int);
void mostrar(int[],int,int);

int main()
{
    int arr[] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
    int inf = 0, sup = (sizeof(arr)/sizeof(*(arr)))-1;
    cout<<"Array: ";
    mostrar(arr,inf,sup);
    invertir(arr,inf,sup);
    cout<<endl<<"Array invertido: ";
    mostrar(arr,inf,sup);
    return 0;
}

void invertir(int arr[], int inf, int sup){
    int aux;
    if(inf<sup){
        aux = arr[inf];
        arr[inf] = arr[sup];
        arr[sup] = aux;
        inf++;
        sup--;
        invertir(arr, inf, sup);
    }
}

void mostrar(int arr[], int inf, int sup){
    if (inf<=sup){
        cout<<arr[inf]<<", ";
        inf++;
        mostrar(arr,inf,sup);
    }
}
