#include "clientes.h"

//Estrutura de historico de atendimento recebe a struct cliente e o tipo do caixa

typedef struct _hisNode{
    clientes *cliente;
    int tipoCaixa;
    struct _hisnode *prox;
}hisNode;

typedef struct _historico{
    hisNode *topo;
    int tamanho;
}historico; 



historico *criarPilha();

int estaVazia(historico *pilha);

hisNode *criarNode(clientes *cliente, int tipo);


int push(historico *pilha, hisNode *hist);

int pop(historico *pilha);

void imprimirHistorico(historico *pilha);

