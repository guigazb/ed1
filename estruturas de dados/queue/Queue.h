/*-----------------------------------------------------------------------
Queue.h
arquivo com as especificações para o TAD fila em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/
#ifndef Queue_h
#define Queue_h

// definições locais
typedef struct queue Queue;

//especificações para o tad fila

Queue *qCreate (int max); 
/* Construir uma nova fila vazia
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

int qEnqueue(Queue *fila, void *elm ); 
/* Inserir o elemento no fim da fila
Pre-condição: (fila foi criada por qCreate) && (cabe um elemento na fila) && (item != NULL) 
Pos-condição: item foi adicionado ao rear da fila */

void *qDequeue(Queue *fila); 
/* Retira o elemento da frente da fila
Pre-condição: (s foi criada por qCreate) && (existe pelo menos um item na fila)
Pos-condição: elemento do front da fila foi retirado */

void *qFirst(Queue *fila);
/* retorna o atual elemento no inicio da fila
Pre-condição: (fila foi criada por qCreate) && (existe pelo menos um item na fila)
Pos-condição: o retorno é o item no front da fila */

int qIsEmpty( Queue *fila);
/* retorna se o numero de elementos é zero
Pre-condição: (fila foi criada por qCreate)
Pos-condição: retorna true se a fila estiver vazia, false se conter algum elemento */

int qDestroy (Queue *fila);
/* destroi a fila
Pre-condição: (fila foi criada por qCreate) && (não existem itens na fila)
Pos-condição: a fila foi destruida */

#endif /* __QUEUE_H */