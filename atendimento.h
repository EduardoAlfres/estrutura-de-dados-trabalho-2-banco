#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "fila.h"
#include "clientes.h"
#include "historico.h"

//arquivo centraliador das operacoes e calculos, todos eles devem ser feitos aqui

// Prototipos das funcoes de atendimento e escolha de fila
fila *escolherFila(fila *fila1, fila *fila2, clientes *cliente);
int sairFila(fila *fila);
void RealziarOperacao(fila *fila);
int calcularTempo();

#endif