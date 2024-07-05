/*-----------------------------------------------------------------------
TREE.c
arquivo com a implementação para o TAD árvore binária de busca
encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
julho/2024
------------------------------------------------------------------------*/

#ifndef _TREE_C_
#define _TREE_C_
#include <stdio.h>

#include "Tree.h" /* inclui a especificacao do TAD */

#define true  1
#define false 0


typedef struct tnode{
    void* data;
    struct Tnode *l;
    struct Tnode *r;
} Tnode;


Tnode *treeCreate(void* data){
    Tnode* tree = (Tnode*) malloc(sizeof(Tnode));
    if(tree != NULL){
        tree->data = data;
        tree->l = NULL;
        tree->r = NULL;
        return tree;
    }
    return NULL;
}

void preOrdem(Tnode* tree,void(*visit)(void*)){
    if(tree != NULL){
        visit(tree->data);
        preOrdem(tree->l,visit);
        preOrdem(tree->r,visit);
    }
}

void simetrica(Tnode* tree,void(*visit)(void*)){
    if(tree != NULL){
        simetrica(tree->l,visit);
        visit(tree->data);
        simetrica(tree->r,visit);
    }
}

void posOrdem(Tnode* tree,void(*visit)(void*)){
    if(tree != NULL){
        posOrdem(tree->l,visit);
        posOrdem(tree->r,visit);
        visit(tree->data);
    }
}


int treeDestroy (Tnode *tree){
    if(tree != NULL){
        if(tree->l == NULL && tree->r == NULL && tree->data == NULL){
            free(tree);
            return true;
        }
        return false;
    }
    return -1;
}

#endif /* __TREE_C */