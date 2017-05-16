#include <stdio.h>

int main(){
    int num, cont;
	/*contador utilizado para verificar os numeros naturais impares
	começa valendo 1*/
    cont = 1;
	/*entrada de num*/
    printf("Entre com o valor de n: ");
    scanf("%d",&num);
	
	/*while sera realizado enquanto n for diferente de 0*/
    while(num != 0){
			/*caso o numero nao seja par, ou seja, se o resto da divisão de cont por 2
			  seja diferente de 0*/
            if( cont %2 != 0){
				/*imprime o numero e subtrai 1 de num*/
                 printf("%d ", cont);
                 num--;
            }
		/*a cada interação cont é incrementado*/
        cont ++;
    }
    return 0;
}
