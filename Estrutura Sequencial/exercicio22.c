#include <stdio.h>
#include <math.h>
int main(){
    /*declaração das variáveis*/
    float a, b, hipotenusa;
    /*Entrada de dados*/
    printf("Entre com a: ");
    scanf("%f", &a);
    printf("Entre com b: ");
    scanf("%f", &b);
    /*calculo da hipotenusa*/
    a = pow(a,2);
    b = pow(b,2);
    hipotenusa  = sqrt(a+b);
    /*saída de dados*/
    printf("Hipotenusa = %.2f ", hipotenusa);
    return 0;
}

