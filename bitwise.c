#include "bitwise.h"

void escreverBit(FILE* arquivo, unsigned char* buffer , int* contador, char bit){

    *buffer = (*buffer << 1);


    if (bit == '1'){
        *buffer = (*buffer | 1 );
    }

    (*contador)++;

    if(*contador == 8){
        fwrite(buffer , 1 , 1 , arquivo);
        *buffer = 0;
        *contador = 0;
    }
}

void escreverCodigo(FILE* arquivo, unsigned char* buffer, int *contador, const char* codigo){
    int i = 0;
    while(codigo[i] != '\0'){
        escreverBit(arquivo, buffer, contador, codigo[i]);
        i++;
    }
}

unsigned char descarregadorBitsLixo(FILE* arquivo, unsigned char* buffer, int* contador){
    unsigned char lixo = 0;


    if(*contador > 0){
        lixo = 8 - *contador;

        *buffer = (*buffer << lixo);

        fwrite(buffer, 1, 1, arquivo);
    }

    return lixo;

}

int lerBit(FILE* arquivo, unsigned char *buffer, int* contador){
    if(*contador == 0){
        if(fread(buffer, 1, 1, arquivo) != 1){
            return -1;
        }
        *contador = 8;
    }


    int bit = (*buffer >> (*contador - 1)) & 1;

    (*contador)--;

    return bit;
}