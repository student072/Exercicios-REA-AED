#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*registro que reprensentará cada elemento da pilha*/
struct Elemento{
	int num;
	struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct Pilha{
    struct Elemento *topo;/*aponta para o elemento qu esta Elemento topo da pilha*/
};
typedef struct Pilha Pilha;

 /*ponteiro auxiliar*/
 Elemento *aux ;

 Pilha* cria_pilha(){
	/*alocação do ponteiro pi para controlar a pilha*/
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo= NULL;  /*a pilha inicia-se vazia, portanto seu topo é igual a NULL*/
    }
    return pi;
}


/*todo elemento será inserido no topo da pilha*/
void insere_elemento(Pilha *pi){
	/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Elemento *novo =(Elemento*) malloc(sizeof(Elemento));
	printf("Digite o numero a ser inserido na pilha: ");
	scanf("%d",&novo->num);
	/*como o número inserido será o novo topo, ele apontará para o topo atual que será o segundo elemento da pilha*/
	novo->prox = pi->topo;
	/*topo aponta para o endereço de novo*/
	pi->topo = novo;
	printf("\nNumero inserido na pilha!");
	getch();
}



/*os elementos da pilha serão mostrados do último inserido(topo) ao primeiro*/
void consulta_pilha(Pilha *pi){
	/*caso a pilha esteja vazia*/
	if(pi->topo == NULL){
		printf("\nPilha Vazia!!");
	/*caso a pilha não esteja vazia*/
	}else{
		aux = pi->topo;
		do{
			printf(" %d ", aux->num);
			aux = aux->prox;
		} while(aux != NULL);
	}
	getch();
}


/*o elemento a ser removido será sempre o topo(último elemento inserido)*/
void remove_elemento_pilha(Pilha *pi){
	if(pi->topo == NULL){
		printf("\nPilha Vazia!!");
	}else{
		aux = pi->topo;
		printf("%d removido!", pi->topo->num);
		pi->topo = pi->topo->prox;
		free(aux);
	}
	getch();
}



/*a pilha será esvaziada e o espaço ocupado por ela será desalocado*/
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

int main(){
    int op;
	Pilha *pi = cria_pilha();
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
            insere_elemento(pi);
            break;
        case 2:
            consulta_pilha(pi);
            break;
        case 3:
            remove_elemento_pilha(pi);
            break;
        case 4:
            esvazia_pilha(pi);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}


