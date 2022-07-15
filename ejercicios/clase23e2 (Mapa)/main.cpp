#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int, string> mapa;

    mapa.insert({3126998,"María Estela Dominguez"});
    mapa.insert({298732,"Juan Ignacio Rossi"});
    mapa.insert({1683338,"Sebastián Moreno"});
    mapa.insert({2238833,"Sandra Sotomano"});

    cout<<"Ingrese una clave: "<<"298732"<<endl;
    auto itr = mapa.find(298732);
    if (itr != mapa.end()) cout<< itr->second <<endl;
    else cout << "No existe." <<endl;
    cout<<"Ingrese otra clave: "<<"99999"<<endl;
    itr = mapa.find(99999);
    if (itr != mapa.end()) cout<< itr->second <<endl;
    else cout << "No existe." <<endl;
    cout<<"Size of the map: "<<mapa.size()<<endl;
    cout<<"Eliminar entrada 298732: "<<mapa.erase(298732)<<endl;
    cout<<"Todas las entradas del mapa: "<<endl;
    cout << "\tKEY\tELEMENT\n";
    for (itr = mapa.begin(); itr != mapa.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout<<endl;
    return 0;
}
