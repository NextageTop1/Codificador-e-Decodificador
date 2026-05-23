#ifndef BITWISE_H
#define BITWISE_H

#include <stdio.h>

void escreverBit(FILE* arquivo, unsigned char* buffer, int* contador, char bit);

void escreverCodigo(FILE* arquivo, unsigned char* buffer, int *contador, const char* codigo);

int lerBit(FILE* arquivo, unsigned char* buffer, int *contador);

#endif
