#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*registro que reprensentará cada elemento da pilha*/
struct Elemento{
	int num;
	struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Lista contento dois ponteiros do tipo nó para controlar a fila*/
struct Fila{
    struct Elemento *inicio; /*aponta para o elemento do início da fila*/
    struct Elemento *fim; /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

 /*ponteiro auxiliar*/
 Elemento *aux ;

 Fila* cria_fila(){
	/*alocação do ponteiro li para controlar a lista*/
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
		/*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}


void insere_elemento(Fila *fi){
	/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Elemento*novo =(Elemento*) malloc(sizeof(Elemento));
	printf("Digite o numero a ser inserido na fila: ");
	scanf("%d",&novo->num);
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
	if(fi->inicio == NULL){
		fi->inicio = novo;
		fi->fim = novo;
	/*caso a pilha ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila*/
	}else{
		fi->fim->prox = novo;
		fi->fim = novo;
	}
	printf("\nNumero inserido na fila!");
	getch();
}


/*os elementos da fila serão mostrados do primeiro inserido(inicio) ao último (fim)*/
void consulta_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = fi->inicio;
		do{
			printf(" %d ", aux->num);
			aux = aux->prox;
		} while(aux != NULL);
	}
	getch();
}


/*o elemento a ser removido será sempre o primeiro elemento inserido(inicio)*/
void remove_elemento_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = fi->inicio;
		printf("%d removido!", fi->inicio->num);
		fi->inicio = fi->inicio->prox;
		free(aux);
	}
	getch();
}


/*a fila será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		}while(aux != NULL);
		printf("\nFila Esvaziada!!");
	}
	getch();
}

int main(){
    int op;
	Fila *fi = cria_fila();
    while(1){
        system("CLS");
        printf("\nEscolha a opcao desejada ");
        printf("\n1- Inserir numero na fila ");
        printf("\n2- Consultar fila ");
        printf("\n3- Remover da fila");
        printf("\n4- Esvaziar fila: \n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_elemento(fi);
            break;
        case 2:
            consulta_fila(fi);
            break;
        case 3:
            remove_elemento_fila(fi);
            break;
        case 4:
            esvazia_fila(fi);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}



