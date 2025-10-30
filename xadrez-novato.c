#include <stdio.h>

int main() {
    int peca, direcao, casas;
    const int bispo = 5;
    const int torre = 5;
    const int rainha = 8;

    // Inicio do jogo - Escolha da peça
    printf("\n=== DESAFIO DE XADREZ - MateCheck ===\n");
    printf("\nEscolha a peça:\n");
    printf("1 - Bispo\n");
    printf("2 - Torre\n");
    printf("3 - Rainha\n");
    printf("Opção numeral: ");
    scanf("%d", &peca);

    // Validar peça
    if (peca < 1 || peca > 3) {
        printf("\n*** Erro: peça inválida! ***\n");
        return 0;
    }

    // Mostrar direções conforme a peça escolhida
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
    
    } else { // RAINHA
        printf("1 - Cima (máx. 8 casas)\n");
        printf("2 - Baixo (máx. 8 casas)\n");
        printf("3 - Esquerda (máx. 8 casas)\n");
        printf("4 - Direita (máx. 8 casas)\n");
        printf("5 - Diagonal Superior Direita (máx. 8 casas)\n");
        printf("6 - Diagonal Superior Esquerda (máx. 8 casas)\n");
        printf("7 - Diagonal Inferior Direita (máx. 8 casas)\n");
        printf("8 - Diagonal Inferior Esquerda (máx. 8 casas)\n");
    }

    printf("Opção numeral: ");
    scanf("%d", &direcao);

    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    // Validação de movimento mínimo
    if (casas <= 0) {
        printf("\n*** Erro: a peça deve se mover pelo menos 1 casa! ***\n");
        return 0;
    }

    // Valida limite de movimento
    if ((peca == 1 && casas > bispo) || // && = Todas as condições devem ser verdadeiras
        (peca == 2 && casas > torre) ||
        (peca == 3 && casas > rainha)) {
        printf("\n*** Erro: essa peça não pode se mover tantas casas! ***\n");
        return 0;
    }

    printf("\n=== Movimentação ===\n");

    // BISPO = usa for
    if (peca == 1) {
        if (direcao < 1 || direcao > 4) { // Validação direção
            printf("Erro: direção inválida para o Bispo!\n");
            return 0;
        }
        for (int i = 1; i <= casas; i++) { // for para quantidade de casas que será movida
            printf("Casa %d: ", i);
            switch (direcao) { // switch para direção escolhida
                case 1: printf("Diagonal Superior Direita (Cima + Direita)\n"); break;
                case 2: printf("Diagonal Superior Esquerda (Cima + Esquerda)\n"); break;
                case 3: printf("Diagonal Inferior Direita (Baixo + Direita)\n"); break;
                case 4: printf("Diagonal Inferior Esquerda (Baixo + Esquerda)\n"); break;
            }
        }
    }

    // TORRE = usa while
    else if (peca == 2) {
        if (direcao < 1 || direcao > 4) {
            printf("*** Erro: direção inválida para a Torre! ***\n");
            return 0;
        }
        int i = 1;
        while (i <= casas) {
            printf("Casa %d: ", i);
            switch (direcao) {
                case 1: printf("Cima\n"); break;
                case 2: printf("Baixo\n"); break;
                case 3: printf("Esquerda\n"); break;
                case 4: printf("Direita\n"); break;
            }
            i++;
        }
    }

    // RAINHA = usa do-while
    else if (peca == 3) {
        if (direcao < 1 || direcao > 8) {
            printf("*** Erro: direção inválida para a Rainha! ***\n");
            return 0;
        }
        int i = 1;
        do {
            printf("Casa %d: ", i);
            switch (direcao) {
                case 1: printf("Cima\n"); break;
                case 2: printf("Baixo\n"); break;
                case 3: printf("Esquerda\n"); break;
                case 4: printf("Direita\n"); break;
                case 5: printf("Diagonal Superior Direita (Cima + Direita)\n"); break;
                case 6: printf("Diagonal Superior Esquerda (Cima + Esquerda)\n"); break;
                case 7: printf("Diagonal Inferior Direita (Baixo + Direita)\n"); break;
                case 8: printf("Diagonal Inferior Esquerda (Baixo + Esquerda)\n"); break;
            }
            i++;
        } while (i <= casas);
    }

    printf("\nMovimento finalizado com sucesso!\n");
    return 0;
}