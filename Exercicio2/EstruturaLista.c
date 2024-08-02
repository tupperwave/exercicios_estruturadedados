#include <stdio.h>
#include <stdlib.h>

#define MAX 10


// define o que é lista
typedef struct {
    int vetor[MAX];
    int tam;
} List;

void criar(List* lista){
    lista->tam = 0;
}

int itsvazio(List* lista){
    return lista->tam == 0;
}

int itscheio (List* lista){
    return lista->tam == MAX;
}

int itstamanho (List* lista){
    return lista->tam;
}

int itsposição(List* lista, int pos){
    if (pos < 0 || pos >= lista->tam) {
        printf("Posição inválida\n");
        return 0;
    }
     printf("O elemento da posição %d é %d\n", pos, lista->vetor[pos]);
    return 1;
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
    int num;
    

printf("Insira os elementos na lista(no maximo 10)\n ");
printf("Digite -1 para parar\n");

while (lista.tam < MAX){
    printf("Elemento %d: ", lista.tam + 1);
    scanf("%d", &num);
    if (num == -1){
        break;
    }
    lista.vetor[lista.tam] = num;
    lista.tam++;
}


printf("A lista tem %d elementos\n", itstamanho(&lista));

if (itsvazio(&lista)){
    printf("A lista está vazia\n");
}

if (itscheio(&lista)){
    printf("A lista está cheia\n");
}


printf("Qual elemento deseja saber a posição?(começa em 0)\n");
   
scanf("%d", &pos);
itsposição(&lista, pos);

printf("Qual elemento deseja inserir?\n");
scanf("%d", &valor);
printf("Em qual posição deseja inserir?\n");
scanf("%d", &pos);

if (inserir(&lista, pos, valor)){
    printf("Elemento inserido com sucesso\n");
    printf("A lista tem %d elementos\n", itstamanho(&lista));
    printf("os elementos da lista são: \n");
        for (int i = 0; i < lista.tam; i++){
    printf("%d ", lista.vetor[i]);
}
}

printf("\nQual elemento deseja retirar?\n"); 
scanf("%d", &pos);

if (retirar(&lista, pos)){
    printf("Elemento retirado com sucesso\n");
    printf("A lista tem %d elementos\n", itstamanho(&lista));
    printf("os elementos da lista são: \n");
        for (int i = 0; i < lista.tam; i++){
    printf("%d ", lista.vetor[i]);
}
}

}
