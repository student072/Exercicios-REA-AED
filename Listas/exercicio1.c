#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int codigo;
    float preco;
    int qtde;
    struct No *prox;
};

/*para toda hora n�o precisar escrever "struct No" vamos definir
 o tipo No atrav�s de typedef para simplificar*/
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
/*produto sera inserido no fim da lista*/
void insere_produto(Lista *li){
    /*a cada inser��o alocamos dinamicamente um espa�o para um novo n�*/
    No *novo =(No*) malloc(sizeof(No));
    /*cadastro dos dados do produto*/
    printf("Digite o codigo do produto: ");
    scanf("%d",&novo->codigo);
    printf("Digite o preco do produto: ");
    scanf("%f",&novo->preco);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d",&novo->qtde);
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
    printf("\nProduto inserido com sucesso!");
    getch();
}


void aplica_taxa(Lista *li, float taxa){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista n�o esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endere�o que inicio aponta*/
        aux = li->inicio;
        do{
            /*aplica��o da taxa de desconto ao pre�o do prdouto*/
            aux->preco = aux->preco - aux->preco * (taxa/100);
            /*aux aponta para o pr�ximo elemento da lista, que ser� o endere�o contido no ponteiro prox.*/
            aux = aux->prox;
        /*essa opera��o ser� feita at� aux ser diferente de NULL, ou seja, n�o houverem mais elementos a serem impressos*/
        }while(aux != NULL);
        printf("Taxa aplicada com sucesso!");
    }
    getch();
}
void imprime_relatorio(Lista *li){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista n�o esteja vazia*/
    }else{
        /*variavel utilizada para contar a quantidade de produtos com quantidade estocada superior a 500*/
        int quantidade = 0;
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endere�o que inicio aponta*/
        aux = li->inicio;
        printf(">>Relatorio<<\n");
        do{
            /*impress�o do codigo e preco do produto*/
            printf("\nCodigo do produto %d ", aux->codigo);
            printf("\nPreco do produto %.2f \n\n", aux->preco);
            /*verifica��o da quantidade de produto em estoque*/
            if(aux->qtde > 500)
                quantidade++;
            /*aux aponta para o pr�ximo elemento da lista, que ser� o endere�o contido no ponteiro prox.*/
            aux = aux->prox;
        /*essa opera��o ser� feita at� aux ser diferente de NULL, ou seja, n�o houverem mais elementos a serem impressos*/
        }while(aux != NULL);
        printf("\nQuantidade de produtos com quantidade estocada superior a 500: %d", quantidade);
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
    int i;
    float taxa;
    Lista *li = cria_lista();
    /*cadastro dos 5 produtos*/
    for(i = 1; i <= 5; i++){
        system("CLS");
        printf("Insira o produto numero %d\n", i);
        insere_produto(li);
    }
    system("CLS");
    /*aplica��o da taxa de desconto*/
    printf("Insira a taxa de desconto: ");
    scanf("%f", &taxa);
    aplica_taxa(li, taxa);
    system("CLS");
    /*impress�o do relat�rio*/
    imprime_relatorio(li);
    /*esvaziamento da lista utilizada*/
    esvaziar_lista(li);
    return 0;
}

