/*-----------------------------------------------------------------------
CDll.c
arquivo com a implementação para o TAD lista circular duplamente encadeada
em ED 1 
professor: Anselmo Cardoso de Paiva
-------------------------------------------------------------------------
Aluno: Guilherme Barrio Nascimento
maio/2024
------------------------------------------------------------------------*/

#ifndef _CDLL_C_
#define _CDLL_C_

/* Implementação do TAD dlista */
#include "CDll.h" /* inclui a especificacao do TAD */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true  1
#define false 0

typedef struct cdllnode{
    void* data;
    struct cdllnode *next;
    struct cdllnode *prev;
}Cdllnode;

typedef struct cdllist{
    Cdllnode* first;
    Cdllnode* cur;
}Cdllist;

Cdllist *cdllCreate (void){
    Cdllist* cdlista = (Cdllist*)malloc(sizeof(Cdllist));
    if(cdlista != NULL){
        cdlista->first = NULL;
        cdlista->cur = NULL;
        return cdlista;
    }
    return NULL;
}

int cdllInsertasfist( Cdllist *cdlista, void *data){
    if(cdlista != NULL){
        Cdllnode* newnode = (Cdllnode*)malloc(sizeof(Cdllnode));
        if(newnode != NULL){
            newnode->data = data;
            if(cdlista->first != NULL){
                cdlista->first->prev = newnode;
            }
            cdlista->first = newnode;
            newnode->next = cdlista->first;
            newnode->prev = cdlista->first;
            return true;
        } 
    }
    return false;
}


void* cdllRemovefirst( Cdllist *cdlista){
    if(cdlista != NULL){
        Cdllnode* del;
        Cdllnode* afterdel;
        void* data;
        if(cdlista->first != NULL){
            del = cdlista->first;
            data = del->data;
            afterdel = del->next;
            cdlista->first = afterdel;
            free(del);
            return data;
        }
    }
    return NULL;
}


void* cdllGetfirst( Cdllist *cdlista){ // necessário para getnext funcionar
    if(cdlista != NULL){
        void* retorno;
        if(cdlista->first != NULL){
            cdlista->cur = cdlista->first;
            retorno = cdlista->cur->data;
            return retorno;
        }
    }
    return NULL;
}

void* cdllGetnext(Cdllist* cdlista){
    if(cdlista != NULL){
        void* retorno;
        if(cdlista->cur != NULL){
            if(cdlista->cur->next != NULL){
                cdlista->cur = cdlista->cur->next;
                retorno = cdlista->cur->data;
                return retorno;
            }
        }
    }
    return NULL;
}

// os métodos que buscam o ultimo elemento não são muito práticos, pois eles percorrem a cdlista inteira para descobrir o ultimo elemento

int cdllInsertAsLast(Cdllist* cdlista,void* data){
    if(cdlista != NULL){
        Cdllnode* newnode = (Cdllnode*)malloc(sizeof(Cdllnode));
        Cdllnode* last;
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;
            if(cdlista->first == NULL){
                cdlista->first = newnode;
            }else{
                last = cdlista->first;
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

void* cdllRemovelast( Cdllist *cdlista){
    if(cdlista != NULL){
        Cdllnode* del;
        Cdllnode* beforedel;
        void* data;
        if(cdlista->first != NULL){
            del = cdlista->first;
            if(del->next == NULL){
                data = del->data;
                cdlista->first = NULL;
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


int cdllNumNodes(Cdllist* cdlista){
    if(cdlista != NULL){
        Cdllnode* last;
        int num = 0;
        if(cdlista->first != NULL){
            last = cdlista->first;
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

int cdllInsertafterespec(Cdllist* cdlista,void* data,void* key, int(*cmp)(void*,void*)){
    if(cdlista != NULL && data != NULL && key != NULL){
        Cdllnode* newnode = (Cdllnode*)malloc(sizeof(Cdllnode));
        if(newnode != NULL){
            if(cdlista->first != NULL){
                Cdllnode* spec = cdllGetspec(cdlista,key,cmp);
                if(spec != NULL){
                    newnode->data = data;
                    newnode->prev = spec;
                    Cdllnode* next = spec->next;
                    newnode->next = next;
                    spec->next = newnode;
                    if(next == cdlista->first){
                        next->prev = newnode;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

int cdllInsertbeforespec(Cdllist* cdlista,void* data,void* key,int(*cmp)(void*,void*)){
    if(cdlista != NULL && data != NULL && key != NULL){
        Cdllnode* newnode = (Cdllnode*)malloc(sizeof(Cdllnode));
        if(newnode != NULL){
            if(cdlista->first != NULL){
                Cdllnode* spec = cdllGetspec(cdlista,key,cmp);
                if(spec != NULL){
                    newnode->data = data;
                    Cdllnode* prev = spec->prev;
                    newnode->prev = prev;
                    newnode->next = spec;
                    spec->prev = newnode;
                    if(spec == cdlista->first){
                        cdlista->first = newnode;
                    }
                    prev->next = newnode;
                    return true;
                }
            }
        }
    }
    return false;
}

void* cdllQueryspec(Cdllist* cdlista, void*key,int(*cmp)(void*,void*)){
    if(cdlista != NULL && key != NULL){
        if(cdlista->first != NULL){
            Cdllnode* atual = cdlista->first;
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

void* cdllRemovespec(Cdllist* cdlista,void* key,int(*cmp)(void*,void*)){
    if(cdlista != NULL && key != NULL){
        if(cdlista->first != NULL){
        Cdllnode* prev = cdlista->first;
        Cdllnode* spec = prev->next;
        void* salvo;
        int stat = cmp(key,spec->data);
        while(stat != true && spec != cdlista->first){
            prev = spec;
            spec = spec->next;
            stat = cmp(key,spec->data);
        }
        if(stat == true){
            Cdllnode* next = spec->next;
            prev->next = next;
            next->prev = prev;
            salvo = spec->data;
            if(cdlista->first == spec){
                if(spec->next == spec){
                    cdlista->first = NULL;
                }else{
                    cdlista->first = next;
                }
            }
            free(spec);
            return salvo; 
        } 
       }
    }
    return NULL;
}

Cdllnode* cdllGetspec(Cdllist* cdlista,void* key,int(*cmp)(void*,void*)){
    if(cdlista != NULL){
        if(cdlista->first != NULL){
            Cdllnode* prev = cdlista->first;
            Cdllnode* cur = prev->next;
            int stat = cmp(cur->data,key);
            while(stat != true && cur != cdlista->first){
                prev = cur;
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


int cdllDestroy(Cdllist *cdlista){ // destroi apenas listas vazias
    if(cdlista != NULL){
        if(cdlista->first == NULL){
            free(cdlista);
            return true;
        }
    }
    return false;
}

int removedpsspec(Cdllist* cdlista, Cdllnode*p){
    if(cdlista != NULL){}
}

int removeK(Cdllist* cdlista, int k){
    if(cdlista != NULL){}
}

int sllNumComuns(Cdllist *l1, Cdllist *l2, int(*cmp)( void *, void *)){}

int *sllEInversa(Cdllist *l1, Cdllist *l2, int(*cmp)( void *, void *)){}

Cdllist* sllCopiaInvertida(Cdllist *cdlista){
    if(cdlista != NULL){}
}

#endif /* __CDLL_C */