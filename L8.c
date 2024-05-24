#include <stdio.h>
#include <stdlib.h>


int* inverterArray(const int* arr, int tamanho) {

    int* arrayInvertido = (int*)malloc(tamanho * sizeof(int));
    if (arrayInvertido == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }


    const int* ptr = arr + tamanho - 1;

    for (int i = 0; i < tamanho; i++) {
        arrayInvertido[i] = *ptr;
        ptr--;
    }

    return arrayInvertido;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);


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


    int* arrayInvertido = inverterArray(arr, tamanho);


    printf("Array Invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");


    free(arr);
    free(arrayInvertido);

    return 0;
}

