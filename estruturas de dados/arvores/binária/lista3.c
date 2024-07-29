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

Tnode* abpremovemenor(Tnode* tree,void**data){
    void* data2;
    Tnode* aux;
    if(tree != NULL){
        if(tree->l != NULL){
            tree->l = abpremovemenor(tree->l,&data2);
            return tree;
        }else{
            *data = tree->data;
            if(tree->r != NULL){
                aux = tree->r;
                free(tree);
                return aux;
            }else{
                free(tree);
                return NULL;
            }
        }
    }else{
        *data = NULL;
        return NULL;
    }
}

Tnode* abpremovemaior(Tnode* tree,void**data){
    void* data2;
    Tnode* aux;
    if(tree != NULL){
        if(tree->r != NULL){
            tree->r = abpremovemaior(tree->r,&data2);
            return tree;
        }else{
            *data = tree->data;
            if(tree->l != NULL){
                aux = tree->l;
                free(tree);
                return aux;
            }else{
                free(tree);
                return NULL;
            }
        }
    }else{
        *data = NULL;
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

int isabp(Tnode* tree,int(*cmp)(void*,void*)){
    if(tree != NULL){ // nessa cmp, true é a <= b, false é a > b
        void* maiorL = abpmaiordata(tree->l);
        void* menorR = abpmenordata(tree->r);
        int statL = cmp(maiorL,tree->data);
        int statR = cmp(tree->data,menorR);
        return statL && statR;
    }
    return true;
}

int abHeight(Tnode* tree){ // visitção posordem
    int hl,h,hr;
    if(tree != NULL){
        hl = abHeight(tree->l);
        hr = abHeight(tree->r);
        if(hl > hr){
            h = 1 + hl;
        }else{
            h = 1 + hr;
        }
        return h;
    }
    return 0;
}

void visitapornivel(Tnode* tree,int level,int nodelevel,void(*visit)(void*)){ // node level deve ser zero
    if(tree != NULL){
        if(level == nodelevel){
            visit(tree->data);
        }else if(level > nodelevel){
            visitapornivel(tree->l,level,nodelevel + 1,visit);
            visitapornivel(tree->r,level,nodelevel + 1,visit);
        }
    }
}

int abnNoslevelL(Tnode* tree, int l, int level){ // level deve iniciar em 0
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

void* abmaiorvalor(Tnode* tree,int(*cmp)(void*,void*)){
    void* maiorL;
    void* maiorR;
    if(tree != NULL){
        maiorL = abmaiorvalor(tree->l,cmp);
        maiorR = abmaiorvalor(tree->r,cmp);
        return abmaiordostres(maiorL,maiorR,tree->data,cmp);
    }
    return NULL;
}

void* abmaiordostres(void* ml,void* mr,void* root,int(*cmp)(void*,void*)){
    if(ml != NULL){
        if(mr != NULL){
            int stat = cmp(ml,mr); // a > b = true         
            if(stat == true){
                void* maior = ml;
                stat = cmp(maior,root);
                if(stat == true){
                    return maior;
                }else{
                    return root;
                }
            }
        }
    }
}

int abnumNosg1(Tnode* tree){
    int n,nl,nr;
    if(tree != NULL){
        if(tree->l != NULL || tree->r != NULL){
            n = 1;
        }
        nl = abnumnosg1(tree->l);
        nr = abnumnosg1(tree->r);
        return n + nl + nr;
    }
}

int abpcompararvorestopo(Tnode* t1,Tnode* t2){
    int statL,statR;
    if(t1 != NULL){
        if(t2 != NULL){
            statL = abpcompararvorestopo(t1->l,t2->l);
            statR = abpcompararvorestopo(t1->r,t2->r);
            return statL && statR;
        }else{
            return false;
        }
    }else if(t2 != NULL){
        return true;
    }else{
        return false;
    }
}

int abpcompararvoresmaior(Tnode* t1,Tnode* t2,int(*getvalue)(void*)){
    int stat,statL,statR;
    int v1,v2;
    if(t1 != NULL){
        if(t2 != NULL){
            v1 = getvalue(t1->data);
            v2 = getvalue(t2->data);
            if(v1 > v2){
                stat = true;
            }else{
                stat = false;
            }
            statL = abpcompararvoresmaior(t1->l,t2->l,getvalue);
            statR = abpcompararvoresmaior(t1->r,t2->r,getvalue);
            return stat && statL && statR;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int abpcompararvoressum(Tnode* t1,Tnode* t2,int(*getvalue)(void*)){
    int sum1,sum2;
    if(t1 != NULL){
        if(t2 != NULL){
            sum1 = absomaNos(t1,getvalue);
            sum2 = absomanos(t2,getvalue);
            if(sum1 > sum2){
                return true; // 1
            }else if(sum1 == sum2){
                return false; // 0
            }else{
                return -1;
            }
        }else{
            return true; // 1
        }
    }else if(t2 != NULL){
        return -1;
    }else{
        return false; // 0
    }
}

int abAltura(Tnode* tree){
    int h,hl,hr;
    if(tree != NULL){
        hl = abAltura(tree->l);
        hr = abAltura(tree->r);
        if(hl>hr){
            h = 1 + hl;
        }else{
            h = 1 + hr;
        }
        return h;
    }
    return 0;
}

int absomaNos(Tnode* tree,int(*getvalue)(void*)){ 
    // getvalue retorna o inteiro armazenado em data
    int n,nl,nr;
    if(tree != NULL){
        n = getvalue(tree);
        nl = absomaNos(tree->l,getvalue);
        nr = absomaNos(tree->r,getvalue);
        return n + nl + nr;
    }
    return 0;
}

int abisFull(Tnode* tree){
    int stat,statl,statr;
    int hl,hr;
    if(tree != NULL){
        hl = abAltura(tree->l);
        hr = abAltura(tree->r);
        if(hl == hr){
            if((tree->l == NULL && tree->r != NULL)||(tree->l != NULL && tree->r == NULL)){
                stat = false;
            }else{
                stat = true;
            }
            statl = abisfull(tree->l);
            statr = abisfull(tree->r);
            return stat && statl && statr;
        }else{
            return false;
        }  
    }
    return -1; // arvore nula
}

int abpdiferencamaiormenor(Tnode* tree,int(*getvalue)(void*)){
    int maior,menor;
    if(tree != NULL){
        maior = getvalue(abpmaiordata(tree));
        menor = getvalue(abpmenordata(tree));
        return maior - menor;
    }
    return -511354;
}

int abpnNosalturah(Tnode* tree,int h){
    int altura,hl,hr;
    int n;
    if(tree != NULL){
        if(altura == h){
            n = 1;
        }
    }
}

void visitbylevel(Tnode* tree){}

void reversevisit(Tnode* tree){}

void* abpleftiestlevelK(Tnode* tree, int k){}

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

int abnNosg1oumais(Tnode* tree){
    if(tree != NULL){
        int Nos = 0;
        int nl = 0;
        int nr = 0;
        if((tree->l != NULL)||(tree->r != NULL)){
            Nos++;
        }
        nl = abnNosg1oumais(tree->l);
        nr = abnNosg1oumais(tree->r);
        return Nos + nl + nr;
    }
    return 0;
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