#include <stdio.h>
#include <stdlib.h>


int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    return matriz;
}


void liberarMatriz(int** matriz, int linhas) {
    for(int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void lerMatriz(int** matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


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

  
    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &colunasA);
    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &colunasB);

    if(colunasA != linhasB) {
        printf("Erro: o número de colunas de A deve ser igual ao número de linhas de B para a multiplicação.\n");
        return 1;
    }


    int** A = alocarMatriz(linhasA, colunasA);
    int** B = alocarMatriz(linhasB, colunasB);


    printf("Digite os elementos da matriz A:\n");
    lerMatriz(A, linhasA, colunasA);
    printf("Digite os elementos da matriz B:\n");
    lerMatriz(B, linhasB, colunasB);


    int** C = multiplicarMatrizes(A, B, linhasA, colunasA, colunasB);
    printf("Resultado da multiplicação (A * B):\n");
    imprimirMatriz(C, linhasA, colunasB);

    int** At = transporMatriz(A, linhasA, colunasA);
    printf("Transposição da matriz A:\n");
    imprimirMatriz(At, colunasA, linhasA);


    liberarMatriz(A, linhasA);
    liberarMatriz(B, linhasB);
    liberarMatriz(C, linhasA);
    liberarMatriz(At, colunasA);

    return 0;
}



