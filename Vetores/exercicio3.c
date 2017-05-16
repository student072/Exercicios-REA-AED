#include <stdio.h>
#include <math.h>

int main(){
    int vet1[10], vet2[10], i;
    for(i = 0; i < 10; i++){
        scanf("%d", &vet1[i]);
    }
    for(i = 0; i < 10; i++){
        vet2[i] = pow(vet1[i],2);
    }
    for(i = 0; i < 10; i++){
        printf("%d --- %d\n", vet1[i], vet2[i]);
    }
    return 0;
}
