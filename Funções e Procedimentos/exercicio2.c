#include <stdio.h>

/*função que mostra a data, utilizando um switch para avaliar o mês,
 recebe como parâmetro dia, mes e ano*/
void mostra_data(int dia, int mes, int ano){
    switch(mes){
    case 1:
        printf("%d de janeiro de %d", dia, ano);
        break;
    case 2:
        printf("%d de fevereiro de %d", dia, ano);
        break;
    case 3:
        printf("%d de marco de %d", dia, ano);
        break;
    case 4:
        printf("%d de abril de %d", dia, ano);
        break;
    case 5:
        printf("%d de maio de %d", dia, ano);
        break;
    case 6:
        printf("%d de junho de %d", dia, ano);
        break;
    case 7:
        printf("%d de julho de %d", dia, ano);
        break;
    case 8:
        printf("%d de agosto de %d", dia, ano);
        break;
    case 9:
        printf("%d de setembro de %d", dia, ano);
        break;
    case 10:
        printf("%d de outubro de %d", dia, ano);
        break;
    case 11:
        printf("%d de novembro de %d", dia, ano);
        break;
    case 12:
        printf("%d de dezembro de %d", dia, ano);
        break;
    default:
        printf("Data errada!");

    }

}

int main(){
    int dia, mes, ano;
	/*entrada de dados*/
    printf("Entre com o dia, mes e ano: ");
    scanf("%d  %d  %d", &dia, & mes, & ano);
	/*chamada da função*/
    mostra_data(dia, mes, ano);
    return 0;
}


