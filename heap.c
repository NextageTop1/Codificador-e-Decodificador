#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

MinHeap* createHeap(int capacidade){
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    if(heap == NULL) return NULL;

    heap->tamanho = 0;
    heap->capacidade = capacidade;

    heap->array = (HeapElement*)malloc(capacidade * sizeof(HeapElement));

    if(heap->array == NULL){
        free(heap);
        return NULL;
    }

    return heap;

}

void trocarElementos(HeapElement *a, HeapElement *b){
    HeapElement temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *heap, int indice){
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if(esq < heap->tamanho && heap->array[esq].no->frequencia < heap->array[menor].no->frequencia){
        menor = esq;
    }

    if(dir < heap->tamanho &&  heap->array[dir].no->frequencia < heap->array[menor].no->frequencia){
        menor = dir;
    }

    if(menor != indice){
        trocarElementos(&heap->array[indice], &heap->array[menor]);
        minHeapify(heap, menor);
    }
}


void inserirHeap(MinHeap *heap, TNo *no){
    if(heap->tamanho >= heap->capacidade)
        return;

    int i = heap->tamanho;
    heap->tamanho++;

    heap->array[i].no = no;

    int pai = (i - 1) / 2;
    while(i != 0 && heap->array[pai].no->frequencia > heap->array[i].no->frequencia){
        trocarElementos(&heap->array[i], &heap->array[pai]);
        i = pai;
        pai = (i - 1)/2;
    }
}

TNo* extrairMin(MinHeap *heap){
    if(heap->tamanho <= 0) return NULL;

    TNo *raiz = heap->array[0].no;

    heap->array[0] = heap->array[heap->tamanho - 1];
    heap->tamanho--;

    if (heap->tamanho > 0){
        minHeapify(heap, 0);
    }

    return raiz;
}

void destruirHeap(MinHeap *heap){
    if(heap != NULL){
        if(heap->array != NULL){
            free(heap->array);
        }
        free(heap);
    }

}