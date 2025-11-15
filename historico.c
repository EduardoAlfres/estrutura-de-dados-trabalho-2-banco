#include <stdlib.h>
#include "historico.h"

historico *criarPilha(){
    historico *newHistorico = (historico*) malloc(sizeof(historico));
    newHistorico->tamanho = 0;
    newHistorico->topo = NULL;
    return newHistorico;
}

int estaVazia(historico *pilha){
    if(pilha->tamanho == 0) return 1;
    else return 0;
}

hisNode *criarNode(clientes *cliente, int tipo){
    hisNode *newNode = (hisNode*) malloc(sizeof(hisNode));
    newNode->cliente = cliente;
    newNode->tipoCaixa = tipo;
    newNode->prox = NULL;
    return newNode;
}

int push(historico *pilha, hisNode *hist){
    if(!estaVazia(pilha)){
        hist->prox = pilha->topo;
        pilha->topo = hist;
        pilha->tamanho++; 
        return 1;
    }else{
        pilha->topo = hist;
        pilha->tamanho++;
        return 1;
    }
}

int pop(historico *pilha){
    if(estaVazia(pilha)) return 0;
    hisNode *temp = pilha->topo->prox;
    free(pilha->topo);
    pilha->topo = temp;
    //incompleta
}

