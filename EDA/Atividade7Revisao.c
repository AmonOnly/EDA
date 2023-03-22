#include <stdio.h>
#include <stdlib.h>
typedef struct nodo
{
    int i;
    struct nodo *link;
}Nodo;
typedef struct descritor
{
    int tamanho;
    Nodo *inicio;
}Descritor;
int insere(Descritor *p, Nodo *novo, int posi );
void Mostrar(Descritor *p);
void criarNodo(Descritor *p);
int reinicia(Descritor *p);
int main(void){
    Descritor *ini = malloc(sizeof(Descritor));
    Nodo *novo = malloc(sizeof(Nodo));
    novo->i = 99;
    ini->inicio = NULL;
    ini->tamanho =0;
    for(int i =0;i < 10;i++){
        criarNodo(ini);
    }
    Mostrar(ini);
    printf("\n");
    /*if (reinicia(ini) == 1)
    {
        printf("Deu tudo certo");
    }*/
    if(insere(ini,novo,13) == 1){
        return 0;
    }else{
        printf("\n");
        Mostrar(ini);
    }
    return 0;
}
void criarNodo(Descritor *p){
    Nodo *aux = malloc(sizeof(Nodo));
    aux->i = p->tamanho;
    aux->link = p->inicio;
    p->inicio = aux;
    p->tamanho += 1;
}
int reinicia(Descritor *p){
    Nodo *aux = NULL;
    if(p->inicio == NULL){
        return 1;
    }
    aux = p->inicio->link;
    for(int i =0; i < p->tamanho-1;i++){
        free(p->inicio);
        p->inicio = aux;
        aux = aux->link;
    }
    p->tamanho = 0;
    p->inicio = NULL;
    return 1;
}
void Mostrar(Descritor *p){
    Nodo *aux = malloc(sizeof(Nodo));
    aux->link = p->inicio;
    if(p->inicio == NULL){
        printf("Vazio");
    }
    printf("\n");
    for(int i =0;i < p->tamanho;i++){
        printf("Numero da Struct = %i\n",aux->link->i);
        aux = aux->link;
    }
}
int insere(Descritor *p, Nodo *novo, int pos){
    Nodo *aux = NULL;
    Nodo *aux2 = NULL;
    aux = p;
   if(p->inicio == NULL){
        printf("Vazio");
        return 1;
    }
    if(pos > p->tamanho){
        printf("numero maior ou igual, caso "
        "faça com o numero maximo ex posição = 10," 
        "o ultimo será retirado");
        return 1;
    }
    for(int i = 0;i<pos-1;i++){
        aux = aux->link;
    }
    aux2 = aux->link;
    novo->link = aux2;
    aux->link = novo;
    return 0;
}
