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
            cfila->front = qinccirc(cfila->front,cfila->maxItens);
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
    if(cfila != NULL && key != NULL){
        int i, j;
        i = cfila->front;
        for (j = 0; j < cfila->nelms; j++){
        if (cmp(cfila->elms[i], key) == true){
            void *aux = cfila->elms[i];
            while(i < cfila->maxItens){
                int prox = qinccirc(i,cfila->maxItens);
                cfila->elms[i] = cfila->elms[prox];
                i = qinccirc(i,cfila->maxItens);
            }
            cfila->rear = qdeccirc(cfila->rear,cfila->maxItens);
            cfila->elms--;
            return aux;
        }
        i = qinccirc(i,cfila->maxItens);
      }    
    }
    return NULL;
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

//questao 4 prova 2023.1
int qremovelessthankey(Cqueue *cfila,void* key,int (*cmp)(void*,void*)){
    if(cfila != NULL && key != NULL){
        int i = cfila->front;
        while(cmp(key,cfila->elms[i]) != true){
            cfila->front = qinccirc(cfila->front,cfila->maxItens);
            cfila->nelms--;
            i = cfila->front;
            if(i == cfila->rear && cmp(key,cfila->elms[i]) != true){
                return false;
            }
        }
        return true;
    }
    return false;
}

//questao 2 prova 2023.2 e questao 3 2021.2
int PromoveElementoFila (Cqueue *cfila, int n){
    void*aux;
     int j;
     int nextj;
     if(cfila != NULL) {
         //se N for maior que a qtd de itens, o ultimo elemento é promovido ao primeiro
         if(n > cfila->nelms){
             cfila->front = qdeccir(cfila->front,cfila->maxItens);
             cfila->elms[cfila->front] = cfila->elms[cfila->rear];
             cfila->rear = qdeccir(cfila->rear,cfila->maxItens);
             return true;
         }else{//senão

             //começamos no inicio
             j = cfila->front;

             //for para chegar até o enésimo elemento (n-1), pois se queremos o 2 elemento, ele estará na posição 1 da fila.
             for(int i = 0; i < n-1; i++){
                 nextj = qinccirc(j,cfila->maxItens);
                 j = nextj;
             }
             //agora J está na posição do ENÉSIMO, logo guardamos seu valor numa variavel auxiliar
             aux = cfila->elms[j];

             //a partir de N até o final da fila, vamos puxar um elemento para frente, já que queremos remover N do meio
             for(int i = n; i < cfila->nelms; i++){
                 int nextj = incCirc(j,cfila->maxItens);
                 cfila->elms[j] = cfila->elms[nextj];
                 j = nextj;
             }
             //após remover N do meio, vamos decrementar rear e front, e depois colocar AUX no novo front
             cfila->rear = decCir(cfila->rear,cfila->maxItens);
             cfila->front = decCir(cfila->front, cfila->maxItens);
             cfila->elms[cfila->front] = aux;

        }
        return true;

    }
    return false;
}

//questao 2 - 2022.1
int PunePrimeiro(Cqueue *cfila, int n){
    void* aux;
    int j;
    int next;
    if(cfila != NULL && n > 0){
        if(cfila->nelms> 0){
            if(n < cfila->maxItens){
                aux = cfila->elms[cfila->front];
                for(j = 0; j< n; j++){
                    next = qinccirc(j,cfila->maxItens);
                    cfila->elms[j] = cfila->elms[next];
                    j = next;
                }
                cfila->elms[next] = aux;
                return true;
            }else{
                cfila->rear = qinccirc(cfila->rear,cfila->maxItens);
                cfila->elms[cfila->rear] = cfila->elms[cfila->front];
                cfila->front = qinccirc(cfila->front,cfila->maxItens);
            }
            return true;
        }
    }
    return false;
}

#endif /* __CCqueue_C */