#include<stdlib.h>
#include<stdio.h>
#include "biblioteca.h"

int main(){
	int op=0,retorno;
	Node *temp;
	Fila *fila;
	fila=(Fila*)malloc(sizeof(Fila));
	fila->inicio = fila->fim = inicializa();
	fila->tamanho=0;
	
	while(op!=9){
		system("cls");
		printf("	ESCOLHA UMA OPCAO\n");
		printf("0 - Ver valores da fila\n");
		printf("1 - Adicionar no inicio da fila\n");
		printf("2 - Adicionar no fim da fila\n");
		printf("3 - Adicionar em ordem aleatorio na fila\n");
		printf("4 - Retirar do inicio da fila\n");
		printf("5 - Retirar do fim da fila\n");
		printf("6 - Retirar numero especifico da fila\n");
		printf("7 - Verificar se a fila esta vazia\n");
		printf("8 - Verificar se a fila esta cheia\n");
		printf("9 - SAIR\n");
 			scanf("%i",&op);
		switch(op){
			case 0 :
				retorno = todosfila(fila);
				if(retorno==1)  printf("A FILA ESTA VAZIA\n");
				system("pause");
			break;
			case 1 : 
				if(fila->tamanho==max){
					printf("A FILA JA ESTA CHEIA\n");
					system("pause");
				}else{
					temp = (Node*)malloc(sizeof(Node));
					printf("DIGITE O VALOR : ");
					scanf("%i",&temp->valor);
					temp->antes =NULL;
					temp->prox = NULL;
					addinicio(fila,temp);
					fila->tamanho++;
				}
			break;
			case 2 :
				if(fila->tamanho==max){
					printf("A FILA JA ESTA CHEIA\n");
					system("pause");
				}else{
					temp = (Node*)malloc(sizeof(Node));
					printf("DIGITE O VALOR : ");
					scanf("%i",&temp->valor);
					temp->antes =NULL;
					temp->prox = NULL;
					addfim(fila,temp);
					fila->tamanho++;
				}
			break;
			case 3 :
				if(fila->tamanho==max){
					printf("A FILA JA ESTA CHEIA\n");
					system("pause");
				}else{
					temp = (Node*)malloc(sizeof(Node));
					printf("DIGITE O VALOR : ");
					scanf("%i",&temp->valor);
					temp->antes =NULL;
					temp->prox = NULL;
					addordem(fila,temp);
					fila->tamanho++;
				}
			break;
			case 4 :
				if(fila->inicio==NULL){
					printf("A FILA JA ESTA VAZIA\n");
				}else{
					temp = (Node*)malloc(sizeof(Node));
					temp = retirainicio(fila,temp);
					printf("VALOR RETIRADO : %i\n",temp->valor);
					free(temp);
					temp=NULL;
					fila->tamanho--;
				}
				system("pause");
			break;
			case 5 :
				if(fila->inicio==NULL){
					printf("A FILA JA ESTA VAZIA\n");
				}else{
					temp = (Node*)malloc(sizeof(Node));
					temp = retirafim(fila,temp);
					printf("VALOR RETIRADO : %i\n",temp->valor);
					free(temp);
					temp=NULL;
					fila->tamanho--;
				}
				system("pause");
			break;
			case 6 :
				if(fila->inicio==NULL){
					printf("A FILA JA ESTA VAZIA\n");
				}else{
					printf("DIGITE O VALOR A SER RETIRADO : ");
					scanf("%i",&retorno);
					retorno = retiravalor(fila,retorno);
					if(retorno == 0){
						printf("VALOR RETIRADO COM SUCESSO\n");
						fila->tamanho--;
					}
					else
						printf("VALOR NAO ENCONTRADO\n");
				}
				system("pause");
			break;
			case 7 : retorno=vazia(fila);
				if(retorno==1)  printf("A FILA ESTA VAZIA\n");
				else			printf("A FILA NAO ESTA VAZIA\n");
				system("pause");
			break;
			case 8 : retorno=cheia(fila);
				if(retorno==1)  printf("A FILA ESTA CHEIA\n");
				else			printf("A FILA NAO ESTA CHEIA\n");
				system("pause");
			break;
			case 9 : return(0);
			default : printf("OPCAO INVALIDA\n");system("pause");
		}
	}
}

Node *inicializa(){
	return NULL;
}

int vazia(Fila *fila){
	if(fila->inicio==NULL)
		return(1);
	else
		return(0);
}

int cheia(Fila *fila){
	if(fila->tamanho==max)
		return(1);
	else
		return(0);
}

int todosfila(Fila *fila){
	Node *temp = fila->inicio;
	if(temp==NULL){
		return(1);
	}
	while(temp != NULL){
		printf("Valor : %i\n",temp->valor);
		temp = temp->prox;
	}
	return(0);
}

void addinicio(Fila *fila,Node *novo){
	if(fila->inicio == NULL){
		fila->inicio = novo;
		fila->fim = novo;
	}else{
		fila->inicio->antes = novo;
		novo->prox = fila->inicio;
		fila->inicio = novo;
	}
	return;
}

void addordem(Fila *fila,Node *novo){
	if(fila->inicio == NULL){
		fila->inicio = novo;
		fila->fim = novo;
	}else{
		Node *atual = fila->inicio->prox;
		Node *antes = fila->inicio;
		while(atual != NULL){
			if(atual->valor >= novo->valor){
				antes->prox = novo;
				novo->antes = antes;
				novo->prox = atual;
				atual->antes = novo;
				return;
			}else{
				antes = antes->prox;
				atual = atual->prox;
			}
		}
		antes->prox=novo;
		novo->antes = antes;
		fila->fim=novo;
	}
	return;
}

void addfim(Fila *fila,Node *novo){
	if(fila->inicio == NULL){
		fila->inicio = novo;
		fila->fim = novo;
	}else{
		novo->antes = fila->fim;
		fila->fim->prox = novo;
		fila->fim=novo;
	}
	return;
}

Node *retirainicio(Fila *fila,Node *retirar){
	retirar = fila->inicio;
	fila->inicio = fila->inicio->prox;
	if(fila->inicio == NULL)
		fila->fim=NULL;
	return retirar;
}

int retiravalor(Fila *fila,int valor){
	Node *antes = fila->inicio;
	if(antes->valor == valor){
		fila->inicio = antes->prox;
		free(antes);
		antes=NULL;
	}
	Node *temp = fila->inicio->prox;
	while(temp != NULL){
		if(valor == temp->valor){
			antes->prox = temp->prox;
			temp->prox->antes = antes;
			free(temp);
			temp = NULL;
			return(0);
		}else{
			antes = antes->prox;
			temp = temp->prox;
		}
	}
	return(1);
}

Node *retirafim(Fila *fila,Node *retirar){
	retirar = fila->fim;
	fila->fim = fila->fim->antes;
	if(fila->fim == NULL)
		fila->inicio = NULL;
	return retirar;
}
