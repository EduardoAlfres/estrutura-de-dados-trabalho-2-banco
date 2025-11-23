#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "clientes.h"
#include "historico.h"
#include "atendimento.h"

int main(){
    int c;
    fila *filaRapida = criarFila(1);
    fila *filaNormal = criarFila(2);
    historico *histRapida = criarPilha();
    historico *histNormal = criarPilha();
    int escolha;
    char escolhaSN;
    int escolhaFim;
    int veri=1;
    int opNum;

    //variaveis de cliente
    char nome[50];
    int num;
    int processos;

    // ==============================================
    //       INSERCAO DE CLIENTES DE TESTE
    // ==============================================
    printf("\n--- Clientes de Teste Inseridos ---\n");
    
    // Cliente 1: Rápido (1 processo)
    clientes *cliA = criarElemento("Alice", 101, 1);
    escolherFila(filaRapida, filaNormal, cliA);
    printf("Cliente %s cadastrado na fila Rapida.\n", cliA->nome);
    
    // Cliente 2: Normal (5 processos)
    clientes *cliB = criarElemento("Bob", 102, 5);
    escolherFila(filaRapida, filaNormal, cliB);
    printf("Cliente %s cadastrado na fila Normal.\n", cliB->nome);
    
    printf("-----------------------------------\n");
    // ==============================================

    while(veri){
        printf("\n------------Controlador de atendimento------------\n");
        printf("Digite o numero correspondente para escolher uma operacao:\n");
        printf("1.Cadastrar cliente\n");
        printf("2.Realizar operacao no caixa rapido\n");
        printf("3.Realiazr operacao no caixa normal\n");
        printf("4.Imprimir a fila do caixa rapido\n");
        printf("5.Imprimir a fila do caixa normal\n");
        printf("6.Finalizar dia.\n");
        scanf("%d", &escolha);
        while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer de input
        switch(escolha){
            case 1: //Cadastrar cliente
                //input de cadastro
                printf("Qual eh o nome do cliente?\n");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha lido pelo fgets
                printf("Qual eh o numero do cliente?\n");
                scanf("%d", &num);
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Qual eh o numero de processos do cliente?\n");
                scanf("%d", &processos);
                while ((c = getchar()) != '\n' && c != EOF) {}

                clientes *cliente = criarElemento(nome, num, processos);//cria um cliente novo 
                fila *temp = escolherFila(filaRapida, filaNormal, cliente);//escolhe e adiciona na fila correspondente

                if(temp->tipo == 1){
                    printf("Fila escolhida: Rapida\n");
                }else{
                    printf("Fila escolhida: Normal\n");
                }
                break;

            case 2: //Realizar operacao no caixa rapido
                if(estaVazia(filaRapida)) {
                    printf("O Caixa Rapido esta vazio. Cadastre um cliente primeiro.\n");
                    break;
                }

                printf("Quantas operacoes deseja realizar?\n");
                scanf("%d", &opNum);
                while ((c = getchar()) != '\n' && c != EOF) {}
                if(opNum < 0){
                    printf("Valor invalido!\n");
                    break;
                }
                while(opNum != 0){
                    RealziarOperacao(filaRapida, histRapida);
                    opNum--;
                }
                break;

            case 3: //Realizar operacao no caixa normal
                if(estaVazia(filaNormal)) {
                    printf("O Caixa Normal esta vazio. Cadastre um cliente primeiro.\n");
                    break;
                }

                printf("Quantas operacoes deseja realizar?\n");
                scanf("%d", &opNum);
                while ((c = getchar()) != '\n' && c != EOF) {}
                if(opNum < 0){
                    printf("Valor invalido!\n");
                    break;
                }
                while(opNum != 0){
                    RealziarOperacao(filaNormal, histNormal);
                    opNum--;
                }
                break;
                
            case 4: //Imprimir a fila do caixa rapido
                imprimirFila(filaRapida);
                break;

            case 5: //Imprimir a fila do caixa normal
                imprimirFila(filaNormal);
                break;

            case 6: //Finalizar dia
                while(1) {
                    int impresso = 0;
                    printf("Deseja exibir o relatorio do dia? (s/n):\n");
                    scanf("%c", &escolhaSN);
                    while ((c = getchar()) != '\n' && c != EOF) {}

                    if(escolhaSN == 's' || escolhaSN == 'S') {
                        printf("Qual relatario? (1 = rapida, 2 = normal)\n");
                        scanf("%d", &escolhaFim);
                        while ((c = getchar()) != '\n' && c != EOF) {}

                        if(escolhaFim == 1){
                            if(imprimirHistorico(histRapida)) {
                                impresso = 1;
                            }
                        }else if(escolhaFim == 2){
                            if(imprimirHistorico(histNormal)) {
                                impresso = 1;
                            }
                        }else{
                            printf("Valor invalido, digite novamente!\n");
                            continue; // Volta para o início do loop para nova entrada
                        }
                        if (impresso) {
                            printf("\nRelatorio exibido. Deseja encerrar o sistema? (s/n):\n");
                            scanf(" %c", &escolhaSN);
                            while ((c = getchar()) != '\n' && c != EOF) {}

                            if(escolhaSN == 's' || escolhaSN == 'S'){
                                veri = 0; // Se confirmar, encerra o loop principal
                                break;
                            }
                            if (escolhaSN == 'n' || escolhaSN == 'N'){
                                break; // Sai do while(1) interno e volta ao menu principal
                            }else{
                                printf("Valor invalido, digite novamente!\n");
                                continue; // Volta para o início do loop para nova entrada
                            }
                        }
                    }else if(escolhaSN == 'n' || escolhaSN == 'N') {
                        printf("Deseja encerrar o sistema? (s/n):\n");
                        scanf(" %c", &escolhaSN);
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        
                        if(escolhaSN == 's' || escolhaSN == 'S') {
                            // Deve encerrar o sistema
                            veri = 0; // Se confirmar, encerra o loop principal
                            break; // Sai do while(1) interno
                             
                        }
                        if (escolhaSN == 'n' || escolhaSN == 'N') {
                            // Deve voltar ao menu principal
                            break; // Sai do while(1) interno e volta ao menu principal
                        }
                    }else{
                        printf("Valor invalido, digite novamente!\n");
                        continue; // Volta para o início do loop para nova entrada
                    }
                }
                break;
            default:
                printf("Valor Invalido digite novamente!\n");
                continue;
        }

    }
    while(!pilhaEstaVazia(histRapida)){
        pop(histRapida);
    }
    while(!pilhaEstaVazia(histNormal)){
        pop(histNormal);
    }
    deletarFila(filaNormal);
    deletarFila(filaRapida);
    return 0;
}