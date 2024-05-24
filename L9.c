#include <stdio.h>
#include <stdlib.h>


int compararInteiros(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


double calcularMedia(int *array, int tamanho) {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma / tamanho;
}


double calcularMediana(int *array, int tamanho) {

    qsort(array, tamanho, sizeof(int), compararInteiros);

 
    if (tamanho % 2 != 0) {
        return array[tamanho / 2];
    }
    else {
        int meio1 = array[tamanho / 2 - 1];
        int meio2 = array[tamanho / 2];
        return (double)(meio1 + meio2) / 2.0;
    }
}


int calcularModa(int *array, int tamanho) {
    int moda = 0;
    int frequencia = 0;
    int maxFrequencia = 0;

  
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

 
    if (maxFrequencia <= 1) {
        return 0;
    }

    return moda;
}

int main() {
    int tamanho;

   
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

   
    int *array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

   
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    double media = calcularMedia(array, tamanho);
    double mediana = calcularMediana(array, tamanho);
    int moda = calcularModa(array, tamanho);

  
    printf("\nResultados:\n");
    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    if (moda != 0) {
        printf("Moda: %d\n", moda);
    } else {
        printf("Sem moda\n");
    }

 
    free(array);

    return 0;
}

