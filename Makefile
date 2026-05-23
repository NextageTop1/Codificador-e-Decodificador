# Nome do executável final
TARGET = huffman

# Compilador que será utilizado
CC = gcc

# Flags de compilação (Ativa todos os avisos de erro e otimiza o código)
CFLAGS = -Wall -Wextra -O2

# Lista dos arquivos de código-fonte (.c)
SRCS = main.c huffman.c heap.c tree.c bitwise.c

# Transforma a lista de .c em uma lista de arquivos objeto (.o)
OBJS = $(SRCS:.c=.o)

# Regra principal: é a que roda quando você digita apenas 'make'
all: $(TARGET)

# Como construir o executável final juntando todos os .o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Como construir cada arquivo .o a partir do seu .c correspondente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar a sujeira (roda quando você digita 'make clean')
clean:
	rm -f $(OBJS) $(TARGET)