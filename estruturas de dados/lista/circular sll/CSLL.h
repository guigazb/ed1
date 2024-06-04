/*-----------------------------------------------------------------------
Sll.h
arquivo com as especificações para o TAD lista simples encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/
#ifndef Sll_h
#define Sll_h

// definições locais

typedef struct sllnode Sllnode;

typedef struct sllist Sllist;

//especificações para o tad pilha

Sllist *sllCreate (void); 
/* Construir uma nova lista vazia
Pre-condição: (chamar a função sllcreate)
Pos-condição: retorna um ponteiro para uma lista vazia */

int sllInsertasfist( Sllist *lista, void *data); 
/* Inserir o elemento no inicio da lista
Pre-condição: (l foi criada por sllCreate) && (data != NULL) 
Pos-condição: data foi adicionado no inicio da lista l */

void *sllRemovefirst( Sllist *lista); 
/* Retira o elemento no inicio da lista
Pre-condição: (l foi criada por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do inicio da lista foi removido */

void *sllGetfirst( Sllist *lista);
/* retorna o atual elemento no inicio da lista
Pre-condição: (l foi criado por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

void *sllGetfirstcur( Sllist *lista);
/* retorna o atual elemento no inicio da lista usando current
Pre-condição: (l foi criado por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

int sllInsertAsLast(Sllist* lista,void* data);
/* insere data como ultimo elemento da lista
Pre-condição: (l foi criada por sllCreate) && (data != NULL)
Pos-condição: retorna se foi possivel inserir o item ou não */

void *sllRemovelast( Sllist *lista); 
/* Retira o elemento no final da lista
Pre-condição: (l foi criada por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do final da lista foi removido */

void* sllGetLast (Sllist* lista);
/* retorna o ultimo elemento da lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o ultimo elemento da lista */

int sllNumNodes(Sllist* lista);
/* retorna o numero de itens na lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o numero de elementos na lista, código de erro se a lista não existir */

int sllInsertafterN(Sllist* lista, void* data, int n);
/* insere um elemento após N itens da lista
Pre-condição: (l foi criada por sllCreate) && (l não está vazia)
Pos-condição: elm foi inserido após n */

int sllInsertafterespec(Sllist* lista,void* data,int(*cmp)(void*,void*));
/* insere elm após item especificado
Pre-condição: (l foi criada por sllCreate)
Pos-condição: elm foi inserido após um item especificado */

int sllInsertbeforespec(Sllist* lista,void* data,int(*cmp)(void*,void*));
/* insere elm antes do item especificado
Pre-condição: (l foi criada por sllCreate)
Pos-condição: elm foi inserido antes de um item especificado */

void* sllQueryspec(Sllist* lista, void*key,int(*cmp)(void*,void*));
/* retorna se o item especificado está na lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna true se o item for encontrado */

void* sllRemovespec(Sllist* lista,void* key,int(*cmp)(void*,void*));
/* remove o elemento especificado
Pre-condição: (l foi criada por sllCreate)
Pos-condição: o elemento especificado foi removido */

void* sllGetnext(Sllist* lista);
/* retorna o elemento current da lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o current da lista */

int sllDestroy (Sllist *lista);
/* destroi a lista
Pre-condição: (l foi criada por sllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */


#endif /* __SLL_H */