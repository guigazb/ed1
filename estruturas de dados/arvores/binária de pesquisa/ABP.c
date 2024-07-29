/*-----------------------------------------------------------------------
ABP.c
arquivo com a implementação para o TAD árvore binária de pesquisa em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
julho/2024
------------------------------------------------------------------------*/

#ifndef _ABP_C_
#define _TREE_C_
#include <stdio.h>

#include "abp.h" /* inclui a especificacao do TAD */

#define true  1
#define false 0


typedef struct tnode{
    void* data;
    struct Tnode *l;
    struct Tnode *r;
} Tnode;


Tnode *abpCreate(void* data){
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

int abpnNos(Tnode* tree){ // visitação simetrica, qualquer visitação pode ser usada
    int nl,n,nr;
    if(tree != NULL){
        nl = abnNos(tree->l);
        n = 1;
        nr = abnNos(tree->r);
        return nl+n+nr;
    }
    return 0;
}

void* abpQuery(Tnode* tree,void* key,int(*cmp)(void*,void*)){
    void* data;
    if(tree != NULL){
        int stat = cmp(key,tree->data);
        if(stat == 0){
            data = tree->data;
            return data;
        }else if(stat == 1){
            data = abpQuery(tree->r,key,cmp);
            return data;
        }else if(stat == -1){
            data = abpQuery(tree->l,key,cmp);
            return data;
        }
    }
    return NULL;
}

Tnode* abpInsert(Tnode* tree,void* data,int(*cmp)(void*,void*)){
    void* data;
    Tnode* newnode;
    if(tree != NULL){
        int stat = cmp(data,tree->data);
        if(stat >= 0){
            tree->r = abpInsert(tree->r,data,cmp);
        }else{
            tree->l = abpInsert(tree->l,data,cmp);
        }
        return tree;
    }else{
        newnode = (Tnode*)malloc(sizeof(Tnode));
        if(newnode != NULL){
            newnode->l = newnode->r = NULL;
            newnode->data = data;
            return newnode;
        }
        return NULL;
    }
}

Tnode* abpRemove(Tnode* tree,void* key,void** data,int(*cmp)(void*,void*)){
    Tnode* son;
    void* datalixo;
    if(tree != NULL){
        int stat = cmp(key,tree->data);
        if(stat == 1){
            tree->r = abpRemove(tree->r,key,data,cmp);
        }else if (stat == -1){
            tree->l = abpRemove(tree->l,key,data,cmp);
        }else{
            *data = tree->data;
            if(tree->l == NULL && tree->r == NULL){
                free(tree);
                return NULL;
            }else if( tree->l == NULL && tree->r != NULL){
                son = tree->r;
                free(tree);
                return son;
            }else if( tree->l != NULL && tree->r == NULL){
                son = tree->l;
                free(tree);
                return son;
            }else{
                tree->data = abpmenordata(tree->r);
                abpRemove(tree->r,tree->data,datalixo,cmp); // coloca o data no lugar, e faz a lógica pro resto ficar certo tbm
                return tree;
            }
        }
        return NULL;
    }
    *data = NULL;
    return NULL;
}

void* abpmenordata(Tnode* tree){
    if(tree != NULL){
        if(tree->l != NULL){
            return abpmenordata(tree->l);
        }else{
            return tree->data;
        }
    }else{
        return NULL;
    }
}

void* abpmaiordata(Tnode* tree){
    if(tree != NULL){
        if(tree->r != NULL){
            return abpmaiordata(tree->r);
        }else{
            return tree->data;
        }
    }else{
        return NULL;
    }
}

int abpEspelhada (Tnode* t1, Tnode* t2,int(*cmp)(void *, void *)){ 
    int statl,statr, igual;
    if(t1 != NULL){
        if(t2!= NULL){
            statl = abpEspelhada(t1->l,t2->r,cmp);
            statr = abpEspelhada(t1->r,t2->l,cmp);
            igual = cmp(t1->data,t2->data);
            return statl && statr && igual;
        }else{
            return false;
        }
    }else if(t2 != NULL){
        return false;    
    }else{
        return true;
    }
}

Tnode *abpRemoveMaior( Tnode *t, int (*cmp)( void *, void * ), void **data ){
    if ( t != NULL ){    
        void *data2;
        Tnode *aux;
        if ( t->r != NULL ){
            t->r = abpRemoveMaior( t->r, cmp, &data2 );
            return t;
        } else {
            if ( t->l != NULL ){
                aux = t->l;
                *data = t->data;
                free( t );
                return aux;
            } else {
                *data = t->data;
                free( t );
                return NULL;
            }
        }
    }
    *data = NULL;
    return NULL;
}

Tnode *abpRemoveMenor(Tnode *t, int (*cmp)( void *, void * ), void **data ){
    if ( t != NULL ){    
        void *data2;
        Tnode *aux;
        if ( t->l != NULL ){
            t->l = abpRemoveMaior( t->l, cmp, &data2 );
            return t;
        } else {
            if ( t->r != NULL ){
                aux = t->r;
                *data = t->data;
                free( t );
                return aux;
            } else {
                *data = t->data;
                free( t );
                return NULL;
            }
        }
    }
    *data = NULL;
    return NULL;
}

void* getData(Tnode* tree){
    if(tree != NULL){
        return tree->data;
    }else{
        return NULL;
    }
}

int abpDestroy(Tnode *tree){
    if(tree != NULL){
        if(tree->l == NULL && tree->r == NULL && tree->data == NULL){
            free(tree);
            return true;
        }
        return false;
    }
    return -1;
}


#endif /* __ABP_C */