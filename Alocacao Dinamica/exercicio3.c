#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    char *ptr;

    printf("Entre com o tamanho da string: ");
    scanf("%d", &n);

    /*alocando espaço para n inteiros*/
    ptr = (char*)malloc(n * sizeof(char));

    printf("Digite a string: ");
    scanf(" %[^\n]", ptr);
    i = 0;
    /*mostrando a string sem vogais*/
    while(ptr[i] != '\0'){
        if(ptr[i]!= 'a' && ptr[i]!= 'A' && ptr[i]!= 'e' && ptr[i]!= 'E' && ptr[i]!= 'i' && ptr[i]!= 'I' && ptr[i]!= 'o' && ptr[i]!= 'O' && ptr[i]!= 'u' && ptr[i]!= 'U')
            printf("%c  ", ptr[i]);
            i++;
    }
    /*desalocando o espaço utilizado anteriormente*/
    free(ptr);
    return 0;
}

