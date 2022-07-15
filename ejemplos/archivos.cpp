#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main()
{
    FILE *F; //tipo de dato FILE y puntero de tipo FILE de nombre de identificador F
    F = fopen("alumnos.dat", wb+); //abre o crea el archivo alumnos para escritura, y especifica que es binario

    if((F = fopen("alumnos.dat", wb+))==NULL){ //controla que se haya abierto bien, si el puntero es NULL significa que no abrio bien
        error(1);
    }

    system ("pause");
    return 0;
}
