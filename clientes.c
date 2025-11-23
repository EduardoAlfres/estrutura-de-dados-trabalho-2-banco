#include <stdlib.h>
#include <string.h>
#include "clientes.h"

// Funções de cliente
// Função que cria um novo cliente com as informações fornecidas
clientes *criarElemento(char nome[50], int numero, int processos){
    clientes *newCliente = (clientes*) malloc(sizeof(clientes));
    strcpy(newCliente->nome, nome);
    newCliente->num = numero;
    newCliente->processos = processos;
    newCliente->totalProcessos = processos;

    return newCliente; // Retorna o ponteiro para o novo cliente criado
}

// Função que deleta um cliente da memória
int deletarCliente(clientes *cliente){
    if(!cliente) return 0;
    free(cliente);
    return 1; // Retorna 1 para indicar sucesso na deleção
}