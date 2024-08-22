#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_CONTAS 50
#define NOME_TAMANHO 50

typedef struct contabancaria {
    char nome[NOME_TAMANHO];
    int numeroConta;
} ContaBancaria;

void lerArquivoContas(const char *nomeArquivo, ContaBancaria *contas);

int buscaExponencial(ContaBancaria *contas, int n, int numeroConta);

int min(int x, int y);

void ordenarContas(ContaBancaria *contas, int n);

