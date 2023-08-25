#include <iostream>
#include <fstream>
#include <cstdlib>      // Para funciones rand() y srand()
#include <ctime>        // Para la función time()

#define INFILE "numeros_aleatorios.csv"
#define OUTFILE "numeros_ordenados.csv"

using namespace std;

// Prototipos de funciones
void generateRandomNumbers(int N, int *array);
void quickSort(int *data, int lo, int hi);

int main() {
    int N;
    cout << "Ingrese el número de elementos aleatorios que desea generar: ";
    cin >> N;

    // Asignar memoria en el Heap para el arreglo
    int *array = new int[N];

    generateRandomNumbers(N, array);

    // Escribir números en el archivo INFILE
    ofstream outFile(INFILE);
    for(int i = 0; i < N - 1; i++) {
        outFile << array[i] << ",";
    }
    outFile << array[N - 1];
    outFile.close();

    // Leer números desde el archivo y almacenarlos en memoria local
    ifstream inFile(INFILE);
    for(int i = 0; i < N; i++) {
        char ch;
        inFile >> array[i] >> ch; // Leer número y coma
    }
    inFile.close();

    // Clasificar números
    quickSort(array, 0, N - 1);

    // Escribir números clasificados en el archivo OUTFILE
    ofstream sortedFile(OUTFILE);
    for(int i = 0; i < N - 1; i++) {
        sortedFile << array[i] << ",";
    }
    sortedFile << array[N - 1];
    sortedFile.close();

    // Limpiar memoria
    delete[] array;

    cout << "Proceso completado. Números generados y ordenados correctamente." << endl;
    return 0;
}

void generateRandomNumbers(int N, int *array) {
    srand(time(NULL)); // Semilla para generar números aleatorios
    for(int i = 0; i < N; i++) {
        array[i] = rand() % (N * 2) + 1; // Números aleatorios entre 1 y 2N
    }
}

void quickSort(int *data, int lo, int hi) {
    if(lo > hi) return;
    int l = lo;
    int h = hi;
    int p = data[(hi + lo) / 2];

    while(l <= h) {
        while(data[l] < p) l++;
        while(data[h] > p) h--;
        if(l <= h) {
            swap(data[l], data[h]);
            l++; h--;
        }
    }
    quickSort(data, lo, h);
    quickSort(data, l, hi);
}
