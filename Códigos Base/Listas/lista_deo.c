#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
    struct No *ant;
};
/*para toda hora não precisarmos escrever "struct No" vamos definir o tipo No
   através de typedef para simplificar*/
typedef struct No No;
/*toda lista tem um inicio e fim, para isso declaramos dois ponteiros do tipo No para apontar para os
   os nós que estarão no iniício e fim da lista respectivamente.
   Como a lista está inicialmente vazia, inicio e fim apontam para NULL */
No *inicio = NULL;
No *fim = NULL;
/*necessitaremos também de dois ponteiros auxilares *aux1 e *aux2  para as operações da lista*/
No *aux;
No *aux2;

void insere_lista(){
    No *novo =(No*) malloc(sizeof(No));   /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    /*o número a ser inserido será armazenado em novo->num*/
    printf("Digite o numero a ser inserido na lista: "); scanf("%d",&novo->num);
    if(inicio == NULL){ /*caso a lista estiver vazia o elemento a ser inserido será o primeiro e último elemento da lista*/
        /*como será o único elemento da lista, novo->prox e novo->ant apontam para null*/
        novo->prox = NULL;
        novo->ant = NULL;
        inicio = novo; /*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        fim = novo; /*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
    }else{ /*caso a lista não esteja vazia*/
        aux = inicio; /*aux aponta para o endereço que inicio aponta*/
        /*enquanto ainda houverem elementos na lista e o novo número for maior que aux->num,
         ou seja enquanto não for encontrado um número maior que o número inserido*/
        while(aux!=NULL && novo->num > aux->num){
            aux = aux->prox; /*aux aponta para o próximo elemento da lista*/
             /*isso é feito para encontrar o ponto exato para o número ser inserido*/
        }
        /*caso não existam números maiores ou iguais ao novo número , ele será inserido no início da lista*/
        if(aux == inicio){
            novo->prox = inicio; /*novo->prox apontara para o atual inicio, que depois será o segundo elemento*/
            novo->ant = NULL; /*como novo será o primeiro da lista, seu ponteiro ant deverá apontar para null*/
            inicio->ant = novo; /*o inicio atual(que depois será o segunda da lista) em ant, apontara para o endereço de novo*/
            inicio = novo; /*inicio aponta para novo*/
        /*caso todos elementos da lista sejam menores que o número a ser inserido, ele será inserido no fim*/
        }else if(aux == NULL){
            fim->prox = novo; /*o fim atual (que depois será o penultimo da lista) em prox, apontará para novo*/
            novo->ant = fim; /*novo -> ant aponta para o endereço do fim atual.*/
            fim = novo; /*fim aponta para novo*/
            fim->prox = NULL; /*todo ultimo elemento da lista  em prox aponta para null*/
        }else{  /*caso novo seja inserido no meio da lista, ele será inserido antes de aux*/
            novo->prox = aux; /*novo será inserido antes do aux atual, então novo->prox aponta para o aux atual*/
            aux->ant->prox = novo;/*o número que estava antes de aux em prox aponta para novo*/
            novo->ant = aux->ant; /*novo-> ant aponta para o nó anterior a aux atual*/
            aux->ant = novo;/*aux atual será o elemento seguinte a novo, portanto em ant apontará para novo*/
        }
    }
    printf("\nNumero inserido na lista!");
    getch();
}

void imprime_lista_inicio_ao_fim(){
    /*caso a lista esteja vazia*/
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux = inicio;
        do{
            /*impressão do elemento que aux aponta*/
            printf(" %d ", aux->num);
            /*aux aponta para o próximo elemento da lista, que será o endereço contido no ponteiro prox.*/
            aux = aux->prox;
            /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos
             a serem impressos*/
        }while(aux != NULL);
    }
    getch();
}


void imprime_lista_fim_ao_inicio(){
    /*caso a lista esteja vazia*/
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que fim aponta*/
        aux = fim;
        do{
            /*impressão do elemento que aux aponta*/
            printf(" %d ", aux->num);
            /*aux aponta para o elemento anterior da lista, que será o endereço contido no ponteiro ant.*/
            aux = aux->ant;
            /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos
                a serem impressos*/
        }while(aux != NULL);
    }
    getch();
}

