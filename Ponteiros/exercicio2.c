#include <stdio.h>

int main(){
	/*declaração das variáveis e ponteiros*/
    int var1, var2, *p1, *p2;
	/*inicialização dos ponteiros*/
    p1 = &var1;
    p2 = &var2;
	/*verificação de qual variável tem o maior endereço de memória e impressão do resultado*/
    if(p1 > p2){
        printf("%p", p1);
    }else{
        printf("%p", p2);
    }
    return 0;
}
