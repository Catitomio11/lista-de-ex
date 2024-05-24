#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

// Função de comparação para qsort (compara funcionários com base na idade)
int compararIdade(const void *a, const void *b) {
    const Funcionario *funcionarioA = (const Funcionario *)a;
    const Funcionario *funcionarioB = (const Funcionario *)b;

    // Ordem crescente por idade
    return funcionarioA->idade - funcionarioB->idade;
}

int main() {
    int numFuncionarios;

    // Solicita ao usuário o número de funcionários
    printf("Digite o número de funcionários: ");
    scanf("%d", &numFuncionarios);

    // Limpar o buffer do teclado
    while(getchar() != '\n');

    // Aloca memória para o array de funcionários
    Funcionario *funcionarios = (Funcionario *)malloc(numFuncionarios * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Solicita ao usuário para inserir o nome e a idade de cada funcionário
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0'; // Remove a quebra de linha
        printf("Digite a idade do funcionário %d: ", i + 1);
        scanf("%d", &funcionarios[i].idade);
        // Limpar o buffer do teclado
        while(getchar() != '\n');
    }

    // Ordena o array de funcionários por idade
    qsort(funcionarios, numFuncionarios, sizeof(Funcionario), compararIdade);

    // Exibe os funcionários ordenados
    printf("\nFuncionários ordenados por idade:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Idade: %d\n", funcionarios[i].nome, funcionarios[i].idade);
    }

    // Libera a memória alocada
    free(funcionarios);

    return 0;
}

