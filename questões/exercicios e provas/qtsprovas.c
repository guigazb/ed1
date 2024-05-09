#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

// 2023.2 - questao 4
int removemaioresquekey(Stack* pilha,void* key,int(*cmp)(void*,void*)){
    if(pilha != NULL && key != NULL){
        int i = pilha->top;
        while(cmp(key,pilha->item[i]) != true){
            pilha->top--;
            i = pilha->top;
            if(pilha->top == 0 && cmp(key,pilha->item[i]) != true){
                return false;
            }
        }
        return true;
    }
    return false;
}

//2023.2 - Q4 - cmp
int cmp(void* a,void*b){
    int* ptra = (int*)a;
    int* ptrb = (int*)b;
    if(*ptra < *ptrb){
        return true;
    }else{
        return false;
    }
}

//2023.2 - questão 3
char* invertenumeros(char* str,int n){ //n é o tamanho do vetor
    if(str != NULL && n > 0){
        Stack* pilha = stkCreate(n);
        if(pilha != NULL){
            char* caractere[n];
            int j = 0;
            for(int i = 0; i < n; i++){
                if(str[i] > 46 && str[i] < 58){
                    stkPush(pilha,(void*)&str[i]);
                }else{
                    caractere[j] = str[i];
                    j++;
                }
            }
            for(int k = strlen(caractere) - 1; k < n; k++){
                caractere[k] = (char*)stkPop(pilha);
            }
            return caractere;
        }
    }
    return NULL;
}

//2023.1 - questao 4
int qremovelessthankey(Cqueue *cfila,void* key,int (*cmp)(void*,void*)){
    if(cfila != NULL && key != NULL){
        int i = cfila->front;
        while(cmp(key,cfila->elms[i]) != true){
            cfila->front = qinccirc(cfila->front,cfila->maxItens);
            cfila->nelms--;
            i = cfila->front;
            if(i == cfila->rear && cmp(key,cfila->elms[i]) != true){
                return false;
            }
        }
        return true;
    }
    return false;
}

//questão 1 2023.2 e 2021.2
int multiplicamatrizes(int* v1,int* v2,int* v3, int n){
    if(v1 != NULL && v2 != NULL && v3 != NULL && n > 0){
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                v3[i*n+j] = 0;
                for(int k = 0; k < n; k++){
                    v3[i*n + j] += v1[i*n + k] * v2[k*n + j];
                }
            }
        }
        return v3;
    }
    return false;
}

//questão 1 2022.1
int MultiplicaMatrizPelaTRansposta (int *v1, int *v2, int *v3, int n){
    if(v1 != NULL && v2 != NULL && v3 != NULL && n > 0){
        // transpor v2 antes de continuar
        v2 = transposta(v2,n,n);
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                v3[i*n+j] = 0;
                for(int k = 0; k < n; k++){
                    v3[i*n + j] += v1[i*n + k] * v2[k*n + j];
                }
            }
        }
        return v3;
    }
    return false;
}

int* transposta(int*vma,int n,int m){
    int* vmat = (int*)malloc(sizeof(int)*n*m);
    if(vma != NULL && vmat != NULL && n > 0 && m > 0){
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                vmat[j*n +i] = vma[i*m + j];
            }
        }
        return vmat;
    }
    free(vmat);
    return NULL;
}

//questão 2 - 2023.1
int Maiordacolunamat(int *v1,int n, int m, int col){
    if(v1 != NULL && col <= m && n > 0 && m > 0){
        int *coluna = (int*)malloc(sizeof(int) * n);
        if(coluna != NULL){
            for(int i = 0; i< n ; i++){
                coluna[i]  = v1[i*m +(col-1)];
            }
            int maior = 0;
            for(int j = 0; j < n; j++){
                if(coluna[j] >= maior){
                    maior = coluna[j];
                }
            }
            return maior;
        }
    }
    return - 10000;
}