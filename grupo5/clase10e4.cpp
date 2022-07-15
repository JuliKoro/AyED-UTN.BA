/*
	Observaciones:
		- No deberian usar un array global, eso esta mal.
		- el codigo del ejercicio 1 esta de sobra, no era requerido
		- la funcion busquedaBinaria debia ser la misma que esta en la diapositiva pero adaptada a una matriz en lugar de vector, recibiendo por parametro la matriz, la cantidad de datos ingresados y el tamaño.
		- al mostrar ascendentemente deberia de mostrar solo los articulos ingresados en lugar del array completo por 0 en los lugares donde no se cargo un dato todavia
*/

#include <iostream>
using namespace std;

const int mes = 12;
const int sucursal = 5;
const int articulo = 5;
const int art = 20;
const int col = 2;
int list[art][col];

int contarFilas()  {
	int cont = 0;
	for (int i = 0; i < 20; i++) {
		if (list[i][0] != 0) cont = cont + 1; 
	}
	return cont;	
}

int busquedaBinaria(int objetivo) {
	int primero = 0;
	int rows = contarFilas();
	int ultimo = rows - 1;
	int medio;
	bool encontrado = false;
	while (primero <= ultimo && !encontrado) {
		medio = (primero + ultimo) / 2;
		if (list[medio][0] == objetivo)
			encontrado = true;
		else if (objetivo > list[medio][0])
			primero = medio + 1;
		else
			ultimo = medio - 1;
	}
	if (encontrado) {
		return medio;
	} else {
		return -1;
	}
}

void ordenamientoBurbuja() {
	int temp, temp2;
	int iteracion;
	int indice;
	for (iteracion = 1; iteracion < art; iteracion++) {
		for (indice = 0; indice < art - iteracion; indice++)
			if (list[indice][1] > list[indice + 1][1]) {
				temp = list[indice][1];
				temp2 = list[indice][0];
				list[indice][1] = list[indice + 1][1];
				list[indice][0] = list[indice + 1][0];
				list[indice + 1][1] = temp;
				list[indice + 1][0] = temp2;
			}
	}
}
void datosMatriz (int mVentas [][mes][sucursal]) {
	for (int s=0; s<sucursal; s++){
		for (int m=0; m<mes; m++){
			for (int a=0; a<articulo; a++){
				cout<<"Ingrese ventas de articulo "<<a+1<<" por mes "<<m+1<<" de la sucursal "<<s+1<<endl;
				cin>>mVentas[a][m][s];
			}
		}
	}
}

void mostrarDatos (int mVentas[][mes][sucursal]) {
	int suma = 0;
	int mesx;
	cout<<"Ingrese el numero mes del que quiere ver las ventas"<<endl;
	cin>> mesx;
	for (int u=0; u<sucursal; u++) {
		for (int a=0; a<articulo; a++){
			suma = suma + mVentas[a][mesx-1][u];
		}
	}
	cout << "El valor de las ventas totales del mes " << mesx << " es: " << suma << endl;
} 

void agregarArticulos() {
  int flag = 1;
  while (flag == 1) {
	int rows =  contarFilas();
	cout << "Ingrese el codigo del articulo" << endl;
	cin >> list[rows][0];
	cout << "Ingrese la cantidad de stock" << endl; 
	cin >> list[rows][1];
  cout << "Agregado" << endl;
  cout << "Desea agregar otro? Ingrese 1 para seguir" << endl;
  cin >> flag;
  }
  
}

void mostrarStock () {
	int x, y;
	cout << "ingrese el numero de articulo a mostrar stock." << endl;
	cin >> y;
	x = busquedaBinaria(y);
	if (x != -1) {
		cout << "El stock es: " << list[x][1] << endl;
	} else {
		cout << "El codigo no se encuentra." << endl;
	}
}

void modificarStock () {
	int x, y, nuevo;
	cout << "ingrese el numero de articulo a modificar stock." << endl;
	cin >> y;
	x = busquedaBinaria(y);
	if (x != -1) {
		cout << "ingrese nuevo stock." << endl;
		cin >> nuevo;
		list[x][1] = nuevo;
	} else {
		cout << "El codigo no se encuentra." << endl;
	}
}

void mostrar() {
	for(int i = 0; i<art; i++) {
		cout << list[i][0] << " " << list[i][1] << endl; 
	}
	cout << endl;
}

int main() {
	int mVentas[articulo][mes][sucursal];
	int menu = 10;

    while (menu != 0) {
        cout << "Ingrese 1 para agregar articulos." << endl;
        cout << "Ingrese 2 para mostrar stock." << endl;
        cout << "Ingrese 3 para modificar stock." << endl;
        cout << "Ingrese 4 para listar los articulos ascendentemente." << endl;
        cout << "Ingrese 5 para agregar todas las ventas mensuales." << endl;
        cout << "Ingrese 6 para mostrar las ventas  totales." << endl;
        cout << "Ingrese 0 para salir." << endl;
        cin >> menu;

        switch (menu) {
        	case 1: 
        		agregarArticulos();
        		break;
        	case 2: 
        		mostrarStock();
        		break;
            case 3: 
        		modificarStock();
        		break;
        	case 4: 
        		ordenamientoBurbuja();
        		mostrar();
        		break;
            case 5:
				datosMatriz(mVentas);
                break;
            case 6:
				mostrarDatos(mVentas);
                break;
        }
    }
	return 0;
}
