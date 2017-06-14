#include <stdio.h>
#include <string.h>
int main(){
    char s1[20];
    int cont = 0;
    scanf("%[^\n]", s1);
    cont = strlen(s1);

    while(cont > 0){
        printf("%c", s1[cont-1]);
        cont--;
    }
    return 0;
}



