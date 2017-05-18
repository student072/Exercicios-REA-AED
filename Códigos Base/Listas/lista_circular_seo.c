#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
};
typedef struct No No;
 No *inicio = NULL;
 No *fim = NULL;
 No *aux ;
 No *anterior;

void insere_inicio_lista(){
    No *novo =(No*) malloc(sizeof(No));
    scanf("%d",&novo->num);
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->prox = inicio;
    }else{
        aux = inicio;
        /*caso o numero a ser inserido seja menor que o primeiro elemento da lista, ele será o novo primeiro elemento da lisa*/
        if(novo->num < aux->num){
            novo->prox = inicio;
            inicio = novo;
            fim->prox = inicio;
        /*caso o numero a ser inserido seja maior que o ultimo elemento da lista, ele será o novo ultimo elemento da lisa*/
        }else if(novo->num > fim->num){
            fim->prox = novo;
            fim = novo;
            fim->prox = inicio;
        /*caso o numero a ser inserido deva ser inseirido no meio da lista*/
        }else{
            /*euquanto aux(elemento atual que esta sendo comparado) for diferente de fim e o numero a ser inserido for maior que aux->num*/
            while(aux != fim && novo->num > aux->num){
                anterior = aux;/*anterior aponta para o endereço que aux aponta*/
                aux = aux->prox; /*aux aponta para o próximo nó da lista*/
            }
        anterior->prox = novo;/*o primeiro número menor que o novo inseirido no atributo prox recebe o endereço de novo*/
        novo->prox = aux; /*novo no atibuto prox, recebe o endereço do primeiro número maior que ele*/
        }
    }
    printf("\nNumero inserido na lista!");
     getch();
}

void consulta_lista(){
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        aux = inicio;
        do{
            printf(" %d ", aux->num);
            aux = aux->prox;
        }while(aux != inicio);
    }
     getch();
}

void remover_elemento(){
    int numero;
    int achou;
    int quantidade;
    int elemento;
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        printf("Digite o elemento a ser removido: ");
        scanf("%d", &numero);
        aux = inicio;
        anterior = NULL;
        achou = 0;
        quantidade = 0;

                do{
                    quantidade = quantidade + 1;
                    aux = aux->prox;
                }while(aux != inicio);
                 elemento = 1;
                 do{
                    if(inicio == fim && inicio->num == numero){
                        free(inicio);
                        inicio = NULL;
                        achou = achou + 1;
                    }else{
                        if(aux->num == numero){
                            achou = achou + 1;
                            if(aux == inicio){
                                    inicio = aux->prox;
                                    fim->prox = inicio;
                                    free(aux);
                                    aux = inicio;
                            }else if(aux == fim){
                                    fim = anterior;
                                    fim->prox = inicio;
                                    free(aux);
                                    aux = NULL;
                                   }else{
                                       anterior->prox = aux->prox;
                                       free(aux);
                                       aux = anterior->prox;
                                   }
                        }else{
                            anterior = aux;
                            aux = aux->prox;
                        }
                    }
                    elemento = elemento + 1;
                }while(elemento <= quantidade);


        if(achou == 0){
            printf("Numero nao encontrado!");
        }else{
            printf("Numero removido %d vez(es)",achou);
        }
    }
     getch();
}
void esvaziar_lista(){
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        aux = inicio;
        do{
            inicio = inicio->prox;
            free(aux);
            aux = inicio;
        }while(aux != fim);
        free(fim);
        inicio = NULL;
        printf("\nLista Esvaziada!!");
    }
    getch();
}
int main(){
    int op;
    while(1){
        system("CLS");
        printf("\nEscolha a opcao desejada: ");
        printf("\n1- Inserir numero na lista: ");
        printf("\n2- Imprimir lista");
        printf("\n3- Remover elemento: ");
        printf("\n4- Esvaziar lista: \n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_inicio_lista();
            break;
        case 2:
            consulta_lista();
            break;
        case 3:
            remover_elemento();
            break;
        case 4:
            esvaziar_lista()
;            break;
        default:
            exit(1);
        }
    }
    return 0;
}


