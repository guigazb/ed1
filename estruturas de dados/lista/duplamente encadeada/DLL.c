/*-----------------------------------------------------------------------
Dll.c
arquivo com a implementação para o TAD dlista duplamente encadeada em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/

#ifndef _DLL_C_
#define _DLL_C_

/* Implementação do TAD dlista */
#include "Dll.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0

typedef struct dllnode{
    void* data;
    struct dllnode *next;
    struct dllnode *prev;
}Dllnode;

typedef struct dllist{
    Dllnode* first;
    Dllnode* cur;
}Dllist;

Dllist *dllCreate (void){
    Dllist* dlista = (Dllist*)malloc(sizeof(Dllist));
    if(dlista != NULL){
        dlista->first = NULL;
        dlista->cur = NULL;
        return dlista;
    }
    return NULL;
}

int dllInsertasfist( Dllist *dlista, void *data){
    if(dlista != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = dlista->first; 
            newnode->prev = NULL;
            if(dlista->first != NULL){
                dlista->first->prev = newnode;
            }
            dlista->first = newnode;
            return true;
        } 
    }
    return false;
}


void *dllRemovefirst( Dllist *dlista){
    if(dlista != NULL){
        Dllnode* del;
        Dllnode* afterdel;
        void* data;
        if(dlista->first != NULL){
            del = dlista->first;
            data = del->data;
            afterdel = del->next;
            dlista->first = afterdel;
            free(del);
            return data;
        }
    }
    return NULL;
}


void *dllGetfirst( Dllist *dlista){ // necessário para getnext funcionar
    if(dlista != NULL){
        void* retorno;
        if(dlista->first != NULL){
            dlista->cur = dlista->first;
            retorno = dlista->cur->data;
            return retorno;
        }
    }
    return NULL;
}

void* dllGetnext(Dllist* dlista){
    if(dlista != NULL){
        void* retorno;
        if(dlista->cur != NULL){
            if(dlista->cur->next != NULL){
                dlista->cur = dlista->cur->next;
                retorno = dlista->cur->data;
                return retorno;
            }
        }
    }
    return NULL;
}

int dllInsertAsLast(Dllist* dlista,void* data){
    if(dlista != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        Dllnode* last;
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;
            if(dlista->first == NULL){
                dlista->first = newnode;
                newnode->prev = NULL;
            }else{
                last = dlista->first;
                while(last->next != NULL){
                    last = last->next;
                }
                last->next = newnode;
                newnode->prev = last;
            }
            return true;
        }
    }
    return false;
}

void *dllRemovelast( Dllist *dlista){
    if(dlista != NULL){
        Dllnode* del;
        Dllnode* beforedel;
        void* data;
        if(dlista->first != NULL){
            del = dlista->first;
            if(del->next == NULL){
                data = del->data;
                dlista->first = NULL;
                free(del);
                return data; 
            }
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


int dllNumNodes(Dllist* dlista){
    if(dlista != NULL){
        Dllnode* last;
        int num = 0;
        if(dlista->first != NULL){
            last = dlista->first;
            num++;
            while(last->next != NULL){
                num++;
                last = last->next;
            }  
         return num;
    }
    }
    return -1;
}

int dllInsertafterespec(Dllist* dlista,void* data,void* key, int(*cmp)(void*,void*)){
    if(dlista != NULL && data != NULL && key != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        if(newnode != NULL){
            if(dlista->first != NULL){
                Dllnode* spec = dllGetspec(dlista,key,cmp);
                if(spec != NULL){
                    newnode->data = data;
                    newnode->prev = spec;
                    Dllnode* next = spec->next;
                    newnode->next = next;
                    spec->next = newnode;
                    if(next != NULL){
                        next->prev = newnode;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

int dllInsertbeforespec(Dllist* dlista,void* data,void* key,int(*cmp)(void*,void*)){
    if(dlista != NULL && data != NULL && key != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        if(newnode != NULL){
            if(dlista->first != NULL){
                Dllnode* spec = dllGetspec(dlista,key,cmp);
                if(spec != NULL){
                    newnode->data = data;
                    Dllnode* prev = spec->prev;
                    newnode->prev = prev;
                    newnode->next = spec;
                    spec->prev = newnode;
                    if(prev == NULL){
                        dlista->first = newnode;
                    }else{
                        prev->next = newnode;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void* dllQueryspec(Dllist* dlista, void*key,int(*cmp)(void*,void*)){
    if(dlista != NULL && key != NULL){
        if(dlista->first != NULL){
            Dllnode* atual = dlista->first;
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

void* dllRemovespec(Dllist* dlista,void* key,int(*cmp)(void*,void*)){
    if(dlista != NULL && key != NULL){
        if(dlista->first != NULL){
        Dllnode* spec = dlista->first;
        Dllnode* next;
        Dllnode* prev;
        void* data;
        int stat = cmp(key,spec->data);
        while(stat != true && spec->next != NULL){
            spec = spec->next;
            stat = cmp(key,spec->data);
        }
        if(stat == true){
            next = spec->next;
            prev = spec->prev;
            data = spec->data;
            if(next != NULL){
                next->prev = prev;
            }
            if(prev != NULL){
                prev->next = next;
            }else{
                dlista->first = next;
            }
            free(spec);
            return data;
        }
       }
    }
    return NULL;
}

Dllnode* dllGetspec(Dllist* dlista,void* key,int(*cmp)(void*,void*)){
    if(dlista != NULL){
        if(dlista->first != NULL){
            Dllnode* cur = dlista->first;
            int stat = cmp(cur->data,key);
            while(stat != true &&cur->next != NULL){
                cur = cur->next;
                stat = cmp(key,cur->data);
            }
            if(stat == true){
                return cur;
            }
        }
    }
    return NULL;
}

int dllDestroyNotEmpty(Dllist *dlista, int (*myfree)(void *)){
    Dllnode* cur, *prev;
    if(dlista != NULL){
        if(dlista->first != NULL){
            cur = dlista->first;
            while(cur != NULL ){
                myfree(cur->data);
                prev = cur;
                cur = cur->next;
                free (prev);
            }
        }
        free(dlista);
        return true;
    }
    return false;
}


int dllDestroy (Dllist *dlista){ // destroi apenas listas vazias
    if(dlista != NULL){
        if(dlista->first == NULL){
            free(dlista);
            return true;
        }
    }
    return false;
}

#endif /* __DLL_C */