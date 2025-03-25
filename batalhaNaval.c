#include <stdio.h>

// Definir o tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("3 "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("5 "); // Área afetada pela habilidade
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade em cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int x = origemX + i - 2; // Ajuste de índice
                int y = origemY + j - 2; // Ajuste de índice
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    if (tabuleiro[x][y] == 0) // Só marcar as posições de água
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Função para aplicar a habilidade em cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int x = origemX + i - 2; // Ajuste de índice
                int y = origemY + j - 2; // Ajuste de índice
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    if (tabuleiro[x][y] == 0) // Só marcar as posições de água
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Função para aplicar a habilidade em octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    int octaedro[5][5] = {
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemX + i - 2; // Ajuste de índice
                int y = origemY + j - 2; // Ajuste de índice
                if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                    if (tabuleiro[x][y] == 0) // Só marcar as posições de água
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Função para colocar navios no tabuleiro
void colocarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int direcao) {
    for (int i = 0; i < 3; i++) { // Tamanho do navio é 3
        if (direcao == 0) { // Horizontal
            if (y + i < TAMANHO_TABULEIRO)
                tabuleiro[x][y + i] = 3;
        } else { // Vertical
            if (x + i < TAMANHO_TABULEIRO)
                tabuleiro[x + i][y] = 3;
        }
    }
}

int main() {
    // Inicializar o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Colocar navios no tabuleiro
    colocarNavios(tabuleiro, 1, 1, 0); // Navio horizontal na linha 1
    colocarNavios(tabuleiro, 4, 4, 1); // Navio vertical na coluna 4

    // Aplicar as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 5, 5);
    aplicarHabilidadeCruz(tabuleiro, 3, 3);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
