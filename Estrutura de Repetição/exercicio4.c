#include <stdio.h>

int main(){
    int num, i, soma;
    num = 0;
	
	/*for utilizado para entrada de dados de 10 numeros*/
    for(i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d",&num);
		/*cada vez que um número é digitado ele é somado a variável soma*/
        soma+= num;
    }
	/*impressão da soma*/
    printf("\nSoma: %d", num);
    return 0;
}

