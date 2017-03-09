#include <stdio.h>
int main(){
    /*declaração das variáveis*/
    float g1,g2, g3;
    /*cálculos da premiação de cada ganhador*/
    g1 = 780000.00 * 0.46;
    g2 = 780000.00 * 0.32;
    g3 = 780000.00 - g1 - g2;
    /*saída de dados*/
    printf("Premiacao:");
    printf("\nGanhador 1 = %.2f ", g1);
    printf("\nGanhador 2 = %.2f ", g2);
    printf("\nGanhador 3 = %.2f ", g3);
    return 0;
}

