/*-----------------------------------------------------------------------
CSll.h
arquivo com as especificações para o TAD lista circular simples encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/
#ifndef CSll_h
#define CSll_h

// definições locais

typedef struct csllnode Csllnode;

typedef struct csllist Csllist;

//especificações para o tad lista circular simples

Csllist *csllCreate(void); 
/* Construir uma nova lista vazia
Pre-condição: (chamar a função sllcreate)
Pos-condição: retorna um ponteiro para uma lista vazia */

int csllInsertasfist(Csllist *cslista, void *data); 
/* Inserir o elemento no inicio da lista
Pre-condição: (l foi criada por sllCreate) && (data != NULL) 
Pos-condição: data foi adicionado no inicio da lista l */

void *csllRemovefirst(Csllist *cslista); 
/* Retira o elemento no inicio da lista
Pre-condição: (l foi criada por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do inicio da lista foi removido */

void *csllGetfirst(Csllist *cslista);
/* retorna o atual elemento no inicio da lista
Pre-condição: (l foi criado por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

void *csllGetfirstcur(Csllist *cslista);
/* retorna o atual elemento no inicio da lista usando current
Pre-condição: (l foi criado por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

int csllInsertAsLast(Csllist* cslista,void* data);
/* insere data como ultimo elemento da lista
Pre-condição: (l foi criada por sllCreate) && (data != NULL)
Pos-condição: retorna se foi possivel inserir o item ou não */

void *csllRemovelast(Csllist* cslista); 
/* Retira o elemento no final da lista
Pre-condição: (l foi criada por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do final da lista foi removido */

void* csllGetLast(Csllist* cslista);
/* retorna o ultimo elemento da lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o ultimo elemento da lista */

int csllNumNodes(Csllist* cslista);
/* retorna o numero de itens na lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o numero de elementos na lista, código de erro se a lista não existir */

int csllInsertafterespec(Csllist* cslista,void* data,int(*cmp)(void*,void*));
/* insere elm após item especificado
Pre-condição: (l foi criada por sllCreate)
Pos-condição: elm foi inserido após um item especificado */

int csllInsertbeforespec(Csllist* cslista,void* data,int(*cmp)(void*,void*));
/* insere elm antes do item especificado
Pre-condição: (l foi criada por sllCreate)
Pos-condição: elm foi inserido antes de um item especificado */

void* csllQueryspec(Csllist* cslista, void*key,int(*cmp)(void*,void*));
/* retorna se o item especificado está na lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna true se o item for encontrado */

void* csllRemovespec(Csllist* cslista,void* key,int(*cmp)(void*,void*));
/* remove o elemento especificado
Pre-condição: (l foi criada por sllCreate)
Pos-condição: o elemento especificado foi removido */

void* csllGetnext(Csllist* cslista);
/* retorna o elemento current da lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o current da lista */

int csllDestroy (Csllist *cslista);
/* destroi a lista
Pre-condição: (l foi criada por sllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */


#endif /* __CSLL_H */