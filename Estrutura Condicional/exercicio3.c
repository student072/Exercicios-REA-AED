#include <stdio.h>

int main(){
    int n;

    /*entrada de dados*/
    printf("Entre com um numero inteiro: ");
    scanf("%d", &n);
    /*se o resto da divisao de n por 2 for 0 numero sera par
      do contrario será impar*/
    if(n % 2 == 0){
        printf("Numero Par");
    }else{
        printf("Numero impar");
    }
    return 0;
}
