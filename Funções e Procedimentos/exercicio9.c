#include <stdio.h>
int calcula_somatorio(int num){
    int somatorio = 0, i;
    for(i = 1;i <= num ;i++){
        somatorio += i;

    }
    return somatorio;
}

int main(){
    int num;
    scanf("%d", &num);
    printf("Somatorio de 1 ate %d: %d", num, calcula_somatorio(num));
    return 0;
}


