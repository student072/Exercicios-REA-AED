#include <stdio.h>

int main(){
	/*declaração das variáveis*/
    int mat[4][4], i, j;
	/*entrada de dados da matriz*/
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 4 ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
	/*verificar em toda matriz os valores maiores que 10 e imprimi-los*/
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 4 ; j++){
            if(mat[i][j] > 10){
                printf("%d ", mat[i][j]);
            }
        }
    }
    return 0;
}
