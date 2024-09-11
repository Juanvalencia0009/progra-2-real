#include <iostream>
#include <vector>
#include <iomanip> // Para std::setprecision

using namespace std;

// Función para sumar matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) { 
    // se crea la funcion sumarMatrices que recibe dos matrices como parametros
    vector<vector<int>> matriz_resultante(matriz1.size(), vector<int>(matriz1[0].size(), 0)); 
    // se crea una matriz resultante con las mismas dimensiones que las matrices originales
    for (size_t i = 0; i < matriz1.size(); ++i) { 
        // se recorre cada fila de la matriz1
        for (size_t j = 0; j < matriz1[0].size(); ++j) { 
            // se recorre cada columna de la matriz1
            matriz_resultante[i][j] = matriz1[i][j] + matriz2[i][j]; 
            // se suma el elemento correspondiente de la matriz1 y la matriz2 y se almacena en la matriz resultante
        }
    }
    return matriz_resultante; 
    // se devuelve la matriz resultante
}

// Función para restar matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    vector<vector<int>> matriz_resultante(matriz1.size(), vector<int>(matriz1[0].size(), 0));
    for (size_t i = 0; i < matriz1.size(); ++i) {
        for (size_t j = 0; j < matriz1[0].size(); ++j) {
            matriz_resultante[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
    return matriz_resultante;
}

// Función para multiplicar matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    size_t filas1 = matriz1.size();
    size_t columnas1 = matriz1[0].size();
    size_t filas2 = matriz2.size();
    size_t columnas2 = matriz2[0].size();

    if (columnas1 != filas2) {
        return {}; // Retorna una matriz vacía si las dimensiones no son compatibles
    }
    
    vector<vector<int>> matriz_resultante(filas1, vector<int>(columnas2, 0)); //crea un matriz resultante a partir de las dimensiones de las matrices originales

    for (size_t i = 0; i < filas1; ++i) { //recorre las filas de la matriz1
        for (size_t j = 0; j < columnas2; ++j) { //recorre las columnas de la matriz2
            for (size_t k = 0; k < columnas1; ++k) {//recorre las columnas de la matriz1
                matriz_resultante[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return matriz_resultante;
}

// Función para multiplicar una matriz por un escalar
vector<vector<int>> multiplicarPorEscalar(const vector<vector<int>>& matriz, int escalar) {
    vector<vector<int>> matriz_resultante(matriz.size(), vector<int>(matriz[0].size()));

    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[0].size(); ++j) {
            matriz_resultante[i][j] = matriz[i][j] * escalar;
        }
    }

    return matriz_resultante;
}

// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& matriz) {
    size_t filas = matriz.size();
    size_t columnas = matriz[0].size();
    vector<vector<int>> matriz_transpuesta(columnas, vector<int>(filas));//le entrego los valores al contrario para que quede como una matriz transpuesta

    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            matriz_transpuesta[j][i] = matriz[i][j];
        }
    }

    return matriz_transpuesta;
}

// Función para calcular la determinante de una matriz 2x2
int calcularDeterminante2x2(const vector<vector<int>>& matriz) {
    return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
}

// Función para calcular la matriz inversa de una matriz 2x2
vector<vector<double>> calcularInversa2x2(const vector<vector<int>>& matriz) {
    int det = calcularDeterminante2x2(matriz);
    if (det == 0) {
        cout << "Error: La matriz no es invertible porque su determinante es 0." << endl;
        return {};
    }
    vector<vector<double>> matriz_inversa(2, vector<double>(2));
    matriz_inversa[0][0] = matriz[1][1] / static_cast<double>(det);// static_cast<double>(det) convierte det (que es un int) a un double. Esto es importante porque la división entre enteros en C++ realiza una división entera, y queremos asegurarnos de que la operación produzca un resultado en punto flotante.
    matriz_inversa[0][1] = -matriz[0][1] / static_cast<double>(det);
    matriz_inversa[1][0] = -matriz[1][0] / static_cast<double>(det);
    matriz_inversa[1][1] = matriz[0][0] / static_cast<double>(det);

    return matriz_inversa;
}

void mostrarMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) { //const auto& fila: Usa el tipo auto para deducir el tipo de fila automáticamente, que en este caso es una referencia constante a un vector de enteros (una fila de la matriz). El uso de auto simplifica el código y evita tener que especificar el tipo exacto.

        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

void mostrarMatrizDouble(const vector<vector<double>>& matriz) {
    for (const auto& fila : matriz) {
        for (double valor : fila) {
            cout << fixed << setprecision(2) << valor << " ";
        }
        cout << endl;
    }
}

int main() {
    int dimension;
    cout << "Elige el tamaño de la matriz:" << endl;
    cout << "1. Matriz 1x1" << endl;
    cout << "2. Matriz 2x2" << endl;
    cout << "3. Matriz 3x3" << endl;
    cout << "4. Matriz 4x4" << endl;
    cout << "Opción: ";
    cin >> dimension;

    if (dimension < 1 || dimension > 4) {
        cout << "Opción no válida." << endl;
        return 1; // Salir del programa si la opción es inválida
    }

    int size = dimension;
    vector<vector<int>> matriz1(size, vector<int>(size));
    vector<vector<int>> matriz2(size, vector<int>(size));

    // Pedir al usuario los números para la primera matriz
    cout << "Introduce los números para la primera matriz " << size << "x" << size << ":" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    }

    // Pedir al usuario los números para la segunda matriz
    cout << "Introduce los números para la segunda matriz " << size << "x" << size << ":" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }

    int opcion;
    while (true) {
        cout << "\nElige una opción:" << endl;
        cout << "1. Sumar las matrices" << endl;
        cout << "2. Restar las matrices" << endl;
        cout << "3. Multiplicar las matrices" << endl;
        cout << "4. Multiplicar la matriz 1 por un escalar" << endl;
        cout << "5. Multiplicar la matriz 2 por un escalar" << endl;
        cout << "6. Transponer la matriz 1" << endl;
        cout << "7. Transponer la matriz 2" << endl;
        cout << "8. Calcular la matriz inversa de la matriz 1" << endl;
        cout << "9. Calcular la matriz inversa de la matriz 2" << endl;
        cout << "10. Calcular la determinante de la matriz 1" << endl;
        cout << "11. Calcular la determinante de la matriz 2" << endl;
        cout << "12. Salir del programa" << endl;
        cout << "Opción: ";
        cin >> opcion;

        vector<vector<int>> resultado;
        vector<vector<double>> resultado_inversa;

        try {
            switch (opcion) {
                case 1:
                    resultado = sumarMatrices(matriz1, matriz2);
                    cout << "Resultado de la suma:" << endl;
                    mostrarMatriz(resultado);
                    break;
                case 2:
                    resultado = restarMatrices(matriz1, matriz2);
                    cout << "Resultado de la resta:" << endl;
                    mostrarMatriz(resultado);
                    break;
                case 3:
                    resultado = multiplicarMatrices(matriz1, matriz2);
                    cout << "Resultado de la multiplicación:" << endl;
                    mostrarMatriz(resultado);
                    break;
                case 4:
                {
                    int escalar;
                    cout << "Introduce el escalar para la matriz 1: ";
                    cin >> escalar;
                    resultado = multiplicarPorEscalar(matriz1, escalar);
                    cout << "Resultado de la multiplicación por escalar de la matriz 1:" << endl;
                    mostrarMatriz(resultado);
                    break;
                }
                case 5:
                {
                    int escalar;
                    cout << "Introduce el escalar para la matriz 2: ";
                    cin >> escalar;
                    resultado = multiplicarPorEscalar(matriz2, escalar);
                    cout << "Resultado de la multiplicación por escalar de la matriz 2:" << endl;
                    mostrarMatriz(resultado);
                    break;
                }
                case 6:
                    resultado = transponerMatriz(matriz1);
                    cout << "Resultado de la transposición de la matriz 1:" << endl;
                    mostrarMatriz(resultado);
                    break;
                case 7:
                    resultado = transponerMatriz(matriz2);
                    cout << "Resultado de la transposición de la matriz 2:" << endl;
                    mostrarMatriz(resultado);
                    break;
                case 8:
                    if (size == 2) {
                        resultado_inversa = calcularInversa2x2(matriz1);
                        cout << "Resultado de la inversa de la matriz 1:" << endl;
                        mostrarMatrizDouble(resultado_inversa);
                    } else {
                        cout << "La matriz 1 no es 2x2 y no se puede calcular la inversa." << endl;
                    }
                    break;
                case 9:
                    if (size == 2) {
                        resultado_inversa = calcularInversa2x2(matriz2);
                        cout << "Resultado de la inversa de la matriz 2:" << endl;
                        mostrarMatrizDouble(resultado_inversa);
                    } else {
                        cout << "La matriz 2 no es 2x2 y no se puede calcular la inversa." << endl;
                    }
                    break;
                case 10:
                    if (size == 2) {
                        int det = calcularDeterminante2x2(matriz1);
                        cout << "Determinante de la matriz 1: " << det << endl;
                    } else {
                        cout << "La matriz 1 no es 2x2 y no se puede calcular la determinante." << endl;
                    }
                    break;
                case 11:
                    if (size == 2) {
                        int det = calcularDeterminante2x2(matriz2);
                        cout << "Determinante de la matriz 2: " << det << endl;
                    } else {
                        cout << "La matriz 2 no es 2x2 y no se puede calcular la determinante." << endl;
                    }
                    break;
                case 12:
                    cout << "Saliendo del programa..." << endl;
                    return 0;
                default:
                    cout << "Opción no válida." << endl;
            }
        } catch (const invalid_argument& e) {  // el catch funciona para capturar excepciones que se producen en el código y e es una varible del tipo invalid argumento 
            cout << "Error: " << e.what() << endl; //e.what Llama al método what() del objeto e para obtener un mensaje de error que describe el problema. Esto es útil para mostrar un mensaje claro y entendible al usuario o al desarrollador sobre la naturaleza del error.
        }
    }

    return 0;
}
