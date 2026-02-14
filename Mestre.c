#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define HAB 5   


void mostrarTabuleiro(int tab[TAM][TAM]) {

    printf("\nTABULEIRO FINAL:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tab[i][j] == 0) printf(". ");    
            else if (tab[i][j] == 3) printf("N "); 
            else if (tab[i][j] == 5) printf("* "); 
        }
        printf("\n");
    }
}


void aplicarHabilidade(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {

    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (hab[i][j] == 1) {

                int linhaTab = origemL + (i - centro);
                int colunaTab = origemC + (j - centro);

               
                if (linhaTab >= 0 && linhaTab < TAM &&
                    colunaTab >= 0 && colunaTab < TAM) {

                    
                    if (tab[linhaTab][colunaTab] == 0)
                        tab[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

int main() {

    int tabuleiro[TAM][TAM];

    
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;


    for (int i = 0; i < 3; i++) tabuleiro[1][2+i] = 3; 
    for (int i = 0; i < 3; i++) tabuleiro[5+i][7] = 3; 
    for (int i = 0; i < 3; i++) tabuleiro[i][i] = 3;   
    for (int i = 0; i < 3; i++) tabuleiro[i][9-i] = 3; 

    
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    int centro = HAB / 2;

    
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

   
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    aplicarHabilidade(tabuleiro, octaedro, 6, 7);

    
    mostrarTabuleiro(tabuleiro);

    return 0;
}
