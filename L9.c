#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois inteiros (necessária para qsort)
int compararInteiros(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função para calcular a média de um array de números
double calcularMedia(int *array, int tamanho) {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma / tamanho;
}

// Função para calcular a mediana de um array de números
double calcularMediana(int *array, int tamanho) {
    // Ordena o array
    qsort(array, tamanho, sizeof(int), compararInteiros);

    // Se o tamanho do array for ímpar, a mediana é o elemento do meio
    if (tamanho % 2 != 0) {
        return array[tamanho / 2];
    }
    // Se o tamanho do array for par, a mediana é a média dos dois elementos do meio
    else {
        int meio1 = array[tamanho / 2 - 1];
        int meio2 = array[tamanho / 2];
        return (double)(meio1 + meio2) / 2.0;
    }
}

// Função para calcular a moda de um array de números
int calcularModa(int *array, int tamanho) {
    int moda = 0;
    int frequencia = 0;
    int maxFrequencia = 0;

    // Percorre o array para encontrar a moda
    for (int i = 0; i < tamanho; i++) {
        int contagem = 0;
        for (int j = 0; j < tamanho; j++) {
            if (array[j] == array[i]) {
                contagem++;
            }
        }
        if (contagem > maxFrequencia) {
            maxFrequencia = contagem;
            moda = array[i];
        }
    }

    // Se não houver moda, retorna 0
    if (maxFrequencia <= 1) {
        return 0;
    }

    return moda;
}

int main() {
    int tamanho;

    // Solicita ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Aloca memória para o array
    int *array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Solicita ao usuário para inserir os elementos do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Calcula a média, mediana e moda
    double media = calcularMedia(array, tamanho);
    double mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

    // Exibe os resultados
    printf("\nResultados:\n");
    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    if (moda != 0) {
        printf("Moda: %d\n", moda);
    } else {
        printf("Sem moda\n");
    }

    // Libera a memória alocada para o array
    free(array);

    return 0;
}

