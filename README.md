# Busca Exponencial

Discentes:

Lucas Fernandes Vieira

Giovanni Willian

## O que é?
  
A busca exponencial é um código que encontra um determinado elemento dentro de um vetor.
Inicia comparando o primeiro elemento do vetor, caso não seja o elemento desejado vai dobrar o índice até que seu valor seja igual ou maior que o valor buscado.
Depois disso uma busca binária é feita dentro do intervalo encontrado.

```c
    int buscaExponencial(int *arr, int n, int valor) {
        // Verifica se o valor está no primeiro elemento
        if (arr[0] == valor) {
            return 0;
        }
        // Encontra o intervalo onde o valor pode estar
        int i = 1;
        while (i < n && arr[i] <= valor) {
            i *= 2;
        }
        // Realiza busca binária no intervalo identificado
        return buscaBinaria(arr, i / 2, (i < n) ? i : n - 1, valor);
    }
```
## Quando usar?

Funciona bem em vetores ordenados, especialmente quando a busca binária é inviável pelo fato do tamanho do vetor ser desconhecido, ou quando o vetor é muito grande.
É útil para encontrar uma informação em um banco de dados.

## Como Funciona?

* Primeiro, verifica se o valor está na primeira posição.

* Em seguida, vai dobrando o índice 𝑖 até encontrar um intervalo onde o valor pode estar.

* Finalmente, chama a função "buscaBinaria" para procurar dentro desse intervalo.

## Complexidade de Tempo

> Melhor Caso: Quando o vetor a ser buscado é o primeiro da lista a complexidade será O(1).

> Pior Caso: Quando o vetor a ser buscado é o ultimo da lista a complexidade será O(log n).

## Complexidade de Espaço

A busca exponencial, assim como a busca binária, não exige armazenamento adicional significativo além das variáveis usadas para a busca, sendo assim a complexidade de espaço constante, O(1).

## Prós

* É mais eficiente do que a busca linear e funciona bem com grandes conjuntos de dados.

* A busca exponencial é simples e fácil de implementar.

## Contras

* A busca exponencial requer a classificação de toda a lista, o que nem sempre é possível ou prático.

* O algoritmo pode não ser eficiente para conjuntos de dados em que o valor de destino está localizado próximo ao início da lista.

