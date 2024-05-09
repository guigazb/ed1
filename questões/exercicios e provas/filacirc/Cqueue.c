/*-----------------------------------------------------------------------
Cqueue.c
arquivo com a implementação para o TAD fila em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _Cqueue_C_
#define _Cqueue_C_

/* Implementação do TAD fila como um vetor */
#include "Cqueue.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0


typedef struct cqueue{
    void **elms;
    int maxItens;
    int rear;
    int front;
    int nelms;
}Cqueue;

Cqueue *cqCreate (int max){
    if(max > 0){
        Cqueue* cfila = (Cqueue*)malloc(sizeof(Cqueue));
        if(cfila != NULL){
            cfila->elms = (void**)malloc(sizeof(void*)*max);
            if(cfila->elms != NULL){
                cfila->maxItens = max;
                cfila->front = 0;
                cfila->rear = -1;
                cfila->nelms = 0;
                return cfila;
            }
        }
        free(cfila);
    }
    return NULL;
}


int cqEnqueue(Cqueue *cfila, void *elm,int (*incCirc)(int i,int max)){
    if(cfila != NULL){
        if(cfila->nelms < cfila->maxItens){
            cfila->rear = incCirc(cfila->rear,cfila->maxItens);
            cfila->elms[cfila->rear] = elm;
            cfila->nelms++;
            return true;
        }
    }
    return false;
}

void *cqDequeue(Cqueue *cfila){
    void* auxiliar;
    if(cfila != NULL){
        if(cfila->nelms > 0){
            auxiliar = cfila->elms[cfila->front];
            cfila->front = incCirc(cfila->front,cfila->maxItens);
            return auxiliar;
        }
    }
    return NULL;
}

void *cqFirst(Cqueue *cfila){
    void* auxiliar;
    if(cfila != NULL){
        if(cfila->nelms > 0){
            auxiliar = cfila->elms[cfila->front];
            return auxiliar;
        }
    }
    return NULL;
}

int cqIsEmpty(Cqueue *cfila){
    if(cfila != NULL){
        if(cfila->nelms <= 0){
            return true;
        }
    }
    return false;
}

int cqDestroy (Cqueue *cfila){
    if(cfila != NULL){
        if(cfila->nelms <= 0){
            free(cfila->elms);
            free(cfila);
            return true;
        }
    }
    return false;
}

//questão 4
//4.1
void *cqGetLast(Cqueue *cfila){
    if(cfila!= NULL){
        if(cfila->nelms > 0){
            void* auxiliar = cfila->elms[cfila->rear];
            return auxiliar;
        }
    }
    return NULL;
}

//4.2
int  cqEnqueueN(Cqueue *cfila, int n, void **elms){
    if(cfila != NULL){
        if(n < cfila->maxItens){
            for(int i = 0; i < n; i++){
                cqEnqueue(cfila,elms[i],incCirc(cfila->rear,cfila->maxItens));
            }
            return true;
        }
    }
    return false;
}

//4.3
void *cqDequeueN(Cqueue *cfila, int n){
    if(cfila != NULL){
        void** elementos = (void**)malloc(sizeof(void*)*n);
        if(elementos != NULL){
            for(int i = 0; i < n; i++){
                elementos[i] = cqDequeue(cfila);
            }
            return elementos;
        }
        free(elementos);
    }
    return NULL;
}

//4.4
void *cqDequeueSpecified(Cqueue *cfila, void *key, int (*cmp)(void *, void *)){
    if(cfila != NULL){
        
    }
}

//questão 10
int cqReorganiza(Cqueue* cfila){
    if(cfila != NULL){
        while(cfila->front != 0){
            int i = cfila->front;
            int anterior = qdeccirc(i , cfila->maxItens);
            for(int j = 0; j < cfila->nelms ; j++){
                cfila->elms[anterior] = cfila->elms[i];
            }
            cfila->front = qdeccirc(cfila->front , cfila->maxItens);
            cfila->rear = qdeccirc(cfila->rear , cfila->maxItens);
        }
    }
}

int qdeccirc(int atual, int max){
    if(atual > 0){
        atual--;
        return atual;
    }else{
        atual = max;
        return atual;
    }
}

int qinccirc(int atual,int max){
    if(atual < max){
        atual++;
        return atual;
    }else{
        atual = 0;
        return atual;
    }
}

#endif /* __CCqueue_C */