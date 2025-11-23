#include <stdlib.h>
#include <stdio.h>
#include "historico.h"

// Funções de historico
// Função que cria uma nova pilha de historico
historico *criarPilha() {
    historico *newHistorico = (historico*) malloc(sizeof(historico));
    newHistorico->tamanho = 0;
    newHistorico->topo = NULL;
    return newHistorico; // Retorna o ponteiro para a nova pilha criada
}

// Função que verifica se a pilha de historico está vazia
int pilhaEstaVazia(historico *pilha) {
    if(pilha->tamanho == 0) return 1; // Retorna 1 se a pilha estiver vazia
    else return 0; // Retorna 0 se a pilha não estiver vazia
}

// Função que cria um novo nó de historico
hisNode *criarNode(clientes *cliente, int tipo) {
    hisNode *newNode = (hisNode*) malloc(sizeof(hisNode));
    newNode->cliente = cliente;
    newNode->tipoCaixa = tipo;
    newNode->prox = NULL;
    return newNode; // Retorna o ponteiro para o novo nó criado
}

// Função que adiciona um nó na pilha de historico
int push(historico *pilha, hisNode *hist) {
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
int pop(historico *pilha) {
    if(pilhaEstaVazia(pilha)) return 0; // Verifica se a pilha está vazia e retorna 0 se estiver

    clientes *clienteRemovido = pilha->topo->cliente; // Armazena o cliente que será removido
    hisNode *noASerRemovido = pilha->topo; // Armazena o nó que será removido
    pilha->topo = pilha->topo->prox; // Atualiza o topo da pilha para o próximo nó 

    free(clienteRemovido); // Libera a memória do cliente removido
    free(noASerRemovido); // Libera a memória do nó removido

    pilha->tamanho--; // Decrementa o tamanho da pilha
    return 1; // Retorna 1 para indicar sucesso na remoção
}

// Função que imprime o historico de atendimento
int imprimirHistorico(historico *pilha) {
    hisNode *temp = pilha->topo; // Ponteiro temporário para percorrer a pilha

    if(pilhaEstaVazia(pilha)){
        printf("Historico vazio!\n");
        return 0;
    }

    printf("\n------------Relatorio--------------\n");
    printf("Tipo de caixa: %s\n", (temp->tipoCaixa == 1) ? "Rapida" : "Normal");
    printf("Total de pessoas atendidas: %d\n", pilha->tamanho);
    printf("Tempo medio de atendimento: %.2f minutos\n", calcularTempoMedio(pilha));

    while(temp != NULL) { // Percorre a pilha até o final
        printf("----------------------------\n");
        if(temp->cliente == NULL) { // Verifica se o cliente é NULL
            printf("Erro: Cliente nao encontrado neste registro de historico.\n");
        } else {
            printf("Nome: %s\n", temp->cliente->nome);
            printf("Numero: %d\n", temp->cliente->num);
            printf("Total de processos: %d\n", temp->cliente->totalProcessos);
            printf("Tempo: %d minutos\n", temp->cliente->tempo);
        }
        printf("----------------------------\n");
        temp = temp->prox;
    }
    return 1;
}

// Função que calcula o tempo médio de atendimento
float calcularTempoMedio(historico *pilha) {
    if (pilhaEstaVazia(pilha)) {
        return 0.0f; // Retorna 0 se a pilha estiver vazia, o f indica que é float
    }

    int somaTempos = 0; // Variável para armazenar a soma dos tempos
    hisNode *atual = pilha->topo; // Ponteiro que aponta para o topo da pilha para percorrer a pilha

    while (atual != NULL) { // Percorre a pilha
        if (atual->cliente) {
            somaTempos += atual->cliente->tempo; // Soma o tempo do cliente
        }
        atual = atual->prox; // Avança para o próximo nó
    }

    if (pilha->tamanho == 0) {
        return 0.0f; // Evita divisão por zero
    }

    return (float)somaTempos / pilha->tamanho; // Retorna o tempo médio
}