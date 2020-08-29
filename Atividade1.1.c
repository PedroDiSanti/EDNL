/*
  Arquivo: Atividade1.1.c
  Autor:
    Pedro Afonso Rotta Di Santi (RA00218666)
    Lucas Pavani Mendes (RA00167455)
    Lucas Vasconcellos Coutinho (RA00167383)
    Douglas Gomi (RA00127809)
  Data: 21/08/2020 09:51:20
  Descrição:
    Este programa tem como finalidade explorar a manipulação de uma Árvore Binária. Ela implementa a criação de uma
        uma nova árvore, onde elementos pré-definidos estão inseridos.
    Além disso, implementamos o caminhamentos recursivo eRd e podemos calcular a quantidade de nós da árvore.
    Por fim, "printamos" esse caminhamento e do seu número de nós para uma árvore vazia e para um com
        elementos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char elemento;
    struct No *esq;
    struct No *dir;
} No;

typedef No *Arvore;

Arvore criarArvore( ); //Cria uma árvore vazia.
Arvore construirArvore(char, Arvore, Arvore); //Monta uma árvore usando valor de um char.
void mostrarArvore(Arvore); //Função para realizar o caminhamento eRd.
int contarNos(Arvore); //Função para fazer a contagem dos nós pré-inseridos.

int main(){
    Arvore arvore, arvoreVazia, subArvore1, subArvore2, a, b, c;
    int nos;

    arvoreVazia = criarArvore();

    //BDE
    a = construirArvore('D', NULL, NULL);
    b = construirArvore('E',NULL,NULL);
    c = construirArvore('B', a, b);
    subArvore1 = c;

    //CFG
    a = construirArvore('F', NULL, NULL);
    b = construirArvore('G',NULL,NULL);
    c = construirArvore('C', a, b);
    subArvore2 = c;

    //ABC
    arvore = construirArvore('A', subArvore1, subArvore2);

    nos = contarNos(arvore);
    //nos = contarNos(arvoreVazia);

    if (nos == 0){
        printf("\nTESTE criar árvore vazia\n\n");
        printf("arvore vazia");
    }else{
        printf("\nTESTE construir árvore \n\n");
        printf("Caminhamento eRd: ");
        mostrarArvore(arvore);
    }

    printf("\nnumero de nos = %d", nos);

    printf("\n");

    return 0;
}

Arvore criarArvore( ){
    Arvore ap;
    ap = NULL;
    return ap;
}

Arvore construirArvore(char item, Arvore e, Arvore d){
    No *novo, *raiz;

    novo = malloc(sizeof(No));  novo->elemento = item;

    novo->esq = e;
    novo->dir = d;
    raiz = novo;

    return raiz;
}

void mostrarArvore(Arvore ap){
    if (ap != NULL){
        mostrarArvore(ap->esq);
        printf(" %c  ",ap->elemento);
        mostrarArvore(ap->dir);
    }
}

int contarNos(Arvore ap) {
    int c = 1;

    if (ap != NULL) {
        c += contarNos(ap->esq);
        c += contarNos(ap->dir);
        return c;
    }
    else
        return 0;
}




