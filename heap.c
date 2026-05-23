#include <stdio.h>
#include <stdio.h>
#include "heap.h"

MinHeap* createHeap(){
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
    HeapElement *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *heap, int indice){
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if(esquerda < heap->tamanho && heap->array[esq]->frequencia < heap->array[menor]->frequencia){
        menor = esquerda;
    }

    if(direita < heap->tamanho &&  heap->array[dir]->frequencia < heap->array[menor]->frequencia){
        menor = direita;
    }

    if(menor != indice){
        trocarElementos(&heap->array[idade], &heap->array[menor]);
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
    while(i != 0 && heap->array[pai].no->frequnecia > heap->array[i].no->frequencia){
        trocarElementos(&heap->array[i], &heap->array[pai]);
        i = pai;
        pai = (i - 1)/2;
    }
}

TNo* estrairMin(MinHeap *heap){
    if(heap->tamanho <= 0) return NULL;

    TNo *raiz = heap->array[0].no;

    heap->array[0] = heap->array[heap->tamanho - 1];
    heap->tamanho--;

    if (heap->tamanho > 0){
        minHeapify(heap, 0);
    }

    return raiz;
}

void destrurHeap(MinHeap *heap){
    if(heap != NULL){
        if(heap->array != NULL){
            free(heap->array);
        }
        free(heap);
    }

}