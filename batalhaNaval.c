#include <stdio.h>

// Definindo o tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5  // Tamanho das matrizes de habilidade (5x5)

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // Água (0) em cada posição
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade em cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = { 
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidadeCone[i][j] == 1) {
                int linha = origemLinha - 2 + i;  // Ajuste para que o cone se centralize no ponto de origem
                int coluna = origemColuna - 2 + j;
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5;  // Marca a área afetada pelo cone
                }
            }
        }
    }
}

// Função para aplicar a habilidade cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = { 
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidadeCruz[i][j] == 1) {
                int linha = origemLinha - 2 + i;  // Ajuste para que a cruz se centralize no ponto de origem
                int coluna = origemColuna - 2 + j;
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5;  // Marca a área afetada pela cruz
                }
            }
        }
    }
}

// Função para aplicar a habilidade octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = { 
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidadeOctaedro[i][j] == 1) {
                int linha = origemLinha - 2 + i;  // Ajuste para que o octaedro se centralize no ponto de origem
                int coluna = origemColuna - 2 + j;
                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5;  // Marca a área afetada pelo octaedro
                }
            }
        }
    }
}

int main() {
    // Declaração do tabuleiro 10x10 (matriz)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Definir a posição dos navios no tabuleiro
    tabuleiro[2][3] = 3;  // Exemplo de navio (posição 2, 3)
    tabuleiro[4][5] = 3;  // Exemplo de navio (posição 4, 5)
    
    // Definir as origens das habilidades
    int origemConeLinha = 3, origemConeColuna = 3;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7;

    // Aplicar as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, origemConeLinha, origemConeColuna);
    aplicarHabilidadeCruz(tabuleiro, origemCruzLinha, origemCruzColuna);
    aplicarHabilidadeOctaedro(tabuleiro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibir o tabuleiro com os navios e as áreas de efeito
    printf("Tabuleiro do Batalha Naval com Habilidades Especiais:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
