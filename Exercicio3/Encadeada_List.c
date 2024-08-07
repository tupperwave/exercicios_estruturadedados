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
    lista->topo =NULL;
    lista->tam = 0;
    return 1;
}
//verifica se a lista está vazia
int isVazia(Lista* lista){
    if(lista->topo == NULL){

        printf("Lista vazia\n");
        return 1;
    }
    return 0;
} 

//retorna o tamanho da lista
int tamanho(Lista*lista){
    printf("Tamanho da lista: %d\n", lista->tam);
    return lista->tam;
}

//modifica o conteudo de um elemento da lista 
int modificaelemento(Lista*lista, int pos, int novo){
 if(pos < 1 || pos > lista->tam){
    printf("Posicao inexistente\n");
     return -1;
  }
    No*aux = lista->topo;
    for(int i = 1; i < pos; i++){
        aux = aux->prox;
    }
     aux->info = novo ;
    return 1;
}

int insere(Lista*lista, int valor){
    No*aux = (No*)malloc(sizeof(No));
    if(aux == NULL){
        printf("Memoria insuficiente\n");
        return 0;
    }
    aux->info = valor;
    aux->prox = lista->topo;
    lista->topo = aux;
    lista->tam++;
    return 1;
}

int remover(Lista*lista, int pos){
    if(pos < 1 || pos > lista->tam){
        printf("Posicao inexistente\n");
        return 0;
    }
    No*aux;
    if(pos == 1){
        aux = lista->topo;
        lista->topo = aux->prox;
    }else{
        No*atual = lista->topo;
        for(int i = 1; i < pos - 1; i++){
            atual = atual->prox;
        }
        aux = atual->prox;
        atual->prox = aux->prox;
    }
    free(aux);
    lista->tam--;
    return 1;
}

void imprime(Lista*lista){
    No*aux = lista->topo;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
Lista lista;
cria_lista(&lista); 
isVazia(&lista);

int opcao;
int pos, valor, novo;

do{
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Modificar\n");
    printf("4 - Imprimir\n");
    printf("5 - Tamanho\n");
    printf("6 - Sair\n");
    scanf("%d", &opcao);
    printf("\n");

    switch(opcao){
        case 1:
            printf("Digite o valor\n");
            scanf("%d", &valor);
            insere(&lista, valor);
            printf("\n");
            break;
        case 2:
            printf("Digite a posicao\n");
            scanf("%d", &pos);
            remover(&lista, pos);
            printf("\n");
            break;
        case 3:
            printf("Digite a posicao e o novo valor\n");
            scanf("%d %d", &pos, &novo);
            modificaelemento(&lista, pos, novo);
            printf("\n");
            break;
        case 4:
            printf("Lista: ");
            imprime(&lista);
            printf("\n");
            break;
        case 5:
            tamanho(&lista);
            printf("\n");
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
            printf("\n");
    }

}while(opcao != 6); 
return 0;

}