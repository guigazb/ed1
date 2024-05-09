//fazer questões do slide

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define true 1
#define false 0
#define error -1

//questão 2
char *inverte(char* str,int n){
    // n é o tamanho do vetor, consequentemente o da pilha
    Stack* pilha;
    void* aux;
    if(str != NULL && n > 0){
        pilha = stkCreate(n);
        if(pilha != NULL){
            for(int i = 0; i < n; i++){
                stkPush(pilha,str[i]);
            }
            for(int j = 0; j < n ;j++){
                str[j] = stkPop(pilha);
            }
        }
    }
}

//questão 5
int VerificaNumASeguidoB( char * str, int len){
    if(str != NULL && len > 0){
        Stack* pilha = stkCreate(len);
        if(pilha != NULL){
            char* caractere;
            int stat = true;
            int i = 0;
            while(i < len && stat == true){
                if(str[i] == 'A'){
                    stkPush(pilha,(void*)&str[i]);
                    i++;
                }else{
                    stat = false;
                }
            }
            caractere = (char*)stkPop(pilha);
            while(caractere != NULL && i < len){
                if(str[i] == 'B'){
                    i++;
                    caractere = (char*)stkPop(pilha);
                }else{
                    return false;
                }
            }
            if(caractere == NULL && i >= len){
                return true;
            }else{
                return false;
            }
        }
    }
    return error;
}

//questão 6
//6.1
int stkPushElmAsNRewmove(Stack *pilha, void *elm, int n){
    if(pilha != NULL && elm != NULL){
        if(n > 0){
            for(int i = 0; i< n+1; i++){
                stkPop(pilha);
            }
            stkPush(pilha,elm);
            return true;
        }
    }
    return false;
}

//6.2
int stkPushElmAsNNaoremove(Stack *pilha, void *elm, int n){
    if(pilha != NULL && elm != NULL){
        if(n > 0){
            void* aux[n];
            for(int i = 0; i < n+1; i++){
                aux[i] = stkPop(pilha);
            }
            stkPush(pilha,elm);
            for(int j = sizeof(aux); j >= 0 ; j--){
                stkPush(pilha,aux[j]);
            }
            return true;
        }
    }
    return false;
}

//6.3
int stkPushElmAsUltimo(Stack *pilha, void *elm, int n){
    if(pilha != NULL && elm != NULL){
        Stack* pilhaux = stkCreate(n);
        if(pilhaux != NULL){
            while(stkIsempty(pilha) == false){
                stkPush(pilhaux,stkPop(pilha));
            }
            stkPush(pilha,elm);
            while(stkIsempty(pilhaux) == false){
                stkPush(pilha,stkPop(pilhaux));
            }
            return true;
        }
    }
    return false;
}

//questão 7
int VerificaFormatoString(char *str, int n){
    if(str != NULL && n > 0){
        if((n % 2)!= 0){
            Stack* pilha = stkCreate(n);
            if(pilha != NULL){
                int i = 0;
                char *caractere;
                int stat = true;
                while(str[i] != 'C'){
                    stkPush(pilha,(void*)&str[i]);
                    i++;
                }
                i++;
                while(stat == true && i < n){
                    caractere = (char*)stkPop(pilha);
                    if(*caractere != str[i]){
                        stat = false;
                    }else{
                        i++;
                    }
                }
                stkDestroy(pilha);
                return stat;
            }
        }
    }
    return false;
}

//questão 8
int InverteString(char *str, int n){
    if(str != NULL){
        Stack* pilha =stkCreate(n);
        if(pilha != NULL){
            char* resposta = (char*)malloc(sizeof(char)*n);
            char caractere;
            char* pc = NULL;
            int i = 0, j = 0;
            if(resposta != NULL){
                for(i = 0; i < n; i++){
                    if(str[i] != '.'){
                        stkPush(pilha,(void*)&(str[i]));
                    }else{
                        while(stkIsEmpty(pilha) == false){
                            pc = (char*)stkPop(pilha);
                            caractere = *pc;
                            resposta[j] = caractere;
                            j++;
                        }
                        resposta[j] = '.';
                        j++;
                    }
                }
            }
            free(pc);
            stkDestroy(pilha);
            strcpy(str,resposta);
            return true;
        }
    }
    return false;
}

//questão 9
int VerificaFormatoString(char *str, int n){
    if(str != NULL && n > 0){
        Stack* pilha = stkCreate(n);
        if(pilha != NULL){
            for(int i = 0; i < n; i++){
                if(str[i] == '('){
                    stkPush(pilha,(void*)&str[i]);
                }
            }
            for(int j = 0; j < n; j++){
                if(str[j] == ')'){
                    stkPop(pilha);
                }
            }
            if(stkIsEmpty(pilha) == true){
                return true;
            }else{
                return false;
            }
        }
    }
    return error;
}

//provas
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

int main(){
    return 0;
}