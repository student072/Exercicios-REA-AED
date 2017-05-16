#include <stdio.h>

int calcula_segundos(int horas, int minutos, int segundos){
    return minutos * 60 + horas * 3600 + segundos ;
}

int main(){
    int horas, minutos, segundos;
	
    printf("Entre com o numero de horas: ");
    scanf("%d", &horas);
    printf("Entre com o numero de minutos: ");
    scanf("%d", &minutos);
    printf("Entre com o numero de segundos: ");
    scanf("%d", &segundos);
    printf("Total de segundos: %d", calcula_segundos(horas, minutos, segundos));
    return 0;
}

