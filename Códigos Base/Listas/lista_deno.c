#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
    struct No *ant;
};
typedef struct No No;

/*registro do tipo Lista contento dois ponteiros do tipo nó para controlar a lista*/
struct Lista{
    struct No *inicio; /*aponta para o elemento do início da lista*/
    struct No *fim; /*aponta para o elemento do fim da lista*/
};
typedef struct Lista Lista;

/*necessitaremos também de dois ponteiros auxilares *aux e *ant */
No *aux;
No *aux2;
No *anterior;

Lista* cria_lista(){
	/*alocação do ponteiro li para controlar a lista*/
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
		/*Se a lista está inicialmente vazia, inicio e fim apontam para NULL */
        li->fim = NULL;
        li->inicio = NULL;
    }
    return li;
}

void insere_inicio_lista(Lista *li){
    /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    No *novo =(No*) malloc(sizeof(No));
    /*o número a ser inserido será armazenado em novo->num*/
    printf("Digite o numero a ser inserido no inicio da lista: ");
    scanf("%d",&novo->num);
    /*caso a lista estiver vazia o primeiro elemento a ser inserido será o primeiro e último elemento da lista*/
    if(li->inicio == NULL){
        li->inicio = novo; /*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        li->fim = novo;/*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
        /*como será o único elemento da lista, novo->prox e novo->ant apontam para null*/
        novo->prox = NULL;
        novo->ant = NULL;
    /*caso a lista não esteja vazia*/
    }else{
        /*como a inserção é no inicio, o novo nó inserido receberá no atributo prox (seu ponteiro que aponta para o próximo nó)
         o endereço que inicio aponta*/
        novo->prox =  li->inicio;
        /*inicio no atributo ant recebe o endereço de novo, aqui ainda inicio não foi alterado, portanto essa linha é necessária
           para que quando for o segundo  da lista este elemento possa apontar (através de ant) para o novo elemento que se
           tornará o novo inicio*/
         li->inicio->ant = novo;
        /*novo no atributo ant recebe null, como depois se tornará o primeiro elemento da lista, seu ponteiro que aponta para o
           nó anterior será null*/
        novo->ant = NULL;
        /*aqui inicio apontará para o novo nó inserido*/
         li->inicio = novo;
    }
    printf("\nNumero inserido na lista!");
    getch();
}


void insere_fim_lista(Lista *li){
    /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    No *novo =(No*) malloc(sizeof(No));
    /*o número a ser inserido será armazenado em novo->num*/
    printf("Digite o numero a ser inserido no fim da lista: ");
    scanf("%d",&novo->num);
    /*caso a lista estiver vazia o primeiro elemento a ser inserido será o primeiro e último elemento da lista*/
    if( li->inicio == NULL){
        li->inicio = novo; /*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        li->fim = novo;/*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
        /*como será o único elemento da lista, novo->prox e novo->ant apontam para null*/
        novo->prox = NULL;
        novo->ant = NULL;
    }else{
        /*fim no atributo prox recebe o endereço de novo, aqui ainda fim não foi alterado, portanto essa linha é necessária para
        quando esse elemento vier a ser o penultimo da lista possa apontar para o novo elemento que se tonará o novo fim*/
         li->fim->prox = novo;
        /*como a inserção é no fim, o novo nó inserido receberá no atributo ant(seu ponteiro que aponta para o nó anterior) o
           atual endereço que fim aponta*/
         novo->ant =  li->fim;
        /*como será o ultimo elemento da lista, novo no atributo prox apontará para null*/
        novo->prox = NULL;
        /*fim aponta para o novo nó inserido*/
         li->fim = novo;
    }
    printf("\nNumero inserido na lista!");
    getch();
}



void imprime_lista_inicio_ao_fim(Lista *li){
    /*caso a lista esteja vazia*/
    if( li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux =  li->inicio;
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


void imprime_lista_fim_ao_inicio(Lista *li){
    /*caso a lista esteja vazia*/
    if( li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que fim aponta*/
        aux =  li->fim;
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

void remover_elemento(Lista *li){
    int numero, achou; /*a variável achou será utilizada como um contador de números removidos*/
    if(li->inicio == NULL){ /*caso a lista esteja vazia*/
        printf("\nLista Vazia!!");
    }else{  /*caso a lista não esteja vazia*/
        printf("Digite o elemento a ser removido: ");
		scanf("%d", &numero);
        aux =  li->inicio; /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        achou = 0;
        do{
            if(aux->num == numero){ /*caso aux-> num seja igual ao número a ser removido*/
                achou = achou + 1; /*incrementamos achou*/
                if(aux ==  li->inicio){ /*se o elemento a ser removido for o primeiro da lista*/
                    li->inicio = aux ->prox;/*inicio apontará para o segundo elemento da lista ou para NULL caso o elemento
                                                            removido seja o único elemento da lista*/
                    if ( li->inicio != NULL){ /*caso inicio tenha não recebido null na linha anterior*/
                         li->inicio->ant = NULL; /*ant de inicio também apontará para null*/
                    }
                    free(aux);  /*desalocamos o espaço para onde aux apontava*/
                    aux =  li->inicio; /*aux aponta para o inicio da lista*/
                }else if(aux == li->fim){ /*se o elemento a ser removido for o ultimo da lista*/
                                li->fim =  li->fim->ant; /*fim apontará para o elemento anterior a ele*/
                                li->fim->prox = NULL; /*fim no atributo prox apontará para null*/
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
void esvaziar_lista(Lista *li){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço de inicio  aponta*/
        aux = li->inicio;
        do{
            /*inicio apontará para o próximo elemento da lista*/
            li->inicio = li->inicio->prox;
             /*desalocamos o espaço para onde aux apontava*/
            free(aux);
            /*aux apontará para o mesmo endereço que inicio aponta*/
            aux = li->inicio;
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem removidos*/
        }while(aux != NULL);
        printf("\nLista Esvaziada!!");
    }
    getch();
}

int main(){
    int op;
	Lista *li = cria_lista();
    while(1){
		system("CLS");
        printf("\nEscolha a opcao desejada: ");
        printf("\n1- Inserir numero no inicio da fila: ");
        printf("\n2- Inserir numero no fim da fila: ");
        printf("\n3- Imprimir lista do inicio ao fim");
        printf("\n4- Imprimir lista do fim ao inicio");
        printf("\n5- Remover elemento: ");
        printf("\n6- Esvaziar lista: ");
        printf("\n7- Sair\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_inicio_lista(li);
            break;
        case 2:
            insere_fim_lista(li);
            break;
        case 3:
            imprime_lista_inicio_ao_fim(li);
            break;
        case 4:
            imprime_lista_fim_ao_inicio(li);
            break;
        case 5:
            remover_elemento(li);
            break;
        case 6:
            esvaziar_lista(li);
            break;
        case 7:
            exit(0);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}
