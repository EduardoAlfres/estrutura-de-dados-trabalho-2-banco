#include <stdio.h>
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

    while(veri){
        printf("------------Controlador de atendimento------------\n");
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
                while(veri){
                    printf("Deseja exibir o relatorio do dia? (s/n): \n");
                    scanf("%c", &escolhaSN);
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    if(escolhaSN == 's'){
                        printf("Qual relatario? (1 = rapida, 2 = normal)");
                        scanf("%d", &escolhaFim);
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        if(escolhaFim == 1){
                            imprimirHistorico(histRapida);
                            veri = 0;
                        }else if(escolhaFim == 2){
                            imprimirHistorico(histNormal);
                            veri = 0;
                        }else{
                            printf("Valor invalido, digite novamente!\n");
                        }
                    }else if(escolhaSN == 'n' ){
                        veri = 0;
                    }else{
                        printf("Valor invalido, digite novamente!\n");
                    }
                }
            default:
                printf("Valor Invalido digite novamente!\n");
        }

    }
    deletarFila(filaNormal);
    deletarFila(filaRapida);
    return 0;
}