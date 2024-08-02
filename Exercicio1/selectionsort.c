#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int n) {// Função de Selection Sort
    int i, j, menor, aux;
    for (i = 0; i < n - 1; i++) { // i percorre o vetor
        menor = i;//menor vai guardar o menor valor para ser comparado
        for (j = i + 1; j < n; j++) {//j percorre afrente de i
            if (vetor[j] < vetor[menor]) {//se j<menor logo ele é o novo menor 
                menor = j;
            }
        }
        aux = vetor[menor]; // guarda o menor
        vetor[menor] = vetor[i];
        vetor[i] = aux;// troca o menor com o elemento i
    }
}

int main() {
    FILE *arq;
    int n = 0, tamanho = 10;
    int *vetor;

    arq = fopen("num.1000.2.in", "r");// Abrir o arquivo para leitura, mudar o nome do arquivo alí 
    if (arq == NULL) {
        printf("erro no arquivo ;-;\n");
        return 1;
    }

  
    vetor = (int *)malloc(tamanho * sizeof(int)); //aloca memoria 
    
    while (fscanf(arq, "%d", &vetor[n]) != EOF) { // Lê os valores do arquivo e armazená-los no vetor
        n++;
        if (n == tamanho) {
            tamanho *= 2;
            int *temp = (int *)realloc(vetor, tamanho * sizeof(int)); // aloca mais memoria se necessario
            if (temp == NULL) {
                printf("Erro ao alocar mais memória!\n");
                free(vetor);
                fclose(arq);
                return 1;
            }
            vetor = temp;
        }
    }

    
    fclose(arq);// Fechar o arquivo

    
    clock_t start = clock();
    selectionSort(vetor, n);
    clock_t end = clock();// Função pra medir o tempo de execução do algoritmo

    
    printf("Resultado:\n"); // Imprimir o vetor
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

   
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo: %f s\n", time);  // Calcular e imprimir o tempo de execução

    return 0;
}