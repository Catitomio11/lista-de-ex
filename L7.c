#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

int compararIdade(const void *a, const void *b) {
    const Funcionario *funcionarioA = (const Funcionario *)a;
    const Funcionario *funcionarioB = (const Funcionario *)b;

    // Ordem crescente por idade
    return funcionarioA->idade - funcionarioB->idade;
}

int main() {
    int numFuncionarios;


    printf("Digite o número de funcionários: ");
    scanf("%d", &numFuncionarios);

    while(getchar() != '\n');


    Funcionario *funcionarios = (Funcionario *)malloc(numFuncionarios * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

   
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0'; // Remove a quebra de linha
        printf("Digite a idade do funcionário %d: ", i + 1);
        scanf("%d", &funcionarios[i].idade);

        while(getchar() != '\n');
    }


    qsort(funcionarios, numFuncionarios, sizeof(Funcionario), compararIdade);


    printf("\nFuncionários ordenados por idade:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Idade: %d\n", funcionarios[i].nome, funcionarios[i].idade);
    }

    free(funcionarios);

    return 0;
}

