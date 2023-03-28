#include <stdlib.h>.h>
  
typedef struct Nodo {
  int info; // informacão contida no nodo
  struct Nodo *prox; // ponteiro p/ o proximo nodo (ou NULL)
} nodo;

nodo* inseref(nodo *lista , int x){
  if (lista == NULL){
  lista = (nodo *)malloc(sizeof(nodo)); // utiliza o malloc p/ criar um novo nodo chamado "novo" 
  lista->info = x; // setinha em vez de ponto pq é um ponteiro/ armazena a informação no nodo "novo"
  lista->prox = NULL; // indica que o seu próximo é a lista recebida
    return lista;
  }
else{
  lista->prox= inseref(lista->prox, x);
    return lista;
}
}
void imprime (nodo*lista){ //iterativo
  nodo* aux = lista; 
  while(aux != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}
void contrario(nodo*lista){
   if( lista==NULL)
        return;
    contrario(lista->prox);
    printf("%d ", lista->info);
}

libera(nodo *lista) {
if (lista == NULL) return;
libera(lista->prox);
free(lista);
  
}
int main() {
  nodo *lista = NULL;
  int comando;
  
  while(comando != -1){
    scanf("%d", &comando);
    if (comando!= -1){
    lista = inseref(lista, comando);
    }
  }
  imprime(lista);
  contrario(lista);
  libera(lista);
  return 0;
}