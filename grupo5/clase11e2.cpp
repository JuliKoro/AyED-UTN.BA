/*
    Observacion: esta bien, pero hay 2 cosas:
    -   deberia de poner el menu de una y que el usuario seleccione si quiere o no agregar una
        medida  (de esta manera demuestran que saben usar el tamaño logico y fisico de los
        arrays), en lugar de pedir las 20 medidas de una
    -   lean los mensajes que enviamos con Martin a Slack (Martin envio uno en el que informaba
        como debia ser el menu),
*/

#include <iostream>
#include <windows.h>

using namespace std;

int tamanio = 20;
float opt;

void agregar (float arr [], int& len, int v){
	arr[len] = v;
	len ++;
	tamanio ++;
	return;
}

void eliminar (float arr[], int& len, int pos){
	for (int i = pos-1; i < len-1; i++){
		arr[i]=arr[i+1];
	}
	len --;
	tamanio --;
    return;
}

void datos (float arr[]){
	int j = 0, cent = 0;
	cout<<"Ingrese hasta 20 muestras de medidas (Ingrese -1 para finalizar): "<<endl;
	while (cent != -1 && j < tamanio){
		cout << "Muestra " << j+1 << ": ";
		cin >> arr[j];
		cent = arr[j];
		if (cent == -1){
            arr[j] = 0;
            tamanio = j;
		}
		else j++;
	}
	cout << endl << "Ingrese valor de referencia optimo: ";
	cin >> opt;
}

void promedio (float arr[], float opt){
	float desv[tamanio], prom, total = 0;
	for (int e = 0; e < tamanio; e++){
		desv[e] = opt - arr[e];
		if(desv[e] < 0){
			desv[e] = desv[e]*(-1);
		}
		total = total + desv[e];
	}
	prom = total / tamanio;
	cout << "El promedio de desviaciones con respecto al valor optimo " << opt << " es " << prom << endl;
}

void ordenamientoSeleccion(float arr[]){
	int indice, indiceMenor ,desord, temp;
	for(indice = 0; indice < tamanio; indice++){
	 	indiceMenor = indice;
	 	for(desord = indice+1; desord < tamanio; desord++){
	 		if(arr[desord] < arr[indiceMenor]){
	 			indiceMenor = desord;
			}
		}
		temp = arr[indiceMenor];
		arr[indiceMenor] = arr[indice];
		arr[indice] = temp;
	}
}

void mostrar (float arr[], int len){
	ordenamientoSeleccion(arr);
	for (int i = 0; i < len; i++){
		cout << "Muestra " << i+1 << ": " << arr[i] << endl;
	}
	return;
}

int main (){
    system("color 0A");
	float arr[tamanio];
	int desv[tamanio], menu = 8, v, len, pos;
	bool enc;
	datos(arr);
	while(menu !=0){
        len = tamanio;
        cout << endl << "Elija la accion que desee realizar: " << endl;
        cout << "1. Agregar medicion." << endl;
        cout << "2. Modificar medicion." << endl;
        cout << "3. Eliminar medicion. " << endl;
        cout << "4. Modificar referencia(optimo)." << endl;
        cout << "5. Ver madicion maxima y minima." << endl;
        cout << "6. Mostrar muestras ordenanadas ascendentemente." << endl;
        cout << "7. Mostrar informe (promedio de los desvios)." << endl;
        cout << "0. Salir." << endl;
        cin >> menu;
        switch(menu){
            case 1:
                if (tamanio < 20){
                    cout << "Ingrese la medicion que desea agregar." << endl;
                    cin >> v;
                    agregar (arr, len, v);
                } else cout << "Ya estan ocupadas las 20 mediciones, elimine una para poder agregar una nueva desde el menu." << endl;
                break;
            case 2:
                cout << "Ingrese el numero de muestra que desea reemplazar." << endl;
                cin >> pos;
                cout << "Ingrese el valor de medicion que desea reemplazar." << endl;
                cin >> v;
                arr[pos-1] = v;
                break;
            case 3:
                cout << "Ingrese el numero de muestra que desea eliminar." << endl;
                cin >> pos;
                eliminar (arr, len, pos);
                break;
            case 4:
                cout << "Ingrese el nuevo valor de referencia (optimo)." << endl;
                cin >> opt;
                break;
            case 5:
                ordenamientoSeleccion(arr);
                cout << "Valor de medicion minimo: " << arr[0] << endl;
                cout << "Valor de medicion maximo: " << arr[tamanio-1] << endl;
                break;
            case 6:
                mostrar (arr, len);
                break;
            case 7:
                promedio (arr, opt);
                break;
            case 0:
                break;
            default:
                cout << "Ingrese uno de los valores numericos del menu." << endl;
        }
	}
	return 0;
}
