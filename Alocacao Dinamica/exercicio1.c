#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr, i;
    /*alocando espaço para 5 inteiros*/
    ptr = (int*)malloc(5 * sizeof(int));

    /*armazeando os 5 inteiros no espaço alocado*/
    for(i = 0 ; i < 5; i++){
        printf("Entre com n[%d]: ", i+1);
        scanf("%d", &ptr[i]);
    }
    /*mostrando os 5 inteiros*/
    for(i = 0 ; i < 5; i++){
        printf("%d  ", ptr[i]);
    }
    /*desalocando o espaço utilizado anteriormente*/
    free(ptr);
    return 0;
}
