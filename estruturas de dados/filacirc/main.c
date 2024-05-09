#include <stdio.h>
#include "Cqueue.h"
#define true 1
#define false 0

//incremento circular
int incCirc(int i,	int max){
 if (i == max-1){
 return 0;
 }else{
 return i+1;
 }
}

//decremento circular
int decCirc(int i,	int max){
 if (i == 0){
 return max-1;
 }else{
 return i-1;
 }
}

int cmp(void* a,void* b){
    int* ptra = (int*)a;
    int* ptrb = (int*)b;
    if(*ptra > *ptrb){
        return true;
    }else{
        return false;
    }
}