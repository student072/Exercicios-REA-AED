#include <stdio.h>
int main(){
    /*declaração das variáveis*/
    float tc, tf;
    /*Entrada de dados*/
    printf("Entre com a temperatura em Celsius: ");
    scanf("%f", &tc);
    /*conversão*/
    tf  = tc * (9.0/5.0) + 32;
    /*saída de dados*/
    printf("Temperatura em Fahrenheit = %.2f ", tf);
    return 0;
}
