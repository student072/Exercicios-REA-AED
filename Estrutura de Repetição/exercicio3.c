#include <stdio.h>

int main(){
	/*declaração da variável inteira*/
    int num;
	/*for imprimirá de 1000 em 1000 até 10000
	  começando de 0
	*/
    for(num = 0; num <= 100000; num+= 1000){
        printf("%d\n",num);
    }
    return 0;
}

