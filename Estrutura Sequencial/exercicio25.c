#include <stdio.h>
int main(){
    /*declara��o das vari�veis*/
    float g1,g2, g3;
    /*c�lculos da premia��o de cada ganhador*/
    g1 = 780000.00 * 0.46;
    g2 = 780000.00 * 0.32;
    g3 = 780000.00 - g1 - g2;
    /*sa�da de dados*/
    printf("Premiacao:");
    printf("\nGanhador 1 = %.2f ", g1);
    printf("\nGanhador 2 = %.2f ", g2);
    printf("\nGanhador 3 = %.2f ", g3);
    return 0;
}

