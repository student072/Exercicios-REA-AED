#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*registro que reprensentará cada elemento da pilha*/
struct FILA{
	int num;
	struct FILA *prox;
};
typedef struct FILA Fila;
/*a pilha inicia-se vazia, portanto inicio e fim são iguais a NULL*/
 Fila *inicio = NULL;
 Fila *fim = NULL;
 /*ponteiro auxiliar*/
 Fila *aux ;
 

void insere_elemento(){
	/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Fila*novo =(Fila*) malloc(sizeof(Fila));
	printf("Digite o numero a ser inserido na fila: ");
	scanf("%d",&novo->num);
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
	if(inicio == NULL){
		inicio = novo;
		fim = novo;
	/*caso a pilha ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila*/
	}else{
		fim->prox = novo;
		fim = novo;
	}
	printf("\nNumero inserido na fila!");
	getch();
}


/*os elementos da fila serão mostrados do primeiro inserido(inicio) ao último (fim)*/
void consulta_fila(){
	if(inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = inicio;
		do{
			printf(" %d ", aux->num);
			aux = aux->prox;
		} while(aux != NULL);
	}
	getch();
}


/*o elemento a ser removido será sempre o primeiro elemento inserido(inicio)*/
void remove_elemento_fila(){
	if(inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = inicio;
		printf("%d removido!", inicio->num);
		inicio = inicio->prox;
		free(aux);
	}
	getch();
}


/*a fila será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_fila(){
	if(inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux = inicio;
		do{
			inicio = inicio->prox;
			free(aux);
			aux = inicio;
		}while(aux != NULL);
		printf("\nFila Esvaziada!!");
	}
	getch();
}

int main(){
    int op;
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
            insere_elemento();
            break;
        case 2:
            consulta_fila();
            break;
        case 3:
            remove_elemento_fila();
            break;
        case 4:
            esvazia_fila();
            break;
        default:
            exit(1);
        }
    }
    return 0;
}



