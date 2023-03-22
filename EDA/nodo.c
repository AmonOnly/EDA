#include <stdio.h>
#include <stdlib.h>
struct nodo{
    int x;
    struct nodo *link;
    };
int contaNodo(struct nodo (*p));
int main(void){
    struct nodo a = {10,NULL};
    struct nodo b = {21,&a};
    struct nodo c = {21,(&b)};
    struct nodo d = {21,(&c)};
    struct nodo e = {21,(&d)};
    struct nodo f = {21,(&e)};
    struct nodo g = {21,(&f)};
    struct nodo h = {21,(&g)};
    struct nodo i = {21,(&h)};
    char k;
    printf("Digite o nodo que quer calcular:\n");
    scanf("%c",&k);
    printf("o numero de nodos será %i\n",contaNodo(&i));
    return 0;
}

int contaNodo(struct nodo (*p)){
    int a=1;
    struct nodo *aux = p;
    if(aux->link == NULL){
        return a;
    }
    while (aux->link != NULL)
    {
        aux = (aux->link);
        a++;
    }
    return a;
    
}