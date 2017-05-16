#include <stdio.h>
#include <math.h>
int fibonacci(int n){
    if(n == 1)
        return 0;
    else if(n == 2 || n == 3)
            return 1;
          else
                return fibonacci(n - 1) + fibonacci(n - 2);
}


int main(){
    int n;
    printf("Entre com n: ");
    scanf("%d", &n);
    printf("%d termo de fibonacci = %d", n,fibonacci(n));
    return 0;
}

