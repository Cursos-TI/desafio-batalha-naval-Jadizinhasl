#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar o navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio pode ser posicionado sem ultrapassar os limites do tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0; // Há sobreposição
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Marca as posições ocupadas pelo navio com 3
    }
    return 1;
}

// Função para posicionar o navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio pode ser posicionado sem ultrapassar os limites do tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0; // Há sobreposição
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Marca as posições ocupadas pelo navio com 3
    }
    return 1;
}

// Função para posicionar o navio na diagonal (crescente)
int posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio pode ser posicionado na diagonal crescente sem ultrapassar os limites
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0; // Há sobreposição
    }

    // Posiciona o navio na diagonal crescente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // Marca as posições ocupadas pelo navio com 3
    }
    return 1;
}

// Função para posicionar o navio na diagonal (decrescente)
int posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio pode ser posicionado na diagonal decrescente sem ultrapassar os limites
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO < -1) return 0;

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) return 0; // Há sobreposição
    }

    // Posiciona o navio na diagonal decrescente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3; // Marca as posições ocupadas pelo navio com 3
    }
    return 1;
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas para os navios horizontais
    int linhaHorizontal = 2, colunaHorizontal = 4;

    // Coordenadas para os navios verticais
    int linhaVertical = 5, colunaVertical = 6;

    // Coordenadas para os navios diagonais (crescente e decrescente)
    int linhaDiagonalCrescente = 0, colunaDiagonalCrescente = 0;
    int linhaDiagonalDecrescente = 6, colunaDiagonalDecrescente = 9;

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Falha ao posicionar navio horizontal.\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Falha ao posicionar navio vertical.\n");
    }
    if (!posicionarNavioDiagonalCrescente(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente)) {
        printf("Falha ao posicionar navio diagonal crescente.\n");
    }
    if (!posicionarNavioDiagonalDecrescente(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente)) {
        printf("Falha ao posicionar navio diagonal decrescente.\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
