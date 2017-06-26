#include <stdio.h>


int main(){
    FILE *arq;
    char c;
    /*abertura do arquivo*/
    arq = fopen("arq.txt", "w+");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    /*caracteres serão digitados e gravados no arquivo até que 0 seja digitado , nada depois disso será gravado*/
    while(c != '0'){
        scanf("%c",&c);
        if(c!= '0')
            fprintf(arq,"%c", c);
    }
    /*fechamento do arquivo*/
    fclose(arq);
    return 0;
}
