#include <stdio.h>
int somatorio(int n){
    if(n == 1)
        return n;
    else
        return n + somatorio(n-1);
}


int main(){
    int n;
    printf("Entre com n: ");
    scanf("%d", &n);
    printf("Somatorio de 1 ate %d = %d", n,somatorio(n));
    return 0;
}
