/*-----------------------------------------------------------------------
Sllqueue.h
arquivo com as especificações para o TAD fila implementado em uma
lista simples encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/
#ifndef SllQUEUE_h
#define SllQUEUE_h

// definições locais

typedef struct sllnode Sllnode;

typedef struct sllqueue Sllqueue;

//especificações para o tad pilha

Sllqueue *qlCreate (void); 
/* Construir uma nova lista vazia
Pre-condição: (chamar a função sllcreate)
Pos-condição: retorna um ponteiro para uma lista vazia */

int qlEnqueue(Sllqueue* qlista, void* data); 
/* Inserir o elemento no inicio da lista
Pre-condição: (l foi criada por sllCreate) && (data != NULL) 
Pos-condição: data foi adicionado no inicio da lista l */

void *qlDequeue(Sllqueue* qlista); 
/* Retira o elemento no inicio da lista
Pre-condição: (l foi criada por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: elemento do inicio da lista foi removido */

void *qlGetfirst(Sllqueue* qlista);
/* retorna o atual elemento no inicio da lista
Pre-condição: (l foi criado por sllCreate) && (existe pelo menos um item na lista)
Pos-condição: o retorno é o item no inicio da lista */

//averiguar se é necessario implementar
void* sllGetLast (Sllqueue* qlista);
/* retorna o ultimo elemento da lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o ultimo elemento da lista */

int sllNumNodes(Sllqueue* qlista);
/* retorna o numero de itens na lista
Pre-condição: (l foi criada por sllCreate)
Pos-condição: retorna o numero de elementos na lista, código de erro se a lista não existir */

int qlDestroy (Sllqueue* qlista);
/* destroi a lista
Pre-condição: (l foi criada por sllCreate) && (não existem itens na lista)
Pos-condição: a lista foi destruida */


#endif /* __SLLQUEUE_H */