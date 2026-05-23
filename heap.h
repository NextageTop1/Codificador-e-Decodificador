#ifndef HEAP_H
#define HEAP_H

typedef struct TNo*{
    unsigned char byte;
    int frequencia;
    struct TNo *left;
    struct TNo *right;
}TNo;

typedef struct HeapElement {
    TNo *no;
}HeapElement;

typedef struct MinHeap{
    int tamanho;
    int capacidade;
    HeapElement *array;
}MinHeap;

MinHeap* CreateHeap(int capacidade);
void trocarElementos(HeapElement *a, HeapElement *b);
void minHeapify(MinHeap *a, int indice);
void iserirHeap(MinHeap *heap, TNo *no);
TNo* extrairMin(MinHeap *heap);
void destruirHeap(MinHeap *heap);

#endif