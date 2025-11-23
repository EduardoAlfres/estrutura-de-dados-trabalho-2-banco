#include <stdlib.h>
#include <stdio.h>
#include "atendimento.h"

// Funções de atendimento e escolha de fila
// Função que escolhe a fila baseada na quantidade de processos do cliente
fila *escolherFila(fila *fila1, fila *fila2, clientes *cliente){
    fila *ret;
    if (cliente->processos > 2) { // Clientes com mais de 2 processos vao para a fila normal, os outros para a rapida
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
    if (estaVazia(fila)) return 0; // Verifica se a fila está vazia

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
    if (estaVazia(fila)) {
        return; // Se a fila estiver vazia, não há nada a fazer
    }

    clientes *clienteAtual = fila->comeco->cliente; // Pega o cliente no inicio da fila
    if (clienteAtual->processos > 0) { // Verifica se o cliente ainda tem processos pendentes
        clienteAtual->processos--; // Decrementa o número de processos do cliente
        printf("Operacao realizada para o(a) cliente %s. Processos restantes: %d\n", clienteAtual->nome, clienteAtual->processos); // Imprime o status do atendimento
    }
    if (clienteAtual->processos == 0) { // Se o cliente não tiver mais processos, ele sai da fila
        printf("Cliente %s finalizou todos os processos e saiu da fila.\n", clienteAtual->nome); // Imprime que o cliente saiu da fila
        sairFila(fila, hist); // Remove o cliente da fila e adiciona ao historico
    }
}

// Função que executa um ciclo de atendimento em ambas as filas
static int ultimaFilaAtendida = 1; // Variável estática para rastrear a última fila atendida (0 = Último foi o Rápido; 1 = Último foi o Normal. Começa com 0 (prioriza o Rápido).)
int cicloAtendimento(fila *rapida, fila *normal, historico *histR, historico *histN) {
    // Prioridade: Tentar atender na fila rápida
    if (ultimaFilaAtendida == 1 &&!estaVazia(rapida)) {
        // Se a fila rapida nao estiver vazia, realiza 1 operacao nela
        RealziarOperacao(rapida, histR);
        ultimaFilaAtendida = 0;
        return 1;
    }
    // Se a rápida estiver vazia, tentar atender na fila normal
    if (ultimaFilaAtendida == 0 && !estaVazia(normal)) {
        // Se a fila normal nao estiver vazia, realiza 1 operacao nela
        RealziarOperacao(normal, histN);
        ultimaFilaAtendida = 1;
        return 1;
    }

    // Se a alternância falhou (uma fila está vazia, a outra não), atender a que sobrou
    // Se a normal estiver vazia, tentar atender na fila rapida
    if (!estaVazia(rapida)) {
        // Se a fila rapida nao estiver vazia, realiza 1 operacao nela
        RealziarOperacao(rapida, histR);
        ultimaFilaAtendida = 0;
        return 1;
    }
    // Se a rapida estiver vazia, tentar atender na fila normal
    if (!estaVazia(normal)) {
        // Se a fila normal nao estiver vazia, realiza 1 operacao nela
        RealziarOperacao(normal, histN);
        ultimaFilaAtendida = 1;
        return 1;
    }
    
    // Se chegou aqui, ambas estão vazias
    printf("Atendimento concluido: Todas as filas foram esvaziadas antes do termino das operacoes solicitadas.\n");
    return 0; // Não houve atividade, retorna 0
}