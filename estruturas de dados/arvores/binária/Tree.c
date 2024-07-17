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

int abnNos(Tnode* tree){ // visitação simetrica, qualquer visitação pode ser usada
    int nl,n,nr;
    if(tree != NULL){
        nl = abnNos(tree->l);
        n = 1;
        nr = abnNos(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abHeight(Tnode* tree){ // visitção posordem
    int hl,h,hr;
    if(tree != NULL){
        hl = abHeight(tree->l);
        hr = abHeight(tree->r);
        if(hl > hr){
            h = 1 + hl;
        }else{
            h = 1+ hr;
        }
        return h;
    }
    return 0;
}

int abnNoslevelL(Tnode* tree, int l, int level){
    int n = 0,nl = 0, nr = 0;
    if(tree != NULL){
        if(l == level){
            n = 1;
        }else if(l > level){
            nl = abnNoslevelL(tree->l,l,level + 1);
            nr = abnNoslevelL(tree->r,l,level + 1);
        }
        return nl+nr+n;
    }
    return 0;
}

int abtopoigual(Tnode* t1,Tnode* t2){
    int statl,statr;
    if(t1 != NULL){
        if(t2!= NULL){
            statl = abtopoigual(t1->l,t2->l);
            statr = abtopoigual(t1->r,t2->r);
            return statl && statr;
        }else{
            return false;
        }
    }else if(t2 != NULL){
        return false;
    }else{
        return true;
    }
}

int abtopomaior(Tnode* t1,Tnode* t2,int(*cmp)(void*,void*)){
    int statl,statr, maior;
    if(t1 != NULL){
        if(t2!= NULL){
            statl = abtopomaior(t1->l,t2->l,cmp);
            statr = abtopomaior(t1->r,t2->r,cmp);
            maior = cmp(t1->data,t2->data);
            return statl && statr && maior;
        }else{
            return false;
        }
    }else if(t2 != NULL){
        return false;
    }else{
        return true;
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

//lista 9
int abnNosg0(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if(tree->l == NULL && tree->r == NULL){
            n = 1;
        }
        nl = abnNosg0(tree->l);
        nr = abnNosg0(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosg1(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if((tree->l == NULL && tree->r != NULL) || (tree->l != NULL && tree->r == NULL)){
            n = 1;
        }
        nl = abnNosg1(tree->l);
        nr = abnNosg1(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosg2(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if(tree->l != NULL && tree->r != NULL){
            n = 1;
        }
        nl = abnNosg2(tree->l);
        nr = abnNosg2(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosleft(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if(tree->l != NULL ){
            n = 1;
        }
        nl = abnNosleft(tree->l);
        nr = abnNosleft(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosright(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if(tree->r != NULL){
            n = 1;
        }
        nl = abnNosright(tree->l);
        nr = abnNosright(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosleftsemright(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if(tree->l != NULL && tree->r == NULL){
            n = 1;
        }
        nl = abnNosleftsemright(tree->l);
        nr = abnNosleftsemright(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosrightsemleft(Tnode*tree){
    int nl,n,nr;
    if(tree != NULL){
        if(tree->l == NULL && tree->r != NULL){
            n = 1;
        }
        nl = abnNosrightsemleft(tree->l);
        nr = abnNosrightsemleft(tree->r);
        return nl+n+nr;
    }
    return 0;
}

int abnNosnivelmaiorquelevel(Tnode*tree, int l, int level){
    int n = 0,nl = 0, nr = 0;
    if(tree != NULL){
        if(l > level){
            n = 1;
        }
        nl = abnNosnivelmaiorquelevel(tree->l,l,level + 1);
        nr = abnNosnivelmaiorquelevel(tree->r,l,level + 1);
        return nl+nr+n;
    }
    return 0;
}

#endif /* __TREE_C */