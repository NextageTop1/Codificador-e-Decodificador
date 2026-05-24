#ifndef TREE_H
#define TREE_H

#include "heap.h"

TNo* createNfill(unsigned char byte, int frequencia);
TNo* createHuffmanTree(MinHeap* heap);

void makeCodes(TNo* raiz, char *codigoAtual, int profundidade, char tabela[256][256]);

void freeTree(TNo* raiz);

#endif