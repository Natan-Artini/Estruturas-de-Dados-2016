#include<stdlib.h>
#include<stdio.h>

int uniao(int a,int *vetor1,int b,int *vetor2){
	int laco,c=a+b;
	int *vetor3;
	vetor3 = (int*) malloc(c*sizeof(int));
	for(laco=0;laco<a;laco++){
		vetor3[laco]=vetor1[laco];
	}
	for(laco=0;laco<c;laco++){
		vetor3[a+laco]=vetor2[laco];
	}
	for(laco=0;laco<a+b;laco++){
		printf("Vetor 3 [%i] = %i\n",laco,vetor3[laco]);
	}
}

int main(){
	int a,b,laco;
	int *vetor1;
	int *vetor2;
	
	printf("Digite a quantidade de valor para vetor A\n");
	scanf("%i",&a);
	printf("Digite a quantidade de valor para vetor B\n");
	scanf("%i",&b);
	vetor1 = (int*) malloc(a*sizeof(int));
	for(laco=0;laco<a;laco++){
		printf("Digite o %i valor A : ",laco+1);
		scanf("%i",&vetor1[laco]);
	}
	vetor2 = (int*) malloc(b*sizeof(int));
	for(laco=0;laco<b;laco++){
		printf("Digite o %i valor B : ",laco+1);
		scanf("%i",&vetor2[laco]);
	}
	
	uniao(a,vetor1,b,vetor2);
	return(0);
}
