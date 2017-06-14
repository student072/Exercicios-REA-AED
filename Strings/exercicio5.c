#include <stdio.h>
int main(){
    char s1[20];
    int cont = 0, qtde_uns = 0;
    scanf("%[^\n]", s1);

    while(s1[cont] !='\0'){
        if(s1[cont] == '1'){
            qtde_uns ++;
        }
        cont++;
    }
    printf("String %s contem %d  1s", s1, qtde_uns);
    return 0;
}


