#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função para converter uma string para maiúsculas usando ponteiros
void converterParaMaiusculas(char *texto) {
    while (*texto) {
        *texto = toupper(*texto);
        texto++;
    }
}

int main() {
    char entrada[100];

    // Solicita ao usuário para inserir uma string
    printf("Digite uma string: ");
    fgets(entrada, sizeof(entrada), stdin);

    // Remove o caractere de nova linha lido por fgets
    size_t comprimento = strlen(entrada);
    if (comprimento > 0 && entrada[comprimento - 1] == '\n') {
        entrada[comprimento - 1] = '\0';
    }

    // Converte a string para maiúsculas
    converterParaMaiusculas(entrada);

    // Exibe a string convertida
    printf("String convertida para maiúsculas: %s\n", entrada);

    return 0;
}

