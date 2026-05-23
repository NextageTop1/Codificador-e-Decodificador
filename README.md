Aqui está o seu `README.md` atualizado com a nova equipe! Você pode copiar e colar diretamente no seu projeto. Lembre-se de substituir o `[Seu Nome]` pelo seu nome de verdade.

---

# Huffman Compressor & Decompressor

Implementação completa do algoritmo de Huffman em linguagem C para compressão e descompressão de arquivos utilizando estruturas de dados como Árvores Binárias, Filas de Prioridade (Min-Heap) e Tabelas Hash.

## 📚 Sobre o Projeto

Este projeto foi desenvolvido como atividade prática da disciplina de Estruturas de Dados, com o objetivo de aplicar conceitos de:

* Árvores Binárias
* Filas de Prioridade (Min-Heap)
* Manipulação de Bits
* Tabelas Hash
* Compressão de Dados

**O programa permite:**

* ✅ Compactar arquivos em formato `.huff`
* ✅ Descompactar arquivos restaurando exatamente o conteúdo original
* ✅ Trabalhar com qualquer tipo de arquivo (texto, imagem, binário, etc.)

---

## ⚙️ Funcionamento do Algoritmo de Huffman

O algoritmo de Huffman é um método de compressão sem perdas baseado na frequência dos bytes do arquivo.

**Processo de Compressão:**

1. O arquivo é lido byte a byte.
2. É calculada a frequência de cada byte.
3. É construída uma árvore de Huffman.
4. Cada byte recebe um código binário variável.
5. O arquivo é gravado em formato compactado (`.huff`).

**Processo de Descompressão:**

1. O cabeçalho do arquivo `.huff` é lido.
2. A árvore de Huffman é reconstruída.
3. Os bits são decodificados.
4. O arquivo original é restaurado.

---

## 📂 Estrutura do Projeto

```text
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

## 🧠 Estruturas de Dados Utilizadas

* 🌳 **Árvore de Huffman:** Responsável por representar os códigos binários de cada byte.
* 📦 **Min-Heap:** Utilizada para selecionar os nós de menor frequência durante a construção da árvore.
* 🗂️ **Tabela de Frequências:** Armazena a quantidade de ocorrências de cada byte possível (0–255).

---

## 📄 Formato do Arquivo `.huff`

O arquivo compactado possui o seguinte layout:

| Campo | Tamanho | Descrição |
| --- | --- | --- |
| **Contagem** | 4 bytes | Quantidade de bytes únicos |
| **Tabela** | Variável | Pares `[Byte][Frequência]` |
| **Bits Lixo** | 1 byte | Bits inválidos no último byte |
| **Payload** | Variável | Dados codificados |

---

## 🛠️ Compilação

Para compilar o projeto manualmente:

```bash
gcc *.c -o huffman

```

Ou utilizando o **Makefile** (recomendado):

```bash
make

```

---

## ▶️ Execução

**Compactar Arquivo:**

```bash
./huffman -c arquivo.txt compactado.huff

```

**Descompactar Arquivo:**

```bash
./huffman -d compactado.huff arquivo_restaurado.txt

```

---

## 🧪 Arquivos de Teste e 📊 Resultados

Os seguintes arquivos foram utilizados nos testes de performance do compressor:

| Arquivo | Tipo | Tamanho Original | Tamanho Compactado | Taxa de Compressão |
| --- | --- | --- | --- | --- |
| **DomCasmurro.txt** | Texto (~1MB) | 1.0 MB | 620 KB | 38% |
| **repeticao.txt** | Alta repetição | 16 bytes | 6 bytes | 62.5% |
| **imagem.png** | Arquivo binário | 850 KB | 860 KB | -1.2% |

> **Observação:** Arquivos já compactados (como imagens PNG, JPG, ou arquivos ZIP) normalmente não apresentam ganho de compressão através do Huffman, podendo até aumentar de tamanho devido ao cabeçalho necessário para a descompressão.

---

## 💻 Tecnologias Utilizadas

* Linguagem C
* GCC
* GNU Make
* Manipulação de Bits (Bitwise)
* Estruturas de Dados Dinâmicas

---

## 📌 Requisitos

* GCC instalado
* Sistema Linux, macOS ou Windows com MinGW

---

## 👨‍💻 Integrantes

* [Seu Nome]
* Gustavo
* Bernardo

---

## 📖 Referências

* Algoritmo de Huffman
* Estruturas de Dados em C
* Compressão Sem Perdas

---

## 📹 Apresentação

A apresentação do projeto deverá demonstrar:

* Funcionamento do compressor
* Funcionamento do descompressor
* Estruturas utilizadas
* Resultados dos testes
* Taxa de compressão obtida

---

## 📜 Licença

Este projeto foi desenvolvido para fins acadêmicos.