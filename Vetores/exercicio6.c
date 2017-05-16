#include <stdio.h>

int main(){
    int vet[6],i;
    for(i = 0; i < 6; i++){
        scanf("%d", &vet[i]);
    }
    for(i = 5; i >= 0; i--){
       printf("%d ", vet[i]);
    }

    return 0;
}

