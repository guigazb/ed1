/*-----------------------------------------------------------------------
Stack.c
arquivo com a implementação para o TAD pilha em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _STACK_C_
#define _STACK_C_

/* Implementação do TAD pilha como um vetor */
#include "Stack.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0


typedef struct stack{
    void **item;
    int maxItens;
    int top;
}Stack;

Stack *stkCreate(int max){
    if(max > 0){   
        Stack *pilha = (Stack*)malloc(sizeof(Stack));
        if(pilha != NULL){
            pilha->item = (void**)malloc(sizeof(void*)* max);
            if(pilha->item != NULL){
                pilha->maxItens = max;
                pilha->top = -1;
                return pilha;
            }
        }
        free(pilha);
    }
    return NULL;
}


int stkPush(Stack *pilha, void *elm){
    if(pilha != NULL && elm != NULL){
        if(pilha->top < pilha->maxItens - 1){
            pilha->top ++;
            pilha->item[pilha->top] = elm;
            return true;
        }
    }
    return false;
}

void *stkPop(Stack *pilha){
    void* auxiliar;
    if(pilha != NULL){
        if(pilha->top >= 0){
            auxiliar = pilha->item[pilha->top];
            pilha->top--;
            return auxiliar;
        }
    }
    return NULL;
}


void *stkTop(Stack *pilha){
    void* auxiliar;
    if(pilha != NULL){
        if(pilha->top >= 0){
            auxiliar = pilha->item[pilha->top];
            return auxiliar;
        }
    }
    return NULL;
}


int stkIsEmpty(Stack *pilha){
    if(pilha != NULL){
        if(pilha->top < 0){
            return true;
        }
    }
    return false;
}


int stkDestroy(Stack *pilha){
    if(pilha != NULL){
        if(pilha->top < 0){
            free(pilha->item);
            free(pilha);
            return true;
        }
    }
    return false;
}

//questão 3

void* stkMultipop(Stack* pilha,int k){
    if(pilha != NULL){
        void* aux[k];
        for(int i = 0; i < k; i++){
            if(stkIsempty(pilha) == true){
                return aux;
            }else{
                aux[i] = stkPop(pilha);
            }
        }
    }
    return NULL;
}


#endif /* __STACK_C */