#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(int argc, char *argv[]) {
    // 1. Verifica se o usuário digitou a quantidade certa de palavras no terminal
    // Esperamos 4 palavras: ./huffman, -c (ou -d), entrada.txt, saida.huff
    if (argc != 4) {
        printf("\n--- Huffman Compressor & Decompressor ---\n");
        printf("Uso incorreto dos argumentos.\n\n");
        printf("Como usar:\n");
        printf("  Para compactar:   ./huffman -c <arquivo_original> <arquivo_compactado.huff>\n");
        printf("  Para descompactar: ./huffman -d <arquivo_compactado.huff> <arquivo_restaurado>\n\n");
        return 1; // Encerra o programa com código de erro
    }

    // argv[0] -> O nome do programa ("./huffman")
    // argv[1] -> A flag de comando ("-c" ou "-d")
    // argv[2] -> O nome do arquivo de entrada
    // argv[3] -> O nome do arquivo de saída

    // 2. Compara a string digitada com "-c"
    if (strcmp(argv[1], "-c") == 0) {
        printf("Iniciando compactacao do arquivo: %s\n", argv[2]);
        compactar(argv[2], argv[3]);
    } 
    // 3. Compara a string digitada com "-d"
    else if (strcmp(argv[1], "-d") == 0) {
        printf("Iniciando descompactacao do arquivo: %s\n", argv[2]);
        descompactar(argv[2], argv[3]);
    } 
    // 4. Se o usuário digitou qualquer outra coisa (ex: -x)
    else {
        printf("Erro: Comando '%s' invalido.\n", argv[1]);
        printf("Use '-c' para compactar ou '-d' para descompactar.\n");
        return 1;
    }

    return 0; // Execução finalizada com sucesso
}