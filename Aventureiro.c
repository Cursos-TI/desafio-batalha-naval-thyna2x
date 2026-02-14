#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3


int dentroLimite(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}


int posicionarNavio(int tab[TAM][TAM], int linha, int coluna, int dirL, int dirC) {

    
    for (int i = 0; i < NAVIO_TAM; i++) {
        int novaLinha = linha + i * dirL;
        int novaColuna = coluna + i * dirC;

        if (!dentroLimite(novaLinha, novaColuna))
            return 0; // fora do tabuleiro

        if (tab[novaLinha][novaColuna] != 0)
            return 0; // sobreposição
    }

    
    for (int i = 0; i < NAVIO_TAM; i++) {
        int novaLinha = linha + i * dirL;
        int novaColuna = coluna + i * dirC;
        tab[novaLinha][novaColuna] = 3;
    }

    return 1; 
}


void mostrarTabuleiro(int tab[TAM][TAM]) {
    printf("\nTABULEIRO:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}


int main() {

    int tabuleiro[TAM][TAM];

    
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    


    if (!posicionarNavio(tabuleiro, 1, 2, 0, 1))
        printf("Erro ao posicionar navio horizontal\n");

    if (!posicionarNavio(tabuleiro, 5, 7, 1, 0))
        printf("Erro ao posicionar navio vertical\n");

    if (!posicionarNavio(tabuleiro, 0, 0, 1, 1))
        printf("Erro ao posicionar navio diagonal 1\n");

    if (!posicionarNavio(tabuleiro, 0, 9, 1, -1))
        printf("Erro ao posicionar navio diagonal 2\n");

    mostrarTabuleiro(tabuleiro);

    return 0;
}
