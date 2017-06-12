#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*definição da estrutura que representará  cada elemento da árvore binária
   será uma árvore que armazenará inteiros*/
struct ARVORE{
	int num;
	struct ARVORE *esq, *dir; /*ponteiros para fazer a ligação entre nós a esquerda e a direita*/
};
typedef struct ARVORE Arvore;

/*definição do estrutura que irá representar cada elemento da árvore em um pilha*/
struct PILHA{
	struct ARVORE *num;
	struct PILHA *prox;
};
typedef struct PILHA Pilha;

/*ponteiro que irá apontar para a raiz da árvore, inicialamente ela está vazia, logo aponta para NULL*/
Arvore *raiz = NULL;

/*ponteiros auxiliares*/
Arvore *aux;
Arvore *aux1;
Arvore *novo;
Arvore *anterior;

/*ponteiros para utilização da pilha*/
Pilha *topo;
Pilha *aux_pilha;


void insere_elemento(){
		/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
		Arvore *novo =(Arvore*) malloc(sizeof(Arvore));
		printf("Digite o numero a ser inserido na arvore: ");
		scanf("%d",&novo->num);
		novo->esq = NULL;
		novo->dir = NULL;
		/*caso a árvore esteja vazia, o elemento inserido será a raiz */
		if(raiz == NULL){
			raiz = novo;
		/*caso a árvore  já contenha algum elemento*/
		}else{
			/*variável para verificação*/
		    int achou;
			/*aux aponta para o mesmo endereço de raiz*/
			aux = raiz;
			achou = 0;
			/*é feita uma busca em toda árvore para saber onde novo deve ser enserido*/
			while(achou == 0){
				/*caso o novo numero a ser inserido seja menor que aux-> num*/
				if(novo->num < aux->num){
					/*caso não aja nenhum elemento a esquerda de aux, novo será inserido a esquerda dele*/
					if(aux->esq == NULL){
						aux->esq = novo;
						achou = 1;
					/*caso já exista um elemento a esquerda de aux, aux  aponta para este elemento  e uma nova iteração será realizada*/
					}else{
						aux = aux->esq;
					}
				/*caso o novo numero a ser inserido seja maior ou igual a aux-> num*/
				}else if(novo->num >= aux->num){
					/*caso não aja nenhum elemento a direita de aux, novo será inserido a direita dele*/
					if(aux->dir == NULL){
						aux->dir = novo;
						achou = 1;
					}else{
						/*caso já exista um elemento a direita de aux, aux  aponta para este elemento  e uma nova iteração será realizada*/
						aux = aux->dir;
					}
				}
			}
		}
		printf("\nNumero inserido na arvore!");
		getch();
}
void consulta_no(){
	/*caso a árvore esteja vazia*/
	if(raiz == NULL){
		printf("\nArvore Vazia!!");
	}else{
	    int numero, achou;
		printf("Digite o numero a ser consultado: ");
		scanf("%d", &numero);
		achou = 0;
		/*aux aponta para o mesmo endereço de raiz*/
		aux = raiz;
		/*enquanto aux não apontar para NULL e achou for igual a 0 será feita uma busca na árvore*/
		while(aux != NULL && achou == 0){
			/*caso aux-> seja igual o número buscado*/
			if(aux->num == numero){
				printf("Numero %d encontrado!", numero);
				achou = 1;
			/*do contrário verificamos se o número está a direita ou a esquerda de aux->num e atualizamos aux*/
			}else if(numero < aux->num){
				aux = aux->esq;
				}else{
					aux = aux->dir;
				}

        }
        if(achou == 0) printf("Número não encontrado!");
    }

	getch();
}

/*consulta em ordem mostra os nós na seguinte ordem
	1° ramo da esquerda
	2° raiz
	3° ramo da direita													*/
