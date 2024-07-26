#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int vetor[], int n) {// Função de Selection Sort
    int i, j, aux;
    for (i = 1; i < n; i++) { // i percorre o vetor
        aux = vetor[i]; // guarda o valor de i
        j = i - 1;// j guarda o elemento anterior a i
        while (j >= 0 && vetor[j] > aux) { // enquanto j for maior que 0 e o valor de j for maior que o valor de i
            vetor[j + 1] = vetor[j]; // o valor de j+1 recebe o valor de j
            j--; // decrementa j
        }
        vetor[j + 1] = aux; // o valor de j+1 recebe o valor de i


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
    insertionSort(vetor, n);
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
