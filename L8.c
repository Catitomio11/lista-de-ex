#include <stdio.h>
#include <stdlib.h>

// Função para inverter um array utilizando ponteiros
int* inverterArray(const int* arr, int tamanho) {
    // Aloca memória para o novo array invertido
    int* arrayInvertido = (int*)malloc(tamanho * sizeof(int));
    if (arrayInvertido == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Ponteiro para o final do array original
    const int* ptr = arr + tamanho - 1;

    // Preenche o novo array invertido com os elementos do array original na ordem inversa
    for (int i = 0; i < tamanho; i++) {
        arrayInvertido[i] = *ptr;
        ptr--;
    }

    return arrayInvertido;
}

int main() {
    int tamanho;

    // Solicita ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Solicita ao usuário para digitar os elementos do array
    int* arr = (int*)malloc(tamanho * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Chama a função para inverter o array
    int* arrayInvertido = inverterArray(arr, tamanho);

    // Exibe o array invertido
    printf("Array Invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    // Libera a memória alocada para os arrays
    free(arr);
    free(arrayInvertido);

    return 0;
}

