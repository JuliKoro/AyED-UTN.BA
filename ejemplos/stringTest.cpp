#include <iostream>
#include <string.h>

using namespace std;

int main()
{   int codigo;
    string nombre, colegio;
    cin>>codigo;
    cin.ignore();
    getline(cin, nombre);
    getline(cin, colegio);
    cout<<nombre<<endl<<colegio;
    return 0;

}
