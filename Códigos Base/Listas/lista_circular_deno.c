#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
    struct No *ant;
};
typedef struct No No;
 No *inicio = NULL;
 No *fim = NULL;
 No *aux ;
 No *aux2 ;

void insere_inicio_lista(){
    No *novo =(No*) malloc(sizeof(No));
    scanf("%d",&novo->num);
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        fim->prox = inicio;
        fim->ant = inicio;
    }else{
        novo->prox = inicio;
        inicio->ant = novo;
        novo->ant = fim;
        fim->prox = novo;
        inicio = novo;
    }
    printf("\nNumero inserido na lista!");
}
void insere_fim_lista(){
    No *novo =(No*) malloc(sizeof(No));
    scanf("%d",&novo->num);
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        novo->prox = inicio;
        novo->ant = inicio;
    }else{
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
        fim->prox = inicio;
        inicio->ant = fim;
    }
    printf("\nNumero inserido na lista!");
}
void consulta_lista_inicio(){
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        aux = inicio;
        do{
            printf(" %d ", aux->num);
            aux = aux->prox;
        } while(aux != inicio);
    }
}
void consulta_lista_fim(){
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    }else{
        aux = fim;
        do{
            printf(" %d ", aux->num);
            aux = aux->ant;
        } while(aux != fim);
    }
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
        achou = 0;
        quantidade = 0;
                do{
                    quantidade = quantidade + 1;
                    aux = aux->prox;
                }while(aux != inicio);
                 elemento = 1;
                 do{
                    if(inicio == fim && inicio->num == numero){
                        inicio = NULL;
                        free(inicio);
                        achou = achou + 1;
                    }else{
                        if(aux->num == numero){
                            achou = achou + 1;
                            if(aux == inicio){
                                    inicio = aux->prox;
                                    inicio->ant = fim;
                                    fim->prox = inicio;
                                    free(aux);
                                    aux = inicio;
                            }else if(aux == fim){
                                    fim = fim->ant;
                                    fim->prox = inicio;
                                    free(aux);
                                    aux = NULL;
                                   }else{
                                       aux->ant->prox = aux->prox;
                                       aux->prox->ant = aux->ant;
                                       aux2 = aux;
                                       aux = aux->prox;
                                       free(aux2);
                                   }
                        }else{
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
        printf("\nEscolha a opcao desejada: ");
        printf("\n1- Inserir numero no inicio da fila: ");
        printf("\n2- Inserir numero no fim da fila: ");
        printf("\n3- Imprimir lista do inicio ao fim");
        printf("\n4- Imprimir lista do fim ao inicio");
        printf("\n5- Remover elemento: ");
        printf("\n6- Esvaziar lista: \n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_inicio_lista();
            break;
        case 2:
            insere_fim_lista();
            break;
        case 3:
            consulta_lista_inicio();
            break;
        case 4:
            consulta_lista_fim();
            break;
        case 5:
            remover_elemento();
            break;
        case 6:
            esvaziar_lista()
;            break;
        default:
            exit(1);
        }
    }
    return 0;
}

