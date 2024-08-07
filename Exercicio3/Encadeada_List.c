#include <stdio.h>
#include <stdlib.h>
//define a estrutura do nó
typedef struct No
{
    int info; 
    struct No* prox;
}No;
 // define a estrutura da lista
typedef struct 
{
    No* topo;
    int tam;
}Lista;
// costroi a lista
int cria_lista(Lista*lista){
    lista* topo -> NULL;
    lista* tam -> 0;
}
//verifica se a lista está vazia
int isVazia(Lista*lista){
    if(lista->topo == NULL){
        return 1;
    }
    return 0;
} 
//retorna o tamanho da lista
int tamanho(Lista*lista){
    return lista->tam;
}
//exibe o condeudo de um elemento da lista 
int elemento(Lista*lista, int pos){
 if(pos < 1 || pos > lista->tam){
    printf("Posicao inexistente\n");
     return -1;
  }
    No*aux = lista->topo;
    for(int i = 1; i < pos; i++){
        aux = aux->prox;
    }
    return aux->info;
}

int insere(Lista*lista, int pos, int valor){
    if(pos < 1 || pos > lista->tam + 1){
        printf("Posicao inexistente\n");
        return 0;
    }
    No*aux = (No*)malloc(sizeof(No));
    aux->info = valor;
    if(pos == 1){
        aux->prox = lista->topo;
        lista->topo = aux;
    }else{
        No*aux2 = lista->topo;
        for(int i = 1; i < pos - 1; i++){
            aux2 = aux2->prox;
        }
        aux->prox = aux2->prox;
        aux2->prox = aux;
    }
    lista->tam++;
    return 1;
}

int main(){
Lista


}
