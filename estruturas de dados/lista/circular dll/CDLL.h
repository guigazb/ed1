/*-----------------------------------------------------------------------
CDll.h
arquivo com as especificações para o TAD lista circular duplamente encadeada
em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/
#ifndef CDll_h
#define CDll_h

// definições locais

typedef struct cdllnode Cdllnode;

typedef struct cdllist Cdllist;

//especificações para o tad pilha

Cdllist *cdllCreate (void); 
/* Construir uma nova lista vazia
Pre-condição: (chamar a função dllcreate)
Pos-condição: retorna um ponteiro para uma lista vazia */

int cdllInsertasfist(Dllist *cdlista, void *data); 
/* Inserir o elemento no inicio da lista
Pre-condição: (l foi criada por dllCreate) && (data != NULL) 
Pos-condição: data foi adicionado no inicio da lista l */

void *cdllGetfirst(Dllist* cdlista);
/* retorna o atual elemento no inicio da lista usando current
Pre-condição: (l foi criado por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

int cdllInsertAsLast(Dllist* cdlista,void* data);
/* insere data como ultimo elemento da lista
Pre-condição: (l foi criada por dllCreate) && (data != NULL)
Pos-condição: retorna se foi possivel inserir o item ou não */

void *cdllRemovelast( Dllist *cdlista); 
/* Retira o elemento no final da lista
Pre-condição: (l foi criada por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do final da lista foi removido */

int cdllNumNodes(Dllist* cdlista);
/* retorna o numero de itens na lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o numero de elementos na lista, código de erro se a lista não existir */

int cdllInsertafterespec(Dllist* cdlista,void* data,void* key,int(*cmp)(void*,void*));
/* insere elm após item especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: elm foi inserido após um item especificado */

int cdllInsertbeforespec(Dllist* cdlista,void* data,void* key,int(*cmp)(void*,void*));
/* insere elm antes do item especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: elm foi inserido antes de um item especificado */

void* cdllQueryspec(Dllist* cdlista, void*key,int(*cmp)(void*,void*));
/* retorna se o item especificado está na lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna true se o item for encontrado */

void* cdllRemovespec(Dllist* cdlista,void* key,int(*cmp)(void*,void*));
/* remove o elemento especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: o elemento especificado foi removido */

void* cdllGetnext(Dllist* cdlista);
/* retorna o elemento current da lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o current da lista */

Dllnode* cdllGetspec(Dllist* cdlista,void* key,int(*cmp)(void*,void*));
/* retorna o elemento spec dentro de uma função, USO INTERNO DO TAD APENAS
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o spec da função caso exista */

int cdllDestroy (Dllist *cdlista);
/* destroi a lista
Pre-condição: (l foi criada por dllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */


#endif /* __CDLL_H */