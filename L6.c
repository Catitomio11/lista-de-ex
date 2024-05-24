#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

// Estrutura para armazenar os dados do funcionário
typedef struct {
    char nome[MAX_NOME];
    int idade;
    float salario;
} Funcionario;

// Função para adicionar um novo registro de funcionário
void adicionarFuncionario(FILE *arquivo) {
    Funcionario funcionario;

    printf("Digite o nome do funcionário: ");
    scanf("%s", funcionario.nome);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &funcionario.idade);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario.salario);

    fseek(arquivo, 0, SEEK_END);
    fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);

    printf("Funcionário adicionado com sucesso!\n");
}

// Função para listar todos os registros de funcionários
void listarFuncionarios(FILE *arquivo) {
    Funcionario funcionario;
    rewind(arquivo);

    printf("Lista de Funcionários:\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }
}

// Função para buscar um funcionário pelo nome
void buscarFuncionario(FILE *arquivo) {
    char nomeBusca[MAX_NOME];
    Funcionario funcionario;
    int encontrado = 0;

    printf("Digite o nome do funcionário a ser buscado: ");
    scanf("%s", nomeBusca);

    rewind(arquivo);
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        if (strcmp(funcionario.nome, nomeBusca) == 0) {
            printf("Funcionário encontrado:\n");
            printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado.\n");
    }
}

int main() {
    FILE *arquivo = fopen("funcionarios.bin", "r+b");

    if (arquivo == NULL) {
        arquivo = fopen("funcionarios.bin", "w+b");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Funcionário\n");
        printf("2. Listar Funcionários\n");
        printf("3. Buscar Funcionário\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarFuncionario(arquivo);
                break;
            case 2:
                listarFuncionarios(arquivo);
                break;
            case 3:
                buscarFuncionario(arquivo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    fclose(arquivo);
    return 0;
}

