#ifndef FILA_H
#define FILA_H

#include "clientes.h"

//estrutura das filas de atendimento, tipo  1 = rapida tipo 2 = normal 
typedef struct _lugar{
    clientes *cliente;
    struct _lugar *pro;
}lugar;

typedef struct _fila{
    int tipo;
    lugar *comeco;
    lugar *fim;
    int tamanho;
}fila;

// Prototipos das funcoes de fila
fila *criarFila(int tipo);
int estaVazia(fila *f);
lugar *criarLugar(clientes *cliente);

void enfileirar(fila *fila, lugar *cliente);
int desenfilerirar(fila *fila);

void imprimirFila(fila *fila);
int deletarFila(fila *fila);

#endif