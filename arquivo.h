#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif

using namespace std;

bool diretorioExiste(const string& path) {
    struct stat info;
    return (stat(path.c_str(), &info) == 0 && (info.st_mode & S_IFDIR));
}

void createDiretorio(const string& path) {
    if (!diretorioExiste(path)) {
        if (MKDIR(path.c_str()) != 0) {
            cout << "Erro ao criar diretorio: " << path << endl;
        } else {
            cout << "Diretorio criado: " << path << endl;
        }
    }
}

// Fun��o auxiliar para criar a estrutura completa de um algoritmo
void criarEstruturaCompleta(const string& nomeAlgoritmo) {
    cout << "Criando estrutura de diretorios para " << nomeAlgoritmo << "..." << endl;

    // Criar pasta principal
    createDiretorio(nomeAlgoritmo);

    // Criar pastas de Entrada, Sa�da e Tempo
    createDiretorio(nomeAlgoritmo + "/ArquivosdeEntrada");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeSaida");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeTempo");

    // Criar subpastas dentro de Entrada
    createDiretorio(nomeAlgoritmo + "/ArquivosdeEntrada/Crescente");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeEntrada/Decrescente");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeEntrada/Randomico");

    // Criar subpastas dentro de Sa�da
    createDiretorio(nomeAlgoritmo + "/ArquivosdeSaida/Crescente");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeSaida/Decrescente");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeSaida/Randomico");

    // Criar subpastas dentro de Tempo
    createDiretorio(nomeAlgoritmo + "/ArquivosdeTempo/Crescente");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeTempo/Decrescente");
    createDiretorio(nomeAlgoritmo + "/ArquivosdeTempo/Randomico");

    cout << "Estrutura de diretorios do " << nomeAlgoritmo << " criada com sucesso!" << endl << endl;
}

void criarPastaInsertionSort() {
    criarEstruturaCompleta("InsertionSort");
}

void criarPastaBubbleSort() {
    criarEstruturaCompleta("BubbleSort");
}

void criarPastaShellSort() {
    criarEstruturaCompleta("ShellSort");
}

void criarPastaSelectionSort() {
    criarEstruturaCompleta("SelectionSort");
}

void criarPastaMergeSort() {
    criarEstruturaCompleta("MergeSort");
}

void criarPastaQuickSortPrimeiro() {
    criarEstruturaCompleta("QuickSortPrimeiro");
}

void criarPastaQuickSortMedia() {
    criarEstruturaCompleta("QuickSortMedia");
}


#endif
