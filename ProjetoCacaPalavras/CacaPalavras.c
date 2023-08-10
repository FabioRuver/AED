#include <stdio.h>
#include <string.h>

//Alunos: Fabio S. Ruver; Nicolas Jesus
/*
o programa consiste em pegar as entradas fornecidas, montar uma matriz N x N. Apos montada ele busca a primeira letra da palavra, se encontrar, 
o programa testa todas as funcoes de direcao, que sao 8. Em cada funcao de direcao fizemos um teste para saber se a proxima letra foi encontrada,
em caso verdadeiro, vai incrementar/decrementar/manter a coluna/linha, dependendo a funcao que esta executando.
Por exemplo, a funcao Norte vai manter a coluna e vai subtrair 1 da linha atual. Já a funcao nordeste incrementa a linha e coluna.
E para os casos em que a verificacao chega numa borda, fizemos duas funcao para garantir que os valores fiquem dentro da matriz 
*/

//serve para que os valores que forem diminuidos, fiquem dentro dos limites da matriz
int limiteMenor (int x, int y) {
	int comp = y-1;

	if (0>x) {
		return comp;
	} else {
		return x;
	}
}

//serve para que os valores que forem incrementados, fiquem dentro dos limites da matriz
int limiteMaior (int x, int y) {
	int comp = y-1;
	if (comp < x) {
		return 0;
	} else {
		return x;
	}

}


//se for encontrada acima (norte)
void norte (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int linhaMenos = linha - 1;
	int x = 1;// contador
	int indexTam = tamanhoPalavra-1;
	
	linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);
	for (int t = 1; t < tamanhoPalavra; t++) { //para cada letra da palavra
		if (palavra[t] == matriz[linhaMenos][coluna] ) {//encontrou a proxima letra
			if (t == indexTam && x == indexTam) { //esse teste garante que a palavra foi encontrada por completo
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linhaMenos, coluna);
			}

			x=x+1;

			linhaMenos--;
			linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);

		}
	}
}


//se for encontrada abaixo(sul)
void sul (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int x = 1;
	int linhaMais = linha + 1;
	int indexTam = tamanhoPalavra-1;
	
	linhaMais = limiteMaior(linhaMais, tamanhoMatriz);
	for (int t = 1; t < tamanhoPalavra; t++) {
		if (palavra[t] == matriz[linhaMais][coluna]) {
			if (t == indexTam && x == indexTam) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linhaMais, coluna);
			}

			x=x+1;

			linhaMais++;
			linhaMais = limiteMaior(linhaMais, tamanhoMatriz);

		}
	}
}


//se for encontrada a direta (leste)
void leste (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int x = 1; 
	int colunaMais = coluna + 1;
	int indexTam = tamanhoPalavra-1;

	colunaMais = limiteMaior(colunaMais, tamanhoMatriz);

	for (int t=1; t <tamanhoPalavra; t++) {
		if (palavra[t] == matriz[linha][colunaMais]) {

			if (t == indexTam && x == indexTam) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linha, colunaMais);
			}

			x=x+1;
			
			colunaMais++;
			colunaMais= limiteMaior(colunaMais, tamanhoMatriz);
		}
	}
}


//se for encontrada a esquerda (oeste)
void oeste (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int linhaMenos = coluna - 1;
	int x = 1;
	int indexTam = tamanhoPalavra-1;
	
	linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);
	
	for (int t = 1; t < tamanhoPalavra; t++) {
		if (palavra[t] == matriz[linha][linhaMenos]) {
			if (x == indexTam && t == indexTam) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linha, linhaMenos);
			}

			x=x+1;

			linhaMenos--;
			linhaMenos=limiteMenor(linhaMenos, tamanhoMatriz);

		}
	}
}


//se for encontrada acima-direita(nordeste)
void nordeste (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int x=1;
	int colunaMais = coluna + 1;
	int linhaMenos = linha - 1;
	int indexTam = tamanhoPalavra-1;
	
	linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);
	colunaMais = limiteMaior(colunaMais, tamanhoMatriz);

	for (int t = 1; t < tamanhoPalavra; t++) {
		if (palavra[t] ==matriz[linhaMenos][colunaMais] ) {
			if (x == indexTam && t == indexTam) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linhaMenos, colunaMais);
			}

			x=x+1;
			linhaMenos--;
			colunaMais++;

			colunaMais = limiteMaior(colunaMais, tamanhoMatriz);
			linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);

		}
	}
}


