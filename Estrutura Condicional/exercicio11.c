#include <stdio.h>

int main(){
    int idade, tempo_servico;

    /*entrada de dados*/
    printf("Entre com a idade: ");
    scanf("%d", &idade);
    printf("Entre com o tempo de servico: ");
    scanf("%d", &tempo_servico);
    /*se a idade for >= a 65 e tempo de serviço >= 30 ou idade>=60 e tempo de servico 
	  >= a 25 a aposentadoria é possível */
    if(idade >= 65 || tempo_servico >= 30 || (idade>=60 && tempo_servico >=25)){
        printf("Pode se aposentar");
    }else {
        printf("Nao pode ser aposentar");
    }
    return 0;
}

