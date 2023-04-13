#include <iostream>

using namespace std;

int mayor(int[], int, int);
int may = 0;
int main()
{
    int arr[] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
    int inf = 0, sup = 9;
    cout << "Numero mayor del array: " << mayor(arr,inf,sup) << endl;
    return 0;
}

int mayor(int arr[], int inf, int sup){
    int len = sup+1;
    if (len == 1) return arr[inf];
    else {
        if(inf == sup) return may;
        else{
            if(arr[inf]>=may) may = arr[inf];
            inf++;
            mayor(arr,inf,sup);
        }
    }
}
