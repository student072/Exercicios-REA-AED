
/*Pe�a ao usu�rio para digitar tr�s valores inteiros e imprima a soma deles.*/
#include <stdio.h>
int main(){
    /*declara��o das vari�veis*/
    int n1, n2, n3, soma;
    /*Entrada de dados*/
    printf("Entre com n1: ");
    scanf("%d", &n1);
    printf("Entre com n2: ");
    scanf("%d", &n2);
    printf("Entre com n3: ");
    scanf("%d", &n3);
    /*soma*/
    soma  = n1 + n2 + n3;
    /*sa�da de dados*/
    printf("Soma = %d ", soma);
    return 0;
}
