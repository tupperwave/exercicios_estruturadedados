#include <stdio.h>
#include <stdlib.h>

#define n 10

// define o que é lista
typedef struct {
    int vetor[n];
    int tam;
} List;

void criar(List* lista){
    lista->tam = 0;
}

int itsvazio(List* lista){
    return lista->tam == 0;
}

int itscheio (List* lista){
    return lista->tam == n;
}

int itstamanho (List* lista){
    return lista->tam;
}

int itsposição(List* lista, int pos){
    for (int i = 0; i < lista->tam; i++){
        if (lista->vetor[i] == pos){
            printf("O elemento %d está na posição %d/n", pos, i); 
            return 1;
        }   
    }
    return 0;
}

int inserir(List* lista, int pos, int valor){
    if (itscheio(lista)){
        return 0;
    }
    if (pos < 0 || pos > lista->tam){
        return 0;//verifica se a posição é válida
    }
    for (int i = lista->tam; i > pos; i--){
        lista->vetor[i] = lista->vetor[i-1];
    }
    lista->vetor[pos] = valor;
    lista->tam++;
    return 1;
}

int retirar(List* lista, int pos){

    for (int i = pos; i < lista->tam-1; i++){
        lista->vetor[i] = lista->vetor[i+1];
    }
    lista->tam--;
    return 1;
}

int main (){
    List lista;
    criar(&lista);
    int pos; 
    int valor; 
    

printf("Insira os elementos na lista(no maximo 10)/n ");
for (int i = 0; i < n; i++){
scanf("%d", &lista.vetor[i]);
lista.tam++;
}
printf("A lista tem %d elementos/n", itstamanho(&lista));
printf("A lista está cheia? %d/n", itscheio(&lista));
printf("A lista está vazia? %d/n", itsvazio(&lista));

printf("Qual elemento deseja saber a posição?/n");
   
scanf("%d", &pos);
if (itsposição(&lista, pos)){
    printf("O elemento da posição %d é %d/n", pos, lista.vetor[pos]);
}

printf("Qual elemento deseja inserir?/n");

scanf("%d", &valor);
printf("Em qual posição deseja inserir?/n");
scanf("%d", &pos);

if (inserir(&lista, pos, valor)){
    printf("Elemento inserido com sucesso/n");
    printf("A lista tem %d elementos/n", itstamanho(&lista));
}

printf("Qual elemento deseja retirar?/n"); 
scanf("%d", &pos);

if (retirar(&lista, pos)){
    printf("Elemento retirado com sucesso/n");
    printf("A lista tem %d elementos/n", itstamanho(&lista));
}
}
