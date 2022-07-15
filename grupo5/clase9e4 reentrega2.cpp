/*
    Observacion: esta bien, pero la funcion minimo de ustedes no es una traduccion del pseudocodigo ya que el pseudocodigo
    toma como primer minimo al primer valor diferente de 0, hagan traducciones no quieran ahorrar tiempo porque les juega en
    contra
*/

#include <iostream>

using namespace std;

const int tamanio_fila = 10;
const int tamanio_col = 4;


void mostrarTodo(int matriz[tamanio_fila][tamanio_col]) { //muestra legajo y las 3 notas
    for (int f = 0; f < tamanio_fila; f++) {
        cout << endl << "legajo numero: " << matriz[f][0] << " ";
        for (int c = 1; c < tamanio_col; c++) {
            cout << "Nota " << c << ": " << matriz[f][c] << " ";
        }
    }
    cout << " " << endl;
}



void mostrarPromedios(int matriz[tamanio_fila][tamanio_col]) { //muetra legajo y luego calcula promedio de las 3 notas
    float resultado = 0;
    for (int g = 0; g < tamanio_fila; g++) {
        int promedio = 0;
        for (int s = 0; s < tamanio_col; s++) {
            if (s == 0) {
                cout << "Legajo nunemro: " << matriz[g][s];
            }
            if (s != 0) {
                promedio = matriz[g][s] + promedio;
            }
        }
        resultado = promedio / 3;
        cout << " " << "Promedio: " << resultado << endl;
    }
}

int maximo(int matriz[tamanio_col - 1]) {
    int max = matriz[0];
    int posic = 0;
    for (int u = 0; u < tamanio_fila - 1; u++) { //busca la mejor nota de las 3  
        if (max < matriz[u]) {
            max = matriz[u];
            posic = u;
        }
    }
    return posic;
}

void mejorCalificacion(int matriz[tamanio_fila][tamanio_col], int leg) {
    int mejorNota[tamanio_col - 1];
    for (int j = 0; j < tamanio_fila; j++) {
        if (leg == matriz[j][0]) {
            cout << "La mejor calificacion del legajo numero: " << matriz[j][0] << " es: ";
            for (int w = 0; w < tamanio_col; w++) { //llevo la info a un array unidemencional
                mejorNota[w] = matriz[j][w + 1];
            }
        }

    }
    cout << maximo(mejorNota) << endl;
}

int minimo(int matriz[tamanio_col - 1]) {
    int min = matriz[0];
    int posic = 0;
    for (int u = 0; u < tamanio_fila - 1; u++) { //busca la mejor nota de las 3  
        if (min > matriz[u]) {
            min = matriz[u];
            posic = u;
        }
    }
    return posic;
}


void peorCalificacion(int matriz[tamanio_fila][tamanio_col], int leg) {

    int peorNota[tamanio_col - 1];
    for (int a = 0; a < tamanio_fila; a++) {
        if (leg == matriz[a][0]) {
            cout << "La peor calificacion del legajo numero: " << matriz[a][0] << " es: ";
            for (int x = 0; x < tamanio_col; x++) { //llevo la info a un array unidemencional
                peorNota[x] = matriz[a][x + 1];
                minimo(peorNota);
            }

        }
    }
    cout << minimo(peorNota) << endl;
}



int main() {
    int menu = 10;
    int plantilla[tamanio_fila][tamanio_col];
    int leg;


    while (menu != 0) {

        cout << "Ingrese 1 para agregar la plantilla de legajos y sus notas." << endl;
        cout << "Ingrese 2 para mostrar la plantilla." << endl;
        cout << "Ingrese 3 para mostrar todos los legajos y sus promedios." << endl;
        cout << "Ingrese 4 para buscar la mejor nota por legajo." << endl;
        cout << "Ingrese 5 para buscar la menor nota por legajo." << endl;
        cout << "Ingrese 0 para salir." << endl;
        cin >> menu;

        switch (menu) {
            case 1:
                for (int p = 0; p < tamanio_fila; p++) {
                    cout << "Ingrese el legajo numero: " << p + 1 << endl;
                    cin >> plantilla[p][0];
                    cout << "Ingrese 3 notas: ";
                    for (int m = 1; m < tamanio_col; m++) {
                        cin >> plantilla[p][m];
                    }
                }
                break;

            case 2:
                mostrarTodo(plantilla);
                break;

            case 3:
                mostrarPromedios(plantilla);
                break;

            case 4:
                cout << "Ingrese el legajo que busca: ";
                cin >> leg;
                mejorCalificacion(plantilla, leg);
                break;

            case 5:
                cout << "Ingrese el legajo: ";
                cin >> leg;
                peorCalificacion(plantilla, leg);
                break;
        }
    }
    return 0;



}