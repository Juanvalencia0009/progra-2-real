
#include <iostream>
using namespace std;
#include <vector>
void mostrarMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) { //const auto& fila: Usa el tipo auto para deducir el tipo de fila automáticamente, que en este caso es una referencia constante a un vector de enteros (una fila de la matriz). El uso de auto simplifica el código y evita tener que especificar el tipo exacto.

        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

int main()
{
	cout << "Introduce 0 o 1 en la matriz de 3x4: " << endl;
	int size1 = 3;
	int size = 4;
	vector<vector<int>> matriz1(size1, vector<int>(size));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j  < 4; ++j) {
			//cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> matriz1[i][j];
		}
	}
	vector<vector<int>> matrizr(size1, vector<int>(size));
	matrizr[0][0] =  matriz1[0][0] + matriz1 [1][0] + matriz1[0][1] + matriz1[1][1] ;
	matrizr[1][0] =  matriz1[1][0] + matriz1 [0][0] + matriz1[0][1] + matriz1[1][1] + matriz1[2][0] + matriz1[2][1] ;
	matrizr[2][0] =  matriz1[2][0] + matriz1 [2][1] + matriz1[1][1] + matriz1[1][0] ;
	matrizr[0][1] =  matriz1[0][1] + matriz1 [0][0] + matriz1[1][0] + matriz1[1][1] + matriz1[1][2] + matriz1[0][2];
	matrizr[1][1] =  matriz1[1][1] + matriz1 [0][0] + matriz1[1][0] + matriz1[2][0] + matriz1[2][1] + matriz1[2][2] + matriz1[1][2] + matriz1[0][2] + matriz1[0][1];
	matrizr[2][1] =  matriz1[2][1] + matriz1 [2][0] + matriz1[1][0] + matriz1[1][1] + matriz1[1][2] + matriz1[2][2];
	matrizr[0][2] =  matriz1[0][2] + matriz1 [0][1] + matriz1[1][1] + matriz1[1][2] + matriz1[1][3] + matriz1[0][3];
	matrizr[1][2] =  matriz1[1][2] + matriz1 [0][1] + matriz1[1][1] + matriz1[2][1] + matriz1[2][2] + matriz1[2][3] + matriz1[1][3] + matriz1[0][3] + matriz1[0][2];
	matrizr[2][2] =  matriz1[2][2] + matriz1 [2][1] + matriz1[1][1] + matriz1[1][2] + matriz1[1][3] + matriz1[2][3];
	matrizr[0][3] =  matriz1[0][3] + matriz1 [0][2] + matriz1[1][2] + matriz1[1][3] ;
	matrizr[1][3] =  matriz1[1][3] + matriz1 [0][3] + matriz1[0][2] + matriz1[1][2] + matriz1[2][2] + matriz1[2][3];
    matrizr[2][3] =  matriz1[2][3] + matriz1 [2][2] + matriz1[1][2] + matriz1[1][3] ;
    
    mostrarMatriz (matrizr);
	return 0;
}