void consulta_arvore_ordem(){
	/*caso a árvore esteja vazia*/
	if(raiz == NULL){
		printf("\nArvore Vazia!!");
	/*caso a árvore contenha elementos*/
	}else{
		/*aux aponta para o endereço de raiz*/
		aux = raiz;
		/*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
		topo = NULL;
		do{
			/*caminha pela árvore pelo ramo da esquerda até NULL, colocando cada elemento visitado na pilha */
			while(aux != NULL){
				/*alocamos um espaço para inserir o elemento a ser mostrado na pilha*/
                Pilha *aux_pilha =(Pilha*) malloc(sizeof(Pilha));
				/*a pilha recebe o elemento apontado por auix*/
				aux_pilha->num = aux;
				/*para encadear os elementos da pilha, aux_pilha->prox aponta para o topo da pilha*/
				aux_pilha->prox = topo;
				/*o topo da pilha apontará para o elemento que está sendo inserido na pilha*/
				topo = aux_pilha;
				/*aux aponta para o elemento a esquerda do aux atual*/
				aux = aux->esq;
			}
			/*imprimiremos aos elementos empilhados no momento a partir do topo */
			if(topo != NULL){
				aux_pilha = topo;
				printf("%d ", aux_pilha->num->num);
				/*caso aja um elemento a direita do elemento apontado por topo na árvore, seu prox será NULL, portanto ao encontrar 
				um elemento a direita do elemento impresso retornaremos ao while anterior antes de imprimir o restante da pilha*/
				aux = topo->num->dir;
				topo = topo->prox;
				free(aux_pilha);
			}
		}while(topo != NULL || aux != NULL);
	}
	getch();
}

/*consulta em pré-ordem mostra os nós na seguinte ordem
	1° raiz
	2° ramo da esquerda
	3° ramo da direita													*/
void consulta_arvore_pre_ordem(){
	/*caso a árvore esteja vazia*/
	if(raiz == NULL){
		printf("\nArvore Vazia!!");
	/*caso a árvore contenha elementos*/
	}else{
		/*aux aponta para o endereço de raiz*/
		aux = raiz;
		/*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
		topo = NULL;
		do{
			/*caminha pela árvore mostrando cada elemento visitado, e também coloca cada elemento visitado na pilha */
			while(aux != NULL){
				/*alocamos um espaço para inserir um elemento na pilha*/
                Pilha *aux_pilha =(Pilha*) malloc(sizeof(Pilha));
				/*impressão do elemento apontado por aux*/
				printf("%d ", aux->num);
				/*colocamos na pilha o elemento impresso*/
				aux_pilha->num = aux;
				aux_pilha->prox = topo;
				topo = aux_pilha;
				/*fazemos com que aux aponte para o elemento a sua esquerda*/
				aux = aux->esq;
			}
			if(topo != NULL){
				aux_pilha = topo;
				topo = topo->prox;
				/*aux aponta para o elemento a direita de topo na árvore*/
				aux = aux_pilha->num->dir;


			}
		}while(topo != NULL || aux != NULL);
	}
	getch();
}
void consulta_arvore_pos_ordem(){
	/*caso a árvore esteja vazia*/
	if(raiz == NULL){
		printf("\nArvore Vazia!!");
	/*caso a árvore contenha elementos*/
	}else{
		/*aux aponta para o endereço de raiz*/
		aux = raiz;
		/*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
		topo = NULL;
		do{
            do{
				/*caminha pela árvore pelo ramo da esquerda até NULL, colocando cada elemento visitado na pilha, além disso
				   antes de colocar a raiz de cada sub-árvore na pilha também caminha no ramo da direita*/
                while(aux != NULL){
					/*alocamos um espaço para inserir um elemento na pilha*/
                    Pilha *aux_pilha =(Pilha*) malloc(sizeof(Pilha));
					/*a pilha recebe o elemento apontado por auix*/
                    aux_pilha->num = aux;
					/*para encadear os elementos da pilha, aux_pilha->prox aponta para o topo da pilha*/
                    aux_pilha->prox = topo;
					/*o topo da pilha apontará para o elemento que está sendo inserido na pilha*/
                    topo = aux_pilha;
					/*aux aponta para o elemento a esquerda do aux atual*/
                    aux = aux->esq;
                }
				/*caso o exista um elemento a direita do endereço apontado por topo na árvore, aux aponta para esse elemento*/
                if(topo->num->dir != NULL){
                    aux = topo->num->dir;
                }
            }while(aux != NULL);
            if(topo!= NULL){
				/*imprime o elemento apontado por topo*/
                printf("%d ", topo->num->num);
				/*se ainda existirem elementos na pilha além de topo*/
                if(topo->prox != NULL){
					/*caso o exista um elemento a direita do endereço apontado por topo na árvore e esse elemento seja diferente de topo,
					aux apontara para esse elementoe topo apontará para o próximo elemento da pilha*/
                    if(topo->prox->num->dir != NULL && topo->prox->num->dir != topo->num){
                        aux = topo->prox->num->dir;
                        topo = topo->prox;
					/*caso o exista um elemento a direita do endereço apontado por topo na árvore e esse elemento seja igual a topo,
						topo apontará para o próximo elemento da pilha e este será  impresso*/
                    }else{
						/*caso o exista um elemento a direita do endereço apontado por topo na árvore e esse elemento seja igual a topo,
						topo apontará para o próximo elemento da pilha e este será  impresso*/
                        while(topo->prox != NULL && topo->prox->num->dir == topo->num){
                            topo = topo->prox;
                            printf("%d ", topo->num->num);
                        }
						/*topo apontará para o próximo elemento da pilha*/
                        topo = topo->prox;
						/*se topo não for null aux aponta para o elemento a direita do endereço apontado por topo na árvoree*/
                        if(topo != NULL){
                            aux  = topo->num->dir;
						/*caso contrário aux recebe NULL*/
                        }else{
                            aux = NULL;
                        }
                    }
				/*se topo igual a NULL*/
                }else{
                    topo = topo->prox;
                    aux = NULL;
                }
            }
		}while(topo != NULL || aux != NULL);

    }
