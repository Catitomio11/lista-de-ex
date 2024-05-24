#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100


struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    struct Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    char escolha[4];

    do {
        
        printf("Digite o nome do produto: ");
        scanf("%s", produtos[numProdutos].nome);
        printf("Digite o preço do produto: ");
        scanf("%f", &produtos[numProdutos].preco);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &produtos[numProdutos].quantidade);
        numProdutos++;

        printf("Deseja cadastrar outro produto? (sim/nao): ");
        scanf("%s", escolha);
    } while (strcmp(escolha, "sim") == 0);

    
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
        printf("\n");
    }

  
    float valorTotal = 0;
    for (int i = 0; i < numProdutos; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }
    printf("Valor total em estoque: %.2f\n", valorTotal);

    return 0;
}









