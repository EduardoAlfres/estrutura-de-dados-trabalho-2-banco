#ifndef HISTORICO_H
#define HISTORICO_H

#include "clientes.h"

//Estrutura de historico de atendimento recebe a struct cliente e o tipo do caixa

typedef struct _hisNode{
    clientes *cliente;
    int tipoCaixa;
    struct _hisNode *prox;
}hisNode;

typedef struct _historico{
    hisNode *topo;
    int tamanho;
}historico; 

// Prototipos das funcoes de historico
historico *criarPilha();
int pilhaEstaVazia(historico *pilha);
hisNode *criarNode(clientes *cliente, int tipo);    

int push(historico *pilha, hisNode *hist);
int pop(historico *pilha);

float calcularTempoMedio(historico *pilha); // Calcula o tempo medio de atendimento
int imprimirHistorico(historico *pilha);
int imprimirHistoricoGeral(historico *rapido, historico *normal, historico *geral);

#endif