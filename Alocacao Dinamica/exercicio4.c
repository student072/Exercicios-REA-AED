#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr, i;
    /*alocando espa�o para 1500 inteiros*/
    ptr = (int*)calloc(1500 , sizeof(int));
    /*atribuindo o valor do indice a cada espa�o do vetpr alocado*/
    for(i = 0 ; i < 1500; i++){
       ptr[i] = i;
    }
     /*imprimindo os 10 primeiros e 10 ultimos numeros*/
    for(i = 0 ; i < 1500; i++){
       if(i <= 9 || i > 1489)
            printf("%d ", ptr[i]);
    }
    /*desalocando o espa�o utilizado anteriormente*/
    free(ptr);
    return 0;
}


