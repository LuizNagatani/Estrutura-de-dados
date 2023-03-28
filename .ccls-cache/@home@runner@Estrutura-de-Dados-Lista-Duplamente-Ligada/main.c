#include <stdio.h>

typedef struct Nodo {
int info;
struct Nodo *ant;
struct Nodo *prox;
} nodo;

nodo*insereComeco(nodo*lista, int x){
nodo*novo = (nodo*)malloc(sizeof(nodo));
  novo->prox = lista;
  novo->ant = NULL;
  novo->info = x;
if (lista != NULL)
  lista -> ant = novo;
    return novo;
}
void insereapos(nodo *r, int x) {
nodo *prox = r->prox;
nodo *novo = (nodo *)malloc(sizeof(nodo));
novo->info = x;
novo->ant = r;
novo->prox = prox;
  if (prox != NULL) 
prox->ant = novo;
r->prox = novo;
}
void removeNodo(nodo*r){
if(r->ant != NULL)
  r->ant->prox = r->prox;
  if(r->prox != NULL)
    r->prox->ant = r->ant;
  free(r);

  
}

int main() {
nodo *lista = NULL;
lista = insereComeco(lista, 10);

  insereapos(lista, 52);
  insereapos(lista->prox, 32);
  removeNodo(lista);



  return 0;
}