getch();
}
void remove_elemento(){
	/*caso a árvore esteja vazia*/
	if(raiz == NULL){
		printf("\nArvore Vazia!!");
	/*caso a árvore contenha elementos*/
	}else{
	    int numero, achou;
		printf("Digite o numero a ser removido da arvore: ");
		scanf("%d", &numero);
		/*aux aponta para o endereço de raiz*/
		aux = raiz;
		achou = 0;
		/*varre toda a árvore a procura do número a ser removido*/
		while(aux != NULL && achou == 0){
			if(aux->num == numero){
				achou = 1;
			}else if(aux->num > numero){
				aux = aux->esq;
				}else{
					aux = aux->dir;
				}

        }
		/*caso o número não seja encontrado*/
        if(achou == 0){
            printf("Numero nao encontrado!");
		/*caso o número seja encontrado*/
        }else{
			/*caso o número a ser removido não seja a raiz*/
            if(aux != raiz){
                anterior = raiz;
				/*aqui procura-se o número anterior ao número a ser removido, o endereço deste será armazenado em anteirior*/
                while(anterior->dir != aux && anterior->esq != aux){
                    if(anterior->num > numero){
						/*o número esta a esqueda da árvore*/
                        anterior = anterior->esq;
                    }else{
						/*o número esta a direita da árvore*/
                        anterior = anterior->dir;
                    }
                }
				/*se o nó a ser removido for um nó folha*/
                if(aux->dir == NULL && aux->esq == NULL){
						/*se o nó a ser removido esta a direita de aux*/
                        if(anterior->dir == aux){
                            anterior->dir = NULL;
						/*se o nó a ser removido esta a esquerda de aux*/
                        }else{
                            anterior->esq = NULL;
                        }
                    free(aux);
				/*se o nó a ser removido for um nó não folha*/
                }else{
					/*se o nó a ser removido tiver apenas filho a direita*/
                    if(aux->dir != NULL  && aux->esq == NULL){
						/*se o nó a ser removido estiver a esquerda de anterior*/
                        if(anterior->esq == aux){
                            anterior->esq = aux->dir;
						/*se o nó a ser removido estiver a direita de anterior*/
                        }else{
                            anterior->dir = aux->dir;
                        }
                        free(aux);
					/*se o nó a ser removido tiver apenas filho a esquerda*/
                    }else if(aux->esq != NULL && aux->dir == NULL){
						/*se o nó a ser removido estiver a esquerda de anterior*/
                        if(anterior->esq == aux){
                            anterior->esq = aux->esq;
						/*se o nó a ser removido estiver a direita de anterior*/
                        }else{
                            anterior->dir = aux->esq;
                        }
                        free(aux);
					/*se o nó a ser removido tiver filho a direita e a esquerda*/
                    }else if(aux->esq != NULL && aux->dir != NULL){
						/*se o nó a ser removido estiver a direita de anterior*/
                        if(anterior->dir == aux){
                            anterior->dir = aux->dir;
							/*o nó a esquerda do nó a ser removido fica apontado por aux1*/
                            aux1 = aux->esq;
						/*se o nó a ser removido estiver a esquerda de anterior*/
                        }else{
                            anterior->esq = aux->dir;
							/*o nó a direita do nó a ser removido fica apontado por aux1*/
                            aux1 = aux->esq;
                        }
                        free(aux);
						/*aux aponta para anteirior*/
                        aux = anterior;
						/*realocando o pedaço da árvore*/
                        while(aux != NULL){
							/*caso aux seja menor, que aux1*/
                            if(aux->num < aux1->num){
								/*caso aux não tenha filho a direita*/
                                if(aux->dir == NULL){
                                    aux->dir = aux1;
                                    aux = NULL;
								/*caso aux tenha filho a direita*/
                                }else{
                                    aux = aux->dir;
                                }
							/*caso aux seja maior, que aux1*/
                            }else if(aux->num > aux1->num){
								/*caso aux não tenha filho a esquerda*/
                                if(aux->esq == NULL){
                                    aux->esq = aux1;
                                    aux = NULL;
								/*caso aux tenha filho a esquerda*/
                                }else{
                                    aux = aux->esq;
                                }
                            }
                        }
                    }
                }
			/*caso o número a ser removido não seja a raiz*/
            }else{
				/*se o nó a ser removido for raiz e folha*/
                if(aux->dir == NULL && aux->esq == NULL){
                    free(aux);
                    raiz = NULL;
                }else{
					/*se o nó a ser removido tiver apenas filho a direita*/
                    if(aux->dir != NULL && aux->esq == NULL){
                        raiz = aux->dir;
                        free(aux);
					/*se o nó a ser removido tiver apenas filho a esquerda*/
                    }else if(aux->esq != NULL && aux->dir == NULL){
                        raiz = raiz->esq;
                        free(aux);
					/*se o nó a ser removido tiver filho a direita e a esquerda*/
                    }else if(aux->dir != NULL && aux->esq != NULL){
                        raiz = aux->dir;
                        aux1 = aux->esq;
                        free(aux);
                        aux = raiz;
						/*realocando o pedaço da árvore*/
                        while(aux != NULL){
							/*caso aux seja menor, que aux1*/
                            if(aux->num < aux1->num){
								/*caso aux não tenha filho a direita*/
                                if(aux->dir == NULL){
                                    aux->dir = aux1;
                                    aux = NULL;
								/*caso aux tenha filho a direita*/
                                }else{
                                    aux = aux->dir;
                                }
							/*caso aux seja maior, que aux1*/
                            }else if(aux->num > aux1->num){
								/*caso aux não tenha filhos a esquerda*/
                                if(aux->esq == NULL){
                                    aux->esq = aux1;
                                    aux = NULL;
								/*caso aux tenha filhos a esquerda*/
                                }else{
                                    aux = aux->esq;
                                }
                            }
                        }
                    }
                }
            }
            printf("Numero excluido da Arvore!");
        }
	}
	getch();
}
void esvaziar_arvore(){
	/*caso a árvore esteja vazia*/
	if(raiz == NULL){
		printf("\nArvore Vazia!!");
	/*caso a árvore contenha elementos*/
	}else{
		/*aux aponta para o endereço de raiz*/
	    aux = raiz;
		/*como aqui utilizaremos uma pilha, incializamos seu topo com null*/
	    topo = NULL;
	    do{
	        while(aux != NULL){
                Pilha *aux_pilha =(Pilha*) malloc(sizeof(Pilha));
				/*impressão do elemento apontado por aux*/
                printf("%d ", aux->num);
				/*colocamos na pilha o elemento impresso*/
                aux_pilha->num = aux;
                aux_pilha->prox = topo;
                topo = aux_pilha;
				/*fazemos com que aux aponte para o elemento a sua esquerda*/
                aux = aux->esq;
	        }
	        if(topo != NULL){
                aux_pilha = topo;
                topo = topo->prox;
				/*aux aponta para o elemento a direita de topo na árvore*/
                aux = aux_pilha->num->dir;
	        }

	    }while(topo != NULL || aux != NULL);

	    aux_pilha = topo;
		/*passagem por todos os elementos da pilha e removendo cada um deles*/
	    while(aux_pilha != NULL){
            topo = topo->prox;
            free(topo->num);
            free(aux_pilha);
            aux_pilha = topo;
	    }
	    raiz = NULL;
	    printf("\nArvore esvaziada");

	}
	getch();
}




int main(){
	 int op;
    while(1){
        system("CLS");
        printf("\nEscolha a opcao desejada ");
        printf("\n1- Inserir na arvore ");
        printf("\n2- Consultar um no da arvore ");
        printf("\n3- Consultar arvore em ordem");
		printf("\n4- Consultar arvore em pre-ordem");
		printf("\n5- Consultar arvore em pos-ordem");
		printf("\n6- Excluir um no da arvore ");
        printf("\n7- Esvaziar arvore: \n");
        scanf("%d",&op);
        switch(op){
        case 1:
            insere_elemento();
            break;
        case 2:
            consulta_no();
            break;
        case 3:
           consulta_arvore_ordem();
            break;
        case 4:
            consulta_arvore_pre_ordem();
            break;
		case 5:
            consulta_arvore_pos_ordem();
            break;
		case 6:
            remove_elemento();
            break;
		case 7:
            esvaziar_arvore();
            break;
        default:
            exit(1);
        }
    }
	return 0;
}
