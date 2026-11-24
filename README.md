# Projeto de Algoritmos de Ordenação

Projeto da disciplina Projeto de Algoritmos (UFV-CRP) em C++. Compara sete algoritmos de ordenação em três tipos de entrada (crescente, decrescente e aleatória) e com tamanhos de 10 a 1.000.000 de elementos.

**Algoritmos:** Insertion Sort, Selection Sort, Bubble Sort, Shell Sort, Merge Sort, Quick Sort (pivô primeiro e pivô médio) e Heap Sort (heap mínimo, saída em ordem decrescente).

**Fila de prioridade mínima (opção 9):** HEAP_MINIMUM, HEAP_EXTRACT_MIN, HEAP_INCREASE_KEY e MAX_HEAP_INSERT (versão mínimo).

**Estrutura:**
- `main.cpp`: menu principal e chamadas dos algoritmos.
- `algoritmo.h`: implementação dos algoritmos com medição de tempo, incluindo `minHeapify`, `buildMinHeap`, `heapSortMin` e a classe `MinHeap`.
- `funcao.h`: gera as entradas, grava as saídas e os tempos.
- `arquivo.h`: cria as pastas de saída.
- `menu.h`: textos do menu.
- Uma pasta por algoritmo, com `ArquivosdeEntrada`, `ArquivosdeSaida` e `ArquivosdeTempo`.

**Como rodar:** compile `main.cpp` com um compilador C++ (por exemplo, `g++ main.cpp -o main`) e execute. Escolha o algoritmo no menu.
