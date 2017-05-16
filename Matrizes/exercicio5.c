#include <stdio.h>

int main(){
    int mat[5][5], i, j, linha, coluna, num;
    char verificador;
	/*variáveis para o armazenamento das linhas e colunas.*/
    linha = 0;
    coluna  = 0;
	/*verificador para dizer se o número foi encontrado ou não*/
    verificador = 'n';
	/*entrada de dados da matriz*/
    for(i = 0; i < 5 ; i++){
        for(j = 0; j < 5 ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
	/*entrada do número a ser procurado*/
    printf("Entre com o numero a ser procurado: ");
    scanf("%d", &num);
    printf("\n");
	/*verificar em toda matriz o valor procurado, caso encontrado armazanar sua linha e coluna
	   Também alterar o verificar para s*/
    for(i = 0; i < 5 ; i++){
        for(j = 0; j < 5 ; j++){
            if(mat[i][j] == num){
               linha = i;
               coluna = j;
               verificador = 's';
            }
        }
    }
	/*se o número foi encontrado(verificador == 's'), imprima a linha e coluna em que o número esta armazenado
	  caso contrário imprima "número não encontrado"*/
    if(verificador == 's'){
        printf("Numero %d encontrado na linha %d e  %d coluna", num, linha, coluna);
    }else{
        printf("Numero nao encontrado");
    }

    return 0;
}

