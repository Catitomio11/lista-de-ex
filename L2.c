#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int count = 0;
    char c;

    
    printf("Digite um nome: ");
    fgets(str, sizeof(str), stdin);

    
    for(int i = 0; str[i] != '\0'; i++) {
        c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    
    printf("O número de vogais no nome é: %d\n", count);

    return 0;
}







