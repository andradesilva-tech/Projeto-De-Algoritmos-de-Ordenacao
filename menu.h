#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <fstream>

using namespace std;

void menu(){

    cout<<"|=========================PROJETO DE ALGORITMOS(MENU)==========================|"<< endl;
    cout<<"| 1-Insertion Sort                                                             |"<< endl;
    cout<<"| 2-Bubble Sort                                                                |"<<endl;
    cout<<"| 3-Shell Sort                                                                 |"<<endl;
    cout<<"| 4-Selection Sort                                                             |"<<endl;
    cout<<"| 5-Merge Sort                                                                 |"<<endl;
    cout<<"| 6-Quick Sort (Pivo: Primeiro)                                                |"<<endl;
    cout<<"| 7-Quick Sort (Pivo: Media)                                                   |"<<endl;
    cout<<"| 8-Heap Sort (Minimo)                                                         |"<<endl;
    cout<<"| 9-Operacoes Heap (Fila de Prioridade Minima)                                 |"<<endl;
    cout<<"| 0-Sair                                                                       |"<< endl;
    cout<<"|==============================================================================|"<<endl;
    cout<<"Informe o algoritmo: "<<endl;

}

void menuOperacoesHeap(){
    cout<<"\n=== OPERACOES DE MIN HEAP ===" << endl;
    cout<<"| 1-HEAP_MINIMUM" << endl;
    cout<<"| 2-HEAP_EXTRACT_MIN" << endl;
    cout<<"| 3-HEAP_INCREASE_KEY (chave 1000 na posicao escolhida)" << endl;
    cout<<"| 4-MAX_HEAP_INSERT (inserir 1000)" << endl;
    cout<<"| 0-Voltar ao menu principal" << endl;
    cout<<"| Informe a operacao: ";
}

void tipoEntrada(){
    cout<<"|=========================TIPO ENTRADA=========================|"<< endl;
    cout<<"|c - Crescente                                                 |" <<endl;
    cout<<"|d - Decrescente                                               |" <<endl;
    cout<<"|r - Random                                                    |"<<endl;
    cout<<"|==============================================================|"<<endl;
    cout<<"Selecione a entrada: ";

}

void tamanho(){

    cout<<"|=========================TAMANHO ENTRADA=========================|"<< endl;
    cout<<"|1 - 10                                                           |" << endl;
    cout<<"|2 - 100                                                          |"<<endl;
    cout<<"|3 - 1000                                                         |"<<endl;
    cout<<"|4 - 10000                                                        |"<<endl;
    cout<<"|5 - 100000                                                       |"<<endl;
    cout<<"|6 - 1000000                                                      |"<<endl;
    cout<<"|=================================================================|"<< endl;
    cout<<"Selecione o tamanho: ";
}

#endif

