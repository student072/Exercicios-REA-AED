#include <stdio.h>
int main(){
    char frase[20];
    int cont = 0;
    scanf("%[^\n]", frase);

    while(frase[cont] !='\0'){
        cont++;
    }
    printf("String %s tem %d de comprimento", frase, cont);
    return 0;
}
