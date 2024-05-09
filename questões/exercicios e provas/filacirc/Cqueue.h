/*-----------------------------------------------------------------------
Cqueue.h
arquivo com as especificações para o TAD fila circular em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/
#ifndef Cqueue_h
#define Cqueue_h

// definições locais
typedef struct cqueue Cqueue;

//especificações para o tad fila circular

Cqueue *cqCreate (int max); 
/* Construir uma nova fila circular vazia
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

int cqEnqueue(Cqueue *cfila, void *elm,int (*incCirc)(int i,int max)); 
/* Inserir o elemento no fim da fila
Pre-condição: (fila foi criada por cqCreate) && (cabe um elemento na fila) && (item != NULL) 
Pos-condição: item foi adicionado ao rear da fila */

void *cqDequeue(Cqueue *cfila); 
/* Retira o elemento da frente da fila
Pre-condição: (s foi criada por cqCreate) && (existe pelo menos um item na fila)
Pos-condição: elemento do front da fila foi retirado */

void *cqFirst(Cqueue *cfila);
/* retorna o atual elemento no inicio da fila
Pre-condição: (fila foi criada por cqCreate) && (existe pelo menos um item na fila)
Pos-condição: o retorno é o item no front da fila */

int cqIsEmpty(Cqueue *cfila);
/* retorna se o numero de elementos é zero
Pre-condição: (fila foi criada por cqCreate)
Pos-condição: retorna true se a fila estiver vazia, false se conter algum elemento */

int cqDestroy (Cqueue *cfila);
/* destroi a fila circular
Pre-condição: (fila foi criada por cqCreate) && (não existem itens na fila circular)
Pos-condição: a fila circular foi destruida */

//questão 4
//4.1
void *cqGetLast( Cqueue *cfila);
/* retorna o ultimo item da fila se remover
Pre-condição: (fila foi criada por cqCreate) && (existem itens na fila circular)
Pos-condição: a fila circular foi destruida */

//4.2
int  cqEnqueueN (Cqueue *cfila, int n, void **elms);
/* coloca um vetor com n elemento na fila circular
Pre-condição: (fila foi criada por cqCreate) && (a fila não está cheia)
Pos-condição: a fila circular foi destruida */

//4.3
void *cqDequeueN (Cqueue *cfila, int n);
/* devolve um vetor com os n primeiros elementos da fila circular
Pre-condição: (fila foi criada por cqCreate) && (existem itens na fila circular)
Pos-condição: a fila circular foi destruida */

//4.4
void *cqDequeueSpecified (Cqueue *cfila, void *key, int (*cmp)(void *, void *));
/* remove e devolve da fila circular um elemento especificado por uma chave 
Pre-condição: (fila foi criada por cqCreate) && (existem itens na fila circular)
Pos-condição: o elemento foi devolvido e a fila alterada */

//questão 10
int cqReorganiza(Cqueue* cfila);
/* organiza o front no primeiro espaço do vetor, e os seguintes nas posições posteriores
Pre-condição: (fila foi criada por cqCreate) && (existem itens na fila circular)
Pos-condição: a fila foi reorganizada */

int qdeccirc(int atual ,int max);
int qinccirc(int atual,int max);

#endif /* __CQUEUE_H */