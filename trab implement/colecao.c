/*-----------------------------------------------------------------------
colecao.c
arquivo com a implementação para o TAD colecao
trabalho de implementação em Estrutura de dados 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _COLECAO_C_
#define _COLECAO_C_

/* Implementação do TAD Colecao como um vetor */
#include "colecao.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0


typedef struct jogo{
    void **item;
    int numItens;
    int maxItens;
    int current;
}Jogo;


Jogo *gameCreate(int maxItens){
    Jogo *c;
    if(maxItens > 0){
        c = (Jogo*)malloc(sizeof(Jogo));
        if(c!= NULL){
            c->item = (void**)malloc(sizeof(void*) * maxItens);
            if(c ->item != NULL){
                c ->numItens = 0;
                c ->maxItens = maxItens;
                c-> current = 0;
                return c;
            }
        } 
        free(c);  
    }
    return NULL;
}

int gameInsert(Jogo *c, void* elemento){
    if(c != NULL){
        if(c->numItens < c->maxItens){
            c->item[c->numItens] = elemento;
            c->numItens++;
            return true;
        }
    }
    return false;
}

void *gameRemove(Jogo *c,void*elem,int(*cmp)(void*,void*)){
    int i = 0, j = 0, stat;
    void* lugarseguro;
    
    if(c != NULL && elem != NULL){
       if(c->numItens > 0){
            stat = cmp(c ->item[i],elem);
        while(stat != true && i< c->numItens){
           i++;
           stat = cmp(c->item[i],elem);
           if(stat == true){
            lugarseguro = c->item[i];
            for(j = i; j < c->numItens-1 ; j++){
                c->item[j] = c->item[j+1];
            }
            c->numItens--;
            return lugarseguro;
           } 
        }
        }
    }
    return NULL;
}

int *gameQuery(Jogo *C,void*elem, int(*cmp)(void *,void*)){
    int stat, i = 0;
    if(C != NULL && elem != NULL ){
        if(C->numItens > 0){
            stat = cmp(C->item[i] , elem);
            while(stat != true && i < C->numItens){
                i++;
                stat = cmp(C->item[i] ,elem);
            }
            if(stat == true){
                return C->item[i];
            }
        }
    }
    return false;
}

int gameDestroy(Jogo *c){
    if(c != NULL){
        if(c->numItens <= 0){
            free(c->item);
            free(c);
            return true;
        }
        return false;
    }
    return -1;
}


void *gamegetfirst(Jogo *c){
    if(c != NULL){
        if(c->numItens > 0){
            c-> current = 0;
            return c->item[c->current];
        }
    }
    return NULL;
}
void *gameGetnext(Jogo *c){
    if(c != NULL){
        if(c->current < c->numItens -1){
            c->current ++;
            return c->item[c->current];
        }
    }
    return NULL;
}

int gameClean(Jogo *c){
    if(c!= NULL){
        c->current = 0;
        c->numItens = 0;
        return true;
    }
    return false;
}

#endif /* __COLECAO_C */