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

// lista - 8
void* removeK(Dllist* lista,int k);

// lista - 10
int *dllEInversa(Dllist* l1, Dllist* l2, int(*cmp)( void *, void *));

// lista - 11
int removeOrdemimp(Dllist* lista);

// prova 2022.1 - 2
void  PegaElementosIguais(Dllist *l1, Dllist *l2, Dllist *l3);
/* Escreva um algoritmo que recebe três listas lineares duplamente encadeadas L1, 
L2 e L3. E, retorna a Lista L3 com os nós de L1 que estão que tem um igual em L2 
(data), ou seja que estão presentes em ambas as listas (L1 e L2). Não pode alocar novos 
nós. L3 é recebida pelo algoritmo sem nenhum nó (vazia). Os elementos incluídos em 
L3 devem ser retirados da lista L1. */

//2017 - q2
int trocaIJ(Dllist* lista,int i, int j);

//2023.2 - q4
Dllist* movemenoresl2paral1(Dllist* l1,Dllist* l2,void* key,int(*cmp)(void*,void*));

// provas desconhecidas

int dllFixprev(Dllist* dlista);

int dllDestroy (Dllist* dlista);

int inverte(Dllist* l1,Dllist* l2);
// retorna os elms de l1 em l2 na ordem inversa

int dllquebracomuns(Dllist* l1,Dllist* l2);

void dllPegaIguais(Dllist*l1, Dllist*l2, Dllist*l3);

/* destroi a lista
Pre-condição: (l foi criada por dllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */


#endif /* __DLL_H */