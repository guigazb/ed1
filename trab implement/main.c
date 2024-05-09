#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "colecao.h"
#include "colecao.c"
#define true 1
#define false 0

typedef struct {
    char nome[30];
    int preco;
    float duracao;
}tipoJogo;


void listarColecao(Jogo *c,int atual){
    tipoJogo *var = (tipoJogo*) gamegetfirst(c);
    int ind = 0;
    if(c != NULL && atual > 0){
        /*for(i = 0; i < atual; i++){
            printf("item %d: \n",i+1);
            printf("nome: %s ,preco: %d ,duracao: %.2f \n", var->nome, var->preco, var->duracao);
            var = (tipoJogo*)gameGetnext(c);
        }*/
        while(var != NULL){
            printf("item %d: \n",ind + 1);
            printf("nome: %s ,preco: %d ,duracao: %.2f \n", var->nome, var->preco, var->duracao);
            var = (tipoJogo*)gameGetnext(c);
            ind++;
        }
    }else if(atual <= 0){
            printf("sem itens para imprimir \n");
        }
}  

int cmp(void* a, void* b){
    tipoJogo *pa = (tipoJogo *) a;
    tipoJogo *pb = (tipoJogo*) b;
    if(pa != NULL && pb != NULL){
        if(strcmp(pa->nome,pb->nome) == 0 && pa->preco == pb->preco && pa->duracao == pb->duracao){
           return true;
        }
        return false;
    }
    return -1;
}


int main(){
    //criar cofo, inserir elementos, e para cada elemento inserido incrementar a variavel Atual para listar o cofo posteriormente
    
    int flag = true;
    int atual;
    void listarColecao(Jogo *c,int atual);
    int cmp(void* a, void* b);

    Jogo *jogo = NULL;

    while(flag == true){
        
        printf("1 - Criar colecao \n");
        printf("2 - Inserir um elemento \n");
        printf("3 - Remover um elemento \n");
        printf("4 - Consultar um elemento \n");
        printf("5 - Listar os elementos \n");
        printf("6 - Destruir a colecao \n");
        printf("7 - Esvaziar a colecao \n");
        printf("0 - Sair \n");
        printf("deseja realizar qual operacao? \n ");
        
        int opcao;
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                if(jogo != NULL){
                    printf("existe uma colecao criada \n");
                    printf("destrua a colecao anterior antes de criar uma nova\n");
                    break;
                }
                int max;
                printf("insira o tamanho da colecao: ");
                scanf("%d", &max);
                jogo = gameCreate(max);
                printf("Colecao criada com sucesso! \n");
                break;
            }
            case 2:{
                tipoJogo *a = (tipoJogo *) malloc(sizeof(tipoJogo));
                if(jogo != NULL && a != NULL){
                    printf("Nome: ");
                    scanf("%s", a->nome);
                    printf("preco: ");
                    scanf("%d", &a->preco);
                    printf("duracao: ");
                    scanf("%f", &a->duracao);
                    if(gameInsert(jogo, a)){
                        printf("jogo inserido com sucesso \n");
                        atual ++;
                        break;
                    }else{
                        printf("Erro ao inserir jogo \n");
                        break;
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 3:{
                tipoJogo *a = (tipoJogo *) malloc(sizeof(tipoJogo));
                if(jogo != NULL && a != NULL){
                    printf("Nome: ");
                    scanf("%s", a->nome);
                    printf("preco: ");
                    scanf("%d", &a->preco);
                    printf("duracao: ");
                    scanf("%f", &a->duracao);
                    gameRemove(jogo, a, cmp);
                    atual --;
                    break;
                }
                printf("erro de parametro");
                break;
            }
            case 4:{
                tipoJogo *a = (tipoJogo *) malloc(sizeof(tipoJogo));
                if(jogo != NULL && a != NULL){
                    printf("Nome: ");
                    scanf("%s", a->nome);
                    printf("preco: ");
                    scanf("%d", &a->preco);
                    printf("duracao: ");
                    scanf("%f", &a->duracao);
                    tipoJogo *chave = (tipoJogo*) gameQuery(jogo, a, cmp);
                    if(chave != NULL){
                        printf("jogo encontrado !");
                        printf("Nome: %s, preco: %d, duracao: %.2f \n", chave->nome, chave->preco, chave->duracao);
                        break;
                    }else{
                        printf("O jogo nao foi encontrado \n");
                        break;
                    }
                }
                printf("erro de parametro");
                break;
            }
            case 5:{
                if(jogo != NULL){
                    listarColecao(jogo,atual);
                    break;
                }
                printf("erro de parametro \n");
                break;
            }
            case 6:{
                if(jogo != NULL){
                    if(gameDestroy(jogo)){
                        printf("Colecao destruida \n");
                        jogo = NULL;
                        break;
                    }else{
                        printf("A colecao nao foi destruida \n");
                        break;
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 7:{
                if(jogo != NULL){
                    if(gameClean(jogo)){
                       printf("A colecao foi esvaziada \n");
                       atual = 0;
                       break;
                    }else{
                      printf("A colecao nao foi esvaziada \n");
                      break;
                    }
                }
                printf("erro de parametro \n");
                break;
            }
            case 0:{
                printf("sistema encerrado com sucesso! \n");
                return 0;
            }
            default:{
                printf("opcao invalida \n");
                break;
            }
        }
    } flag = false;
}
