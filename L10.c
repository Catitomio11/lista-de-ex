#include <stdio.h>
#include <time.h>


void processamentoSimples() {
    for (int i = 0; i < 1000000; i++) {
       
        int resultado = i * i;
    }
}

int main() {
    
    clock_t inicio, fim;
    double tempoDecorrido;

   
    inicio = clock();


    processamentoSimples();

    
    fim = clock();

    
    tempoDecorrido = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

 
    printf("Tempo decorrido: %.6f segundos\n", tempoDecorrido);

    return 0;
}

