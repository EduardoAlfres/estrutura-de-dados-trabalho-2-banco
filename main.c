#include <stdio.h>

int main(){
    int escolha;
    char escolhaFim;
    int veri=1;


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

        switch(escolha){
            case 1:
                break;
            case 2: 
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                while(veri){
                    printf("Deseja exibir o relatorio do dia? (s/n): \n");
                    scanf("%c", &escolhaFim);
                    if(escolhaFim == 's'){
                        printf("exibindo...");
                        veri = 0;
                    }else if(escolhaFim == 'n' ){
                        veri = 0;
                    }else{
                        printf("Valor inválido, digite novamente!\n");
                    }
                }
            default:
                printf("Valor Inválido digite novamente!\n");
        }

    }
    return 0;
}