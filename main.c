#include <stdio.h>
#include "fila.h"
#include "clientes.h"
#include "historico.h"
#include "atendimento.h"

int main(){
    int c;
    fila *filaRapida = criarFila(1);
    fila *filaNormal = criarFila(2);
    historico *hist1 = criarPilha();
    historico *hist2 = criarPilha();
    int escolha;
    char escolhaSN;
    int escolhaFim;
    int veri=1;
    int opNum;


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
            case 1:
                char nome[50];
                int num;
                int processos;
                //input de cadastro
                printf("Qual é o nome do cliente?\n");
                fgets(nome, sizeof(nome), stdin);
                printf("Qual é o numero do cliente?\n");
                scanf("%d", &num);
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Qual é o numero de processos do cliente?\n");
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

            case 2: 
                printf("Quantas operações deseja realizar?\n");
                scanf("%d", &opNum);
                while ((c = getchar()) != '\n' && c != EOF) {}
                if(opNum < 0){
                    printf("Valor inválido!\n");
                    break;
                }
                while(opNum != 0){
                    RealziarOperação(filaRapida);
                    opNum--;
                }
                break;
            case 3:
                printf("Quantas operações deseja realizar?\n");
                scanf("%d", &opNum);
                while ((c = getchar()) != '\n' && c != EOF) {}
                if(opNum < 0){
                    printf("Valor inválido!\n");
                    break;
                }
                while(opNum != 0){
                    RealziarOperação(filaNormal);
                    opNum--;
                }
                break;
            case 4:
                imprimirFila(filaRapida);
                break;
            case 5:
                imprimirFila(filaNormal);
                break;
            case 6:
                while(veri){
                    printf("Deseja exibir o relatorio do dia? (s/n): \n");
                    scanf("%c", &escolhaSN);
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    if(escolhaSN == 's'){
                        printf("Qual relatario? (1 = rapida, 2 = normal)");
                        scanf("%d", &escolhaFim);
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        if(escolhaFim == 1){
                            imprimirHistorico(hist1);
                            veri = 0;
                        }else if(escolhaFim == 2){
                            imprimirHistorico(hist2);
                            veri = 0;
                        }else{
                            printf("Valor inválido, digite novamente!\n");
                        }
                    }else if(escolhaSN == 'n' ){
                        veri = 0;
                    }else{
                        printf("Valor inválido, digite novamente!\n");
                    }
                }
            default:
                printf("Valor Inválido digite novamente!\n");
        }

    }
    deletarFila(filaNormal);
    deletarFila(filaRapida);
    return 0;
}