//se for encontrada abaixo-direita(sudeste)
void sudeste (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int linhaMais = linha + 1;
	int colunaMais = coluna + 1, x = 1;
	int indexTam = tamanhoPalavra-1; 
	
	linhaMais = limiteMaior(linhaMais, tamanhoMatriz);
	colunaMais = limiteMaior(colunaMais, tamanhoMatriz);

	for (int t = 1; t < tamanhoPalavra; t++) {
		if (palavra[t] == matriz[linhaMais][colunaMais]) {
			if (x == indexTam && t == indexTam) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linhaMais, colunaMais);
			}

			x=x+1;
			linhaMais++;
			colunaMais++;

			linhaMais = limiteMaior(linhaMais, tamanhoMatriz);
			colunaMais = limiteMaior(colunaMais, tamanhoMatriz);

		}
	}
}


//se for encontrada abaixo-esquerda(sudoeste)
void sudoeste (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int colunaMenos = coluna - 1;
	int x = 1, linhaMais = linha + 1;
	int indexTam = tamanhoPalavra-1;
	
	colunaMenos = limiteMenor(colunaMenos, tamanhoMatriz);
	linhaMais = limiteMaior(linhaMais, tamanhoMatriz);

	for (int t = 1; t < tamanhoPalavra; t++) {
		if(palavra[t]==matriz[linhaMais][colunaMenos]) {
			if (x == indexTam && t == indexTam ) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linhaMais, colunaMenos);
			}

			x=x+1;
			colunaMenos--;
			linhaMais++;
			
			linhaMais = limiteMaior(linhaMais, tamanhoMatriz);
			colunaMenos = limiteMenor(colunaMenos, tamanhoMatriz);
		}
	}
}


//se for encontrada acima-esquerda(noroeste)
void noroeste (int linha, int coluna, int tamanhoPalavra, int tamanhoMatriz, char palavra[tamanhoMatriz], char matriz[][tamanhoMatriz]) {
	int colunaMenos = coluna - 1;
	int linhaMenos = linha - 1, x= 1;
	int indexTam = tamanhoPalavra-1;
	
	linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);
	colunaMenos = limiteMenor(colunaMenos, tamanhoMatriz);

	for (int t = 1; t < tamanhoPalavra; t++) {
		if (palavra[t] == matriz[linhaMenos][colunaMenos]) {
			if (x == indexTam && t == indexTam) {
				printf("(%d,%d) (%d,%d)\n", linha, coluna, linhaMenos, colunaMenos);
			}
			
			x=x+1;
			linhaMenos--;
			colunaMenos--;
			
			colunaMenos = limiteMenor(colunaMenos, tamanhoMatriz);
			linhaMenos = limiteMenor(linhaMenos, tamanhoMatriz);
						
		}
	}

}


int main () {
	int tamanhoMatriz, tamanhoPalavra;
	scanf("%d", &tamanhoMatriz);
	char matriz[tamanhoMatriz][tamanhoMatriz], palavra[100];

	for (int i = 0; i < tamanhoMatriz; i++) {
		scanf("\n%[^\n]", matriz[i]);//"\n%[^\n]" serve pra considerar os espaços em branco como parte da string digitada
	}

	scanf("%s", palavra);

	tamanhoPalavra = strlen(palavra); //tamanho da palavra digitada

	for (int linha = 0; linha < tamanhoMatriz; linha++) {//para cada linha da matriz
		for (int coluna = 0; coluna < tamanhoMatriz; coluna++) {//para cada coluna da matriz
			if (palavra[0] == matriz[linha][coluna]) {//se encontrar a primeira letra da palavra, vai verificar todo o arredor dessa letra pra ver se encontra os restante das letras
				//ordenado de acordo com a saida do runcodes
				oeste(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra, matriz);

				leste(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra, matriz);

				sul(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra, matriz);

				norte(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra,matriz);

				nordeste(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra,matriz);

				noroeste(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra,matriz);

				sudeste(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra,matriz);

				sudoeste(linha, coluna, tamanhoPalavra, tamanhoMatriz, palavra, matriz);
			}
		}
	}
}

