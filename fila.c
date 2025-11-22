#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

// Funções de fila
// Função que cria uma nova fila com o tipo fornecido
fila *criarFila(int tipo){
    fila *filaL = (fila*) malloc(sizeof(fila));
    filaL->tipo = tipo;
    filaL->tamanho = 0;
    filaL->comeco = NULL;
    filaL->fim = NULL;
    return filaL; // Retorna o ponteiro para a nova fila criada
}

// Função que verifica se a fila está vazia
int estaVazia(fila *f){
    if(f->tamanho == 0) return 1; // Retorna 1 se a fila estiver vazia
    else return 0; // Retorna 0 se a fila não estiver vazia
}

// Função que cria um novo lugar na fila para o cliente fornecido
lugar *criarLugar(clientes *cliente){
    lugar *li = (lugar*) malloc(sizeof(lugar));
    li->cliente = cliente;
    return li; // Retorna o ponteiro para o novo lugar criado
}

// Função que adiciona um cliente na fila
void enfileirar(fila *fila, lugar *cliente){
    if(estaVazia(fila)) {
        fila->comeco = cliente;
        fila->fim = cliente;
        fila->comeco->pro = NULL;
        fila->tamanho = 1;
    }else{
        lugar *temp = fila->fim;
        fila->fim = cliente;
        temp->pro = fila->fim;
        fila->fim->pro = NULL;
        fila->tamanho++;
    }
}

// Função que remove o cliente do inicio da fila
clientes *desenfilerirar(fila *fila){
    if(estaVazia(fila)) return 0; // Verifica se a fila está vazia
    clientes *clienteRemovido = fila->comeco->cliente; // Armazena o cliente que será removido
    lugar *lugarRemovido = fila->comeco; // Armazena o lugar que será removido
    fila->comeco = fila->comeco->pro; // Atualiza o início da fila para o próximo lugar

    free(lugarRemovido); // Libera a memória do lugar removido
    fila->tamanho--; // Decrementa o tamanho da fila
    if(fila->tamanho == 0) {
        fila->comeco = NULL; // Se a fila ficar vazia, atualiza o começo para NULL
        fila->fim = NULL; // Se a fila ficar vazia, atualiza o fim para NULL
    }

    return clienteRemovido; // Retorna o cliente removido
}

// Função que imprime os clientes na fila
void imprimirFila(fila *fila){
    int i;
    lugar *temp = fila->comeco;
    printf("A fila atualmente tem: \n");
    printf("%d elementos sendo eles:\n", fila->tamanho);
    for(i = 1; i <= fila->tamanho; i++){
        printf("----------------------------\n");
        printf("Nome: %s\n", temp->cliente->nome);
        printf("Numero: %d\n", temp->cliente->num);
        printf("Processos: %d\n", temp->cliente->processos);
        printf("----------------------------\n");
        temp = temp->pro;
    }
}

// Função que deleta a fila da memória
int deletarFila(fila *fila){
    if(!estaVazia){
        int i;
        for(fila->tamanho; fila->tamanho != 0; fila->tamanho--){
            desenfilerirar(fila);
        }
        free(fila);
        return 1;
    };
    free(fila);
    return 1; 
}