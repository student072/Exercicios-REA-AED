#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct No{
    int codigo;
    float preco;
    int qtde;
    struct No *prox;
};

/*para toda hora não precisar escrever "struct No" vamos definir
 o tipo No através de typedef para simplificar*/
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
/*produto sera inserido no fim da lista*/
void insere_produto(Lista *li){
    /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    No *novo =(No*) malloc(sizeof(No));
    /*cadastro dos dados do produto*/
    printf("Digite o codigo do produto: ");
    scanf("%d",&novo->codigo);
    printf("Digite o preco do produto: ");
    scanf("%f",&novo->preco);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d",&novo->qtde);
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
    printf("\nProduto inserido com sucesso!");
    getch();
}


void aplica_taxa(Lista *li, float taxa){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux = li->inicio;
        do{
            /*aplicação da taxa de desconto ao preço do prdouto*/
            aux->preco = aux->preco - aux->preco * (taxa/100);
            /*aux aponta para o próximo elemento da lista, que será o endereço contido no ponteiro prox.*/
            aux = aux->prox;
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem impressos*/
        }while(aux != NULL);
        printf("Taxa aplicada com sucesso!");
    }
    getch();
}
void imprime_relatorio(Lista *li){
    /*caso a lista esteja vazia*/
    if(li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*variavel utilizada para contar a quantidade de produtos com quantidade estocada superior a 500*/
        int quantidade = 0;
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux = li->inicio;
        printf(">>Relatorio<<\n");
        do{
            /*impressão do codigo e preco do produto*/
            printf("\nCodigo do produto %d ", aux->codigo);
            printf("\nPreco do produto %.2f \n\n", aux->preco);
            /*verificação da quantidade de produto em estoque*/
            if(aux->qtde > 500)
                quantidade++;
            /*aux aponta para o próximo elemento da lista, que será o endereço contido no ponteiro prox.*/
            aux = aux->prox;
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem impressos*/
        }while(aux != NULL);
        printf("\nQuantidade de produtos com quantidade estocada superior a 500: %d", quantidade);
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
    /*aplicação da taxa de desconto*/
    printf("Insira a taxa de desconto: ");
    scanf("%f", &taxa);
    aplica_taxa(li, taxa);
    system("CLS");
    /*impressão do relatório*/
    imprime_relatorio(li);
    /*esvaziamento da lista utilizada*/
    esvaziar_lista(li);
    return 0;
}

