#include <stdio.h>
int main(){
    /*declara��o das vari�veis*/
    float tc, tf;
    /*Entrada de dados*/
    printf("Entre com a temperatura em Celsius: ");
    scanf("%f", &tc);
    /*convers�o*/
    tf  = tc * (9.0/5.0) + 32;
    /*sa�da de dados*/
    printf("Temperatura em Fahrenheit = %.2f ", tf);
    return 0;
}
