/*-----------------------------------------------------------------------
Matriz.c
arquivo com a implementação para o TAD matriz em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _Matriz_C_
#define _Matriz_C_

/* Implementação do TAD fila como um vetor */
#include "Matriz.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTERR –1
#define FLOAT_ERR -1.0
#define TRUE 1 
#define FALSE 0

struct matriz{
 int lin;
 int col;
 float* v;
}Matrix;
 
 
Matriz * matCreate (int n, int m){
 Matriz *mat;
 if ( n > 0 && m > 0 ){
    mat = (Matriz*) malloc(sizeof(Matriz));
    if (mat != NULL){
        mat->lin = n;
        mat->col = m;
        mat->v = (float *) malloc(sizeof(float) *n *m);
        if(mat->v != NULL ){
          return mat;
        }
        free(mat);
    }
 }
 return NULL;
}

int matDestroy (Matriz* mat){
 if ( mat != NULL ){
    free(mat->v);
    free(mat);
    return TRUE;
    } 
 return FALSE;
}
 
float matGetElemIJ (Matriz *mat, int i, int j){
 int k; /* índice do elemento no vetor */
 if (mat != NULL ){
    if (i>=0 && i<mat->lin && j>=0 && j<mat->col){
        k = i*mat->col + j;
        return mat->v[k];
        }
    }
 return FLOAT_ERR;
 }
 
int matSetElemIJ (Matriz* mat, int i, int j, float v){
 
 int k; /* índice do elemento no vetor */
 if (mat != NULL ) {
    if (i >= 0 && i < mat->lin && j >= 0 && j < mat->col) {
        k = i*mat->col + j;
        mat->v[k] = v;
        return TRUE;
        }
    }
 return FALSE;
 }

int matGetNumLines (Matriz *mat){
 if ( mat != NULL ){
    return mat->lin;
    }
 return -1;
}

int matGetNumCollumns (Matriz* mat){
 if ( mat != NULL ) {
    return mat->col;
    }
 return -1;
}

Matriz* getransposta(Matriz* mat,int n, int m){
    if(mat != NULL && n > 0 && m > 0){
        Matriz *vmta = (Matriz*)malloc(sizeof(Matriz)*n*m);
        if(vmta != NULL){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m;j++){
                    vmta[j*n + i] = mat[i*m +j];
                }
            }
            return vmta;
        }
    }
    return NULL;
}

#endif /* __MATRIZ_C */