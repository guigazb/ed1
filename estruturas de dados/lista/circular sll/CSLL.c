/*-----------------------------------------------------------------------
CSll.c
arquivo com a implementação para o TAD lista circular simplesmente encadeada 
em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/

#ifndef _CSLL_C_
#define _CSLL_C_

/* Implementação do TAD cslista */
#include "CSll.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0

typedef struct csllnode{
    void* data;
    struct csllnode *next;
}Csllnode;

typedef struct csllist{
    Csllnode* first;
    Csllnode* cur;
}Csllist;

Csllist *csllCreate (void){
    Csllist* cslista = (Csllist*)malloc(sizeof(Csllist));
    if(cslista != NULL){
        cslista->first = NULL;
        return cslista;
    }
    return NULL;
}

int csllInsertasfist( Csllist *cslista, void *data){
    if(cslista != NULL){
        Csllnode* newnode = (Csllnode*)malloc(sizeof(Csllnode));
        if(newnode != NULL){
            newnode->data = data;
            cslista->first = newnode;
            newnode->next = cslista->first;
            return true;
        } 
    }
    return false;
}


void *csllRemovefirst( Csllist *cslista){
    if(cslista != NULL){
        Csllnode* del;
        Csllnode* afterdel;
        void* data;
        if(cslista->first != NULL){
            del = cslista->first;
            data = del->data;
            afterdel = del->next;
            cslista->first = afterdel;
            free(del);
            return data;
        }
    }
    return NULL;
}


void *csllGetfirst( Csllist *cslista){
    if(cslista != NULL){
        Csllnode* salvo;
        void* data;
        if(cslista->first != NULL){
            salvo = cslista->first;
            data = salvo->data;
            return data;
        }
    }
    return NULL;
}

void *csllGetfirstcur( Csllist *cslista){ // necessário para getnext funcionar
    if(cslista != NULL){
        if(cslista->first != NULL){
            cslista->cur = cslista->first;
            return cslista->cur->data;
        }
    }
    return NULL;
}

int csllInsertAsLast(Csllist* cslista,void* data){
    if(cslista != NULL){
        Csllnode* newnode = (Csllnode*)malloc(sizeof(Csllnode));
        Csllnode* last;
        if(newnode != NULL){
            newnode->data = data;
            if(cslista->first == NULL){
                cslista->first = newnode;
            }else{
                last = cslista->first;
                while(last->next != cslista->first){
                    last = last->next;
                }
                last->next = newnode;
            }
            newnode->next = cslista->first;
            return true;
        }
    }
    return false;
}

void *csllRemovelast( Csllist *cslista){
    if(cslista != NULL){
        Csllnode* del;
        Csllnode* beforedel;
        void* data;
        if(cslista->first != NULL){
            del = cslista->first;
            while(del->next != NULL){
                beforedel = del;
                del = del->next;
            }
            beforedel->next = NULL;
            data = del->data;
            free(del);
        
         return data;
    }
    }
    return NULL;
}

void* csllGetLast (Csllist* cslista){
    if(cslista != NULL){
        Csllnode* last;
        void* data;
        if(cslista->first != NULL){
            last = cslista->first;
            while(last->next != NULL){
                last = last->next;
            }
            data = last->data;
         return data;
    }
    }
    return NULL;
}

int csllNumNodes(Csllist* cslista){
    if(cslista != NULL){
        Csllnode* last;
        int num;
        if(cslista->first != NULL){
            last = cslista->first;
            num++;
            while(last->next != cslista->first){
                num++;
                last = last->next;
            }  
         return num;
        }
    }
    return -1;
}

int csllInsertafterespec(Csllist* cslista,void* data,void*key ,int(*cmp)(void*,void*)){
    if(cslista != NULL && data != NULL){
        Csllnode* newnode = (Csllnode*)malloc(sizeof(Csllnode));
        if(newnode != NULL){
            Csllnode* prev = cslista->first;
            Csllnode* spec = prev->next;
            newnode->data = data;
            newnode->next = NULL;
            int stat = cmp(key,spec->data);
            while(stat != true && spec != cslista->first){
                prev = spec;
                spec = spec->next;
                stat = cmp(key,spec->data);
            }
            if(stat == true){
                Csllnode* next = spec->next;
                newnode->next = next;
                spec->next = newnode;
            }
            return true;
        }
    }
    return false;
}

int csllInsertbeforespec(Csllist* cslista,void* data,void*key,int(*cmp)(void*,void*)){
    if ( cslista != NULL) {
        if ( cslista->first != NULL) {
            Csllnode *prev = cslista->first;
            Csllnode *spec = prev->next;
            int stat = cmp(spec->data,key);
            while(stat != true && spec != cslista->first){
                prev = spec; 
                spec= spec->next;
                stat = cmp(spec->data, key);
            }
            if(stat == true){
                Csllnode* newnode = (Csllnode *) malloc(sizeof(Csllnode));
                if(newnode != NULL){
                    newnode->data = data;
                    newnode->next = spec;
                    if(spec == cslista->first){
                        cslista->first = newnode;
                    }
                    prev->next = newnode;
                    return true;
                }
            }
        }
    }
    return false;
}

void* csllQueryspec(Csllist* cslista, void*key,int(*cmp)(void*,void*)){
    if(cslista != NULL && key != NULL){
        if(cslista->first != NULL){
            Csllnode* atual = cslista->first;
            int stat = cmp(atual->data,key);
            while(stat != true && atual->next != NULL){
                atual = atual->next;
                stat = cmp(atual->data,key);
            }
            if(stat == true){
                return atual->data;
            }
        }
    }
    return NULL;
}

void* csllRemovespec(Csllist* cslista,void* key,int(*cmp)(void*,void*)){
    if(cslista != NULL && key != NULL){
        if(cslista->first != NULL){
        Csllnode* prev = cslista->first;
        Csllnode* spec = prev->next;
        void* salvo;
        int stat = cmp(key,spec->data);
        while(stat != true && spec != cslista->first){
            prev = spec;
            spec = spec->next;
            stat = cmp(key,spec->data);
        }
        if(stat == true){
            prev->next = spec->next;
            salvo = spec->data;
            if(cslista->first == spec){
                if(spec->next == spec){
                    cslista->first = NULL;
                }else{
                    cslista->first = spec->next;
                }
            }
            free(spec);
            return salvo; 
        } 
       }
    }
    return NULL;
}

void* csllGetnext(Csllist* cslista){
    if(cslista != NULL){
        if(cslista->cur != NULL){
            cslista->cur = cslista->cur->next;
            return cslista->cur->data;
        }
    }
    return NULL;
}

int csllDestroy (Csllist *cslista){
    if(cslista != NULL){
        if(cslista->first == NULL){
            free(cslista);
            return true;
        }
    }
    return false;
}

#endif /* __CSLL_C */