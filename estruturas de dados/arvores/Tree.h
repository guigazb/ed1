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

int treeDestroy(Tnode *tree);
/* destroi a árvore
Pre-condição: (chamar a função treeCreate)
Pos-condição: retorna uma árvore contendo data */


#endif /* __TREE_H */