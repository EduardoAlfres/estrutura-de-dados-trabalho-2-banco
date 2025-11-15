#include "clientes.h"

//estrutura das filas de atendimento, tipo  1 = rapida tipo 2 = normal 
typedef struct _lugar{
    clientes cliente;
    struct _lugar *pro;
}lugar;

typedef struct _fila{
    int tipo;
    lugar *comeco;
    lugar *fim;
    int tamanho;
}fila;


void criarFila();
int estaVazia(fila fila);


void enfileirar(fila fila, lugar *cliente);
void desenfilerirar(fila fila);

void imprimirFila(fila fila);
int getTamnho(fila fila);

void deletarFila(fila fila);
