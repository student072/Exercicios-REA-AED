#include <stdio.h>
#include <math.h>
/*função para calcular o volume da esfera*/
float calcula_volume(float raio){
    float pi = 3.1415;
    return (4/3)* pi * pow(raio,3);
}

int main(){
    float raio;
	/*entrada de dados*/
    printf("Entre com o raio da esfera: ");
    scanf("%f", &raio);
	/*chamada da função e impressao do resultado da mesma*/
    printf("Volume da esfera: %f", calcula_volume(raio));
    return 0;
}
