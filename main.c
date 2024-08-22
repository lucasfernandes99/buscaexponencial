#include <stdio.h>
#include "ContaBancaria.h"
#include <time.h>

int main()
{
    const char *nomeArquivo = "contas_bancarias.txt";
    ContaBancaria contas[TOTAL_CONTAS];
    int numeroConta;
    int i;

    lerArquivoContas(nomeArquivo, contas);
    ordenarContas(contas, TOTAL_CONTAS); // Garantir que os dados estão ordenados

    // Debug: Verificar se os dados foram lidos corretamente
    for (i = 0; i < TOTAL_CONTAS; i++)
    {
        printf("Conta: %d, Nome: %s\n", contas[i].numeroConta, contas[i].nome);
    }

    printf("Digite o numero da conta a ser buscada: ");
    scanf("%d", &numeroConta);

    // Marcar o tempo de início
    clock_t inicio = clock();
    int indice = buscaExponencial(contas, TOTAL_CONTAS, numeroConta);
    // Marcar o tempo de fim
    clock_t fim = clock();
    // Calcular o tempo gasto em milissegundos
    double tempoGasto = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    if (indice != -1)
    {
        printf("Nome: %s\n", contas[indice].nome);
    }
    else
    {
        printf("Conta não encontrada.\n");
    }

        printf("Tempo de execucao: %f milissegundos\n", tempoGasto);

    return 0;
}
