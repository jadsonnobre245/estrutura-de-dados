#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int vet[100];
    int ini;
    int fim;
}Deque;

typedef struct{
  int topo;
  int vet[100];
}Pilha;

Pilha *criapilha(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    p->topo=-1;
    return p;
}

int pilhaisempty(Pilha *p){
    if(p->topo==-1){
        return 1;
    }else{
        return 0;
    }
}

int pilhaisfull(Pilha *p){
    if(p->topo==99){
        return 1;
    }else{
        return 0;
    }
}

Pilha *push(Pilha *p,int v){
    if(!pilhaisfull(p)){
        p->topo++;
        p->vet[p->topo]=v;
        return p;
    }
}

int pop(Pilha *p){
    int v;
    if(!pilhaisfull(p)){
        v=p->vet[p->topo];
         p->topo--;
        return v;
    }
}

Pilha* inverte(Pilha *p){
   int cima;
   int baixo;
   if(p->topo==0){
        return p;
   }
   if(!pilhaisfull(p)){
    cima=pop(p);
    baixo=pop(p);
    p=push(p,cima);
    p=push(p,baixo);
    return p;
   }
}

Deque* criadeque(){
    Deque *d;
    d=(Deque*)malloc(sizeof(Deque));
    d->ini=-1;
    d->fim=-1;
    return d;
}

int dequeisempty(Deque *d){
    if(d->ini==-1&&d->fim==-1){
        return 1;
    }else{
        return 0;
    }
}

int dequeisfull(Deque *d){
    if(d->ini==99||d->fim==99){
        return 1;
    }else{
        return 0;
    }
}
Deque *insereinicio(Deque *d,int v){
 if(dequeisempty(d)){
    d->ini=50;
    d->fim=50;
    d->vet[d->ini]=v;
 }

 if(!dequeisfull(d)){
    d->ini++;
    d->vet[d->ini]=v;
 }else{
    printf("deque xeio");
 }

return d;
}

Deque *inserefim(Deque *d,int v){
if(dequeisempty(d)){
    d->ini=50;
    d->fim=50;
    d->vet[d->fim]=v;
 }
 if(!dequeisfull(d)){
    d->fim--;
    d->vet[d->fim]=v;
 }else{
    printf("deque xeio");
 }
return d;
}

int removeinicio(Deque *d){
    int v;
    if(!dequeisempty(d)){
    v=d->vet[d->ini];
    d->ini--;
    }
   return v;
}

int removefim(Deque *d){
    int v;
    if(!dequeisempty(d)){
    v=d->vet[d->fim];
    d->fim++;
    }
   return v;
}

Deque *troca(Deque *d){
    int inicio,fim;
    if(!dequeisempty(d)){
        inicio=removeinicio(d);
        fim=removefim(d);
        d=insereinicio(d,fim);
        d=inserefim(d,inicio);
    }else if(d->ini==50&&d->fim==50){
        return d;
    }
return d;
}

int main()
{
    Pilha d;
    Pilha *Pd;
    Pd=&d;
    Pd=criapilha();
    Pd=push(Pd,5);
     Pd=push(Pd,3);
     Pd=inverte(Pd);
    printf("%d",Pd->vet[Pd->topo]);

    return 0;
}
