/*-----------------------------------------------------------------------
Twostacks.c
arquivo com a implementação para o TAD pilha em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _TWOSTACKS_C_
#define _TWOSTACKS_C_

/* Implementação do TAD duas pilha como um vetor */
#include "Twostacks.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0


typedef struct twostacks{
    void **item;
    int maxItens;
    int top1;
    int top2;
}Twostacks;

Twostacks *tstkCreate (int max){
    Twostacks* tpilha;
    if(max > 0){
        tpilha = (Twostacks*)malloc(sizeof(Twostacks));
        if(tpilha != NULL){
            tpilha->item = (void**)malloc(sizeof(void*)*max);
            if(tpilha->item != NULL){
                tpilha->top1 = -1;
                tpilha->top2 = max;
                tpilha->maxItens = max;
                return tpilha;
            }
        }
        free(tpilha);
    }
    return NULL;
}

int tstkPush1(Twostacks *tpilha, void *elm){
    if(tpilha != NULL){
        if((tpilha->top2 - tpilha->top1) > 1){
            tpilha->top1++;
            tpilha->item[tpilha->top1] = elm;
            return true;
        }
    }
    return false;
}

void *tstkPop1(Twostacks *tpilha){
    void* auxiliar;
    if(tpilha!= NULL){
        if(tpilha->top1 >= 0){
            auxiliar = tpilha->item[tpilha->top1];
            tpilha->top1--;
            return auxiliar;
        }
    }
    return NULL;
}

int tstkPush2(Twostacks *tpilha, void *elm){
    if(tpilha != NULL){
        if((tpilha->top2 - tpilha->top1) > 1){
            tpilha->top2--;
            tpilha->item[tpilha->top2] = elm;
            return true;
        }
    }
    return false;
}

void *tstkPop2(Twostacks *tpilha){
    void* auxiliar;
    if(tpilha != NULL){
        if(tpilha->top2 < tpilha->maxItens){
            auxiliar = tpilha->item[tpilha->top2];
            tpilha->top2 ++;
            return auxiliar;
        }
    }
    return NULL;
}

int tstk1IsEmpty(Twostacks *tpilha){
    if(tpilha != NULL){
        if(tpilha->top1 + 1 == tpilha->top2){
            return true;
        }
    }
    return false;
}

int tstk2IsEmpty(Twostacks *tpilha){
    if(tpilha != NULL){
        if(tpilha->top2 - 1 == tpilha->top1){
            return true;
        }
    }
    return false;
}

int tstkFull(Twostacks *tpilha){
    if(tpilha != NULL){
        if((tpilha->top2 - tpilha->top1) <= 1){
            return true;
        }
    }
    return false;
}

#endif /* __TWOSTACKS_C */