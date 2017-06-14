#include <stdio.h>
struct pessoa{
    char nome[50];
    int idade;
    char endereco[80];
};

int main(){
    struct pessoa p1;
    printf("Entre com o nome: ");
    gets(p1.nome);
    fflush(stdin);
    printf("Entre com a idade: ");
    scanf("%d", &p1.idade);
    fflush(stdin);
    printf("Entre com o endereco: ");
    gets(p1.endereco);
    printf("\nNome: %s", p1.nome);
    printf("\nIdade: %d", p1.idade);
    printf("\nEndereco: %s", p1.endereco);
    return 0;
}
