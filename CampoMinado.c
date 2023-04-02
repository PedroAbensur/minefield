#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void imprime_matriz (char M[][N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d | ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%c  ", M[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for (j = 0; j < (n + 2*n); j++) {
        printf("-");
    }
    printf("\n  ");
    for (j = 0; j < n; j++) {
        printf("  %d", j + 1);
    }
}

void gera_campo (char M[][N], int n) {
    int linha, coluna;
    int quantidade_bombas = 0.2*n*n;
    srand(time(NULL));

    while (quantidade_bombas != 0) {
        linha = rand() % n;
        coluna = rand() % n;
        if (M[linha][coluna] != '*'){
            M[linha][coluna] = '*';
            --quantidade_bombas;
        } 
    }
} 

int n_bombas (int l, int c, char M[][N], int n) {
    int contador_bombas = 0, contador_jogadas = 0.8*n*n, contador;
    int i = l - 1, j = c - 1;
    char cima = M[i-1][j], baixo = M[i+1][j], esquerda = M[i][j-1], direita = M[i][j+1];
    char diagonal_superior_esquerda = M[i-1][j-1], diagonal_superior_direita = M[i-1][j+1], diagonal_inferior_esquerda = M[i+1][j-1], diagonal_inferior_direita = M[i+1][j+1];
    for (contador = 0; contador < contador_jogadas; contador++) {
        if ((l < 1) || (l > n) || (c < 1) || (c > n)) {
            printf("Entrada invalida.\n\n");
            imprime_matriz(M, n);
            printf("\nDigite a linha e coluna desejada: ");
            scanf("%d %d", &l, &c);
        } else{
             if (M[l][c] == '*') {
                printf("VOCE PERDEU! FIM DO JOGO.");
                break;
            }
            if ((i == 0) && (j == 0)) {
                if (baixo == '*'){
                    contador_bombas += 1;
                }
                if (direita == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_direita == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i == 0) && (j == n - 1)) {
                if (baixo == '*'){
                    contador_bombas += 1;
                }
                if (esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_esquerda == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i == n - 1) && (j == 0)) {
                if (cima == '*'){
                    contador_bombas += 1;
                }
                if (direita == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_direita == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i == n - 1) && (j == n - 1)) {
                if (cima == '*'){
                    contador_bombas += 1;
                }
                if (esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_esquerda == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i != n - 1) && (i != 0) && (j != 0) && (j != n - 1)) {
                if (baixo == '*'){
                    contador_bombas += 1;
                }
                if (cima == '*'){
                    contador_bombas += 1;
                }
                if (direita == '*'){
                    contador_bombas += 1;
                }
                if (esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_direita == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_direita == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_esquerda == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i == 0) && (j != 0) && (j != n - 1)) {
                if (esquerda == '*'){
                    contador_bombas += 1;
                }
                if (direita == '*'){
                    contador_bombas += 1;
                }
                if (baixo == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_direita == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i == n - 1) && (j != 0) && (j != n - 1)) {
                if (esquerda == '*'){
                    contador_bombas += 1;
                }
                if (direita == '*'){
                    contador_bombas += 1;
                }
                if (cima == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_direita == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i != 0) && (i != n - 1) && (j == 0)) {
                if (baixo == '*'){
                    contador_bombas += 1;
                }
                if (direita == '*'){
                    contador_bombas += 1;
                }
                if (cima == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_direita == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_inferior_direita == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            if ((i != 0) && (i != n - 1) && (j == n - 1)) {
                if (esquerda == '*'){
                    contador_bombas += 1;
                }
                if (baixo == '*'){
                    contador_bombas += 1;
                }
                if (cima == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_esquerda == '*'){
                    contador_bombas += 1;
                }
                if (diagonal_superior_esquerda == '*'){
                    contador_bombas += 1;
                }
                char contador_bombas1 = contador_bombas + '0';
                M[i][j] = contador_bombas1;
            }
            imprime_matriz(M,n);
        }
        printf("\nDigite a linha e coluna desejada: ");
        scanf("%d %d", &l, &c);
    }
}      

int main() {
    int n_matriz, linha, coluna, i, j, contador_posicoes;
    printf("Digite o tamanho da matriz desejada: ");
    scanf("%d", &n_matriz);
    char matriz_base[N][N];
    for (i = 0; i < n_matriz; i++) {
        for (j = 0; j < n_matriz; j++) {
            matriz_base[i][j] = '?';
        }
    }
    if ((n_matriz <= 9) && (n_matriz >= 3)) {
        imprime_matriz(matriz_base, n_matriz);
        printf("\nDigite a linha e coluna desejada: ");
        scanf("%d %d", &linha, &coluna);
        gera_campo(matriz_base,n_matriz);
        n_bombas(linha, coluna, matriz_base,n_matriz);
    } else {
        printf("Entrada invalida.");
        printf("\nDigite o tamanho da matriz desejada: ");
        scanf("%d", &n_matriz);
        for (i = 0; i < n_matriz; i++) {
            for (j = 0; j < n_matriz; j++) {
                matriz_base[i][j] = '?';
            }
        }
        imprime_matriz(matriz_base, n_matriz);
        gera_campo(matriz_base,n_matriz);
        n_bombas(linha, coluna, matriz_base,n_matriz);
    }
}


