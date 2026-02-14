#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

int main() {
    
    int tabuleiro[TAM][TAM];


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    int navioHorizontal[NAVIO_TAM] = {3,3,3};
    int navioVertical[NAVIO_TAM] = {3,3,3};

   
    int linhaH = 2, colunaH = 4; 
    int linhaV = 5, colunaV = 1; 

    
    if (colunaH + NAVIO_TAM > TAM) {
        printf("Erro: Navio horizontal ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

   
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
            return 1;
        }
    }

    
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    
    if (linhaV + NAVIO_TAM > TAM) {
        printf("Erro: Navio vertical ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

    
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
            return 1;
        }
    }

    
    for (int i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    
    printf("\nTABULEIRO BATALHA NAVAL:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }

    return 0;
}
