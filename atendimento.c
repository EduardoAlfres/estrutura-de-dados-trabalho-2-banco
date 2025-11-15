#include <stdlib.h>
#include "atendimento.h"

fila *escolherFila(fila *fila1, fila *fila2, clientes *cliente){
    fila *ret;
    if(cliente->processos > 2){
        enfileirar(fila2, cliente);
        ret = fila2;
    }else{
        enfileirar(fila1, cliente);
        ret = fila1;
    }
    return ret;
}

int sairFila(fila *fila){
    if(estaVazia(fila)) return 0;
    clientes *clienteTemp = fila->comeco->cliente;
    deletarCliente(clienteTemp); //Está aqui só para n criar lixo na memória após o fim do programa, tem que verificar com o professor se cliente pode ser deletado quando sai da fila
    desenfilerirar(fila->comeco);
    return 1;
}

void RealziarOperação(fila *fila){
    if(fila->comeco->cliente->processos > 0){
        fila->comeco->cliente->processos--;
    }else{
        sairFila(fila);
    }
}