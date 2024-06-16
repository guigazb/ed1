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
            newnode->next = dlista->first; // = NULL
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


void *dllRemovefirst(Dllist *dlista){
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
                del->prev = del;
                del = del->next;
            }
            del->prev->next = NULL;
            data = del->data;
            free(del);
            return data;
        }
    }
    return NULL;
}

void* dllGetLast (Dllist* dlista){
    if(dlista != NULL){
        Dllnode* last;
        void* data;
        if(dlista->first != NULL){
            last = dlista->first;
            while(last->next != NULL){
                last = last->next;
            }
            data = last->data;
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
        Dllnode* del = dlista->first;
        Dllnode* next;
        Dllnode* prev;
        void* salvo;
        int stat = cmp(key,del->data);
        while(stat != true && del->next != NULL){
            del = del->next;
            stat = cmp(key,del->data);
        }
        if(stat == true){
            next = del->next;
            prev = del->prev;
            salvo = del->data;
            if(next != NULL){
                next->prev = prev;
            }
            if(prev != NULL){
                prev->next = next;
            }else{
                dlista->first = next;
            }
            free(del);
            return salvo; 
        }
       }
    }
    return NULL;
}

void* removeK(Dllist* lista,int k){
    if(lista != NULL && k > 0){
        if(lista->first != NULL){
            Dllnode* spec = lista->first;
            void* salvo;
            for(int i = 0; i < k; i++){
                spec = spec->next;
            }
            salvo = spec->data;
            Dllnode* prev = spec->prev;
            prev->next = spec->next;
            Dllnode* next = spec->next;
            next->prev = prev;
            free(spec);
            return salvo;
        }
    }
    return NULL;
}

int *dllEInversa(Dllist *l1, Dllist *l2, int(*cmp)( void *, void *)){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){
            Dllnode* cur1 = l1->first;
            Dllnode* cur2 = l2->first;
            while(cur2->next != NULL){
                cur2 = cur2->next;
            }
            int stat = cmp(cur1->data,cur2->data);
            while(stat == true && cur1 != NULL && cur2 != NULL){
                cur1 = cur1->next;
                cur2 = cur2->prev;
                if(cur1 != NULL && cur2 != NULL){
                    stat = cmp(cur1->data,cur2->data);
                }else{
                    stat = false;
                }
            }
            if(cur1 == NULL && cur2 == NULL){
                return true;
            }else{
                return false;
            }
        }
    }
    return -1;
}

int trocaIJ(Dllist* lista,int i, int j){
    if(lista != NULL && i != 0 && j != 0){
        if(lista->first != NULL){
            Dllnode* cur1 = lista->first;
            Dllnode* cur2 = lista->first;
            for(int k = 0; k < i;k++){
                cur1 = cur1->next;
            }
            for(int l = 0; l < j;l++){
                cur2 = cur2->next;
            }
            if(cur1 != NULL && cur2 != NULL){
                Dllnode* prev1 = cur1->prev;
                Dllnode* prev2 = cur2->prev;
                Dllnode* next1 = cur1->next;
                Dllnode* next2 = cur2->next;
                if(prev1 == NULL){
                    lista->first = cur2;
                    cur2->prev = NULL;
                    cur2->next = next1;
                    next1->prev = cur2;
                    prev2->next = cur1;
                    cur1->prev = prev2;
                    next2->prev = cur1;
                    cur1->next = next2;
                }else if(prev2 == NULL){
                    lista->first = cur1;
                    cur1->prev = NULL;
                    cur1->next = next2;
                    next2->prev = cur1;
                    prev1->next = cur2;
                    cur2->prev = prev1;
                    next1->prev = cur2;
                    cur2->next = next1;
                }else{
                    prev1->next = cur2;
                    cur2->prev = prev1;
                    next1->prev = cur2;
                    cur2->next = next1;
                    prev2->next = cur1;
                    cur1->prev = prev2;
                    next2->prev = cur1;
                    cur1->next = next2;
                }
                return true;
            }
            return false;
        }
    }
    return -1;
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