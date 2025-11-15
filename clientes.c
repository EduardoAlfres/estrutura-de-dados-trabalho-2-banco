#include <stdlib.h>
#include "clientes.h"
#include <string>

clientes *criarElemento(char nome[50], int numero, int processos){
    clientes *newCliente = (clientes*) malloc(sizeof(clientes));
    strcpy(newCliente->nome, nome);
    newCliente->num = numero;
    newCliente->processos = processos;

    return newCliente;

}

int deletarCliente(clientes *cliente){
    if(!cliente) return 0;
    free(cliente);
    return 1;
}