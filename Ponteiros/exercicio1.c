#include <stdio.h>

int main(){
	/*declaração das variáveis e ponteiros*/
    int var1, *p1;
    float var2, *p2;
    char var3, *p3;
	
	/*inicialização dos ponteiros*/
    p1 = &var1;
    p2 = &var2;
    p3 = &var3;
	
	/*atribuição de valores para as variáveis através dos ponteiros*/
    *p1 = 10;
    *p2 = 5.99;
    *p3 = 'K';
	/*Impressão dos valores*/
    printf("\nValor de var1 %d", var1);
    printf("\nValor de var2 %f", var2);
    printf("\nValor de var3 %c", var3);
	
	/*modificação dos valores das variáveis através dos ponteiros*/
    *p1 = 63;
    *p2 = 87.15;
    *p3 = 'z';
	/*Impressão após a mudança*/
    printf("\n\nValor de var1 %d", var1);
    printf("\nValor de var2 %f", var2);
    printf("\nValor de var3 %c", var3);
    return 0;
}
