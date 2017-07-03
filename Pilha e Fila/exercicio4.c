#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*registro que reprensentar� cada elemento da pilha*/
struct Elemento_pilha{
	int num;
	struct Elemento_pilha *prox;
};
typedef struct Elemento_pilha Elemento_pilha;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct Pilha{
    struct Elemento_pilha *topo;/*aponta para o elemento qu esta Elemento topo da pilha*/
};
typedef struct Pilha Pilha;

 /*ponteiro auxiliar*/
 Elemento_pilha *aux ;


 /*registro que reprensentar� cada elemento da pilha*/
struct Elemento_fila{
	int num;
	struct Elemento_fila *prox;
};
typedef struct Elemento_fila Elemento_fila;

/*registro do tipo Lista contento dois ponteiros do tipo n� para controlar a fila*/
struct Fila{
    struct Elemento_fila *inicio; /*aponta para o elemento do in�cio da fila*/
    struct Elemento_fila *fim; /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

 /*ponteiro auxiliar*/
 Elemento_fila *aux2 ;


 Pilha* cria_pilha(){
	/*aloca��o do ponteiro pi para controlar a pilha*/
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo= NULL;  /*a pilha inicia-se vazia, portanto seu topo � igual a NULL*/
    }
    return pi;
}

Fila* cria_fila(){
	/*aloca��o do ponteiro li para controlar a lista*/
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
		/*a fila inicia-se vazia, portanto inicio e fim s�o iguais a NULL*/
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

/*todo elemento ser� inserido no topo da pilha*/
void insere_elemento_pilha(Pilha *pi){
	/*a cada inser��o alocamos dinamicamente um espa�o para um novo elemento*/
	Elemento_pilha *novo =(Elemento_pilha*) malloc(sizeof(Elemento_pilha));
	printf("\nDigite o numero a ser inserido na pilha: ");
	scanf("%d",&novo->num);
	/*como o n�mero inserido ser� o novo topo, ele apontar� para o topo atual que ser� o segundo elemento da pilha*/
	novo->prox = pi->topo;
	/*topo aponta para o endere�o de novo*/
	pi->topo = novo;
	printf("\nNumero inserido na pilha!\n");
	getch();
}

void insere_elemento_fila(Fila *fi){
	/*a cada inser��o alocamos dinamicamente um espa�o para um novo elemento*/
	Elemento_fila *novo =(Elemento_fila*) malloc(sizeof(Elemento_fila));
	printf("\nDigite o numero a ser inserido na fila: ");
	scanf("%d",&novo->num);
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido ser� o primeiro e o �ltimo */
	if(fi->inicio == NULL){
		fi->inicio = novo;
		fi->fim = novo;
	/*caso a pilha ja contenha algum elemento, o novo elemento ser� sempre inserido no fim da fila*/
	}else{
		fi->fim->prox = novo;
		fi->fim = novo;
	}
	printf("\nNumero inserido na fila!\n");
	getch();
}

/* fun��o verifica os n�meros que est�o nas duas estruturas
   cada elemento da pilha � comparado os todos elementos da fila verificando a igualdade*/
void consulta_iguais(Pilha *pi, Fila *fi){
    int achou;
    aux = pi->topo;
    /*looping da pilha*/
    do{
        achou = 0;
        aux2 = fi->inicio;
         /*looping da fila*/
        do{
            if(aux2->num == aux->num)
                achou ++;
            aux2 = aux2->prox;
        } while(aux2 != NULL);

        if(achou > 0)
            printf(" %d", aux->num);
        aux = aux->prox;
    } while(aux != NULL);
	getch();
}
/* fun��o verifica os n�meros que est�o somente na fila
   cada elemento da fila � comparado os todos elementos da pilha*/
void consulta_fila(Pilha *pi, Fila *fi){
    int achou;
    aux2 = fi->inicio;
    /*looping da fila*/
    do{
        achou = 0;
        aux = pi->topo;
        /*looping da pilha*/
        do{
            if(aux2->num == aux->num)
                achou ++;
            aux = aux->prox;
        } while(aux != NULL);
        if(achou == 0)
            printf(" %d", aux2->num);
        aux2 = aux2->prox;
    } while(aux2 != NULL);
	getch();
}
/* fun��o verifica os n�meros que est�o somente na pilha
   cada elemento da pilha � comparado os todos elementos da fila*/
void consulta_pilha(Pilha *pi, Fila *fi){
    int achou;
    aux = pi->topo;
     /*looping da pilha*/
    do{
        achou = 0;
        aux2 = fi->inicio;
         /*looping da fila*/
        do{
            if(aux2->num == aux->num)
                achou ++;
            aux2 = aux2->prox;
        } while(aux2 != NULL);
        if(achou == 0)
            printf(" %d", aux->num);
        aux = aux->prox;
    } while(aux != NULL);
	getch();
}

/*a pilha ser� esvaziada e o espa�o ocupado por ela ser� desalocado*/
void esvazia_pilha(Pilha *pi){
	if(pi->topo == NULL){
		printf("\nPilha Vazia!!");
	}else{
		aux = pi->topo;
		do{
			pi->topo = pi->topo->prox;
			free(aux);
			aux = pi->topo;
		}while(aux != NULL);
		printf("\nPilha Esvaziada!!");
	}
	getch();
}
/*a fila ser� esvaziada e o espa�o ocupado por ela ser� desalocado*/
void esvazia_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux2 = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux2);
			aux2 = fi->inicio;
		}while(aux2 != NULL);
		printf("\nFila Esvaziada!!");
	}
	getch();
}

int main(){
    int i;
	Pilha *pi = cria_pilha();
	Fila *fi = cria_fila();
	/*inserindo elementos na pilha*/
	for(i = 1; i <= 5; i++ ){
        insere_elemento_pilha(pi);
        system("CLS");
	}
	/*inserindo elementos na fila*/
	for(i = 1; i <= 5; i++ ){
        insere_elemento_fila(fi);
        system("CLS");
	}
	/*relatorio 1*/
	printf("\nNumeros que est�o nas duas estruturas\n");
	consulta_iguais(pi, fi);
	/*relatorio 2*/
	printf("\nNumeros que est�o somente na fila\n");
	consulta_fila(pi, fi);
	/*relatorio 3*/
	printf("\nNumeros que est�o somente na pilha\n");
	consulta_pilha(pi, fi);

	/*esvaziando pilha e fila utilizadas*/
	esvazia_fila(fi);
	esvazia_pilha(pi);
    return 0;
}



