#include <stdio.h>

// 2
// Lista 2



// 4
// Ex3
float *multiplicaMatrizEmVetor( int n, int m, int p, int q, float *vma, float *vmb, float *vmc) {
	if (vma != NULL && vmb != NULL && vmc != NULL && n > 0 && m > 0 && p > 0 && q > 0 && m == p) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < q; j++){
				vmc[i*q + j] = 0.0;
				for (int k = 0; k < m; k++){
					vmc[i*q + j] += vma[i*m + k] * vmb[k*q + j];
				}
			}
		}
		return vmc;
	}
	return NULL;
}


//6 
//Ex3



//7
// Lista 2 Ex11



//8
int **transposta(int **ma, int n, int m) {
	if (ma != NULL && n>0 && m>0){
		int **mta;
		mta = (int*)malloc(sizeof(int)*m);
		if (mta != NULL){
			for (int i = 0; i < m; i++){
				mta[i] = (int*)malloc(sizeof(int) * n);
				if (mta[i] == NULL){
					for (int j = i-1; i >= 0; j--){
						free(mta[j]);
					}
					free(mta);
					return NULL;
				}
			}
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					mta[i][j] = 0;
					mta[i][j] += ma[j][i];
				}
			}
			return mta;
		}
	}
	return NULL;
}



//9
int *transposta(int *vma, int n, int m){
	int *vmta;
	vmta = (int*)malloc(sizeof(int)*n*m);
	if (vmta != NULL && vma != NULL && n > 0 && m > 0){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++){
				vmta[j*n + i] = vma[i*m + j];
			}
		}
		return vmta;
	}
	return NULL;
}


// 10
int TipodeMatriz(int *vma, int n, int m){
	int diagonal = 1, simetrica = 1;
	if (vma != NULL && n > 0 && m == n) {
		int vtma;
		vtma =  transposta(vma, n, m); //9
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (vma[i*m+j] != vtma[i*m+j]){
					simetrica = 0;
					return 3;
				}
				if (i != j && vma[i*m + j] != 0){
					diagonal = 0;
				}
			}
		}
		if (diagonal == 1){
			return 2;
		}
		if (simetrica == 1){
			return 1;
		}
		return 0;
	}
	return NULL;
}


//11
int TipodeMatrizQuadrada(int *ma, int n, int m){
	if (ma!=NULL && n > 0 && m > 0){
		if (n == m){
			return 0;
		}
		return -1;
	}
	return NULL;
}



// 12
int TipodeMatrizSimetrica(int *vma, int n, int m) {
	if (vma != NULL && n > 0 && m > 0){
		if (n == m){
			int vtma;
			vtma = transposta(vma, n, m);
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (vma[i*m+j] != vtma[i*m+j]){
						return 0;
					}
				}
			}
			return 1;
		}
		return -1;
	}
	return NULL;
}


// 13
int TipodeMatrizDiagonal(int *vma, int n, int m){
	if (vma != NULL && n > 0 && m > 0){
		if (n == m){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (i != j && vma[i*m + j] != 0){
						return 0;
					}
				}
			}
			return 1;
		}
		return -1;
	}
	return NULL;
}


// 14
int TipodeMatrizAssimetrica(int *vma, int n, int m) {
	if (vma != NULL && n > 0 && m > 0){
		if (n == m){
			int vtma;
			vtma = transposta(vma, n, m);
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					if (vma[i*m+j] != vtma[i*m+j]){
						return 1;
					}
				}
			}
			return 0;
		}
		return -1;
	}
	return NULL;
}


// 15
// Ex12


// 16a
int **multiplicaPelaTranspostaA(int **ma, int n, int m){
	if (ma != NULL && n > 0 && m > 0){
		int **mproduto;
		int **mta;
		mta = transposta(ma, n, m); // 8
		mproduto = (int*)malloc(sizeof(int)*n);
		if (mproduto != NULL){
			for (int i = 0; i < n; i++){
				mproduto[i] = (int*)malloc(sizeof(int)*m);
				if (mproduto == NULL){
					for (int j = i - 1; j >= 0; j--){
						free(mproduto[j]);
					}
					free(mproduto);
					return NULL;
				}
			}
			if (mta != NULL) {
				for (int i = 0; i < n; i++){
					for (int j = 0; j < m; j++){
						mproduto[i][j] = 0;
						for (int k = 0; k < n; k++){
							mproduto[i][j] += ma[i][k] * mta[k][j];
						}
					}
				}
				return mproduto;
			}
			
		}
	}
	return NULL;
}




// 16b
int **multiplicaPelaTranspostaB(int **ma, int n, int m){
	if (ma != NULL && n > 0 && m > 0) {
		int **mproduto;
		mproduto = (int*)malloc(sizeof(int)*n);
		if (mproduto != NULL){
			for (int i = 0; i < n; i++){
				mproduto[i] = (int*)malloc(sizeof(int)*m);
				if (mproduto[i] == NULL){
					for (int j = i-1; j >= 0; j--){
						free(mproduto[j]);
					}
					free(mproduto);
					return NULL;
				}
			}
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					mproduto[i][j] = 0;
					for (int k = 0; k < n; k++){
						mproduto[i][j] += ma[i][k] * ma[j][k];
					}
				}
			}
			return mproduto;
		}
	}
	return NULL;
}



// 17a
int *multiplicaPelaTranspostaA(int *vma, int n, int m){
	if (vma != NULL && n > 0 && m > 0) {
		int *vmta, *vmproduto;
		vmta = transposta(vma, n, m); // 9
		vmproduto = (int*)malloc(sizeof(int)*n*m);
		if (vmproduto != NULL){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					vmproduto[i*m+j] = vma[i*m+k] * vmta[k*m+j];
				}
			}
			return vmproduto;
		}
	}
	return NULL;
}



// 17b
int *multiplicaPelaTranspostaB(int *vma, int n, int m){
	if (vma != NULL && n > 0 && m > 0) {
		int *vmproduto;
		vmproduto = (int*)malloc(sizeof(int)*n*m);
		if (vmproduto != NULL){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					vmproduto[i*m+j] = vma[i*m+k] * vma[k*m+j];
				}
			}
			return vmproduto;
		}
		
	}
}


// 18
int * linhadaMatriz(int **ma, int n, int m, int l){
	if (ma != NULL && n > 0 && m > 0 && (I > 0 && I <= n)){
		int *v;
		v = (int*)malloc(sizeof(int)*m);
		if (v != NULL){
			for (int i = 0; i < m; i++){
				v[i] = ma[I-1][i];
			}
			return v;
		}
	}
	return NULL;
}


// 19
int * colunadaMatriz(int **ma, int n, int m, int p){
	if (ma != NULL && n > 0 && m > 0 && (p > 0 && p <= m)){
		int *v;
		v = (int*)malloc(sizeof(int)*n);
		if (v != NULL){
			for (int i = 0; i < n; i++){
				v[i] = ma[i][p-1];
			}
			return v;
		}
	}
	return NULL;
}