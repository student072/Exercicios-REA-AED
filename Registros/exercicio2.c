#include <stdio.h>
struct Aluno{
    char nome[50];
    int matricula;
    char curso[30];
};

int main(){
    struct Aluno alunos[5];
    int i;
    for(i = 0; i < 5; i++){
        printf("Entre com o nome: ");
        gets(alunos[i].nome);
        fflush(stdin);
        printf("Entre com a matricula: ");
        scanf("%d", &alunos[i].matricula);
        fflush(stdin);
        printf("Entre com o curso: ");
        gets(alunos[i].curso);
    }
    for(i = 0; i < 5; i++){
        printf("\nNome: %s",alunos[i].nome);
        printf("\nMatricula: %d", alunos[i].matricula);
        printf("\nCurso: %s", alunos[i].curso);
    }
    return 0;
}

