/*-----------------------------------------------------------------------
Twostacks.h
arquivo com as especificações para o TAD duas pilhas em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/
#ifndef TWOSTACKS_h
#define TWOSTACKS_h

// definições locais
typedef struct twostacks Twostacks;

//especificações para o tad pilha

Twostacks *tstkCreate (int max); 
/* Construir uma nova pilha
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma pilha vazia */

int tstkPush1(Twostacks *tpilha, void *elm); 
/* Inserir o elemento do topo da pilha
Pre-condição: (s foi criada por stkCreate) && (cabe  um elemento na pilha) && (item != NULL) 
Pos-condição: item foi adicionado ao topo da pilha s */

void *tstkPop1(Twostacks *tpilha); 
/* Retira o elemento no topo da pilha
Pre-condição: (s foi criada por stkCreate) && (existe pelo menos um item na pilha)
Pos-condição: elemento do topo da pilha foi removido */

int tstkPush2(Twostacks *tpilha, void *elm); 
/* Inserir o elemento do topo da pilha
Pre-condição: (s foi criada por stkCreate) && (cabe  um elemento na pilha) && (item != NULL) 
Pos-condição: item foi adicionado ao topo da pilha s */

void *tstkPop2(Twostacks *tpilha); 
/* Retira o elemento no topo da pilha
Pre-condição: (s foi criada por stkCreate) && (existe pelo menos um item na pilha)
Pos-condição: elemento do topo da pilha foi removido */


int tstkFull(Twostacks *tpilha);
/* retorna se ambas pilhas estão cheia
Pre-condição: (s foi criada por stkCreate) && (existe pelo menos um item na pilha)
Pos-condição: o retorno é o item no topo da pilha */

int tstk1IsEmpty(Twostacks *tpilha);
/* retorna se o numero de elementos é zero
Pre-condição: (s foi criada por stkCreate)
Pos-condição: retorna true se a pilha estiver vazia, false se conter algum elemento */

int tstkDestroy (Twostacks *tpilha);
/* destroi a piha
Pre-condição: (s foi criada por stkCreate) && (não existem itens na pilha)
Pos-condição: a pilha foi destruida */

#endif /* __TWOSTACKS_H */