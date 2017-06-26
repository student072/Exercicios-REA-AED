#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*registro que reprensentará cada elemento da pilha*/
struct PILHA{
	int num;
	struct PILHA *prox;
};
typedef struct PILHA Pilha;
/*a pilha inicia-se vazia, portanto seu topo é igual a NULL*/
 Pilha *topo = NULL;
 /*ponteiro auxiliar*/
 Pilha *aux ;

 
 /*todo elemento será inserido no topo da pilha*/
void insere_elemento(){
	/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Pilha *novo =(Pilha*) malloc(sizeof(Pilha));
	printf("Digite o numero a ser inserido na pilha: ");
	scanf("%d",&novo->num);
	/*como o número inserido será o novo topo, ele apontará para o topo atual que será o segundo elemento da pilha*/
	novo->prox = topo;
	/*topo aponta para o endereço de novo*/
	topo = novo;
	printf("\nNumero inserido na pilha!");
	getch();
}



/*os elementos da pilha serão mostrados do último inserido(topo) ao primeiro*/
void consulta_pilha(){
	/*caso a pilha esteja vazia*/
	if(topo == NULL){
		printf("\nPilha Vazia!!");
	/*caso a pilha não esteja vazia*/
	}else{
		aux = topo;
		do{
			printf(" %d ", aux->num);
			aux = aux->prox;
		} while(aux != NULL);
	}
	getch();
}



/*o elemento a ser removido será sempre o topo(último elemento inserido)*/
void remove_elemento_pilha(){
	if(topo == NULL){
		printf("\nPilha Vazia!!");
	}else{
		aux = topo;
		printf("%d removido!", topo->num);
		topo = topo->prox;
		free(aux);
	}
	getch();
}



/*a pilha será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_pilha(){
	if(topo == NULL){
		printf("\nPilha Vazia!!");
	}else{
		aux = topo;
		do{
			topo = topo->prox;
			free(aux);
			aux = topo;
		}while(aux != NULL);
		printf("\nPilha Esvaziada!!");
	}
	getch();
}

int main(){
    int op;
    while(1){
        system("CLS");
        printf("\nEscolha a opcao desejada ");
        printf("\n1- Inserir numero na pilha ");
        printf("\n2- Consultar pilha ");
        printf("\n3- Remover da pilha");
        printf("\n4- Esvaziar pilha: \n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_elemento();
            break;
        case 2:
            consulta_pilha();
            break;
        case 3:
            remove_elemento_pilha();
            break;
        case 4:
            esvazia_pilha();
            break;
        default:
            exit(1);
        }
    }
    return 0;
}


