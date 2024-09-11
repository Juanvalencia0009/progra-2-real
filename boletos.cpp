#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Leemos la cantidad de dígitos del boleto
    int arr[n]; // Arreglo para almacenar los dígitos

    // Leemos los dígitos del boleto
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum1 = 0, sum2 = 0;
    // Sumar la primera mitad de los dígitos
    for (int i = 0; i < n / 2; i++) {
        sum1 += arr[i];
    }

    // Sumar la segunda mitad de los dígitos
    for (int i = n / 2; i < n; i++) {
        sum2 += arr[i];
    }

    // Verificar si las sumas son iguales
    if (sum1 == sum2) {
        cout << sum1 << " 1" << endl; // Si es válido, se imprime la suma y 1
    } else {
        cout << sum1 + sum2 << " 0" << endl; // Si es inválido, se imprime la suma total y 0
    }

    return 0;
}
