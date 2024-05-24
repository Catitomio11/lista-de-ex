#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int count = 0;
    char c;

    // Solicita ao usuário para inserir uma string
    printf("Digite um nome: ");
    fgets(str, sizeof(str), stdin);

    // Conta o número de vogais na string
    for(int i = 0; str[i] != '\0'; i++) {
        c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    // Imprime o resultado
    printf("O número de vogais no nome é: %d\n", count);

    return 0;
}

