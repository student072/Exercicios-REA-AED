#include <stdio.h>
int main(){
    /*declara��o das vari�veis*/
    float salario;
    /*Entrada de dados*/
    printf("Entre com o salario do funcionario: ");
    scanf("%f", &salario);
    /*calculo do novo salario*/
    salario  += salario * 0.25;
    /*sa�da de dados*/
    printf("Novo salario = %.2f ", salario);
    return 0;
}

