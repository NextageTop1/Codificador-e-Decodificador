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
    int frequencias[256];
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
    makeCodes(raiz, codigoTemporario, 0, tabelaCodigos);

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
        escreverCodigo(out, &buffer , &contadorBits , tabelaCodigos[charLido]);
    }

    unsigned char lixoReal = descarregadorBitsLixo(out, &buffer, &contadorBits);

    fseek(out, posicaoLixo, SEEK_SET);
    fwrite(&lixoReal, sizeof(unsigned char), 1 , out);

    fseek(out, 0 , SEEK_END);

    fclose(in);
    fclose(out);
    freeTree(raiz);
    destruirHeap(heap);
    printf("Compressao Concluida!!!\n");

}

void descompactar(const char* arquivoEntrada, const char* arquivoSaida){
    FILE* in = fopen(arquivoEntrada, "rb");
    if(!in){
        printf("Erro ao abrir arquivo .huff\n");
        return;
    }

    int bytesUnicos;
    if (fread(&bytesUnicos, sizeof(int), 1, in) != 1) {
        printf("Erro: Arquivo compactado vazio ou corrompido.\n");
        fclose(in);
        return;
    }


    MinHeap* heap = createHeap(bytesUnicos);
    for(int i = 0; i < bytesUnicos; i++){
        unsigned char byte;
        int freq;
        if (fread(&byte, sizeof(unsigned char), 1, in) != 1 || 
            fread(&freq, sizeof(int), 1, in) != 1) {
            printf("Erro: Falha ao ler a arvore do cabecalho.\n");
            fclose(in);
            return;
        }
        inserirHeap(heap, createNfill(byte, freq));
    }

    unsigned char lixo;
    
    if (fread(&lixo, sizeof(unsigned char), 1, in) != 1) {
        printf("Erro: Falha ao ler a informacao de lixo no cabecalho.\n");
        fclose(in);
        return;
    }

    TNo* raiz = createHuffmanTree(heap);

    FILE* out = fopen(arquivoSaida, "wb");

    TNo* atual = raiz;
    unsigned char buffer = 0;
    int contadorBits = 0;
    int caracteresExtraidos = 0;
    int totalCaracteres = raiz->frequencia;

    while(caracteresExtraidos < totalCaracteres){

        if (raiz->left == NULL && raiz->right == NULL){
            fwrite(&(raiz->byte), sizeof(unsigned char), 1, out);
            caracteresExtraidos++;
            continue;
        }

        int bit = lerBit(in, &buffer, &contadorBits);

        if(bit == -1){
            printf("A descompactação terminou antes do esperado!!!!");
            break;

        }

        if (bit == 0) atual = atual->left;
        else if (bit == 1) atual = atual->right;

        if(atual->left == NULL && atual->right == NULL){
            fwrite(&(atual->byte), sizeof(unsigned char), 1, out);

            caracteresExtraidos++;

            atual = raiz;
        }
    }

    fclose(in);
    fclose(out);
    freeTree(raiz);
    destruirHeap(heap);
    printf("Descompactado com susseso !!!!");
}