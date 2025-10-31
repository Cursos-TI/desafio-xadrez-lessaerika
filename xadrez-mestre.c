#include <stdio.h>

// ======== FUNÇÕES RECURSIVAS ========

// BISPO
void moverBispo(int passo, int max, int direcao) { 
    if (passo > max) return; // Quando passo ficar maior que max, a função para de se chamar

    switch (direcao) {
        case 1: printf("Casa %d: Diagonal Superior Direita (Cima + Direita)\n", passo); break;
        case 2: printf("Casa %d: Diagonal Superior Esquerda (Cima + Esquerda)\n", passo); break;
        case 3: printf("Casa %d: Diagonal Inferior Direita (Baixo + Direita)\n", passo); break;
        case 4: printf("Casa %d: Diagonal Inferior Esquerda (Baixo + Esquerda)\n", passo); break;
        default: printf("*** Direção inválida para o Bispo! ***\n"); return;
    }
    moverBispo(passo + 1, max, direcao); // chamada recursiva
}
// TORRE
void moverTorre(int passo, int max, int direcao) {
    if (passo > max) return;

    switch (direcao) {
        case 1: printf("Casa %d: Cima\n", passo); break;
        case 2: printf("Casa %d: Baixo\n", passo); break;
        case 3: printf("Casa %d: Esquerda\n", passo); break;
        case 4: printf("Casa %d: Direita\n", passo); break;
        default: printf("*** Direção inválida para a Torre! ***\n"); return;
    }
    moverTorre(passo + 1, max, direcao);
}
// RAINHA
void moverRainha(int passo, int max, int direcao) {
    if (passo > max) return;

    switch (direcao) {
        case 1: printf("Casa %d: Cima\n", passo); break;
        case 2: printf("Casa %d: Baixo\n", passo); break;
        case 3: printf("Casa %d: Esquerda\n", passo); break;
        case 4: printf("Casa %d: Direita\n", passo); break;
        case 5: printf("Casa %d: Diagonal Superior Direita (Cima + Direita)\n", passo); break;
        case 6: printf("Casa %d: Diagonal Superior Esquerda (Cima + Esquerda)\n", passo); break;
        case 7: printf("Casa %d: Diagonal Inferior Direita (Baixo + Direita)\n", passo); break;
        case 8: printf("Casa %d: Diagonal Inferior Esquerda (Baixo + Esquerda)\n", passo); break;
        default: printf("*** Direção inválida para a Rainha! ***\n"); return;
    }
    moverRainha(passo + 1, max, direcao);
}

int main() {
    int peca, direcao, casas;

    // Limites de movimento por peça. Cavalo não precisa, pois sempre se move 2 casas na vertical + 1 horizontal.
    const int bispo = 5;
    const int torre = 5;
    const int rainha = 8;

    printf("\n=== DESAFIO DE XADREZ - MateCheck ===\n");

    // Escolha da peça
    printf("\nEscolha a peça:\n");
    printf("1 - Bispo\n");
    printf("2 - Torre\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("Opção numeral: ");
    scanf("%d", &peca);

    if (peca < 1 || peca > 4) {
        printf("\n*** Erro: peça inválida! ***\n");
        return 0;
    }

    // Direções por peça
    printf("\nEscolha a direção:\n");

    if (peca == 1) { // BISPO
        printf("1 - Diagonal Superior Direita (máx. 5 casas)\n");
        printf("2 - Diagonal Superior Esquerda (máx. 5 casas)\n");
        printf("3 - Diagonal Inferior Direita (máx. 5 casas)\n");
        printf("4 - Diagonal Inferior Esquerda (máx. 5 casas)\n");
    } else if (peca == 2) { // TORRE
        printf("1 - Cima (máx. 5 casas)\n");
        printf("2 - Baixo (máx. 5 casas)\n");
        printf("3 - Esquerda (máx. 5 casas)\n");
        printf("4 - Direita (máx. 5 casas)\n");
    } else if (peca == 3) { // RAINHA
        printf("1 - Cima (máx. 8 casas)\n");
        printf("2 - Baixo (máx. 8 casas)\n");
        printf("3 - Esquerda (máx. 8 casas)\n");
        printf("4 - Direita (máx. 8 casas)\n");
        printf("5 - Diagonal Superior Direita (máx. 8 casas)\n");
        printf("6 - Diagonal Superior Esquerda (máx. 8 casas)\n");
        printf("7 - Diagonal Inferior Direita (máx. 8 casas)\n");
        printf("8 - Diagonal Inferior Esquerda (máx. 8 casas)\n");
    } else { // CAVALO
        printf("1 - Cima + Direita (L em 3 casas)\n");
        printf("2 - Cima + Esquerda (L em 3 casas)\n");
        printf("3 - Baixo + Direita (L em 3 casas)\n");
        printf("4 - Baixo + Esquerda (L em 3 casas)\n");
    }
    printf("Opção numeral: ");
    scanf("%d", &direcao);

    // Quantidade de casas
    if (peca != 4) { // 4 = Cavalo
    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);
    } else {
    casas = 1; // movimento fixo do cavalo (em L)
    }

    if (casas <= 0) {
        printf("\n*** Erro: o movimento precisa ser de pelo menos 1 casa! ***\n");
        return 0;
    }

    // Validar limite de movimento
    if ((peca == 1 && casas > bispo) ||
        (peca == 2 && casas > torre) ||
        (peca == 3 && casas > rainha)) {
        printf("\n*** Erro: essa peça não pode se mover tantas casas! ***\n");
        return 0;
    }

    printf("\n=== Movimentação ===\n");
    // BISPO (recursão)
    if (peca == 1) {
        moverBispo(1, casas, direcao);
    }
    // TORRE (recursão)
    else if (peca == 2) {
        moverTorre(1, casas, direcao);
    }
    // RAINHA (recursão)
    else if (peca == 3) {
        moverRainha(1, casas, direcao);
    }
    // CAVALO (loops múltiplos, break/continue)
    else if (peca == 4) {
        // Primeiro movimento: 2 verticais (Cima ou Baixo)
    for (int i = 1; i <= 2; i++) {
        if (direcao == 1 || direcao == 2)  // Cima
            printf("Casa %d: Cima\n", i);
        else                                // Baixo
            printf("Casa %d: Baixo\n", i);
    }
    // Segundo movimento: 1 horizontal (Direita ou Esquerda)
    int i = 3;
    if (direcao == 1 || direcao == 3) // Direita
        printf("Casa %d: Direita\n", i);
    else                              // Esquerda
        printf("Casa %d: Esquerda\n", i);
}
    printf("\nMovimento finalizado com sucesso!\n");
    return 0;
}