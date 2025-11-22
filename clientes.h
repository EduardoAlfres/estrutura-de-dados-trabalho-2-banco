#ifndef CLIENTES_H
#define CLIENTES_H

//Struct de cliente, carrega as infos de cadastro e tempo de atendimento calculado depois
typedef struct _clientes{
    char nome[50];
    int num;
    int processos;
    int tempo;
}clientes;

// Prototipos das funcoes de cliente
clientes *criarElemento(char nome[50], int numero, int processos);
int deletarCliente(clientes *cliente);

#endif