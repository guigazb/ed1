#include <stdio.h>
#include "cofo.h"

int main(){
    //criar cofo, inserir elementos, e para cada elemento inserido incrementar a variavel Atual para listar o cofo posteriormente
    // int flag = 1;

    int max = 0;
    void listarCofo(Cofo *c,int atual);

    printf("insira o tamanho do cofo: \n");
    scanf("%d",&max);
    Cofo *cofo = cofCreate(max);

    int item = 0, atual = 0;
    for(int i = 0; i<3; i++){
        printf("insira um item no cofo: \n");
        scanf("%d",&item);
        cofInsert(cofo,item);
        atual ++;
        /*if(cofInsert(cofo,item)!= 0){
            atual ++;
        }else{
            printf("ERRO DE INSERCAO \n");
            break;
        }*/
    }
    
    listarCofo(cofo, atual);


}

void listarCofo(Cofo *c,int atual){
    if(c != NULL){
        printf("item 1: %d \n ",cofgetfirst(c));
        for(int i = 0; i< atual -1 ; i++){
            printf("item %d: %d \n",i + 2 ,cofList(c));
        }
    }
}