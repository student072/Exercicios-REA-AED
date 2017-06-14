#include <stdio.h>
#include <string.h>
int main(){
    char s1[20];
    int cont = 0;
    scanf("%[^\n]", s1);

    while(s1[cont] !='\0' ){
        if(s1[cont] != 'a' && s1[cont] != 'A' && s1[cont] != 'e' && s1[cont] != 'E' && s1[cont] != 'i' && s1[cont] != 'I' && s1[cont] != 'o' && s1[cont] != 'O' && s1[cont] != 'u' &&s1[cont] != 'U')
            printf("%c", s1[cont]);
        cont++;
    }
    return 0;
}

