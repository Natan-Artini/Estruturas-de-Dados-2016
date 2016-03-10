#include<stdlib.h>
#include<stdio.h>

int main(){
	int contador=0,a;
	int *aloca;
	aloca = (int *) malloc (5*sizeof(int));
	if(aloca==NULL){
		printf("TA BEM LOCO MESMO!! \n ACABO A MEMORIA\n");
		return(0);
	}else{
		do{
			printf("Digite um valor : ");
			scanf("%i",&aloca[contador]);
			contador++;
			if(contador%5==0){
				realloc(aloca,5*sizeof(int));
				if(aloca==NULL){
					printf("TA BEM LOCO MESMO!! \n ACABO A MEMORIA\n");
					return(0);
				}
			}
		}while(aloca[contador-1]!=0);
	}
	for(a=0;a<contador-1;a++){
		printf("Valor em %i = %i\n",a,aloca[a]);
	}
	return(0);
}
