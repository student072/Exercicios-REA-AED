#include <stdio.h>
int main(){
    char s1[20], s2[20];
    int cont = 0, dif = 0;
    scanf("%[^\n]", s1);
    getchar();
    scanf("%[^\n]", s2);

    while(s1[cont] !='\0' && s2[cont]!='\0'&& dif == 0){
        if(s1[cont] != s2[cont]){
            printf("Strings diferentes!!");
            dif = 1;
        }
        cont++;
    }
    if(dif == 0)
        printf("String %s e %s sao iguais", s1,s2);
    return 0;
}

