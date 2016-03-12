#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int topo=-1;

void empilha(char frase[30],char *frasesaida){
	int laco,laco2,palavras,frase2=0;
	char palavra[topo];
	
	for(laco=0;laco<topo;laco++){
		if(frase[laco]==' ' || frase[laco]=='\n'){
			palavras++;
		}
	}
	
	for(laco=topo;laco>=0;laco--){
		if(frase[laco]==' '){
			for(laco2=laco+1;laco2<topo;laco2++){
				if(frase[laco2]==' '){
					break;
				}else{
					frasesaida[frase2]=frase[laco2];
					frase2++;
				}
			}
			frasesaida[frase2]=' ';
			frase2++;
		}
		if(laco==0){
			for(laco2=laco;laco2<topo;laco2++){
				if(frase[laco2]==' '){
					break;
				}else{
					frasesaida[frase2]=frase[laco2];
					frase2++;
				}
			}
		}
	}
}

int desempilha(char *frasesaida){
	while(topo>=0){
		printf("%c",frasesaida[topo]);
		topo--;
	}
}

int main(){
	char frase[30];
	char frasesaida[30];
	int laco,letras;
	
	strcpy(frase,"ESTE EXERCICIO E MUITO FACIL");
	topo=strlen(frase);
	empilha(frase,&frasesaida[0]);
	desempilha(&frasesaida[0]);
	return(0);
}
