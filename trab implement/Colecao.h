/*-----------------------------------------------------------------------
Colecao.h
arquivo com as especificações para o TAD COLEÇÃO, trabalho de implementação
em Estrutura de dados 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/
#ifndef colecao_h
#define colecao_h
// definições locais
typedef struct  jogo Jogo;

//funções do TAD colecao int

/* cria um novo cofo
Pre-condicao: maxItems > 0
Pos-condicao: retorna o endereço de um novo TAD Cofo
(Inteiros) vazio ou NULL se não conseguir criar*/
Jogo *gameCreate(int maxItens);

/* Adiciona um item no Cofo
Pre-condicao : (c é um TAD Cofo criado por uma chamada a
cofCreate) e (o TAD Cofo nao esta cheio)
Pos-condicao: item foi adicionado ao TAD cofo*/
int gameInsert(Jogo *c, void* elemento);

/* Retira um item da colecao
Pre-condicao: (c é um TAD Colecao criado por uma chamada a
cofCreate) e && (existe pelo menos um item no TAD Cofo)
Pos-condicao: item foi eliminado do TAD cofo */
void *gameRemove(Jogo *c, void* elem, int(*cmp)(void*,void*)); 

/* Encontra um item em um TAD Cofo
Pre-condicao: c é um TAD Cofo criado por uma chamada a cofCreate
Pos-condicao: retorna TRUE se o item identificado por key ele existir no TAD cofo, ou FALSE caso contrátrio
*/
int *gameQuery(Jogo *c,void* elem ,int(*cmp)(void*,void*));

/* Destroi um TAD Cofo
Pre-condicao: c é um TAD Cofo criado por uma chamada a cofCreate e que está vazia
Pos-condicao: a memoria usada pelo TAD foi liberada
*/
int gameDestroy(Jogo *c);


/* retorna primeiro elemento do cofo
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: retorna o primeiro item do cofo
*/

void *gamegetfirst(Jogo *c);

/* pega o proximo elemento do cofo
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: retorna o elemento atual
*/

void *gameGetnext(Jogo *c);

/* pega o proximo elemento do cofo
pre-condição: c é um TAD cofo criado e preenchido inteiro ou parcialmente
pos-condição: esvazia o elemento
*/

int gameClean(Jogo *c);

#endif /* __COLECAO_H */
