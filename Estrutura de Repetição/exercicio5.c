#include <stdio.h>

int main(){
    int i, num, maior, menor;
    maior = 0;
    menor = 0;
	/*for utilizado para entrada de dados de 10 numeros*/
    for(i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d",&num);
		/*caso seja a primeira interação maior e menor recebem o número digitado*/
        if(i == 0){
            maior = num;
            menor = num;
        }
		/*avalia se num é maior que o valor contido em maior, se for
		maior recebe num*/
		else if(num > maior){
				maior = num;
			 }
		/*avalia se num é menor que o valor contido em menor, se for
		menor recebe num*/
			else if(num < menor){
					menor = num;
				}
    }
    printf("\nMaior: %d", maior);
    printf("\nMenor: %d", menor);
    return 0;
}
