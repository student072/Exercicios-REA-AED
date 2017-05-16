#include <stdio.h>

int main(){
    int vet[10],i, pos_maior, pos_menor, menor, maior;
    for(i = 0; i < 10; i++){
        scanf("%d", &vet[i]);
    }
    menor = vet[0];
    maior = vet[0];
    pos_maior = 0;
    pos_menor = 0;
    for(i = 1; i < 10; i++){
       if(vet[i] > maior){
            maior = vet[i];
            pos_maior = i;
       }
       if(vet[i] < menor){
            menor = vet[i];
            pos_menor = i;
       }
    }
    printf("\nMaior numero: %d  Posicao: %d ", maior, pos_maior);
    printf("\nMenor numero: %d  Posicao: %d ", menor, pos_menor);
    return 0;
}

