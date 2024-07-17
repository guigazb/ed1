/*-----------------------------------------------------------------------
tree.h
arquivo com as especificações para o TAD árvore de busca binária em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
julho/2024
------------------------------------------------------------------------*/
#ifndef TREE_h
#define TREE_h

// definições locais

typedef struct tnode Tnode;

//especificações para o tad árvore

Tnode *treeCreate(void* data); 
/* Construir uma nova árvore contendo data
Pre-condição: (chamar a função treeCreate)
Pos-condição: retorna uma árvore contendo data */

void preOrdem(Tnode* tree,void(*visit)(void*));

void simetrica(Tnode* tree,void(*visit)(void*));

void posOrdem(Tnode* tree,void(*visit)(void*));

int abnNos(Tnode* tree);

int abHeight(Tnode* tree);

int abnNoslevelL(Tnode* tree, int l, int level);

int abtopoigual(Tnode* t1,Tnode* t2);

int abtopomaior(Tnode* t1,Tnode* t2,int(*cmp)(void*,void*));

int treeDestroy(Tnode *tree);
/* destroi a árvore
Pre-condição: (chamar a função treeCreate)
Pos-condição: retorna uma árvore contendo data */

//lista 9

int abnNosg0(Tnode*tree);

int abnNosg1(Tnode*tree);

int abnNosg2(Tnode*tree);

int abnNosleft(Tnode*tree);

int abnNosright(Tnode*tree);

int abnNosleftsemright(Tnode*tree);

int abnNosrightsemleft(Tnode*tree);

int abnNosnivelmaiorquelevel(Tnode*tree, int l, int level);


#endif /* __TREE_H */