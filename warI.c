#include <stdio.h>
#include <string.h>

// --- Definição da struct ---
typedef struct {
    char nome[30];   // Nome do território
    char cor[20];    // Cor do exército
    int tropas;      // Quantidade de tropas
} Territorio;

// --- Função utilitária ---
// Limpa o buffer de entrada para evitar problemas ao alternar entre scanf e fgets
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Remove a quebra de linha do fgets
void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    // --- Vetor para armazenar 5 territórios ---
    Territorio territorios[5];

    // --- Entrada dos dados ---
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        // Leitura do nome
        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        removerQuebraLinha(territorios[i].nome);

        // Leitura da cor do exército
        printf("Digite a cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        removerQuebraLinha(territorios[i].cor);

        // Leitura da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada(); // garante que o próximo fgets funcione corretamente
    }

    // --- Exibição dos dados cadastrados ---
    printf("\n========================================\n");
    printf("   LISTA DE TERRITÓRIOS CADASTRADOS\n");
    printf("========================================\n");

    for (int i = 0; i < 5; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
    }

    printf("\nCadastro concluído com sucesso!\n");

    return 0;
}