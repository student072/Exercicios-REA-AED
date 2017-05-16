#include <stdio.h>

int main(){
	/*declaração das variaveis */
    float altura, peso_ideal;
    char sexo;
    printf("\nEntre com seu sexo[ m / f ]: ");
    scanf("%c", &sexo);
    /*entrada de dados*/
    printf("\nEntre com sua altura: ");
    scanf("%f", &altura);
    /*com if avalio cada tipo de entrada possivel, caso seja digitado algo
    que nao seja m/M ou f/F sera dado um aviso para isso foi utilizado um else if
    */
    if(sexo == 'm' || sexo == 'M'){
        peso_ideal = (72.7 * altura) - 58.0;
        printf("Peso ideal: %.2f", peso_ideal);
    }else if(sexo == 'f' || sexo == 'F'){
        peso_ideal = (62.1 * altura) - 44.7;
        printf("Peso ideal: %.2f", peso_ideal);
    }else{
        printf("Sexo digitado esta errado!");
    }
    return 0;
}

