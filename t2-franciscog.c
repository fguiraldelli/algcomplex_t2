/************************************************************************
*																		*
*						Trabalho 2 - Complexidade						*
*							Profª. Cândida								*
*																		*
*		Aluno: Francisco A. C. C. B. Guiraldelli	RA: 379840			*
*																		*
************************************************************************/


#include <stdio.h>

#define MAX 5000

long long int labirinto[MAX][MAX];

int main(){

	int entrada, linha, coluna;
	entrada = 1;
	int pocao;

	/*Inicio do laço do programa com as entrada*/
	while (entrada){

		scanf("%d", &entrada);

		/*Insere nos compartimentos os valores das poções*/
		for(linha = 0; linha < entrada; linha++){

			for (coluna = 0; coluna <= linha; coluna++){

				scanf("%d", &pocao);
				labirinto[linha][coluna] = pocao;
			}

		}

		/*Faz o cálculo bottom-up dos valores das poções dos compartimentos*/
		for(linha = entrada-2; linha >= 0; linha--){

			for (coluna = 0; coluna <= linha; coluna++){

				if(labirinto[linha][coluna] + labirinto[linha+1][coluna] >= 
					labirinto[linha][coluna] + labirinto[linha+1][coluna+1])

					labirinto[linha][coluna] = labirinto[linha][coluna] + 
					labirinto[linha+1][coluna];
				else
					labirinto[linha][coluna] = labirinto[linha][coluna] + 
					labirinto[linha+1][coluna+1];
			}

		}

		/*Retorna o maior valor que está calculado na celula [0][0] da matriz*/
		if (entrada != 0)
			printf("%lld\n", labirinto[0][0]);

	}

	return 0;
}