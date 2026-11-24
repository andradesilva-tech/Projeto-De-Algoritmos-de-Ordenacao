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

// Funcao para converter o numero do tamanho para o valor real
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
// (no Windows o rand() vai so ate 32767, entao combinamos duas chamadas;
//  a conta e feita em long long para nao estourar em sistemas onde o
//  rand() vai ate 2^31 - 1, como Linux e Mac)
int gerarAleatorio() {
    long long valor = ((long long)rand() << 15) ^ (long long)rand();
    return (int)(valor % 1000000);
}

// Funcao para obter o nome do tipo de entrada
string obterNomeTipoEntrada(char entrada) {
    switch(entrada) {
        case 'c': return "crescente";
        case 'd': return "decrescente";
        case 'r': return "randomico";
        default: return "unknown";
    }
}

// Nome da subpasta, igual ao criado em arquivo.h (com inicial maiuscula).
// Em Linux e Mac os nomes de pasta diferenciam maiusculas de minusculas.
string obterNomePasta(char entrada) {
    switch(entrada) {
        case 'c': return "Crescente";
        case 'd': return "Decrescente";
        case 'r': return "Randomico";
        default: return "unknown";
    }
}

// Funcao principal que executa o Insertion Sort e cria os arquivos
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
    string nomeArquivoEntrada = "InsertionSort/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "InsertionSort/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "InsertionSort/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Funcao principal que executa o Bubble Sort e cria os arquivos
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
    string nomeArquivoEntrada = "BubbleSort/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "BubbleSort/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "BubbleSort/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Funcao principal que executa o Shell Sort e cria os arquivos
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
    string nomeArquivoEntrada = "ShellSort/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "ShellSort/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "ShellSort/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Funcao principal que executa o Selection Sort e cria os arquivos
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
    string nomeArquivoEntrada = "SelectionSort/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "SelectionSort/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "SelectionSort/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}

// Funcao principal que executa o Merge Sort e cria os arquivos
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
    string nomeArquivoEntrada = "MergeSort/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "MergeSort/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "MergeSort/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
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
    string nomeArquivoEntrada = "QuickSortPrimeiro/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "QuickSortPrimeiro/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "QuickSortPrimeiro/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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
    string nomeArquivoEntrada = "QuickSortMedia/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "QuickSortMedia/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "QuickSortMedia/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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

// ========== HEAP SORT (MINIMO) ==========

void imprimirVetorHeap(const string& titulo, int array[], int tamanho) {
    cout << titulo << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << setw(4) << array[i] << " ";
    }
    cout << endl << endl;
}

void HeapSort(int opcaoTamanho, char entrada) {
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
    string nomeArquivoEntrada = "HeapSort/ArquivosdeEntrada/" + obterNomePasta(entrada) + "/entrada_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoSaida = "HeapSort/ArquivosdeSaida/" + obterNomePasta(entrada) + "/saida_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";
    string nomeArquivoTempo = "HeapSort/ArquivosdeTempo/" + obterNomePasta(entrada) + "/tempo_" + tipoEntrada + "_" + to_string(tamanho) + ".txt";

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

    // Para vetores pequenos, mostra as etapas pedidas no enunciado:
    // vetor original, depois do BUILD_MIN_HEAP e depois do HEAPSORT.
    // (a copia serve so para exibir; o tempo e medido no vetor original)
    if(tamanho <= 100) {
        int *copiaBuild = new int[tamanho];
        for(int i = 0; i < tamanho; i++) {
            copiaBuild[i] = arrayOriginal[i];
        }
        buildMinHeap(copiaBuild, tamanho);

        cout << endl;
        imprimirVetorHeap("VETOR ORIGINAL:", arrayOriginal, tamanho);
        imprimirVetorHeap("CHAMADO A BUILD:", copiaBuild, tamanho);
        delete[] copiaBuild;
    }

    double tempoExecucao = heapSortTempo(tamanho, array);

    if(tamanho <= 100) {
        imprimirVetorHeap("CHAMADO O HEAPSORT:", array, tamanho);
    }

    ofstream arquivoSaida(nomeArquivoSaida);
    if(arquivoSaida.is_open()) {
        arquivoSaida << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoSaida << "Tamanho: " << tamanho << endl;
        arquivoSaida << "Dados ordenados (heap minimo - ordem decrescente):" << endl;
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
        arquivoTempo << "=== ANALISE DE PERFORMANCE - HEAP SORT (MINIMO) ===" << endl;
        arquivoTempo << "Tipo de entrada: " << tipoEntrada << endl;
        arquivoTempo << "Tamanho do array: " << tamanho << endl;
        arquivoTempo << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;
        arquivoTempo << endl << "=== INFORMACOES SOBRE COMPLEXIDADE ===" << endl;
        arquivoTempo << "Heap Sort - Heap minimo (BUILD_MIN_HEAP + MIN_HEAPIFY), saida decrescente" << endl;
        arquivoTempo << "Melhor caso: O(n log n)" << endl;
        arquivoTempo << "Caso medio: O(n log n)" << endl;
        arquivoTempo << "Pior caso: O(n log n)" << endl;
        arquivoTempo << "Espaco: O(log n) - pilha da recursao do minHeapify; nao usa vetor auxiliar" << endl;
        arquivoTempo << "Nota: Desempenho consistente para todos os tipos de entrada" << endl;
        arquivoTempo << "      Nao e estavel (pode mudar a ordem de elementos iguais)" << endl;
        arquivoTempo.close();
        cout << "Arquivo de tempo criado: " << nomeArquivoTempo << endl;
    } else {
        cout << "Erro ao criar arquivo de tempo!" << endl;
    }

    cout << endl << "=== RESULTADOS ===" << endl;
    cout << "Algoritmo: Heap Sort (Minimo)" << endl;
    cout << "Tipo de entrada: " << tipoEntrada << endl;
    cout << "Tamanho: " << tamanho << " elementos" << endl;
    cout << "Tempo de execucao: " << fixed << setprecision(4) << tempoExecucao << " segundos" << endl;

    if(tamanho > 100) {
        cout << endl << "Array muito grande para exibir na tela." << endl;
        cout << "Verifique o arquivo de saida para ver os elementos ordenados." << endl;
    }

    delete[] array;
    delete[] arrayOriginal;
}
// ========== OPERACOES MIN HEAP ==========

