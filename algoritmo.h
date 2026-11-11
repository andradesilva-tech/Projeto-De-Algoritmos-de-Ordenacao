#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

double insertionSortTempo(int tamanho, int array[]){
    clock_t begin = clock();

    for (int i = 1; i < tamanho; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

double bubbleSortTempo(int tamanho, int array[]){
    clock_t begin = clock();

    for (int i = 0; i < tamanho - 1; i++) {
        bool houveTroca = false;

        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                houveTroca = true;
            }
        }

        if (!houveTroca) {
            break;
        }
    }

    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

double shellSortTempo(int tamanho, int array[]){
    clock_t begin = clock();

    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tamanho; i++) {
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }

    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

double selectionSortTempo(int tamanho, int array[]){
    clock_t begin = clock();

    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

void merge(int array[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j];

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortRecursivo(int array[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSortRecursivo(array, esquerda, meio);
        mergeSortRecursivo(array, meio + 1, direita);

        merge(array, esquerda, meio, direita);
    }
}

double mergeSortTempo(int tamanho, int array[]) {
    clock_t begin = clock();

    mergeSortRecursivo(array, 0, tamanho - 1);

    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

// ========== QUICK SORT - VERS�O 1: PIV� PRIMEIRO ELEMENTO ==========

int partitionPrimeiro(int array[], int baixo, int alto) {
    int pivo = array[baixo];
    int i = baixo + 1;
    int j = alto;

    while (i <= j) {
        while (i <= alto && array[i] <= pivo) {
            i++;
        }
        while (array[j] > pivo) {
            j--;
        }
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    array[baixo] = array[j];
    array[j] = pivo;

    return j;
}

void quickSortPrimeiroRecursivo(int array[], int baixo, int alto) {
    while (baixo < alto) {
        int pi = partitionPrimeiro(array, baixo, alto);

        if (pi - baixo < alto - pi) {
            quickSortPrimeiroRecursivo(array, baixo, pi - 1);
            baixo = pi + 1;
        } else {
            quickSortPrimeiroRecursivo(array, pi + 1, alto);
            alto = pi - 1;
        }
    }
}

double quickSortPrimeiroTempo(int tamanho, int array[]) {
    clock_t begin = clock();
    quickSortPrimeiroRecursivo(array, 0, tamanho - 1);
    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

// ========== QUICK SORT - VERSAO 2: PIVO = ELEMENTO DO MEIO (MEDIA DOS INDICES) ==========

int partitionMedia(int array[], int baixo, int alto) {
    // pivo = elemento da posicao media dos indices (o do meio);
    // leva o pivo para a primeira posicao e particiona igual a versao 1
    int meio = baixo + (alto - baixo) / 2;
    int troca = array[baixo];
    array[baixo] = array[meio];
    array[meio] = troca;

    int pivo = array[baixo];
    int i = baixo + 1;
    int j = alto;

    while (i <= j) {
        while (i <= alto && array[i] <= pivo) {
            i++;
        }
        while (array[j] > pivo) {
            j--;
        }
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    array[baixo] = array[j];
    array[j] = pivo;

    return j;
}

void quickSortMediaRecursivo(int array[], int baixo, int alto) {
    while (baixo < alto) {
        int pi = partitionMedia(array, baixo, alto);

        if (pi - baixo < alto - pi) {
            quickSortMediaRecursivo(array, baixo, pi - 1);
            baixo = pi + 1;
        } else {
            quickSortMediaRecursivo(array, pi + 1, alto);
            alto = pi - 1;
        }
    }
}

double quickSortMediaTempo(int tamanho, int array[]) {
    clock_t begin = clock();
    quickSortMediaRecursivo(array, 0, tamanho - 1);
    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

#endif