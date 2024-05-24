#include <stdio.h>

void lerElementos(int *array, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

int somaElementos(int *array, int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main() {
    int tamanho;

    printf("Quantos elementos você deseja inserir? ");
    scanf("%d", &tamanho);

    int array[tamanho];

    lerElementos(array, tamanho);

    int soma = somaElementos(array, tamanho);

    printf("A soma dos elementos dentro da array é: %d\n", soma);

    return 0;
}
