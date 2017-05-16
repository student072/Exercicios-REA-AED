#include <stdio.h>

int main(){
	/*letra a*/
    int A[6] = {1,0,5,-2,-5,7};
    int soma, i;
	
	/*letra b*/
    soma = A[0] + A[1] + A[5];
    printf("Soma: %d\n\n",soma);
	
	/*letra c*/
    A[4] = 100;
	
	/*letra d*/
    for(i = 0; i < 6; i++)
        printf("%d\n",A[i]);
    return 0;
}
