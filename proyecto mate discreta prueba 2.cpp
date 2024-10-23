#include <iostream>
using namespace std;

// Función para mostrar el conjunto
void mostrarConjunto(int conjunto[], int tam) {
    cout << "{ ";
    for (int i = 0; i < tam; i++) {
        cout << conjunto[i] << " ";
    }
    cout << "}" << endl;
}

// Función para obtener la unión de dos conjuntos
void unionConjuntos(int A[], int tamA, int B[], int tamB, int resultado[], int &tamR) {
    tamR = 0; // Reiniciar tamaño del resultado
    // Agregar elementos de A
    for (int i = 0; i < tamA; i++) {
        bool encontrado = false;
        for (int j = 0; j < tamR; j++) {
            if (resultado[j] == A[i]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado[tamR] = A[i];
            tamR++;
        }
    }
    // Agregar elementos de B
    for (int i = 0; i < tamB; i++) {
        bool encontrado = false;
        for (int j = 0; j < tamR; j++) {
            if (resultado[j] == B[i]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado[tamR] = B[i];
            tamR++;
        }
    }
}

// Función para obtener la intersección de dos conjuntos
void interseccionConjuntos(int A[], int tamA, int B[], int tamB, int resultado[], int &tamR) {
    tamR = 0; // Reiniciar tamaño del resultado
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (A[i] == B[j]) {
                bool encontrado = false;
                for (int k = 0; k < tamR; k++) {
                    if (resultado[k] == A[i]) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    resultado[tamR] = A[i];
                    tamR++;
                }
            }
        }
    }
}

// Función para calcular el MCD de dos números
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b; // Se obtiene el residuo de la división
        a = temp; // Se actualiza a
    }
    return a; // El MCD se encuentra cuando b es 0
}

int main() {
    int A[] = {12, 15, 21};  
    int B[] = {9, 15, 27};  
    int resultado[10];   
    int tamR;         
    int opcion;

    do {
        cout << "\n--- Menú de Operaciones ---" << endl;
        cout << "1. Unión de conjuntos" << endl;
        cout << "2. Intersección de conjuntos" << endl;
        cout << "3. Calcular el MCD de dos números" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                unionConjuntos(A, 3, B, 3, resultado, tamR);
                cout << "Unión: ";
                mostrarConjunto(resultado, tamR);
                break;
            }
            case 2: {
                interseccionConjuntos(A, 3, B, 3, resultado, tamR);
                cout << "Intersección: ";
                mostrarConjunto(resultado, tamR);
                break;
            }
            case 3: {
                int num1, num2;
                cout << "Ingrese el primer número: ";
                cin >> num1;
                cout << "Ingrese el segundo número: ";
                cin >> num2;
                cout << "El MCD de " << num1 << " y " << num2 << " es: " << mcd(num1, num2) << endl;
                break;
            }
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
