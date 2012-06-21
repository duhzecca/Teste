/*
Trabalho 1 - Algoritmos 2
Eduardo Felipe Zecca da Cruz - 380008

Exercicio 9
Verifica se uma matriz quadrada é um quadrado magico
*/

#include<stdio.h>
#define MAX 50

//função para preencher os elementos de uma matriz
void preencheMatriz(int D[MAX][MAX],int n){
	int i,j;

	//preenchendo a matriz
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&D[i][j]);	
		}
	}
}

//soma os elementos das linhas
int somalinhas(int D[MAX][MAX],int n){
	int i,j,soma=0;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){	
			soma = soma + D[i][j];
		}
		return soma;
	}

}

//soma os elementos das colunas
int somacolunas(int D[MAX][MAX],int n){
	int i,j,soma=0;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){	
			soma = soma + D[j][i];
		}
		return soma;
	}
}

//soma os elementos da diagonal principal
int somadiagonalPrincipal(int D[MAX][MAX],int n){
	int i,j,soma=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){	
			if(i == j){//os elementos da diagonal principal sempre tem indice i igual a indice j
				soma = soma + D[i][j];
			}
		}	
	}
	return soma;
}

//soma os elementos da diagonal secundaria
int somadiagonalSecundaria(int D[MAX][MAX],int n){
	int i,j=n-1,soma=0;
	for(i=0;i<n;i++){	
		soma = soma + D[i][j];
		j--;	
	}
	return soma;
}

//verifica se é um quadrado magico
int quadradoMagico(int D[MAX][MAX],int n,int somaLin[],int somaCol[], int somaDiagPrin, int somaDiagSec){
	int i,j,flag=1;
	
	//chamadas das funções de soma de linhas, colunas e diagonais
	for(i=0;i<n;i++){	
		somaLin[i] = somalinhas(D,n);
	}
	for(i=0;i<n;i++){
		somaCol[i] = somacolunas(D,n);
	}
	somaDiagPrin = somadiagonalPrincipal(D,n);
	somaDiagSec = somadiagonalSecundaria(D,n);

	//verifica se todos os elementos do vetor de soma das linhas tem mesmo valor 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(somaLin[i] != somaLin[j]){
				flag = (-1);
				break;
			}
		}
	}

	//verifica se todos os elementos do vetor de soma das colunas tem mesmo valor
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(somaCol[i] != somaCol[j]){
				flag = (-1);
				break;
			}
		}
	}
	
	//verifica se todos os elementos do vetor de soma das linhas e de soma das colunas tem mesmo valor que as diagonais
	for(i=0;i<n;i++){
		if((somaLin[i] != somaDiagPrin) || (somaLin[i] != somaDiagSec) || (somaCol[i] != somaDiagPrin) || (somaCol[i] != somaDiagSec)){
			flag = (-1);
		}
	}
	return flag;

}



int main(){
	int dimensao,quadrada=0;
	int somaLin[MAX], somaCol[MAX], somaDiagPrin=0, somaDiagSec=0;
	int D[MAX][MAX];

	scanf("%d",&dimensao);

	preencheMatriz(D,dimensao);

	quadrada = quadradoMagico(D,dimensao,somaLin,somaCol,somaDiagPrin,somaDiagSec);

	if(quadrada == 1){
		printf("É um quadrado magico\n");
	}else{
		printf("Não é um quadrado magico\n");
	}

return 0;
}
