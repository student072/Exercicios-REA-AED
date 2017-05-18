#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int num;
    struct No *prox;
};
/*para toda hora não precisarmos escrever "struct No" vamos definir
o tipo No através de typedef para simplificar*/
typedef struct No No;
/*toda lista tem um inicio e fim, para isso declaramos dois ponteiros do tipo No para apontar para os
  os nós que estarão no iniício e fim da lista respectivamente.
  Como a lista está inicialmente vazia, inicio aponta para NULL */
No *inicio = NULL;
No *fim = NULL;  /*Em uma lista simplesmente encadeada o ultimo elemento sempre aponta para NULL */
/*necessitaremos também de dois ponteiros auxilares *aux e *ant * para as operações da lista*/
No *aux;
No *anterior;

void insere_lista(){
    /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    No *novo =(No*) malloc(sizeof(No));
    /*o número a ser inserido será armazenado em novo->num*/
    printf("\nDigite o no a ser inserido na lista: ");
    scanf("%d",&novo->num);
    /*caso a lista estiver vazia o primeiro elemento a ser inserido será o primeiro e último*/
    if(inicio == NULL){
        inicio = novo;/*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        fim = novo;/*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
        fim->prox = NULL;/*aqui fazemos com que o endereço para o qual fim aponta, no atributo prox receba NULL*/
	/*caso a lista não esteja vazia*/
    }else{
        anterior = NULL; /*inicialmente anterior apontará para NULL*/
        aux = inicio; /*aux aponta para o primeiro elemento da lista*/
		/*enquanto aux apontar para um nó existente  e o número inserido for maior que o número apontado por aux,
		a variação do valor de aux fará com que o novo número possa ser inseirido no local adequado, que é antes de um número maior que ele.*/
        while(aux != NULL && novo->num > aux->num){
            anterior = aux;/*anterior aponta para o endereço que aux aponta*/
            aux = aux->prox; /*aux aponta para o próximo nó da lista*/
        }
		/*caso não exista nenhum número menor que o novo número*/
        if(anterior == NULL){
            novo->prox = inicio;/*o novo elemento no atributo prox, apontará para o elemento que até então era o primeiro elemento da lista*/
            inicio = novo;/*novo será o primeiro elemento da lista, inicio apontará para o endereço de novo*/
		/*caso não exista nenhum número maior que o novo número*/
        }else if(aux == NULL){
            fim->prox = novo;/* o até então ultimo elemento da lista no atributo prox apontará para novo*/
            fim = novo;/*novo será o ultimo elemento da lista, fim apontará para o endereço de novo*/
            fim->prox = NULL;/*aqui fazemos com que o endereço para o qual fim aponta, no atributo prox receba NULL*/
		/*caso número precise ser inseirido no meio da lista*/
        }else{
            anterior->prox = novo;/*o primeiro número menor que o novo inseirido no atributo prox recebe o endereço de novo*/
            novo->prox = aux;/*novo no atibuto prox, recebe o endereço do primeiro número maior que ele*/
        }
    }
    printf("\nNumero inserido na lista!");
    getch();
}

void imprime_lista(){
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
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem impressos*/
        }while(aux != NULL);
    }
    getch();
}
void remover_elemento(){
    int numero;
    /*a variável achou será utilizada como um contador de números removidos*/
    int achou;
    /*caso a lista esteja vazia*/
    if(inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        printf("Digite o elemento a ser removido: ");
        scanf("%d", &numero);
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux = inicio;
        /*utilizando o ponteiro ele,  fazemos com ele aponte para NULL*/
        anterior = NULL;
        achou = 0;
        do{
            /*caso aux-> num seja igual ao número a ser removido*/
            if(aux->num == numero){
                /*incrementamos achou*/
                achou = achou + 1;
                /*se o elemento a ser removido for o primeiro da lista*/
                if(aux == inicio){
                    /*inicio apontará para o segundo elemento da lista ou para NULL
                      caso o elemento removido seja o único elemento da lista*/
                    inicio = aux ->prox;
                    /*desalocamos o espaço para onde aux apontava*/
                    free(aux);
                    /*aux aponta para o inicio da lista*/
                    aux = inicio;
                    /*se o elemento a ser removido for o último da lista*/
                }else if (aux == fim){
                    /*o elemento anterior a fim, no atributo prox apontará para NULL*/
                    anterior->prox = NULL;
                    /*fim aponta para o elemento apontado por anterior*/
                    fim = anterior;
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
        system("CLS");
        printf("\nEscolha a opcao desejada: ");
        printf("\n1- Inserir numero na fila: ");
        printf("\n2- Imprimir lista");
        printf("\n3- Remover elemento: ");
        printf("\n4- Esvaziar lista: ");
        printf("\n5- Sair\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_lista();
            break;
        case 2:
            imprime_lista();
            break;
        case 3:
            remover_elemento();
            break;
        case 4:
            esvaziar_lista();
            break;
        case 5:
            exit(0);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}

