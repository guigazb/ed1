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

int cdllInsertasfist(Cdllist *cdlista, void *data); 
/* Inserir o elemento no inicio da lista
Pre-condição: (l foi criada por dllCreate) && (data != NULL) 
Pos-condição: data foi adicionado no inicio da lista l */

void *cdllGetfirst(Cdllist* cdlista);
/* retorna o atual elemento no inicio da lista usando current
Pre-condição: (l foi criado por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

int cdllInsertAsLast(Cdllist* cdlista,void* data);
/* insere data como ultimo elemento da lista
Pre-condição: (l foi criada por dllCreate) && (data != NULL)
Pos-condição: retorna se foi possivel inserir o item ou não */

void *cdllRemovelast( Cdllist *cdlista); 
/* Retira o elemento no final da lista
Pre-condição: (l foi criada por dllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do final da lista foi removido */

int cdllNumNodes(Cdllist* cdlista);
/* retorna o numero de itens na lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o numero de elementos na lista, código de erro se a lista não existir */

int cdllInsertafterespec(Cdllist* cdlista,void* data,void* key,int(*cmp)(void*,void*));
/* insere elm após item especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: elm foi inserido após um item especificado */

int cdllInsertbeforespec(Cdllist* cdlista,void* data,void* key,int(*cmp)(void*,void*));
/* insere elm antes do item especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: elm foi inserido antes de um item especificado */

void* cdllQueryspec(Cdllist* cdlista, void*key,int(*cmp)(void*,void*));
/* retorna se o item especificado está na lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna true se o item for encontrado */

void* cdllRemovespec(Cdllist* cdlista,void* key,int(*cmp)(void*,void*));
/* remove o elemento especificado
Pre-condição: (l foi criada por dllCreate)
Pos-condição: o elemento especificado foi removido */

void* cdllGetnext(Cdllist* cdlista);
/* retorna o elemento current da lista
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o current da lista */

Cdllnode* cdllGetspec(Cdllist* cdlista,void* key,int(*cmp)(void*,void*));
/* retorna o elemento spec dentro de uma função, USO INTERNO DO TAD APENAS
Pre-condição: (l foi criada por dllCreate)
Pos-condição: retorna o spec da função caso exista */

int cdllDestroy (Cdllist *cdlista);
/* destroi a lista
Pre-condição: (l foi criada por dllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */

// exercicios
// lista - 7
int removedpsspec(Cdllist* cdlista, Cdllnode*p);
/* destroi a lista
Pre-condição: (l foi criada por dllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */

// lista - 8 
// prova 2021.2 - 1
int removeK(Cdllist* cdlista, int k);
/* destroi a lista
Pre-condição: (l foi criada por dllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */ 

//prova 2021.2 - 2
int sllNumComuns(Cdllist *l1, Cdllist *l2, int(*cmp)( void *, void *));

// prova 2022.1 - 1
int *sllEInversa(Cdllist *l1, Cdllist *l2, int(*cmp)( void *, void *));

//lista - 9
Cdllist *sllCopiaInvertida (Cdllist *cdlista) ;
/* Escreva um algoritmo copia (L1, L2) para  montar uma cópia  L2 da lista L1 (ambas 
duplamente encadeada circular), de modo que os elementos de L2 estejam em L1 na 
ordem inversa. */

// provas sem data
int removeocaraevizinhos(Cdllist* cdlista,void* key,int(*cmp)(void*,void*));

int cdllemsll(Cdllist* cdlista);

int cdllFixprev(Cdllist* cdlista);

//2023.2 - q1
void* removeDomeio(Cdllist* cdlista);

#endif /* __CDLL_H */