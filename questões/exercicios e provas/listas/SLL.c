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
    Sllnode* cur;
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
            return data;
        }
    }
    return NULL;
}

void *sllGetfirstcur( Sllist *lista){ // necessário para getnext funcionar
    if(lista != NULL){
        if(lista->first != NULL){
            lista->cur = lista->first;
            return lista->cur->data;
        }
    }
    return NULL;
}

// os métodos que buscam o ultimo elemento não são muito práticos, pois eles percorrem a lista inteira para descobrir o ultimo elemento

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
        if(lista->first != NULL){
            del = lista->first;
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

void* sllGetLast (Sllist* lista){
    if(lista != NULL){
        Sllnode* last;
        void* data;
        if(lista->first != NULL){
            last = lista->first;
            while(last->next != NULL){
                last = last->next;
            }
            data = last->data;
         return data;
    }
    }
    return NULL;
}

int sllNumNodes(Sllist* lista){
    if(lista != NULL){
        Sllnode* last;
        int num;
        if(lista->first != NULL){
            last = lista->first;
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

int sllInsertafterN(Sllist* lista, void* data,int n){
    if(lista != NULL && data != NULL){
        Sllnode* newnode = (Sllnode*)malloc(sizeof(Sllnode));
        if(newnode != NULL){
            Sllnode* aux = lista->first;
            Sllnode* afteraux;
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

int sllInsertafterespec(Sllist* lista,void* data,int(*cmp)(void*,void*)){
    if(lista != NULL && data != NULL){
        Sllnode* newnode = (Sllnode*)malloc(sizeof(Sllnode));
        if(newnode != NULL){
            Sllnode* aux = lista->first;
            Sllnode* afteraux;
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

int sllInsertbeforespec(Sllist* lista,void* data,int(*cmp)(void*,void*)){
    Sllnode *prev, *spec;
    if ( lista != NULL) {
        if ( lista->first != NULL) {
            prev = NULL; spec = lista->first;
            int stat = cmp(spec->data, data);
            while ( stat != true && spec->next != NULL) {
                prev = spec; spec= spec->next;
                stat = cmp (spec->data, data);
                }
                if ( stat == true) {
                    Sllnode* newnode = (Sllnode *) malloc(sizeof(Sllnode));
                    if ( newnode != NULL){
                        newnode->data = data;
                        newnode->next = spec;
                        if( prev != NULL) {
                        prev->next = newnode;
                        } else {
                        lista->first = newnode;
                        }
                    }
            }
        }
    }
    return true;
}

void* sllQueryspec(Sllist* lista, void*key,int(*cmp)(void*,void*)){
    if(lista != NULL && key != NULL){
        if(lista->first != NULL){
            Sllnode* atual = lista->first;
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

void* sllRemovespec(Sllist* lista,void* key,int(*cmp)(void*,void*)){
    if(lista != NULL && key != NULL){
        if(lista->first != NULL){
        Sllnode* del = lista->first;
        Sllnode* beforedel;
        void* salvo;
        int stat = cmp(key,del->data);
        while(stat != true && del->next != NULL){
            beforedel = del;
            del = del->next;
            stat = cmp(key,del->data);
        }
        if(stat == true){
            salvo = del->data;
            if(beforedel == NULL){
                lista->first = del->next;
            }else{
                beforedel->next = del->next;
            }
            free(del);
            return salvo; 
        }
        
       }
    }
    return NULL;
}

void* sllGetnext(Sllist* lista){
    if(lista != NULL){
        if(lista->cur != NULL){
            lista->cur = lista->cur->next;
            return lista->cur->data;
        }
    }
    return NULL;
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

// exercicios

int sllEigual(Sllist*l1, Sllist *l2,int(*cmp)( void *, void *)){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){
            Sllnode* current1 = l1->first;
            Sllnode* current2 = l2->first;
            int stat = cmp(current1->data,current2->data);
            while(current1->next != NULL && current2->next != NULL && stat == true){
                current1 = current1->next;
                current2 = current2->next;
                stat = cmp(current1->data,current2->data);
            }
            if(stat == true){
                return true;
            }
            return false;
        }
    }
    return - 1;
}

Sllist *sllCopia(Sllist *l1){
    if(l1 != NULL){
        if(l1->first != NULL){
            Sllnode* newnode = l1->first;
            void* data;
            Sllist* l2 = sllCreate();
            if(l2 != NULL){
                while(newnode->next != NULL){
                    data = newnode->data;
                    sllInsertAsLast(l2,data);
                    newnode = newnode->next;
                }
                return l2;
            }
        }
    }
    return NULL;
}

Sllist *sllDiferença(Sllist *l1, Sllist *l2,int(*cmp)(void *,void *)){
    if(l1 != NULL && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){
            Sllnode* current1 = l1->first;
            Sllnode* current2 = l2->first;
            Sllist* L = sllCreate();
            if(L != NULL){
                int igual;
                while(current1->next != NULL){
                    while(current2->next != NULL){
                        igual = cmp(current1->data,current2->data);
                        if(igual == false){
                            sllInsertAsLast(L,current1->data);
                        }
                        current2 = current2->next;
                    }
                    current1 = current1->next;
                }
                return L;
            }
        }
    }
    return NULL;
}
 
int sllNumComuns(Sllist *l1, Sllist *l2, int(*cmp)( void *, void *)){
    if(l1 != NULL  && l2 != NULL){
        if(l1->first != NULL && l2->first != NULL){
            int comuns = 0;
            Sllnode* current1 = l1->first;
            Sllnode* current2 = l2->first;
            while(current1->next != NULL){
                while(current2->next != NULL){
                    int add = cmp(current1->data,current2->data);
                    current2 = current2->next;
                    if(add == true){
                        comuns += 1;
                    }
                }
                current1 = current1->next;
            }
            return comuns;
        }
    }
    return -1;
}

int insereAntesp(Sllist* lista,Sllnode* node,Sllnode* P){ // como vou saber o prev do node? pode dar problema
    if(lista != NULL && node != NULL && P != NULL){
        if(lista->first != NULL){
            Sllnode* current = lista->first;
            Sllnode* prev = NULL;
            Sllnode* currentN = lista->first;
            Sllnode* prevN = NULL;
            while(currentN->next != NULL){
                if(currentN == node){
                    break;
                }
                prev = currentN;
                currentN = currentN->next;
            }
            while(current->next != NULL){
                if(current == P){
                    if(prev == NULL){
                        lista->first = node;
                        node->next = P;
                    }else{
                        prevN->next = node->next;
                        prev->next = node;
                        node ->next = P;
                    }
                    return true;
                }
                prev = current;
                current = current->next;  
            }
            return false;
        }
    }
    return -1;
}

int *sllEInversa(Sllist *l1, Sllist *l2, int(*cmp)( void *, void *)){}

int removeOrdemimp(Sllist* lista){}

#endif /* __SLL_C */