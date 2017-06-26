#include <stdio.h>


int main(){
    FILE *arq;
    int vogal = 0, consoante = 0;
    int c;
    /*abertura do arquivo*/
    arq = fopen("arq.txt", "r+");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    /*sera executado a leitura de caracteres até qo fim do arquivo*/
    while(feof(arq) == 0){
        /*leitura feita caractere por caractere*/
        c = getc(arq);
		/*contagem das vogais*/
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O'|| c == 'u'|| c == 'U'){
            vogal ++;
			/*contagem das consoantes*/
        }else if(c != ' '&& c!='ÿ' && c != '\n' && c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9')
                consoante ++;
        printf("%c",c);

    }
   printf("\nArquivo tem %d vogais e %d consoantes", vogal, consoante);
    /*fechamento do arquivo*/
    fclose(arq);
    return 0;
}


