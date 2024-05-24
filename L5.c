#include <stdio.h>
#include <ctype.h>
#include <string.h>


void converterParaMaiusculas(char *texto) {
    while (*texto) {
        *texto = toupper(*texto);
        texto++;
    }
}

int main() {
    char entrada[100];


    printf("Digite uma string: ");
    fgets(entrada, sizeof(entrada), stdin);

   
    size_t comprimento = strlen(entrada);
    if (comprimento > 0 && entrada[comprimento - 1] == '\n') {
        entrada[comprimento - 1] = '\0';
    }

    converterParaMaiusculas(entrada);


    printf("String convertida para maiúsculas: %s\n", entrada);

    return 0;
}

