#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int num, *dir_num; //*dir_num variable entera del tipo puntero
    num = 20;
    dir_num = &num; //&num direccion de memoria
    cout<<"Numero: "<<*dir_num<<endl; //*dir_num contenido de la variable
    cout<<"Direccion de memoria: "<<dir_num<<endl; //dir_num solo la direccio de memoria

    system("pause");
    return 0;
}
