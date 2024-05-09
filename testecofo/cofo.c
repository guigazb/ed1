/*-----------------------------------------------------------------------
Cofo.c
arquivo com a implementação para o TAD COFO
trabalho de implementação em Estrutura de dados 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
Abril/2024
------------------------------------------------------------------------*/

#ifndef _COFO_C_
#define _COFO_C_

/* Implementação do TAD Cofo como um vetor */
#include "cofo.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>

#define true  1
#define false 0

typedef struct cofo{
int numItens; // número de caboco dentro do cofo
int maxItens; // número de caboco que posso bota dentro do cofo.
int current; // indice atual
int *item; //vetor para guardar os cabocos.
}Cofo;

Cofo *cofCreate(int maxItens){
    Cofo *c;
    if(maxItens > 0){
        c = (Cofo*)malloc(sizeof(Cofo));
        if(c!= NULL){
            c->item = (int*)malloc(sizeof(int) * maxItens);
            if(c ->item != NULL){
                c ->numItens = 0;
                c ->maxItens = maxItens;
                c-> current = 0;
                return c;
            }
            //free(c);
        } 
    }
    return NULL;
}

int cofInsert(Cofo *c,int item){
    if(c != NULL){
        if(c->numItens < c->maxItens){
            c->item[c->numItens] = item;
            c->numItens ++;
            return true;
        }
    }
    return false;
}

int cofRemove(Cofo *c,int key){
    int i = 0, lugarseguro, j = 0;
    if(c != NULL){
        if(c->numItens != 0)
        while(i < c->numItens && key != c->item[i]){
           i++;
           if(key == c->item[i]){
            lugarseguro = c->item[i];
            for(j = i; j < c->numItens-1 ; j--){
                c->item[j] = c->item[j+1];
            }
            c->numItens--;
            return lugarseguro;
           } 
        }
    }
    return -1;
}

int cofQuery(Cofo *C, int key,int(*cmp)(void *,void*)){
    int stat, i = 0;
    if(C != NULL){
        if(C->numItens > 0){
            stat = cmp(C->item[i] , key);
            while(stat != true && i < C->numItens){
                i++;
                stat = cmp(C->item[i] ,key);
            }
            if(stat == true){
                return C->item[i];
            }
        }
    }
    return false;
}

int cofDestroy(Cofo *c){
    if(c != NULL){
        if(c->numItens <= 0){
            free(c->item);
            free(c);
            return true;
        }
    }
    return false;
}

int cofConsult(Cofo *c, int key){
    int i = 0;
    if(c != NULL){
        if(c->numItens != 0)
        while(i < c->numItens && key != c->item[i]){
           i++;
           if(key == c->item[i]){
            return true;
           } 
        }
        return false;
    }
    return -1;

}

int cofgetfirst(Cofo *c){
    if(c != NULL){
        if(c->numItens > 0){
            return c->item[0];
        }
    }
    return false;
}
int cofList(Cofo *c){
    if(c != NULL){
        if(c->current < c->numItens){
            c->current ++;
            return c->item[c->current];
        }
    }
    return 0; // null na versão ponteiro
}

int cofClean(Cofo *c){ return 1;}
#endif