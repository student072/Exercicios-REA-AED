#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
};

typedef struct No No;

/*registro do tipo Lista contento dois ponteiros do tipo n� para controlar a lista*/
struct Lista{
    struct No *inicio; /*aponta para o elemento do in�cio da lista*/
    struct No *fim; /*aponta para o elemento do fim da lista*/
};
typedef struct Lista Lista;

/*necessitaremos tamb�m de dois ponteiros auxilares *aux e *anterior */
No *aux;
No *anterior;

Lista* cria_lista(){
	/*aloca��o do ponteiro li para controlar a lista*/
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
		/*Se a lista est� inicialmente vazia, inicio e fim apontam para NULL */
        li->fim = NULL;
        li->inicio = NULL;
    }
    return li;
}

void insere_inicio_lista(Lista *li){
    /*a cada inser��o alocamos dinamicamente um espa�o para um novo n�*/
    No *novo =(No*) malloc(sizeof(No));
    /*o n�mero a ser inserido ser� armazenado em novo->num*/
    printf("Digite o numero a ser inserido no inicio da lista: ");
    scanf("%d",&novo->num);
    /*caso a lista estiver vazia o primeiro elemento a ser inserido ser� o primeiro e �ltimo*/
    if(li->inicio == NULL){
        /*aqui fazemos com que inicio aponte para o mesmo endere�o que novo aponta*/
        li->inicio = novo;
        novo->prox = NULL;
        /*aqui fazemos com que fim aponte para o mesmo endere�o que novo aponta*/
        li->fim = novo;
        /*aqui fazemos com que o endere�o para o qual fim aponta, no atributo prox receba NULL*/
        li->fim->prox = NULL;
    /*caso a lista n�o esteja vazia*/
    }else{
        /*como a inser��o � no inicio, o novo n� inserido receber� no atributo prox o endere�o que inicio aponta, ou seja,
         o inicio anterior ser� agora o segundo elemento, portante o primeiro elemento da lista ter� que apontar para ele*/
        novo->prox = li->inicio;
        /*aqui fazemos com que inicio aponte para o mesmo endere�o do novo n� inserido*/
        li->inicio = novo;
    }
    printf("\nNumero inserido no inicio da lista!");
    getch();
}

void imprime_lista(Lista *li){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista n�o esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endere�o que inicio aponta*/
        aux = li->inicio;
        do{
            /*impress�o do elemento que aux aponta*/
            printf(" %d ", aux->num);
            /*aux aponta para o pr�ximo elemento da lista, que ser� o endere�o contido no ponteiro prox.*/
            aux = aux->prox;
        /*essa opera��o ser� feita at� aux ser diferente de NULL, ou seja, n�o houverem mais elementos a serem impressos*/
        }while(aux != NULL);
    }
    getch();
}
void insere_fim_lista(Lista *li){
    /*a cada inser��o alocamos dinamicamente um espa�o para um novo n�*/
    No *novo =(No*) malloc(sizeof(No));
    /*o n�mero a ser inserido ser� armazenado em novo->num*/
    printf("Digite o numero a ser inserido no fim da lista: ");
    scanf("%d",&novo->num);
    /*caso a lista estiver vazia o primeiro elemento a ser inserido ser� o primeiro e �ltimo*/
    if(li->inicio == NULL){
        /*aqui fazemos com que inicio aponte para o mesmo endere�o que novo aponta*/
        li->inicio = novo;
        /*aqui fazemos com que fim aponte para o mesmo endere�o que novo aponta*/
        li->fim = novo;
        /*aqui fazemos com que o endere�o para o qual fim aponta, no atributo prox receba NULL*/
        li->fim->prox = NULL;
        /*caso a lista n�o esteja vazia*/
    }else{
        /*como a inser��o � no fim, o n� para o qual fim aponta, no atributo prox, receber� o endere�o de novo, ou seja,
          o �ltimo elemento ser� agora o pen�ltimo, e portanto dever� apontar para o �ltimo elemento inseirido*/
        li->fim->prox = novo;
        /*aqui fazemos com que fim aponte para o mesmo do novo n� inserido*/
        li->fim = novo;
        /*aqui fazemos com que o endere�o para o qual fim aponta, no atributo prox receba NULL*/
        li->fim->prox = NULL;
    }
    printf("\nNumero inserido no fim da lista!");
    getch();
}
void remover_elemento(Lista *li){
    int numero;
    /*a vari�vel achou ser� utilizada como um contador de n�meros removidos*/
    int achou;
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista n�o esteja vazia*/
    }else{
        printf("Digite o elemento a ser removido: ");
        scanf("%d", &numero);
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endere�o que inicio aponta*/
        aux = li->inicio;
        /*utilizando o ponteiro ele,  fazemos com ele aponte para NULL*/
        anterior = NULL;
        achou = 0;
        do{
            /*caso aux-> num seja igual ao n�mero a ser removido*/
            if(aux->num == numero){
                /*incrementamos achou*/
                achou = achou + 1;
                /*se o elemento a ser removido for o primeiro da lista*/
                if(aux == li->inicio){
                    /*inicio apontar� para o segundo elemento da lista ou para NULL
                      caso o elemento removido seja o �nico elemento da lista*/
                    li->inicio = aux ->prox;
                    /*desalocamos o espa�o para onde aux apontava*/
                    free(aux);
                    /*aux aponta para o inicio da lista*/
                    aux = li->inicio;
                /*se o elemento a ser removido for o �ltimo da lista*/
                }else if (aux == li->fim){
                    /*o elemento anterior a fim, no atributo prox apontar� para NULL*/
                    anterior->prox = NULL;
                    /*fim aponta para o elemento apontado por anterior*/
                    li->fim = anterior;
                    /*desalocamos o espa�o para onde aux apontava*/
                    free(aux);
                    /*como era o �ltmo elemento da lista, aux recebe NULL*/
                    aux = NULL;
                    /*se o elemento a ser removido n�o for nem o primeiro nem o �ltimo da lista */
                }else{
                    /*o elemento anterior ao elemento a ser removido, no atributo prox apontar� para o elemento
                      para qual aux->prox apontava*/
                    anterior->prox = aux->prox;
                    /*desalocamos o espa�o para onde aux apontava*/
                    free(aux);
                    /*aux aponta para o pr�ximo elemento da lista, aquele que era o seguinte ao n�mero removido*/
                    aux = anterior -> prox;
                }
				/*caso aux-> num n�o seja igual ao n�mero a ser removido*/
				 }else{
					 anterior = aux;
					 aux = aux -> prox;
				 }
        /*essa opera��o ser� feita at� aux ser diferente de NULL, ou seja, n�o houverem mais elementos a serem pesquisados*/
        }while(aux != NULL);
        /*impress�o do resultado*/
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
    /*caso a lista n�o esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endere�o de inicio  aponta*/
        aux = li->inicio;
        do{
            /*inicio apontar� para o pr�ximo elemento da lista*/
            li->inicio = li->inicio->prox;
            /*desalocamos o espa�o para onde aux apontava*/
            free(aux);
            /*aux apontar� para o mesmo endere�o que inicio aponta*/
            aux = li->inicio;
            /*essa opera��o ser� feita at� aux ser diferente de NULL, ou seja, n�o houverem mais elementos a serem removidos*/
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
