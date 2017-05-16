#include <stdio.h>
float calcula_temperatura(float celsius){
    return celsius *(9.0/5.0) +32.0;
}

int main(){
    float temperatura;
    printf("Entre com a temperatura em celsius: ");
    scanf("%f", &temperatura);
    printf("Temperatura em Fahrenheit: %.2f", calcula_temperatura(temperatura));
    return 0;
}

