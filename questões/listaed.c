#include <stdio.h>

//1
int SomaElmVetor(int *v,int n){

    int soma = 0;

    for(int i = 0; i < n; i++){
        soma += v[i];
    }
  return soma;
}

//2
int MaiorElmVetor(int *v,int n){

    int maior = 0;

    for(int i = 0;i < n ;i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
 return maior;
}

int SomaElmsVetor(int *v, int n){
   int soma = 0;

    for(int i = 0; i < n; i++){
        soma += v[i];
    }
  return soma;

}

int ElmDoMeioVetor(int *v, int n){
   
   int Elm;

   if(n%2 == 0){
     Elm = v[n/2];
   }else{
    Elm = v[n/2 - 1];
   }
   
  
  return Elm;
}

//3
int TrocaElmsVetor(int *v,int n,int p,int q){
    
    int aux;
    aux = v[p];
    v[p] = v[q];
    v[q] = aux;

}

//4
int NumQueFalta(int *v,int n,int p,int q){
  
  int Num;

  for(int i = 0; i<n ; i++){
    if(v[i] == 0){
        Num = i +1;
    }
  }

 return Num;
}

//5
int MaiorSequenciaConsecutiva(int *v,int n,int p,int q){

  int maiorseq = 0;
  int seqAtual = 1;

  for(int i = 0 ; i < n ; i++){   
    if(v[i] == v[i-1]+1){
      seqAtual++;
    }else if(seqAtual > maiorseq){
      maiorseq = seqAtual;
      seqAtual = 1;
    }
  }
  return maiorseq;
}

//6 - igual questão 2
int imprimemaiorvalor(int n, int *v){}

int somadosnumeros(int n, int *v){}

int imprimeelementodomeio(int n, int *v){}

//7
int uniaodosvetores(int *a,int *b,int *c,int n, int m){
  int i = 0;
  int j = 0;
  int k = 0;

  while(i<n && j <m){
    if(a[i]<b[j]){
      c[k] = a[i];
      k++;
      i++;
    }else{
      c[k] = b[j];
      k++;
      j++;
    }
  }

  while(i < n){
    c[k] = a[i];
    k++;
    i++;
  }

  while(j<m){
    c[k] = b[j];
    k++;
    j++;
  }
  
}

int intersecccaovetores(int *a,int *b,int *c,int n, int m){
  int i = 0;
  int j = 0;
  int k = 0;

  while(i <n && j <m){
    if(a[i]<b[j]){
      i++;
    }else if(b[j]<a[i]){
      j++;
    }else{
      c[k] = a[i];
      k++;
      i++;
      j++;
    }
  }

}

int intercalacaovetores(int *a,int *b,int *c,int n, int m){
  int i = 0;
  int j = 0;
  int k = 0;

  while(i<n && j <m){
    c[k] = a[i];
    k++;
    i++;
    
    c[k] = b[j];
    k++;
    j++;

  }

  while(i < n){
    c[k] = a[i];
    k++;
    i++;
  }

  while(j<m){
    c[k] = b[j];
    k++;
    j++;
  }

}

int elementoposimparvet(int *a,int *b,int *c,int n,int m){
  int k = 0;

  for(int i = 1; i<n ;i +=2){
    c[k] = a[i];
    k++;

  }
}

int elementoposparvet(int *a,int *b,int *c,int n, int m){
  int k = 0;

  for(int i = 0; i<m ;i +=2){
    c[k] = a[i];
    k++;

  }
}

//8
int SomaElmMat(float **v, int n, int m){
  float soma = 0.0;

  for(int i = 0; i < n && i < m ; i++){

    soma += v[i][i];

  }

  return soma;
}

//9
int CmpVectorMatrix ( int n, int m, int p, float **vet, float **vmat){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m*p;j++){
      if(vet[i] == vmat[j]){

        printf("o valor %.2f do vetor na posição %d e igual ao valor contido em (%d,%d) na matriz. \n",vet[i], i, j/m, j%m);

      }
    }
  }
  return 0;
} 

//10
int MultMatrixArmazenadaVetor ( int n, int m, int p, int q, float *vma,float *vmb, float *vmc){

  if(m != p){
    printf("nao e possivel realizar essa multiplicacao");
    return 0;
  }
  for(int i = 0; i < n ; i++){
    for(int j = 0; j < q; j++){
      vmc[i*q + j] = 0;
      for(int k = 0; k < m; k++){
        vmc[i*q+j] += vma[i*m +k] * vmb[k*q +j];
      }
    }
  }
 return 1;
}

