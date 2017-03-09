#include <stdio.h>
int main(){
    /*declaração das variáveis*/
    float salario;
    /*Entrada de dados*/
    printf("Entre com o salario do funcionario: ");
    scanf("%f", &salario);
    /*calculo do novo salario*/
    salario  += salario * 0.25;
    /*saída de dados*/
    printf("Novo salario = %.2f ", salario);
    return 0;
}