void remover_elemento(){
    int numero, achou; /*a variável achou será utilizada como um contador de números removidos*/
    if(inicio == NULL){ /*caso a lista esteja vazia*/
        printf("\nLista Vazia!!");
    }else{  /*caso a lista não esteja vazia*/
        printf("Digite o elemento a ser removido: "); scanf("%d", &numero);
        aux = inicio; /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        achou = 0;
        do{
            if(aux->num == numero){ /*caso aux-> num seja igual ao número a ser removido*/
                achou = achou + 1; /*incrementamos achou*/
                if(aux == inicio){ /*se o elemento a ser removido for o primeiro da lista*/
                    inicio = aux ->prox;/*inicio apontará para o segundo elemento da lista ou para NULL caso o elemento
                                        removido seja o único elemento da lista*/
                    if (inicio != NULL){ /*caso inicio tenha não recebido null na linha anterior*/
                        inicio->ant = NULL; /*ant de inicio também apontará para null*/
                    }
                    free(aux);  /*desalocamos o espaço para onde aux apontava*/
                    aux = inicio; /*aux aponta para o inicio da lista*/
                }else if(aux == fim){ /*se o elemento a ser removido for o ultimo da lista*/
                                fim = fim->ant; /*fim apontará para o elemento anterior a ele*/
                                fim->prox = NULL; /*fim no atributo prox apontará para null*/
                                free(aux); /*desalocamos o espaço para onde aux apontava*/
                                aux = NULL; /*como era o últmo elemento da lista, aux recebe NULL*/
                        }else{/*se o elemento a ser removido não for nem o primeiro nem o último da lista */
                                aux->ant->prox = aux->prox; /*o elemento anterior ao que iremos remover, em prox, apontara para
                                                                                   o endereço do próximo elemento depois de aux */
                                aux->prox->ant = aux->ant;  /*o elemento seguinte ao que iremos remover, em ant,  apontará para
                                                                                  o endereço do elemento anterior a aux */
                                aux2 = aux->prox;/*aux2 aponta para o elemento depois de aux*/
                                free(aux); /*desalocamos o espaço para onde aux apontava*/
                                aux = aux2; /*aux aponta para onde aux2 apontava*/
                        }
        }else{ /*caso aux-> num não seja igual ao número a ser removido*/
                    aux = aux -> prox; /*aux aponta para o próximo elemento da lista*/
        }
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem pesquisados*/
        }while(aux != NULL);
        /*impressão do resultado*/
        if(achou == 0){
            printf("Numero nao encontrado!");
        }else{
            printf("Numero removido %d vez(es)",achou);
        }
    }
    getch();
}
void esvaziar_lista(){
    /*caso a lista esteja vazia*/
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
    /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço de inicio  aponta*/
    aux = inicio;
    do{
        /*inicio apontará para o próximo elemento da lista*/
        inicio = inicio->prox;
        /*desalocamos o espaço para onde aux apontava*/
        free(aux);
        /*aux apontará para o mesmo endereço que inicio aponta*/
        aux = inicio;
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem removidos*/
    }while(aux != NULL);
    printf("\nLista Esvaziada!!");
    }
    getch();
}

int main(){
    int op;
    while(1){
        printf("\nEscolha a opcao desejada: ");
        printf("\n1- Inserir numero na fila: ");
        printf("\n2- Imprimir lista do inicio ao fim");
        printf("\n3- Imprimir lista do fim ao inicio");
        printf("\n4- Remover elemento: ");
        printf("\n5- Esvaziar lista: ");
        printf("\n6- Sair\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_lista();
            break;
        case 2:
            imprime_lista_inicio_ao_fim();
            break;
        case 3:
            imprime_lista_fim_ao_inicio();
             break;
        case 4:
            remover_elemento();
            break;
        case 5:
            esvaziar_lista();
            break;
        case 6:
            exit(0);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}

