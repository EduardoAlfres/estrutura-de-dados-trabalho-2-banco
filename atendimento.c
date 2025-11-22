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
    } else {
        // Antes de enfileirar, criar o lugar para o cliente
        lugar *lugarCliente = criarLugar(cliente); // Adicionar na fila rapida
        enfileirar(fila1, lugarCliente); // Adicionar na fila rapida
        ret = fila1;
    }
    return ret; // Retorna a fila que o cliente foi enfileirado
}

// Função que remove o cliente do inicio da fila
int sairFila(fila *fila, historico *hist) { // Deve adicionar o cliente ao historico antes de remover da fila
    if(estaVazia(fila)) return 0; // Verifica se a fila está vazia

    clientes *clienteAtendido = desenfilerirar(fila); // Remove o cliente da fila e armazena o ponteiro para ele
    if (clienteAtendido) {
        clienteAtendido->tempo = 10; // teste fixo de tempo de atendimento
        hisNode *registro = criarNode(clienteAtendido, fila->tipo); // Cria um novo nó de historico com o cliente atendido e o tipo da fila
        push(hist, registro); // Adiciona o nó de historico na pilha de historico
        return 1; // Retorna 1 para indicar sucesso na remoção
    }
    return 0;
}

// Função que realiza a operação de atendimento ao cliente
void RealziarOperacao(fila *fila, historico *hist) {; // Realiza o atendimento do cliente no inicio da fila
    if(fila->comeco->cliente->processos > 0){ // Verifica se o cliente ainda tem processos pendentes
        fila->comeco->cliente->processos--; // Decrementa o número de processos do cliente
    } else {
        sairFila(fila, hist); // Remove o cliente da fila e adiciona ao historico
    }
}