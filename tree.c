#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

TNo* createNfill(unsigned char byte, int frequencia){
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    if(novo != NULL ){
        novo->byte = byte;
        novo->frequencia = frequencia;
        novo->left = NULL;
        novo->right = NULL;
    }
    return novo;
}

TNo* createHuffmanTree(MinHeap *heap){

    while(heap->tamanho > 1) {
        TNo* esquerda = extrairMin(heap);
        TNo* direita = extrairMin(heap);

        TNo* pai = createNfill('*', esquerda->frequencia + direita->frequencia);

        pai->left = esquerda;
        pai->right = direita;

        inserirHeap(heap, pai);

    }

    return extrairMin(heap);
}

void makeCodes(TNo* raiz, char* codigoAtual, int profundidade, char tabela[256][256]){
    if (raiz == NULL ) return;

    if(raiz->left == NULL && raiz->right == NULL){
        codigoAtual[profundidade] = '\0';

        strcpy(tabela[raiz->byte], codigoAtual);

        return;
    }

    if (raiz->left){
        codigoAtual[profundidade] = '0';
        makeCodes(raiz->left, codigoAtual, profundidade + 1, tabela);
    }

    if(raiz->right){
        codigoAtual[profundidade] = '1';
        makeCodes(raiz->right, codigoAtual, profundidade + 1, tabela);
    }
}

void freeTree(TNo* raiz){
    if(raiz == NULL) return;

    freeTree(raiz->left);
    freeTree(raiz->right);

    free(raiz);
}