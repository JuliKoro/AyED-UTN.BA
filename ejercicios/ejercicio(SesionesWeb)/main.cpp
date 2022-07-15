#include <iostream>
#include <time.h>

using namespace std;

struct Sesion {
    int id;
    long fechaHoraInicio;
    long fechaHoraFin;
    int codNav;
};

struct Dato{
    char url[25];
    long fechaHora;
};

struct Nodo{
    Sesion info;
    Nodo* sig;
};

int main()
{

    return 0;
}
