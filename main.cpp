#include <iostream>
#include <cstdlib>
#include <fstream>

#include "menu.h"
#include "arquivo.h"
#include "funcao.h"

using namespace std;

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    int algoritmo;
    char entrada;
    int tamanhoIns;

    criarPastaInsertionSort();
    criarPastaBubbleSort();
    criarPastaShellSort();
    criarPastaSelectionSort();
    criarPastaMergeSort();
    criarPastaQuickSortPrimeiro();
    criarPastaQuickSortMedia();

    do{
        menu();
        cin >> algoritmo;
        cin.ignore();

        if(algoritmo == 0) {
            cout << "O programa foi finalizado" << endl;
            limparTela();
            exit(0);
        } else if(algoritmo < 0 || algoritmo > 7) { 
            cout << "Opcao invalida! Use valores de 0 a 7 ou 0 para sair." << endl;
            cout << "Pressione Enter para continuar...";
            cin.get();
            limparTela();
            continue;
        }

        limparTela();
        tipoEntrada();

        cin >> entrada;
        cin.ignore();

        if(entrada != 'c' && entrada != 'd' && entrada != 'r') {
            cout << "Opcao Invalida! Use apenas c, d ou r." << endl;
            cout << "Pressione Enter para continuar...";
            cin.get();
            limparTela();
            continue;
        }

        limparTela();
        tamanho();

        cin >> tamanhoIns;
        cin.ignore();

        if(tamanhoIns < 1 || tamanhoIns > 6) {
            cout << "Opcao de tamanho invalida! Use valores de 1 a 6." << endl;
            cout << "Pressione Enter para continuar...";
            cin.get();
            limparTela();
            continue;
        }

        limparTela();


        // Executar o algoritmo escolhido
        if(algoritmo == 1) {
            cout << "Processando Insertion Sort..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            InsertionSort(tamanhoIns, entrada);
        } else if(algoritmo == 2) {
            cout << "Processando Bubble Sort..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            BubbleSort(tamanhoIns, entrada);
        } else if(algoritmo == 3) {
            cout << "Processando Shell Sort..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            ShellSort(tamanhoIns, entrada);
        } else if(algoritmo == 4) {
            cout << "Processando Selection Sort..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            SelectionSort(tamanhoIns, entrada);
        } else if(algoritmo == 5) {
            cout << "Processando Merge Sort..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            MergeSort(tamanhoIns, entrada);
        }else if(algoritmo == 6) {
            cout << "Processando Quick Sort (Pivo: Primeiro)..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            QuickSortPrimeiro(tamanhoIns, entrada);
        } else if(algoritmo == 7) {
            cout << "Processando Quick Sort (Pivo: Media)..." << endl;
            cout << "Criando arquivos..." << endl << endl;
            QuickSortMedia(tamanhoIns, entrada);
        } 

        cout << endl << "Processamento concluido!" << endl;
        cout << "Pressione Enter para continuar...";
        cin.get();
        limparTela();

    } while(true);

    return 0;
}