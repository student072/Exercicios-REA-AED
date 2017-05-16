#include <stdio.h>

int main(){
    int mat1[4][4], mat2[4][4], mat3[4][4], i, j;
	/*entrada de dados da primeira matriz*/
    printf("Entre com os elementos da primeira matriz: \n");
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 4 ; j++){
            scanf("%d",&mat1[i][j]);
        }
    }
	/*entrada de dados da segunda matriz*/
    printf("Entre com os elementos da segunda matriz: \n");
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 4 ; j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    printf("\n");
	/*verifica posição por posição de mat1 e mat2 qual número é o maior daquela posição e 
	  armazena-o em mat3*/
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 4 ; j++){
            if(mat1[i][j] >= mat2[i][j] ){
                mat3[i][j] = mat1[i][j];
            }else{
                mat3[i][j] = mat2[i][j];
            }
        }
    }
	/*impressão de mat3*/
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 4 ; j++){
            printf("\t%d",mat3[i][j]);
        }
         printf("\n");
    }
    return 0;
}

