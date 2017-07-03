#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
};

typedef struct No No;

/*registro do tipo Lista contento dois ponteiros do tipo nó para controlar a lista*/
struct Lista{
    struct No *inicio; /*aponta para o elemento do início da lista*/
    struct No *fim; /*aponta para o elemento do fim da lista*/
};
typedef struct Lista Lista;

/*necessitaremos também de dois ponteiros auxilares *aux e *anterior */
No *aux;
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
    /*caso a lista estiver vazia o primeiro elemento a ser inserido será o primeiro e último*/
    if(li->inicio == NULL){
        /*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        li->inicio = novo;
        novo->prox = NULL;
        /*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
        li->fim = novo;
        /*aqui fazemos com que o endereço para o qual fim aponta, no atributo prox receba NULL*/
        li->fim->prox = NULL;
    /*caso a lista não esteja vazia*/
    }else{
        /*como a inserção é no inicio, o novo nó inserido receberá no atributo prox o endereço que inicio aponta, ou seja,
         o inicio anterior será agora o segundo elemento, portante o primeiro elemento da lista terá que apontar para ele*/
        novo->prox = li->inicio;
        /*aqui fazemos com que inicio aponte para o mesmo endereço do novo nó inserido*/
        li->inicio = novo;
    }
    printf("\nNumero inserido no inicio da lista!");
    getch();
}

void imprime_lista(Lista *li){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux = li->inicio;
        do{
            /*impressão do elemento que aux aponta*/
            printf(" %d ", aux->num);
            /*aux aponta para o próximo elemento da lista, que será o endereço contido no ponteiro prox.*/
            aux = aux->prox;
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem impressos*/
        }while(aux != NULL);
    }
    getch();
}
void insere_fim_lista(Lista *li){
    /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    No *novo =(No*) malloc(sizeof(No));
    /*o número a ser inserido será armazenado em novo->num*/
    printf("Digite o numero a ser inserido no fim da lista: ");
    scanf("%d",&novo->num);
    /*caso a lista estiver vazia o primeiro elemento a ser inserido será o primeiro e último*/
    if(li->inicio == NULL){
        /*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        li->inicio = novo;
        /*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
        li->fim = novo;
        /*aqui fazemos com que o endereço para o qual fim aponta, no atributo prox receba NULL*/
        li->fim->prox = NULL;
        /*caso a lista não esteja vazia*/
    }else{
        /*como a inserção é no fim, o nó para o qual fim aponta, no atributo prox, receberá o endereço de novo, ou seja,
          o último elemento será agora o penúltimo, e portanto deverá apontar para o último elemento inseirido*/
        li->fim->prox = novo;
        /*aqui fazemos com que fim aponte para o mesmo do novo nó inserido*/
        li->fim = novo;
        /*aqui fazemos com que o endereço para o qual fim aponta, no atributo prox receba NULL*/
        li->fim->prox = NULL;
    }
    printf("\nNumero inserido no fim da lista!");
    getch();
}
void remover_elemento(Lista *li){
    int numero;
    /*a variável achou será utilizada como um contador de números removidos*/
    int achou;
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        printf("Digite o elemento a ser removido: ");
        scanf("%d", &numero);
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux = li->inicio;
        /*utilizando o ponteiro ele,  fazemos com ele aponte para NULL*/
        anterior = NULL;
        achou = 0;
        do{
            /*caso aux-> num seja igual ao número a ser removido*/
            if(aux->num == numero){
                /*incrementamos achou*/
                achou = achou + 1;
                /*se o elemento a ser removido for o primeiro da lista*/
                if(aux == li->inicio){
                    /*inicio apontará para o segundo elemento da lista ou para NULL
                      caso o elemento removido seja o único elemento da lista*/
                    li->inicio = aux ->prox;
                    /*desalocamos o espaço para onde aux apontava*/
                    free(aux);
                    /*aux aponta para o inicio da lista*/
                    aux = li->inicio;
                /*se o elemento a ser removido for o último da lista*/
                }else if (aux == li->fim){
                    /*o elemento anterior a fim, no atributo prox apontará para NULL*/
                    anterior->prox = NULL;
                    /*fim aponta para o elemento apontado por anterior*/
                    li->fim = anterior;
                    /*desalocamos o espaço para onde aux apontava*/
                    free(aux);
                    /*como era o últmo elemento da lista, aux recebe NULL*/
                    aux = NULL;
                    /*se o elemento a ser removido não for nem o primeiro nem o último da lista */
                }else{
                    /*o elemento anterior ao elemento a ser removido, no atributo prox apontará para o elemento
                      para qual aux->prox apontava*/
                    anterior->prox = aux->prox;
                    /*desalocamos o espaço para onde aux apontava*/
                    free(aux);
                    /*aux aponta para o próximo elemento da lista, aquele que era o seguinte ao número removido*/
                    aux = anterior -> prox;
                }
				/*caso aux-> num não seja igual ao número a ser removido*/
				 }else{
					 anterior = aux;
					 aux = aux -> prox;
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
        printf("\n3- Imprimir lista");
        printf("\n4- Remover elemento: ");
        printf("\n5- Esvaziar lista: ");
        printf("\n6- Sair\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_inicio_lista(li);
            break;
        case 2:
            insere_fim_lista(li);
            break;
        case 3:
            imprime_lista(li);
            break;
        case 4:
            remover_elemento(li);
            break;
        case 5:
            esvaziar_lista(li);
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
