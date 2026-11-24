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

// ========== QUICK SORT - VERSAO 1: PIVO PRIMEIRO ELEMENTO ==========

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
// ========== HEAP SORT (MINIMO) ==========
// Vetor indexado a partir de 0: pai(i) = (i-1)/2, esquerda(i) = 2i+1, direita(i) = 2i+2.
// Heap minimo: todo pai e menor ou igual aos seus filhos, entao o menor fica na raiz.

// MIN_HEAPIFY: desce o elemento da posicao i ate restaurar o heap minimo. O(log n)
void minHeapify(int array[], int tamanho, int i) {
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tamanho && array[esquerda] < array[menor])
        menor = esquerda;

    if (direita < tamanho && array[direita] < array[menor])
        menor = direita;

    if (menor != i) {
        int temp = array[i];
        array[i] = array[menor];
        array[menor] = temp;

        minHeapify(array, tamanho, menor);
    }
}

// BUILD_MIN_HEAP: chama o MIN_HEAPIFY do ultimo no interno ate a raiz. O(n)
void buildMinHeap(int array[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        minHeapify(array, tamanho, i);
}

// HEAPSORT (minimo): leva o menor elemento (raiz) para o final a cada passo,
// por isso o vetor termina em ordem DECRESCENTE. O(n log n)
void heapSortMin(int array[], int tamanho) {
    buildMinHeap(array, tamanho);

    for (int i = tamanho - 1; i > 0; i--) {
        // Move a raiz (menor elemento) para o final
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Restaura o heap minimo na parte que ainda nao foi ordenada
        minHeapify(array, i, 0);
    }
}

double heapSortTempo(int tamanho, int array[]) {
    clock_t begin = clock();

    heapSortMin(array, tamanho);

    clock_t end = clock();
    double tempoGasto = ((double)(end - begin)) / CLOCKS_PER_SEC;
    return tempoGasto;
}

// ========== OPERACOES DE MIN HEAP (FILA DE PRIORIDADE MINIMA) ==========
// Reaproveita o minHeapify e o buildMinHeap do HeapSort.

class MinHeap {
private:
    int* heap;
    int capacidade;
    int tamanhoAtual;

    int pai(int i) { return (i - 1) / 2; }

public:
    MinHeap(int cap) {
        capacidade = cap;
        tamanhoAtual = 0;
        heap = new int[capacidade];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void buildMinHeap(int arr[], int n) {
        if (n > capacidade) {
            cout << "Erro: Tamanho excede capacidade!" << endl;
            return;
        }

        tamanhoAtual = n;
        for (int i = 0; i < n; i++)
            heap[i] = arr[i];

        ::buildMinHeap(heap, tamanhoAtual);
    }

    // HEAP_MINIMUM: o menor elemento esta na raiz. O(1)
    // Use estaVazio() antes: com o heap vazio o -1 e so uma protecao,
    // pois -1 tambem pode ser uma chave valida.
    int heapMinimum() {
        if (tamanhoAtual == 0) {
            return -1;
        }
        return heap[0];
    }

    // HEAP_EXTRACT_MIN: retira a raiz, coloca o ultimo no lugar e
    // chama o MIN_HEAPIFY a partir do primeiro indice. O(log n)
    // Use estaVazio() antes (mesmo motivo do heapMinimum).
    int heapExtractMin() {
        if (tamanhoAtual == 0) {
            return -1;
        }

        int raiz = heap[0];
        heap[0] = heap[tamanhoAtual - 1];
        tamanhoAtual--;
        minHeapify(heap, tamanhoAtual, 0);

        return raiz;
    }

    // HEAP_INCREASE_KEY: aumenta a chave da posicao i. No heap minimo uma chave
    // maior so pode ficar maior que os filhos, entao o elemento desce. O(log n)
    bool heapIncreaseKey(int i, int chave) {
        if (i < 0 || i >= tamanhoAtual) {
            cout << "Erro: posicao invalida!" << endl;
            return false;
        }
        if (chave < heap[i]) {
            cout << "Erro: nova chave menor que a chave atual!" << endl;
            return false;
        }

        heap[i] = chave;
        minHeapify(heap, tamanhoAtual, i);
        return true;
    }

    // MAX_HEAP_INSERT (versao minimo): coloca a chave numa nova folha e
    // sobe enquanto ela for menor que o pai. O(log n)
    void minHeapInsert(int chave) {
        if (tamanhoAtual == capacidade) {
            cout << "Erro: Heap cheio!" << endl;
            return;
        }

        tamanhoAtual++;
        int i = tamanhoAtual - 1;
        heap[i] = chave;

        while (i > 0 && heap[pai(i)] > heap[i]) {
            int temp = heap[i];
            heap[i] = heap[pai(i)];
            heap[pai(i)] = temp;
            i = pai(i);
        }
    }

    void imprimirHeap() {
        cout << "[ ";
        for (int i = 0; i < tamanhoAtual; i++)
            cout << heap[i] << " ";
        cout << "]";
    }

    int getTamanho() {
        return tamanhoAtual;
    }

    bool estaVazio() {
        return tamanhoAtual == 0;
    }
};

#endif
