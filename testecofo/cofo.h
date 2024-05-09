/*-----------------------------------------------------------------------
Cofo.h
arquivo com as especificações para o TAD COFO, trabalho de implementação
em Estrutura de dados 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/
#ifndef cofo_h
#define cofo_h
#include "cofo.c"

// definições locais
typedef struct cofo Cofo;

//funções do TAD cofo int

/* cria um novo cofo
Pre-condicao: maxItems > 0
Pos-condicao: retorna o endereço de um novo TAD Cofo
(Inteiros) vazio ou NULL se não conseguir criar*/
Cofo *cofCreate(int maxItens );

/* Adiciona um item no Cofo
Pre-condicao : (c é um TAD Cofo criado por uma chamada a
cofCreate) e (o TAD Cofo nao esta cheio)
Pos-condicao: item foi adicionado ao TAD cofo*/
int cofInsert(Cofo *c, int item );

/* Retira um item da colecao
Pre-condicao: (c é um TAD Cofo criado por uma chamada a
cofCreate) e && (existe pelo menos um item no TAD Cofo)
Pos-condicao: item foi eliminado do TAD cofo */
int cofRemove(Cofo *c, int item );

/* Encontra um item em um TAD Cofo
Pre-condicao: c é um TAD Cofo criado por uma chamada a cofCreate
Pos-condicao: retorna TRUE se o item identificado por key ele existir no TAD cofo, ou FALSE caso contrátrio
*/
int cofQuery(Cofo *c, int key,int(*cmp)(void *,void*));

/* Destroi um TAD Cofo
Pre-condicao: c é um TAD Cofo criado por uma chamada a cofCreate e que está vazia
Pos-condicao: a memoria usada pelo TAD foi liberada
*/
int cofDestroy(Cofo *c );

/* consulta se um inteiro está no cofo
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: retorna true se o elemento estiver no cofo
*/
int cofConsult(Cofo *c, int key);

/* retorna primeiro elemento do cofo
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: retorna o primeiro item do cofo
*/

int cofgetfirst(Cofo *c);

/* pega o proximo elemento do cofo
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: retorna o elemento atual
*/

int cofList(Cofo *c);

/* remove todos elementos do cofo e armazena em um lugar seguro
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: o TAD cofo será esvaziado, sua memória será liberada, e seus elementos 
serão salvos em um vetor de inteiros
*/
int cofClean(Cofo *c);

#endif /* __COFO_H */
