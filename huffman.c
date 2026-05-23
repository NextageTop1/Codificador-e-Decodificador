#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
#include "heap.h"
#include "tree.h"
#include "bitwise.h"



void contarFrequencias(const char* nomeArquivo, int frequencias[256]){

    for(int i = 0; i < 256; i++) frequencias[i] = 0;

    FILE* arquivo = fopen(nomeArquivo, "rb" );

    if(!arquivo){
        printf("Erro ao abrir arquivo para contagem.\n");
        exit(1);
    }

    unsigned char byte;

    while(fread(&byte, 1, 1, arquivo) == 1){
        frequencias[byte]++;
    }

    fclose(arquivo);

}

void compactar(const char* arquivoEntrada, const char* arquivoSaida){
    int frequencias;
    contarFrequencias(arquivoEntrada, frequencias);

    int bytesUnicos = 0;
    for (int i = 0 ; i < 256 ; i++){
        if(frequencias[i] > 0 ) bytesUnicos++;
    }

    MinHeap* heap = createHeap(bytesUnicos);
    for (int i = 0 ; i < 256 ; i++){
        if(frequencias[i] > 0){
            inserirHeap(heap, createNfill((unsigned char)i, frequencias[i]));
        }
    }

    TNo* raiz = createHuffmanTree(heap);
    char tabelaCodigos[256][256] = {{0}};
    char codigoTemporario[256];
    gerarCodigo(raiz, codigoTemporario, 0, tabelaCodigos);

    FILE* in = fopen(arquivoEntrada, "rb");
    FILE* out = fopen(arquivoSaida, "wb");

    fwrite(&bytesUnicos, sizeof(int), 1, out);

    for(int i = 0; i < 256; i++){
        if(frequencias[i] > 0){
            unsigned char byte = (unsigned char)i;
            fwrite(&byte, sizeof(unsigned char), 1, out);
            fwrite(&frequencias[i], sizeof(int), 1, out);
        }
    }

    long posicaoLixo = ftell(out);
    unsigned char lixoTemporario = 0;
    fwrite(&lixoTemporario, sizeof(unsigned char), 1, out);

    unsigned char buffer = 0;
    int contadorBits = 0;
    unsigned char charLido;

    while(fread(&charLido, 1, 1, in) == 1){
        escreverCodigo(out, &buffer , &contador , tabelaCodigos[charLido]);
    }

    unsigned char lixoReal = descarregadorBitsLixo(out, &buffer, &contadorBits);


    fseek(out, posicaoLixo, SEEK_SET);
    fwrite(&lixoReal, sizeof(unsigned char), 1, out);

    fclose(in);
    fclose(out);
    freeTree(raiz);
    detruirHeap(heap);
    printf("Compressao Concluida!!!\n")

}