#include <stdio.h>

int main(){
    int mat[3][3], i, j, soma = 0;
	/*entrada de dados da matriz*/
    for(i = 0; i < 3 ; i++){
        for(j = 0; j < 3 ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
	/*faz a soma de todos os elementos que estão abaixo da diagonal principal
	 Um elemento esta abaixo da diagonal principal quando linha > coluna*/
    for(i = 0; i < 3 ; i++){
		for(j = 1; j < 3 ; j++){
			if(i > j){
                soma += mat[i][j];
            }
        }
    }
	/*impressão da soma*/
    printf("\nSoma: %d", soma);
    return 0;
}

