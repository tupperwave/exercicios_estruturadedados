#include <stdio.h>
#include <stdlib.h>

#define MAX 200 // Número máximo de vértices

// Estrutura do Grafo usando Matriz de Adjacência
typedef struct {
    int num_vertices;
    int adj[MAX][MAX];
} Grafo;

// Função para inicializar o grafo
void inicializarGrafo(Grafo *g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Função para ler o grafo do arquivo
void lerArquivo(Grafo *g, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Lendo o número de vértices
    fscanf(arquivo, "%d", &(g->num_vertices));

    // Lendo a matriz de adjacência
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            fscanf(arquivo, "%d", &(g->adj[i][j]));
        }
    }

    fclose(arquivo);
}

// Função para imprimir a matriz de adjacência
void imprimirMatrizAdjacencia(Grafo *g) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

// Função para contar o número de arestas no grafo
int contarArestas(Grafo *g) {
    int num_arestas = 0;
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = i + 1; j < g->num_vertices; j++) {
            if (g->adj[i][j] != 0) {
                num_arestas++;
            }
        }
    }
    return num_arestas;
}

// Função para imprimir o número de vértices e arestas
void imprimirInfoGrafo(Grafo *g) {
    int num_arestas = contarArestas(g);
    printf("Número de vértices: %d\n", g->num_vertices);
    printf("Número de arestas: %d\n", num_arestas);
}

// Função de Busca em Largura (BFS) para listar todos os caminhos
void bfsTodosCaminhos(Grafo *g) {
    int fila[MAX], visitado[MAX], antecessor[MAX];
    int frente, tras;

    for (int inicio = 0; inicio < g->num_vertices; inicio++) {
        for (int i = 0; i < g->num_vertices; i++) {
            visitado[i] = 0;
            antecessor[i] = -1;
        }

        frente = tras = 0;
        fila[tras++] = inicio;
        visitado[inicio] = 1;

        printf("Caminhos BFS a partir do vértice %d:\n", inicio);

        while (frente < tras) {
            int v = fila[frente++];

            for (int i = 0; i < g->num_vertices; i++) {
                if (g->adj[v][i] && !visitado[i]) {
                    fila[tras++] = i;
                    visitado[i] = 1;
                    antecessor[i] = v;

                    printf("Caminho: ");
                    int atual = i;
                    while (atual != -1) {
                        printf("%d ", atual);
                        atual = antecessor[atual];
                    }
                    printf("\n");
                }
            }
        }
    }
}

// Função de Busca em Profundidade (DFS) para listar todos os caminhos
void dfsTodosCaminhos(Grafo *g) {
    int pilha[MAX], visitado[MAX], antecessor[MAX];
    int topo;

    for (int inicio = 0; inicio < g->num_vertices; inicio++) {
        for (int i = 0; i < g->num_vertices; i++) {
            visitado[i] = 0;
            antecessor[i] = -1;
        }

        topo = -1;
        pilha[++topo] = inicio;

        printf("Caminhos DFS a partir do vértice %d:\n", inicio);

        while (topo >= 0) {
            int v = pilha[topo--];

            if (!visitado[v]) {
                visitado[v] = 1;
            }

            for (int i = g->num_vertices - 1; i >= 0; i--) {
                if (g->adj[v][i] && !visitado[i]) {
                    pilha[++topo] = i;
                    antecessor[i] = v;

                    printf("Caminho: ");
                    int atual = i;
                    while (atual != -1) {
                        printf("%d ", atual);
                        atual = antecessor[atual];
                    }
                    printf("\n");
                }
            }
        }
    }
}

// Função para imprimir os vizinhos de cada vértice e os pesos das arestas
void imprimirVizinhos(Grafo *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vértice %d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->adj[i][j] != 0) {
                printf("(%d, peso %d) ", j, g->adj[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    Grafo g;

    // Inicializar o grafo
    inicializarGrafo(&g, MAX);

    // Ler o grafo do arquivo
    lerArquivo(&g, "pcv10.txt");

    // Imprimir a matriz de adjacência
    imprimirMatrizAdjacencia(&g);

    // Imprimir o número de vértices e arestas
    imprimirInfoGrafo(&g);

    // Listar todos os caminhos BFS a partir de cada vértice
    bfsTodosCaminhos(&g);

    // Listar todos os caminhos DFS a partir de cada vértice
    dfsTodosCaminhos(&g);

    // Imprimir os vizinhos de cada vértice e os pesos das arestas
    imprimirVizinhos(&g);

    return 0;
}
