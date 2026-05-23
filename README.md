# Huffman Compressor & Decompressor

Implementação completa do algoritmo de Huffman em linguagem C para compressão e descompressão de arquivos utilizando estruturas de dados como Árvores Binárias, Filas de Prioridade (Min-Heap) e Tabelas Hash.

---

## 📚 Sobre o Projeto

Este projeto foi desenvolvido como atividade prática da disciplina de Estruturas de Dados, com o objetivo de aplicar conceitos de:

* Árvores Binárias
* Filas de Prioridade (Min-Heap)
* Manipulação de Bits
* Tabelas Hash
* Compressão de Dados

O programa permite:

✅ Compactar arquivos em formato `.huff`
✅ Descompactar arquivos restaurando exatamente o conteúdo original
✅ Trabalhar com qualquer tipo de arquivo (texto, imagem, binário, etc.)

---

# ⚙️ Funcionamento do Algoritmo de Huffman

O algoritmo de Huffman é um método de compressão sem perdas baseado na frequência dos bytes do arquivo.

## Processo de Compressão

1. O arquivo é lido byte a byte
2. É calculada a frequência de cada byte
3. É construída uma árvore de Huffman
4. Cada byte recebe um código binário variável
5. O arquivo é gravado em formato compactado (`.huff`)

## Processo de Descompressão

1. O cabeçalho do arquivo `.huff` é lido
2. A árvore de Huffman é reconstruída
3. Os bits são decodificados
4. O arquivo original é restaurado

---

# 📂 Estrutura do Projeto

```bash
.
├── main.c
├── huffman.c
├── huffman.h
├── heap.c
├── heap.h
├── tree.c
├── tree.h
├── bitwise.c
├── bitwise.h
├── Makefile
├── README.md
└── testes/
```

---

# 🧠 Estruturas de Dados Utilizadas

## 🌳 Árvore de Huffman

Responsável por representar os códigos binários de cada byte.

## 📦 Min-Heap

Utilizada para selecionar os nós de menor frequência durante a construção da árvore.

## 🗂️ Tabela de Frequências

Armazena a quantidade de ocorrências de cada byte possível (0–255).

---

# 📄 Formato do Arquivo `.huff`

O arquivo compactado possui o seguinte layout:

| Campo     | Tamanho  | Descrição                     |
| --------- | -------- | ----------------------------- |
| Contagem  | 4 bytes  | Quantidade de bytes únicos    |
| Tabela    | Variável | Pares `[Byte][Frequência]`    |
| Bits Lixo | 1 byte   | Bits inválidos no último byte |
| Payload   | Variável | Dados codificados             |

---

# 🛠️ Compilação

Para compilar o projeto:

```bash
gcc *.c -o huffman
```

ou utilizando o Makefile:

```bash
make
```

---

# ▶️ Execução

## Compactar Arquivo

```bash
./huffman -c arquivo.txt compactado.huff
```

## Descompactar Arquivo

```bash
./huffman -d compactado.huff arquivo_restaurado.txt
```

---

# 🧪 Arquivos de Teste

Os seguintes arquivos foram utilizados nos testes:

| Arquivo         | Tipo                          |
| --------------- | ----------------------------- |
| DomCasmurro.txt | Texto (~1MB)                  |
| repeticao.txt   | Alta repetição                |
| imagem.png      | Arquivo binário já compactado |

---

# 📊 Resultados de Compressão

| Arquivo         | Tamanho Original | Tamanho Compactado | Taxa de Compressão |
| --------------- | ---------------- | ------------------ | ------------------ |
| DomCasmurro.txt | 1.0 MB           | 620 KB             | 38%                |
| repeticao.txt   | 16 bytes         | 6 bytes            | 62.5%              |
| imagem.png      | 850 KB           | 860 KB             | -1.2%              |

> Observação: Arquivos já compactados normalmente não apresentam ganho de compressão, podendo até aumentar de tamanho devido ao cabeçalho do algoritmo.

---

# 🔍 Exemplo de Uso

## Compressão

```bash
./huffman -c exemplo.txt exemplo.huff
```

## Descompressão

```bash
./huffman -d exemplo.huff exemplo_restaurado.txt
```

---

# 💻 Tecnologias Utilizadas

* Linguagem C
* GCC
* Manipulação de Bits
* Estruturas de Dados

---

# 📌 Requisitos

* GCC instalado
* Sistema Linux, macOS ou Windows com MinGW

---

# 👨‍💻 Integrantes

* Vitor Gabriel
* Lázaro

---

# 📖 Referências

* Algoritmo de Huffman
* Estruturas de Dados em C
* Compressão Sem Perdas

---

# 📹 Apresentação

A apresentação do projeto deverá demonstrar:

* Funcionamento do compressor
* Funcionamento do descompressor
* Estruturas utilizadas
* Resultados dos testes
* Taxa de compressão obtida

---

# 📜 Licença

Este projeto foi desenvolvido para fins acadêmicos.
