/*-----------------------------------------------------------------------
Dll.h
arquivo com as especificações para o TAD lista duplamente encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/
#ifndef Dll_h
#define Dll_h

// definições locais

typedef struct dllnode Dllnode;

typedef struct dllist Dllist;

//especificações para o tad pilha

Dllist *dllCreate (void); 
/* Construir uma nova lista vazia
Pre-condição: (chamar a função dllcreate)
Pos-condição: retorna um ponteiro para uma lista vazia */

int dllInsertasfist( Dllist *dlista, void *data); 
/* Inserir o elemento no inicio da lista
Pre-condição: (l foi criada por dllCreate) && (data != NULL) 
Pos-condição: data foi adicionado no inicio da lista l */

void *dllRemovefirst( Dllist *dlista); 
/* Retira o elemento no inicio da lista
Pre-condição: (l foi criada por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do inicio da lista foi removido */

void *dllGetfirst( Dllist *dlista);
/* retorna o atual elemento no inicio da lista
Pre-condição: (l foi criado por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

void *dllGetfirstcur( Dllist *dlista);
/* retorna o atual elemento no inicio da lista usando current
Pre-condição: (l foi criado por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

int dllInsertAsLast(Dllist* dlista,void* data);
/* insere data como ultimo elemento da lista
Pre-condição: (l foi criada por dllCreate) && (data != NULL)
Pos-condição: retorna se foi possivel inserir o item ou não */

void *dllRemovelast( Dllist *dlista); 
/* Retira o elemento no final da lista
Pre-condição: (l foi criada por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do final da lista foi removido */

void* dllGetLast (Dllist* dlista);
/* retorna o ultimo elemento da lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o ultimo elemento da lista */

int dllNumNodes(Dllist* dlista);
/* retorna o numero de itens na lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o numero de elementos na lista, código de erro se a lista não existir */

int dllInsertafterN(Dllist* dlista, void* data, int n);
/* insere um elemento após N itens da lista
Pre-condição: (l foi criada por dllCreate) && (l não está vazia)
Pos-condição: elm foi inserido após n */

int dllInsertafterespec(Dllist* dlista,void* data,int(*cmp)(void*,void*));
/* insere elm após item especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: elm foi inserido após um item especificado */

int dllInsertbeforespec(Dllist* dlista,void* data,int(*cmp)(void*,void*));
/* insere elm antes do item especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: elm foi inserido antes de um item especificado */

void* dllQueryspec(Dllist* dlista, void*key,int(*cmp)(void*,void*));
/* retorna se o item especificado está na lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna true se o item for encontrado */

void* dllRemovespec(Dllist* dlista,void* key,int(*cmp)(void*,void*));
/* remove o elemento especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: o elemento especificado foi removido */

void* dllGetnext(Dllist* dlista);
/* retorna o elemento current da lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o current da lista */

int dllDestroy (Dllist *dlista);
/* destroi a lista
Pre-condição: (l foi criada por dllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */


#endif /* __DLL_H */