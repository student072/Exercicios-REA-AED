#include <stdio.h>
/*função que dobra os valores de A e B e armazana nas proprias varíaveis e depois retorna a soma A + B*/
int modifica_valores(int *pA,int *pB){
    *pA *= 2;
    *pB *= 2;
    return (*pA) + (*pB);
}

int main(){
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
	/*impressão e chamada da função, passagem por parâmetro usando o &*/
    printf("Valor de 2A + 2B = %d", modifica_valores(&A,&B));
    return 0;
}
