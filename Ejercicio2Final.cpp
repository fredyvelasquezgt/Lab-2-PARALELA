#include <iostream>
#include <fstream>
#include <cstdlib>      // Para funciones rand() y srand()
#include <ctime>        // Para la función time()
#include <omp.h>

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
    #pragma omp parallel for
        for(int i = 0; i < N; i++) {
            char ch;
            inFile >> array[i] >> ch;
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
    srand(time(NULL));

    #pragma omp parallel for
    for(int i = 0; i < N; i++) {
        array[i] = rand() % (N * 2) + 1;
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

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            quickSort(data, lo, h);
        }
        #pragma omp section
        {
            quickSort(data, l, hi);
        }
    }
}