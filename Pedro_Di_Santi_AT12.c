/*
  Arquivo: Pedro_Di_Santi_AT12.c
  Autor:
    Pedro Afonso Rotta Di Santi (RA00218666)
    Lucas Pavani Mendes (RA00167455)
    Lucas Vasconcellos Coutinho (RA00167383)
    Douglas Gomi (RA00127809)
  Data: 21/08/2020 09:51:20
  Descrição:
    Este programa tem como finalidade explorar a manipulação de uma Árvore Binária. Ela implementa a criação de uma
        uma nova árvore, onde elementos pré-definidos estão inseridos.
    Além disso, implementamos uma estrutura que aponta para o pai dos nós e mostra o caminhamento bfs e quais os pais dos
        nós.
*/

#include <stdio.h>
#include <stdlib.h>

#include "Booleano.h"
#include "FilaPointer.h"

typedef struct No{
    int elemento;
    struct No *pai;
    struct No *esq;
    struct No *dir;
} No;

typedef No *Arvore;

Arvore construirArvore(int, Arvore, Arvore); //Monta uma árvore usando valor de um char.
void mostrarArvore(Arvore); //Função para realizar o caminhamento bfs.
void colocarPai(Arvore); //Função para apontar para o pai do Nó.

int main(){
    Arvore arvore, subArvore1, subArvore2, a, b, c;

    a = construirArvore(1, NULL, NULL);
    b = construirArvore(3,NULL,NULL);
    c = construirArvore(2, a, b);
    subArvore1 = c;

    a = construirArvore(5, NULL, NULL);
    b = construirArvore(7,NULL,NULL);
    c = construirArvore(6, a, b);
    subArvore2 = c;

    printf("\n 4  2  6  1  3  5  7\n\n");

    arvore = construirArvore(4, subArvore1, subArvore2);

    colocarPai(arvore);

    mostrarArvore(arvore);
}

Arvore construirArvore(int elemento, Arvore e, Arvore d){
    No *novo, *raiz;

    novo = malloc(sizeof(No));
    novo->elemento = elemento;

    novo->esq = e;
    novo->dir = d;
    raiz = novo;

    return raiz;
}

void mostrarArvore(Arvore ap){
    No *p; Fila f;
    if (ap == NULL) printf("\n arvore vazia \n");
    else {
        criarFilaVazia(&f); p = ap; pushFila(&f,p);
        do {
            p = acessarFila(&f);
            if (p->pai == NULL)
                printf(" No = %d    nao tem pai\n", p->elemento);
            else
                printf(" No = %d    pai = %d\n",p->elemento, p->pai->elemento);
            popFila(&f);
            if (p->esq != NULL) pushFila(&f,p->esq);
            if (p->dir != NULL) pushFila(&f,p->dir);
        } while (verFilaVazia(&f) == FALSE);
    }
}

void colocarPai(Arvore ap) {
    No *p;
    Fila f;

    if (ap == NULL)
        printf("\n arvore vazia \n");
    else {
        criarFilaVazia(&f);
        p = ap;
        pushFila(&f,p);
        do {
            p = acessarFila(&f);
            popFila(&f);
            if (p->esq != NULL && p->dir != NULL){
                p->esq->pai = p;
                p->dir->pai = p;
            }
            if (p->esq != NULL)
                pushFila(&f,p->esq);
            if (p->dir != NULL)
                pushFila(&f,p->dir);
        } while (verFilaVazia(&f) == FALSE);
    }
}





