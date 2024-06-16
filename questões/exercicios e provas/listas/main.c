#include <stdio.h>
#include "sll.h"
#define true 1
#define false 0

//lista - 1
int compL(Sllist* lista){
    // retorna o comprimento de L
    if(lista != NULL){
        Sllnode* atual = sllGetfirstcur(lista);
        int comp = 0;
        while (atual != NULL){
            comp++;
            atual = sllGetnext(lista);
        }
        return comp;
    }
    return - 1;
}