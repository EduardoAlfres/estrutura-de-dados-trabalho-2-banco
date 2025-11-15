#include "clientes.h"

//Estrutura de historico de atendimento recebe a struct cliente e o tipo do caixa

typedef struct _hisNode{
    clientes cliente;
    int tipoCaixa;
    struct _hisnode *prox;
}hisNode;

typedef struct _historico{
    hisNode *topo;
    int tamanho;
}historico; 



historico *criarPilha();

hisNode *criarNode();

int estaVazia(historico *pilha);

int push(historico *pilha, hisNode *hist);

int pop(historico *pilha, hisNode *hist);

void imprimirHistorico(historico *pilha);

