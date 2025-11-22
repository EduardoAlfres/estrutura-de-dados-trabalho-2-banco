#include <stdlib.h>
#include "atendimento.h"

// Funções de atendimento e escolha de fila
// Função que escolhe a fila baseada na quantidade de processos do cliente
fila *escolherFila(fila *fila1, fila *fila2, clientes *cliente){
    fila *ret;
    if(cliente->processos > 2){ // Clientes com mais de 2 processos vao para a fila normal, os outros para a rapida
        // Antes de enfileirar, criar o lugar para o cliente
        lugar *lugarCliente = criarLugar(cliente); // Adicionar na fila normal
        enfileirar(fila2, lugarCliente); // Adicionar na fila normal
        ret = fila2;
    }else{
        // Antes de enfileirar, criar o lugar para o cliente
        lugar *lugarCliente = criarLugar(cliente); // Adicionar na fila rapida
        enfileirar(fila1, lugarCliente); // Adicionar na fila rapida
        ret = fila1;
    }
    return ret; // Retorna a fila que o cliente foi enfileirado
}

// Função que remove o cliente do inicio da fila
int sairFila(fila *fila){
    if(estaVazia(fila)) return 0;
    clientes *clienteTemp = fila->comeco->cliente;
    deletarCliente(clienteTemp); //Está aqui só para n criar lixo na memória após o fim do programa, tem que verificar com o professor se cliente pode ser deletado quando sai da fila
    desenfilerirar(fila->comeco);
    return 1;
}

// Função que realiza a operação de atendimento ao cliente
void RealziarOperacao(fila *fila){
    if(fila->comeco->cliente->processos > 0){
        fila->comeco->cliente->processos--;
    }else{
        sairFila(fila);
    }
}