#include <stdio.h>

int main(){
    int num, cont;
	/*contador determinara a quantidade de multiplos de 3*/
    cont  = 0;
	/*numero a ser analisado*/
	num = 1;
	/*enquanto contador for menor que 5 realize o laço
	  e a cada interação num é incrementado*/
    while(cont < 5){
		/*se o resto da divisão de num por 3 for 0, num é multiplo de 3
		 caso if seja verdadeiro o número é impresso e o contador é incrementado*/
        if( num%3 == 0){
            printf("%d ", num);
            cont++;
        }
        num++;
    }
    return 0;
}
