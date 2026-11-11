#ifndef FUNCAO_H
#define FUNCAO_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include "algoritmo.h"

using namespace std;

// Fun��o para converter o n�mero do tamanho para o valor real
int obterTamanhoReal(int opcaoTamanho) {
    switch(opcaoTamanho) {
        case 1: return 10;
        case 2: return 100;
        case 3: return 1000;
        case 4: return 10000;
        case 5: return 100000;
        case 6: return 1000000;
        default: return 10;
    }
}

// Gera um numero aleatorio entre 0 e 999999
// (no Windows o rand() vai so ate 32767, entao combinamos duas chamadas)
int gerarAleatorio() {
    return ((rand() << 15) | rand()) % 1000000;
}

// Fun��o para obter o nome do tipo de entrada
string obterNomeTipoEntrada(char entrada) {
    switch(entrada) {
        case 'c': return "crescente";
        case 'd': return "decrescente";
        case 'r': return "randomico";
        default: return "unknown";
    }
}

// Fun��o principal que executa o Insertion Sort e cria os arquivos
void InsertionSort(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "InsertionSort/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "InsertionSort/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "InsertionSort/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = insertionSortTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << tamanho << endl;
        arquivoTempo << fixed << setprecision(6) << tempoExecucao << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Insertion Sort" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de sa�da para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Fun��o principal que executa o Bubble Sort e cria os arquivos
void BubbleSort(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "BubbleSort/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "BubbleSort/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "BubbleSort/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = bubbleSortTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << tamanho << endl;
        arquivoTempo << fixed << setprecision(6) << tempoExecucao << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Bubble Sort" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de sa�da para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Fun��o principal que executa o Shell Sort e cria os arquivos
void ShellSort(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "ShellSort/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "ShellSort/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "ShellSort/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = shellSortTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << tamanho << endl;
        arquivoTempo << fixed << setprecision(6) << tempoExecucao << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Shell Sort" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de sa�da para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Fun��o principal que executa o Selection Sort e cria os arquivos
void SelectionSort(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "SelectionSort/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "SelectionSort/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "SelectionSort/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = selectionSortTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << tamanho << endl;
        arquivoTempo << fixed << setprecision(6) << tempoExecucao << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Selection Sort" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de sa�da para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Fun��o principal que executa o Merge Sort e cria os arquivos
void MergeSort(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "MergeSort/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "MergeSort/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "MergeSort/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = mergeSortTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << tamanho << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << tamanho << endl;
        arquivoTempo << fixed << setprecision(6) << tempoExecucao << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Merge Sort" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de sa�da para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// ========== QUICK SORT - VERSAO 1: PIVO PRIMEIRO ELEMENTO ==========

void QuickSortPrimeiro(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "QuickSortPrimeiro/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "QuickSortPrimeiro/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "QuickSortPrimeiro/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoEntrada << "Tamanho: " << tamanho << endl;
        arquivoEntrada << "Dados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = quickSortPrimeiroTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoSaida << "Tamanho: " << tamanho << endl;
        arquivoSaida << "Dados ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << "=== ANALISE DE PERFORMANCE - QUICK SORT (PIVO: PRIMEIRO) ===" << endl;
        arquivoTempo << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoTempo << "Tamanho do array: " << tamanho << endl;
        arquivoTempo << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;
        arquivoTempo << endl;
        arquivoTempo << "=== INFORMACOES SOBRE COMPLEXIDADE ===" << endl;
        arquivoTempo << "Quick Sort - Pivo: primeiro elemento" << endl;
        arquivoTempo << "Melhor caso: O(n log n)" << endl;
        arquivoTempo << "Caso medio: O(n log n)" << endl;
        arquivoTempo << "Pior caso: O(n^2) - ocorre em vetores ja ordenados ou invertidos" << endl;
        arquivoTempo << "Espaco: O(log n) - pilha de recursao" << endl;
        arquivoTempo << "Nota: Pivo fixo no primeiro elemento degenera para O(n^2) em entradas ja ordenadas" << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Quick Sort (Pivo: Primeiro)" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// ========== QUICK SORT - VERSAO 2: PIVO = ELEMENTO DO MEIO (MEDIA DOS INDICES) ==========

void QuickSortMedia(int opcaoTamanho, char entrada) {
    int tamanho = obterTamanhoReal(opcaoTamanho);
    int *array = new int[tamanho];
    int *arrayOriginal = new int[tamanho];

    if(entrada == 'c') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = i;
            arrayOriginal[i] = i;
        }
    } else if(entrada == 'd') {
        for(int i = 0; i < tamanho; i++) {
            array[i] = tamanho - 1 - i;
            arrayOriginal[i] = tamanho - 1 - i;
        }
    } else if(entrada == 'r') {
        srand(static_cast<unsigned>(time(nullptr)));
        for(int i = 0; i < tamanho; i++) {
            array[i] = gerarAleatorio();
            arrayOriginal[i] = array[i];
        }
    }

    string tipoEntrada = obterNomeTipoEntrada(entrada);
    string nomeArquivoEntrada = "QuickSortMedia/ArquivosdeEntrada/" + tipoEntrada + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "QuickSortMedia/ArquivosdeSaida/" + tipoEntrada + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "QuickSortMedia/ArquivosdeTempo/" + tipoEntrada + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

    ofstream arquivoEntrada(nomeArquivoEntrada);
    if(arquivoEntrada.is_open()) {
        arquivoEntrada << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoEntrada << "Tamanho: " << tamanho << endl;
        arquivoEntrada << "Dados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoEntrada << arrayOriginal[i] << endl;
        }
        arquivoEntrada.close();
        cout << "Arquivo de entrada criado: " << nomeArquivoEntrada << endl;
    } else {
        cout << "Erro ao criar arquivo de entrada!" << endl;
    }

    double tempoExecucao = quickSortMediaTempo(tamanho, array);

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoSaida << "Tamanho: " << tamanho << endl;
        arquivoSaida << "Dados ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            arquivoSaida << array[i] << endl;
        }
        arquivoSaida.close();
        cout << "Arquivo de saida criado: " << nomeArquivoSaida << endl;
    } else {
        cout << "Erro ao criar arquivo de saida!" << endl;
    }

    ofstream arquivoTempo(nomeArquivoTempo);
    if(arquivoTempo.is_open()) {
        arquivoTempo << "=== ANALISE DE PERFORMANCE - QUICK SORT (PIVO: MEDIA) ===" << endl;
        arquivoTempo << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoTempo << "Tamanho do array: " << tamanho << endl;
        arquivoTempo << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;
        arquivoTempo << endl;
        arquivoTempo << "=== INFORMACOES SOBRE COMPLEXIDADE ===" << endl;
        arquivoTempo << "Quick Sort - Pivo: elemento do meio (media dos indices)" << endl;
        arquivoTempo << "Melhor caso: O(n log n)" << endl;
        arquivoTempo << "Caso medio: O(n log n)" << endl;
        arquivoTempo << "Pior caso: O(n^2)" << endl;
        arquivoTempo << "Espaco: O(log n) - pilha de recursao" << endl;
        arquivoTempo << "Nota: Pivo do meio evita o pior caso em entradas ja ordenadas ou invertidas" << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Quick Sort (Pivo: Media)" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho <= 100) {
        cout << endl << "Elementos ordenados:" << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << array[i] << endl;
        }
    } else {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

#endif // FUNCAO_H
