#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

fila *criarFila(int tipo){
    fila *filaL = (fila*) malloc(sizeof(fila));
    filaL->tipo = tipo;
    filaL->tamanho = 0;
    filaL->comeco = NULL;
    filaL->fim = NULL;
    return filaL;
}

int estaVazia(fila *f){
    if(f->tamanho == 0) return 1;
    else return 0;
}

lugar *criarLugar(clientes *cliente){
    lugar *li = (lugar*) malloc(sizeof(lugar));
    li->cliente = cliente;
    return li;
}


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

desenfilerirar(fila *fila){
    if(estaVazia(fila)) return 0;
    lugar *temp = fila->comeco->pro;
    if(temp){
        free(fila->comeco);
        fila->comeco = temp;
        fila->tamanho--;
    }else{
        free(fila->comeco);
        fila->tamanho--;
        fila->comeco = NULL;
        fila->fim = NULL;
    }
    return 1;
}

void imprimirFila(fila *fila){
    int i;
    lugar *temp = fila->comeco;
    printf("A fila atualmente tem: \n");
    printf("%d elementos sendo eles:\n", fila->tamanho);
    for(i = 1; i <= fila->tamanho; i++){
        printf("----------------------------\n");
        printf("Nome: %s\n", temp->cliente->nome);
        printf("Numero: %d", temp->cliente->nome);
        printf("Processos: %d", temp->cliente->processos);
        printf("----------------------------\n");
        temp = temp->pro;
    }
}

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
