# Projeto de Algoritmos de Ordenação

Projeto da disciplina Projeto de Algoritmos (UFV-CRP) em C++. Compara seis algoritmos de ordenação em três tipos de entrada (crescente, decrescente e aleatória) e com tamanhos de 10 a 1.000.000 de elementos.

**Algoritmos:** Insertion Sort, Selection Sort, Bubble Sort, Shell Sort, Merge Sort e Quick Sort (pivô primeiro e pivô médio).

**Estrutura:**
- `main.cpp`: menu principal e chamadas dos algoritmos.
- `algoritmo.h`: implementação dos algoritmos com medição de tempo.
- `funcao.h`: gera as entradas, grava as saídas e os tempos.
- `arquivo.h`: cria as pastas de saída.
- `menu.h`: textos do menu.
- Uma pasta por algoritmo, com `ArquivosdeEntrada`, `ArquivosdeSaida` e `ArquivosdeTempo`.

**Como rodar:** compile `main.cpp` com um compilador C++ (por exemplo, `g++ main.cpp -o main`) e execute. Escolha o algoritmo no menu.
