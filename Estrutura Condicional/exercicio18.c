#include <stdio.h>

int main(){
    int codigo, quantidade;

    /*entrada de dados*/
    printf("Entre com o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Entre com  quantidade do produto: ");
    scanf("%d", &quantidade);
    /*analise de codigo com o switch
	  a operação quantidade * preço é feita no printf
	*/
      switch(codigo){
      case 100:
          printf(" %d Cachorro Quente: %.2f", quantidade, quantidade * 1.20);
          break;
      case 101:
          printf(" %d Bauru Simples: %.2f", quantidade, quantidade * 1.30);
          break;
      case 102:
         printf(" %d Bauru com Ovo: %.2f", quantidade, quantidade * 1.50);
          break;
      case 103:
          printf(" %d Hamburguer: %.2f", quantidade, quantidade * 1.20);
          break;
      case 104:
          printf(" %d Cheeseburger: %.2f", quantidade, quantidade * 1.70);;
          break;
      case 105:
          printf(" %d Suco: %.2f", quantidade, quantidade * 2.20);
          break;
      case 106:
          printf(" %d Refrigerante: %.2f", quantidade, quantidade * 1.00);
          break;
      default:
        printf("Codigo inexistente!");
      }
    return 0;
}


