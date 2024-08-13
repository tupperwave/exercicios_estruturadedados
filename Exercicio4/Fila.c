//fila tem caracteriscas de lista que remove o primeiro elemento e
//faz inserção no final da fila

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct No
{
    int info; 
    struct No* prox;
}No;

typedef struct Fila
{
    No* inicio;
    No* fim;
    int tam;

}fila;

int cria_fila(fila* f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->tam = 0;
    return 1;
}

int inserir_fim(fila*f, int valor){
No* novo = (No*)malloc(sizeof(No));
if(novo == NULL)
    return 0;
 novo->info = valor;
 novo->prox = NULL;

    if(f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
         f->fim = novo;
         return 1;
}

int remover_inicio(fila* f, int* valor){
    if(f->inicio == NULL)
        return 0;
    No* aux = f->inicio;
    *valor = aux->info;
    f->inicio = aux->prox;
    if(f->inicio == NULL)
        f->fim = NULL;
    free(aux);
    return 1;
}

int filaIs(fila* f){
    if (f->inicio == NULL)
        printf("Fila vazia\n");
    else if (f->tam = MAX)
        printf("Fila cheia\n");
    else (f->tam < MAX);
        printf("Fila com espaço\n");
    return 1;
} 

int consulta_inicio(fila* f, int* valor){
    if(f->inicio == NULL)
        return 0;
    *valor = f->inicio->info;
    return 1;
}

int main(){
int valor;
int tam;
int opçao;

fila f;
cria_fila(&f);

printf(" digite o tamanho da fila: ");
scanf ("%d", &tam);

printf("Digite os valores: ");
for(int i = 0; i < tam; i++){
    scanf("%d", &valor);
    inserir_fim(&f, valor);
}
do{

    printf(" Digite o valor para ação:\n");
    printf("1 - Inserir no final da fila\n");
    printf("2 - Remover do inicio da fila\n");
    printf("3  - Verificar situação da fila\n");
    printf("4 - Consultar o inicio da fila\n");
    scanf("%d", &opçao);
    printf("\n");

    switch(opçao){
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserir_fim(&f, valor);
            break;
        case 2:
            if(remover_inicio(&f, &valor))
                printf("Valor removido: %d\n", valor);
            else
                printf("Fila vazia\n");
            break;
        case 3:
            filaIs(&f);
            break;
        case 4:
            if(consulta_inicio(&f, &valor))
                printf("Valor do inicio: %d\n", valor);
            else
                printf("Fila vazia\n");
            break;
        default:
            printf("Opção invalida\n");
    }
    
}while(opçao != 0);
return 0;

}