//11
int *DevolveVetorLinhaIFatiaK(int ***VolA, int *vet, int N, int M, int P, int I, int K){
  for(int j = 0; j < M; j++){
    vet[j] = VolA[I][j][K];

  }
  return vet;
}
int *DevolverVetorColunaJFatiaK(int ***VolA, int *vet, int N, int M, int P, int j, int K){
  for(int i = 0; i < N; i++){
    vet[i] = VolA[i][j][K];

  }
  return vet;

}
int *DevolverVetorDiagonalfatiaK(int ***VolA, int *vet, int N, int M, int P, int K){

  int menorvalor = 0;
  if(N < M){
    menorvalor = N;
  }
  else if (N == M){
    menorvalor = M;
  }else{
    menorvalor = M;
  }

  for(int i = 0; i< menorvalor;i++){
    vet[i] = VolA[i][i][K];
  }
  
  return vet;
}
int *DevolverVetorLinhaITodasFatias(int ***VolA, int *vet, int N, int M, int P, int I){
  for(int k = 0; k < P ; k++){
    for(int j = 0; j < M; j++){
      vet[k * M + j] = VolA[I][j][k];
    }
  }
  return vet;
}
int *DevolverVetorElmIJTodasasFatias(int ***VolA, int *vet, int N, int M, int P, int I, int j){
  for(int k = 0; k < P; k++){
    vet[k] = VolA[I][j][k];

  }
  return vet;

}

//12
int *transposta(int **vma, int **vmb, int n, int m){
  for(int i = 0;i<n;i++){
    for(int j = 0; j <m; j++){
      vmb[j][i] = vma[i][j];
    }
  }
}

//13 - igual a 10

//14 igual a 11

//15 pensar melhor dps
int TipodeMatriz(int **ma, int n, int m){ 
  int simetrica = 1, diagonal = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j< m; j++){
      if(ma[i][j] != ma[j][i]){

        simetrica = 0;
      }
      if(i != j && ma[i][j] != 0){

        diagonal = 0;
      }
    }
  }

  if(simetrica == 1){
    return 1; // matriz quadrada simetrica
  }else if(diagonal == 1){
    return 2; // matriz quadrada diagonal
  }else{
    return 3; // matriz quadrada assimetrica
  }

  if(n == m){
    return 0; // matriz quadrada
  }
}

//16
int TipodeMatrizQuadrada(int **ma, int n, int m){
  if(n != m){
    return -1;
  }else{
    return 0;
  }
}

//17
int TipodeMatrizSimétrica(int **ma, int n, int m){
  if(n != m){
    return -1;
  }
  for(int i = 0; i<n; i++){
    for(int j = 0;j<m;j++){
      if(ma[i][j] != ma[j][i]){
        return 0;
      }
    }
  }
  return 1;
}

//18
int TipodeMatrizDiagonal(int **ma, int n, int m){
  if(n != m){
    return -1;
  }
  for(int i = 0; i<n; i++){
    for(int j = 0;j<m;j++){
      if(i != j && ma[i][j] != 0){
        return 0;
      }
    }
  }
  return 1;
}

//19
int TipodeMatrizAssimétrica(int **ma, int n, int m){
  if(n != m){
    return -1;
  }
  for(int i = 0; i<n; i++){
    for(int j = 0;j<m;j++){
      if(ma[i][j] == ma[j][i]){
        return 0;
      }
    }
  }
  return 1;
}

//20 igual 17
//21
int *multiplicaPelaTranspostaA(int **ma, int **vmc, int n, int m){
  if(n !=m){
    return NULL;
  }
  
  int **transposta = (int **)malloc(n * sizeof(int *));
  for(int i = 0; i <n; i++){
    transposta[i] = (int *)malloc(m * sizeof(int));
    for(int j = 0; j<m; j++){
      transposta[i][j] = ma[j][i];
    }
  }

  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < m; j++){
      vmc[i][j] = 0;
      for(int k = 0; k < m ; k++){
        vmc[i][j] += ma[i][k] * transposta[k][j];
      }
    }
  }
  return vmc;
}

int *multiplicaPelaTranspostaB(int **ma, int **vmc, int n, int m){
  if(n !=m){
    return NULL;
  }

  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < m; j++){
      vmc[i][j] = 0;
      for(int k = 0; k < m ; k++){
        vmc[i][j] += ma[i][k] * ma[j][k];
      }
    }
  }
  return vmc;
}

//22
int * linhadaMatriz(int **ma, int *vet, int n, int m, int l){
  for(int j = 0 ; j<m; j++){
    vet[j] = ma[l][j];
  }
  return vet;
} 

//23
int * colunadaMatriz(int **ma, int *vet, int n, int m, int p){
  for(int i = 0 ; i < m; i++){
    vet[i] = ma[p][i];
  }
  return vet;
} 

//24
int * diagonaldaMatriz(int **ma, int *vet, int n, int m){
  if(n != m){
    return NULL;
  }
  for(int i = 0 ; i<m ;i++){
    vet[i] = ma[i][i];
  }
  return vet;
}
