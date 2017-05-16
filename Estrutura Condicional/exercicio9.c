#include <stdio.h>

int main(){
    int n;
    /*entrada de dados*/
    printf("Entre com um numero inteiro de 1 a 7: ");
    scanf("%d", &n);
    /*analise de n com o switch*/
      switch(n){
      case 1:
          printf("Domingo");
          break;
      case 2:
           printf("Segunda-feira");
          break;
      case 3:
          printf("Terca-feira");
          break;
      case 4:
          printf("Quarta-feira");
          break;
      case 5:
          printf("Quinta-feira");
          break;
      case 6:
          printf("Sexta-feira");
          break;
      case 7:
          printf("Sabado");
          break;
      default:
        printf("Erro!");
      }
    return 0;
}

