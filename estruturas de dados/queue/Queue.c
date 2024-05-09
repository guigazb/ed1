/*-----------------------------------------------------------------------
Queue.c
arquivo com a implementação para o TAD fila em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _QUEUE_C_
#define _QUEUE_C_

/* Implementação do TAD fila como um vetor */
#include "Queue.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0


typedef struct queue{
    void **item;
    int maxItens;
    int rear;
    int front;
}Queue;

Queue *qCreate (int max){
    if(max > 0){
        Queue* fila = (Queue*)malloc(sizeof(Queue));
        if(fila != NULL){
            fila->item = (void**)malloc(sizeof(void*)*max);
            if(fila->item != NULL){
                fila->maxItens = max;
                fila->front = 0;
                fila->rear = -1;
                return fila;
            }
        }
        free(fila);
    }
    return NULL;
}


int qEnqueue(Queue *fila, void *elm ){
    if(fila != NULL){
        if(fila->rear < fila->maxItens-1){
            fila->rear++;
            fila->item[fila->rear] = elm;
            return true;
        }
    }
    return false;
}

void *qDequeue(Queue *fila){
    void* auxiliar;
    if(fila != NULL){
        if(fila->rear >= 0){
            auxiliar = fila->item[fila->front];
            for(int i = 0; i < fila->rear;i++){
                fila->item[i] = fila->item[i+1];
                fila-> rear--;
                return auxiliar;
            }
        }
    }
    return NULL;
}

void *qFirst(Queue *fila){
    void* auxiliar;
    if(fila != NULL){
        if(fila->rear >= 0){
            auxiliar = fila->item[fila->front];
            return auxiliar;
        }
    }
    return NULL;
}

int qIsEmpty(Queue *fila){
    if(fila != NULL){
        if(fila->rear < 0){
            return true;
        }
    }
    return false;
}

int qDestroy (Queue *fila){
    if(fila != NULL){
        if(fila->rear < 0){
            free(fila->item);
            free(fila);
            return true;
        }
    }
    return false;
}


#endif /* __QUEUE_C */