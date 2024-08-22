#include "ContaBancaria.h"

void lerArquivoContas(const char *nomeArquivo, ContaBancaria *contas)
{
    int i;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (i = 0; i < TOTAL_CONTAS; i++)
    {
        if (fscanf(arquivo, "%d %s", &contas[i].numeroConta, contas[i].nome) != 2)
        {
            printf("Erro ao ler dados do arquivo na linha %d.\n", i + 1);
            break;
        }
    }

    fclose(arquivo);
}

int buscaExponencial(ContaBancaria *contas, int n, int numeroConta)
{
    if (contas[0].numeroConta == numeroConta)
    {
        return 0;
    }

    int i = 1;
    while (i < n && contas[i].numeroConta <= numeroConta)
    {
        i = i * 2;
    }

    // Chama busca binária entre i/2 e o mínimo entre i e n-1
    int esquerda = i / 2;
    int direita = min(i, n - 1);

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        if (contas[meio].numeroConta == numeroConta)
        {
            return meio;
        }
        if (contas[meio].numeroConta < numeroConta)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1; // Não encontrado
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

void ordenarContas(ContaBancaria *contas, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (contas[j].numeroConta > contas[j + 1].numeroConta)
            {
                ContaBancaria temp = contas[j];
                contas[j] = contas[j + 1];
                contas[j + 1] = temp;
            }
        }
    }
}
