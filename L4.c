#include <stdio.h>
#include <stdlib.h>

// Função para alocar memória para uma matriz
int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    return matriz;
}

// Função para liberar a memória de uma matriz
void liberarMatriz(int** matriz, int linhas) {
    for(int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para ler uma matriz
void lerMatriz(int** matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para multiplicar duas matrizes
int** multiplicarMatrizes(int** A, int** B, int linhasA, int colunasA, int colunasB) {
    int** C = alocarMatriz(linhasA, colunasB);
    for(int i = 0; i < linhasA; i++) {
        for(int j = 0; j < colunasB; j++) {
            C[i][j] = 0;
            for(int k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Função para transpor uma matriz
int** transporMatriz(int** matriz, int linhas, int colunas) {
    int** transposta = alocarMatriz(colunas, linhas);
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    return transposta;
}

int main() {
    int linhasA, colunasA, linhasB, colunasB;

    // Leitura das dimensões das matrizes A e B
    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &colunasA);
    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &colunasB);

    // Verifica se a multiplicação é possível
    if(colunasA != linhasB) {
        printf("Erro: o número de colunas de A deve ser igual ao número de linhas de B para a multiplicação.\n");
        return 1;
    }

    // Aloca memória para as matrizes A e B
    int** A = alocarMatriz(linhasA, colunasA);
    int** B = alocarMatriz(linhasB, colunasB);

    // Leitura das matrizes A e B
    printf("Digite os elementos da matriz A:\n");
    lerMatriz(A, linhasA, colunasA);
    printf("Digite os elementos da matriz B:\n");
    lerMatriz(B, linhasB, colunasB);

    // Multiplicação das matrizes A e B
    int** C = multiplicarMatrizes(A, B, linhasA, colunasA, colunasB);
    printf("Resultado da multiplicação (A * B):\n");
    imprimirMatriz(C, linhasA, colunasB);

    // Transposição da matriz A
    int** At = transporMatriz(A, linhasA, colunasA);
    printf("Transposição da matriz A:\n");
    imprimirMatriz(At, colunasA, linhasA);

    // Libera a memória alocada para as matrizes
    liberarMatriz(A, linhasA);
    liberarMatriz(B, linhasB);
    liberarMatriz(C, linhasA);
    liberarMatriz(At, colunasA);

    return 0;
}

