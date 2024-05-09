 /*-----------------------------------------------------------------------
Matriz.h
arquivo com as especificações para o TAD fila circular em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/
#ifndef Matriz_h
#define Matriz_h

// definições locais 

typedef struct matriz Matriz;  /* Tipo exportado */

Matriz * matCreate (int n, int m);
/* aloca e retorna uma matriz de dimensão n por m
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

int matDestroy (Matriz* mat);
/* libera a memória de uma matriz previamente criada
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

float matGetElemIJ (Matriz* mat, int i, int j);
/* retorna o valor do elemento da linha i e coluna j da matriz
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

int matSetElemIJ (Matriz* mat, int i, int j, float v);
/* atribui o valor do elemento da linha i e coluna j da matriz
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

int matGetNumLines (Matriz* mat);
/* retorna o numero de linhas da matriz
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

int matGetNumCollumns (Matriz* mat);
/* retorna o numero de linhas da matriz
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

Matriz getransposta(Matriz* mat,int n, int m);
/* retorna a transposição da matriz
Pre-condição: (max_itens > 0)
Pos-condição: retorna um ponteiro para uma fila vazia */

#endif /* __MATRIZ_H */
