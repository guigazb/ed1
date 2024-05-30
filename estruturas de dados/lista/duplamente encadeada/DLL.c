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

// os métodos que buscam o ultimo elemento não são muito práticos, pois eles percorrem a dlista inteira para descobrir o ultimo elemento

int dllInsertAsLast(Dllist* dlista,void* data){
    if(dlista != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        Dllnode* last;
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;
            if(dlista->first == NULL){
                dlista->first = newnode;
            }else{
                last = dlista->first;
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

int dllInsertafterN(Dllist* dlista, void* data,int n){
    if(dlista != NULL && data != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        if(newnode != NULL){
            Dllnode* aux = dlista->first;
            Dllnode* afteraux;
            newnode->data = data;
            newnode->next = NULL;
            for(int i = 0; i<n ; i++){
                aux = aux->next;
            }
            afteraux = aux->next;
            aux->next = newnode;
            newnode->next = afteraux;
            return true;
        }
    }
    return false;
}

int dllInsertafterespec(Dllist* dlista,void* data,int(*cmp)(void*,void*)){
    if(dlista != NULL && data != NULL){
        Dllnode* newnode = (Dllnode*)malloc(sizeof(Dllnode));
        if(newnode != NULL){
            Dllnode* aux = dlista->first;
            Dllnode* afteraux;
            newnode->data = data;
            newnode->next = NULL;
            while(cmp(data,(void*)&aux->data) == false){
                aux = aux->next;
            }
            afteraux = aux->next;
            aux->next = newnode;
            newnode->next = afteraux;
        
            return true;
        }
    }
    return false;
}

int dllInsertbeforespec(Dllist* dlista,void* data,int(*cmp)(void*,void*)){
    Dllnode *prev, *spec;
    if ( dlista != NULL) {
        if ( dlista->first != NULL) {
            prev = NULL; spec = dlista->first;
            int stat = cmp(spec->data, data);
            while ( stat != true && spec->next != NULL) {
                prev = spec; spec= spec->next;
                stat = cmp (spec->data, data);
                }
                if ( stat == true) {
                    Dllnode* newnode = (Dllnode *) malloc(sizeof(Dllnode));
                    if ( newnode != NULL){
                        newnode->data = data;
                        newnode->next = spec;
                        if( prev != NULL) {
                        prev->next = newnode;
                        } else {
                        dlista->first = newnode;
                        }
                    }
            }
        }
    }
    return true;
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