void OperacoesMinHeap(int opcaoOperacao) {
    static MinHeap* minHeap = nullptr;
    static bool heapCriado = false;

    // Voltar ao menu principal: descarta o heap sem pedir um vetor novo
    if (opcaoOperacao == 0) {
        if (minHeap != nullptr) {
            delete minHeap;
            minHeap = nullptr;
        }
        heapCriado = false;
        cout << "Voltando ao menu principal..." << endl;
        return;
    }

    // Se e a primeira vez, criar o heap
    if (!heapCriado || minHeap == nullptr) {
        int n;
        cout << "\n=== CRIAR HEAP INICIAL ===" << endl;
        cout << "Tamanho do vetor: ";
        cin >> n;
        cin.ignore();

        if (cin.fail() || n < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Tamanho invalido!" << endl;
            return;
        }

        if (minHeap != nullptr) {
            delete minHeap;
        }
        minHeap = new MinHeap(n + 100);

        int* arr = new int[n];
        cout << "Digite os elementos do vetor:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Elemento [" << i << "]: ";
            cin >> arr[i];
            cin.ignore();
        }

        cout << "\nVetor inserido: [ ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;

        minHeap->buildMinHeap(arr, n);

        cout << "Heap criado: ";
        minHeap->imprimirHeap();
        cout << endl;

        delete[] arr;
        heapCriado = true;
    }

    // Executar a operacao escolhida
    switch(opcaoOperacao) {
        case 1: { // HEAP_MINIMUM
            cout << "\n=== HEAP_MINIMUM ===" << endl;
            cout << "Heap atual: ";
            minHeap->imprimirHeap();
            cout << endl;

            // Testa o heap vazio pelo tamanho, e nao pelo valor retornado:
            // -1 pode ser um elemento valido digitado pelo usuario.
            if (!minHeap->estaVazio()) {
                cout << "Elemento minimo: " << minHeap->heapMinimum() << endl;
            } else {
                cout << "Heap vazio!" << endl;
            }
            break;
        }

        case 2: { // HEAP_EXTRACT_MIN
            cout << "\n=== HEAP_EXTRACT_MIN ===" << endl;
            cout << "Heap ANTES: ";
            minHeap->imprimirHeap();
            cout << endl;

            if (!minHeap->estaVazio()) {
                int min = minHeap->heapExtractMin();
                cout << "Elemento extraido: " << min << endl;
                cout << "Heap DEPOIS: ";
                minHeap->imprimirHeap();
                cout << endl;
            } else {
                cout << "Heap vazio!" << endl;
            }
            break;
        }

        case 3: { // HEAP_INCREASE_KEY (chave 1000 na posicao escolhida)
            int posicao;
            cout << "\n=== HEAP_INCREASE_KEY ===" << endl;
            cout << "Heap ANTES: ";
            minHeap->imprimirHeap();
            cout << endl;

            cout << "Posicao (0 a " << minHeap->getTamanho() - 1 << ") que recebera a chave 1000: ";
            cin >> posicao;
            cin.ignore();

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Posicao invalida!" << endl;
                break;
            }

            if (minHeap->heapIncreaseKey(posicao, 1000)) {
                cout << "Heap DEPOIS de colocar 1000 na posicao " << posicao << ": ";
                minHeap->imprimirHeap();
                cout << endl;
            }
            break;
        }

        case 4: { // MAX_HEAP_INSERT (inserir 1000)
            cout << "\n=== MAX_HEAP_INSERT ===" << endl;
            cout << "Heap ANTES: ";
            minHeap->imprimirHeap();
            cout << endl;

            minHeap->minHeapInsert(1000);

            cout << "Heap DEPOIS de inserir 1000: ";
            minHeap->imprimirHeap();
            cout << endl;
            break;
        }
    }
}

#endif