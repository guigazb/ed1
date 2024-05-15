/*-----------------------------------------------------------------------
Sll.c
arquivo com a implementação para o TAD lista simplesmente encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/

#ifndef _SLL_C_
#define _SLL_C_

/* Implementação do TAD lista */
#include "Sll.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0

typedef struct sllnode{
    void* data;
    struct sllnode *next;
}Sllnode;

typedef struct sllist{
    Sllnode* first;
}Sllist;

Sllist *sllCreate (void){
    Sllist* lista = (Sllist*)malloc(sizeof(Sllist));
    if(lista != NULL){
        lista->first = NULL;
        return lista;
    }
    return NULL;
}

int sllInsertasfist( Sllist *lista, void *data){
    if(lista != NULL){
        Sllnode* newnode = (Sllnode*)malloc(sizeof(Sllnode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = lista->first; // = NULL
            lista->first = newnode;
            return true;
        } 
    }
    return false;
}


void *sllRemovefirst( Sllist *lista){
    if(lista != NULL){
        Sllnode* del;
        Sllnode* afterdel;
        void* data;
        if(lista->first != NULL){
            del = lista->first;
            data = del->data;
            afterdel = del->next;
            lista->first = afterdel;
            free(del);
            return data;
        }
    }
    return NULL;
}


void *sllGetfirst( Sllist *lista){
    if(lista != NULL){
        Sllnode* salvo;
        void* data;
        if(lista->first != NULL){
            salvo = lista->first;
            data = salvo->data;
            free(salvo);
            return data;
        }
    }
    return NULL;
}

// os métodos que buscam o ultimo elemento não são práticos, pois eles percorrem a lista inteira para descobrir o ultimo elemento

int sllInsertAsLast(Sllist* lista,void* data){
    if(lista != NULL){
        Sllnode* newnode = (Sllnode*)malloc(sizeof(Sllnode));
        Sllnode* last;
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;
            if(lista->first == NULL){
                lista->first = newnode;
            }else{
                last = lista->first;
                while(last->next != NULL){
                    last = last->next;
                }
                last->next = newnode;
            }
            return true;
        }
    }
    return false;
}

void *sllRemovelast( Sllist *lista){
    if(lista != NULL){
        Sllnode* del;
        Sllnode* beforedel;
        void* data;
        if(lista->first == NULL){
            return NULL;
        }else{
            del = lista->first;
            while(del->next != NULL){
                beforedel = del;
                del = del->next;
            }
            beforedel->next = NULL;
            data = del->data;
            free(del);
        }
         return data;
    }
    return NULL;
}

void* sllGetLast (Sllist* lista){
    if(lista != NULL){
        Sllnode* last;
        void* data;
        if(lista->first == NULL){
            return NULL;
        }else{
            last = lista->first;
            while(last->next != NULL){
                last = last->next;
            }
            data = last->data;
        }
         return data;
    }
    return NULL;
}

int sllNumNodes(Sllist* lista){
    if(lista != NULL){
        Sllnode* last;
        int num;
        if(lista->first == NULL){
            return 0;
        }else{
            last = lista->first;
            num++;
            while(last->next != NULL){
                num++;
                last = last->next;
            }  
        }
         return num;
    }
    return -1;
}

int sllDestroy (Sllist *lista){
    if(lista != NULL){
        if(lista->first == NULL){
            free(lista);
            return true;
        }
    }
    return false;
}

#endif /* __SLL_C */