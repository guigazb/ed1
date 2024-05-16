/*-----------------------------------------------------------------------
Sllqueue.c
arquivo com a implementação para o TAD fila em lista simplesmente 
encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/

#ifndef _SLLQUEUE_C_
#define _SLLQUEUE_C_

/* Implementação do TAD fila implementado em lista */
#include "Sllqueue.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0

typedef struct sllnode{
    void* data;
    struct sllnode *next;
}Sllnode;

typedef struct sllqueue{
    Sllnode* first;
    Sllnode* last;
}Sllqueue;

Sllqueue *qlCreate (void){
    Sllqueue* qlista = (Sllqueue*)malloc(sizeof(Sllqueue));
    if(qlista != NULL){
        qlista->first = NULL;
        qlista->last = NULL;
        return qlista;
    }
    return NULL;
} 


int qlEnqueue(Sllqueue* qlista, void* data){
    if(qlista != NULL && data != NULL){
        Sllnode* newnode = (Sllnode*)malloc(sizeof(Sllnode));
        Sllnode* last;
        if(newnode != NULL){
            newnode->next = NULL;
            newnode->data = data;
            last = qlista->last;
            if(last != NULL){
                last->next = newnode;
            }else{
                qlista->first = newnode;
            }
            qlista->last = newnode;
            return true;
        }
    }
    return false;
}


void *qlDequeue(Sllqueue* qlista){
    if(qlista != NULL){
        if(qlista->first != NULL){
            void* data;
            Sllnode* del = qlista->first;
            data = del->data;
            if(qlista->first == qlista->last){
                qlista->first = NULL;
                qlista->last = NULL;
            }else{
                qlista->first = del->next;
            }
            free(del);
            return data;
        }
    }
    return NULL;
}


void *qlGetfirst(Sllqueue* qlista){
    if(qlista != NULL){
        if(qlista->first != NULL){
            void* data;
            Sllnode* retorno = qlista->first;
            data = retorno->data;
            free(retorno);
            return data;
        }
    }
    return NULL;
}

int qlDestroy (Sllqueue *qlista){
    if(qlista != NULL){
        if(qlista->first == NULL && qlista->last == NULL){
            free(qlista);
            return true;
        }
    }
    return false;
}

#endif /* __SLLQUEUE_C */