//padrao matheus
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
	int info;
	struct Nodo *prox;
}Nodo;

void inserir(Nodo**,Nodo**,int);
int retirar(Nodo**);
void imprimir(Nodo**);
 
main(){
	
	Nodo *inicio=NULL;
	Nodo *fim;
	int n;
	char op;
	
	for(;;){
		printf("[1]inserir [2]remover [3]mostrar [4]exit \n ");
		scanf("%c",&op);
		
		switch(op){
			case '1':
				printf("digite numero que deseja inserir \n");
				scanf("%i",&n);
				inserir(&inicio,&fim,n);
				break;
			case '2':
				printf("\n");
				retirar(&inicio);
				printf("\n");
				break;
			case '3':
				printf("\n");
				printf("Itens de sua Fila:\n");
				imprimir(&inicio);
				printf("\n");
				break;
			case '4':
				exit(1);
				break;
		}
	}	
}

void inserir(Nodo**inicio,Nodo**fim,int n){
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo));
	if(novo==NULL)exit(99);
	
	if(*inicio==NULL){
		*inicio=novo;
	}
	else{
		(*fim)->prox=novo;
	}
	*fim=novo;
	novo->info=n;
	novo->prox=NULL;
	

}
int retirar(Nodo**inicio){
	int n;
	Nodo*aux;
	if(!*inicio){
		printf("pilha vazia\n ");
		return 0;
	}
	aux=*inicio;
	n=aux->info;
	*inicio=(*inicio)->prox;
	free(aux);
	return(n);
	
	
}
void imprimir(Nodo**inicio){
	Nodo *aux;
	aux=*inicio;
	while(aux!=NULL){
		printf("[%i]",aux->info);
		printf("\n");
		aux=aux->prox;
	}

}
