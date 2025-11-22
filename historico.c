#include <stdlib.h>
#include <stdio.h>
#include "historico.h"

// Funções de historico
// Função que cria uma nova pilha de historico
historico *criarPilha(){
    historico *newHistorico = (historico*) malloc(sizeof(historico));
    newHistorico->tamanho = 0;
    newHistorico->topo = NULL;
    return newHistorico; // Retorna o ponteiro para a nova pilha criada
}

// Função que verifica se a pilha de historico está vazia
int pilhaEstaVazia(historico *pilha){
    if(pilha->tamanho == 0) return 1; // Retorna 1 se a pilha estiver vazia
    else return 0; // Retorna 0 se a pilha não estiver vazia
}

// Função que cria um novo nó de historico
hisNode *criarNode(clientes *cliente, int tipo){
    hisNode *newNode = (hisNode*) malloc(sizeof(hisNode));
    newNode->cliente = cliente;
    newNode->tipoCaixa = tipo;
    newNode->prox = NULL;
    return newNode; // Retorna o ponteiro para o novo nó criado
}

// Função que adiciona um nó na pilha de historico
int push(historico *pilha, hisNode *hist){
    if(!pilhaEstaVazia(pilha)){
        hist->prox = pilha->topo;
        pilha->topo = hist;
        pilha->tamanho++; 
        return 1;
    }else{
        pilha->topo = hist;
        pilha->tamanho++;
        return 1; // Retorna 1 para indicar sucesso na adição
    }
}

// Função que remove o nó do topo da pilha de historico
int pop(historico *pilha){
    if(pilhaEstaVazia(pilha)) return 0;
    hisNode *temp = pilha->topo->prox;
    free(pilha->topo);
    pilha->topo = temp;
    pilha->tamanho--;
    return 1; // Retorna 1 para indicar sucesso na remoção
}

// Função que imprime o historico de atendimento
void imprimirHistorico(historico *pilha){
    int i;
    hisNode *temp = pilha->topo;
    printf("------------Relatorio--------------\n");
    for(i = 1; i <= pilha->tamanho; i++){
        printf("----------------------------\n");
        printf("Nome: %s\n", temp->cliente->nome);
        printf("Numero: %d\n", temp->cliente->nome);
        printf("Processos: %d\n", temp->cliente->processos);
        printf("Tempo: %ds\n", temp->cliente->tempo);
        printf("----------------------------\n");
        temp = temp->prox;
    }
}