#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[40];
    int ano_nasc;
};
typedef struct aluno aluno;
int main(){
    int n, i;
    aluno *ptr;
    printf("Entre com o numero de registros a serem alocados: ");
    scanf("%d", &n);
    /*alocando espaço para n iregistros*/
    ptr = (aluno*)malloc(n * sizeof(aluno));

    /*armazeando os n registros no espaço alocado*/
    for(i = 0 ; i < n; i++){
        printf("Numero de matricula: ");
        scanf("%d", &ptr[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", ptr[i].nome);
        printf("Ano de nascimento: ");
        scanf("%d", &ptr[i].ano_nasc);
        printf("\n\n");
    }
    /*mostrando os n registros armazenados*/
    for(i = 0 ; i < n; i++){
        printf("Numero de matricula %d \n", ptr[i].matricula);
        printf("Nome: %s \n" , ptr[i].nome);
        printf("Ano de nascimento: %d\n\n" , ptr[i].ano_nasc);
    }
    /*desalocando o espaço utilizado anteriormente*/
    free(ptr);
    return 0;
}

