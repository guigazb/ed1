#include <stdio.h>
#define true 1
#define false 0

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
