#include <stdio.h>
#include <string.h>

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu de atributos
int escolherAtributo(const char* msg) {
    int opcao;
    printf("%s\n", msg);
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha um atributo (1-5): ");
    scanf("%d", &opcao);
    return (opcao >= 1 && opcao <= 5) ? opcao : -1; // Valida a entrada
}

int main() {
    char estado1[3], codigo1[4], nomeCidade1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1, densidadePopulacional1, pibPerCapita1;

    char estado2[3], codigo2[4], nomeCidade2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2, densidadePopulacional2, pibPerCapita2;

    // Entrada de dados para a primeira carta
    printf("Insira os dados da primeira carta:\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", estado1);
    limparBuffer();
    printf("Código da Carta (ex: A01): ");
    scanf("%3s", codigo1);
    limparBuffer();
    printf("Nome da Cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    if (area1 <= 0) {
        printf("Erro: A área deve ser maior que zero.\n");
        return 1;
    }
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000) / populacao1;

    // Entrada de dados para a segunda carta
    printf("\nInsira os dados da segunda carta:\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", estado2);
    limparBuffer();
    printf("Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);
    limparBuffer();
    printf("Nome da Cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    if (area2 <= 0) {
        printf("Erro: A área deve ser maior que zero.\n");
        return 1;
    }
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000) / populacao2;

    // Escolha de dois atributos
    int atributo1, atributo2;
    do {
        atributo1 = escolherAtributo("Escolha o primeiro atributo para comparar:");
    } while (atributo1 == -1);

    do {
        atributo2 = escolherAtributo("Escolha o segundo atributo para comparar:");
    } while (atributo2 == -1 || atributo2 == atributo1);

    float valor1C1, valor1C2, valor2C1, valor2C2;
    
    // Obtenção dos valores para comparação
    switch (atributo1) {
        case 1: valor1C1 = populacao1; valor1C2 = populacao2; break;
        case 2: valor1C1 = area1; valor1C2 = area2; break;
        case 3: valor1C1 = pibPerCapita1; valor1C2 = pibPerCapita2; break;
        case 4: valor1C1 = pontosTuristicos1; valor1C2 = pontosTuristicos2; break;
        case 5: valor1C1 = densidadePopulacional1; valor1C2 = densidadePopulacional2; break;
    }
    
    switch (atributo2) {
        case 1: valor2C1 = populacao1; valor2C2 = populacao2; break;
        case 2: valor2C1 = area1; valor2C2 = area2; break;
        case 3: valor2C1 = pibPerCapita1; valor2C2 = pibPerCapita2; break;
        case 4: valor2C1 = pontosTuristicos1; valor2C2 = pontosTuristicos2; break;
        case 5: valor2C1 = densidadePopulacional1; valor2C2 = densidadePopulacional2; break;
    }

    // Comparação e soma dos atributos
    int pontosC1 = ((atributo1 != 5 && valor1C1 > valor1C2) || (atributo1 == 5 && valor1C1 < valor1C2)) ? 1 : 0;
    pontosC1 += ((atributo2 != 5 && valor2C1 > valor2C2) || (atributo2 == 5 && valor2C1 < valor2C2)) ? 1 : 0;

    int pontosC2 = ((atributo1 != 5 && valor1C2 > valor1C1) || (atributo1 == 5 && valor1C2 < valor1C1)) ? 1 : 0;
    pontosC2 += ((atributo2 != 5 && valor2C2 > valor2C1) || (atributo2 == 5 && valor2C2 < valor2C1)) ? 1 : 0;

    // Exibição do resultado
    printf("\nResultado da rodada:\n");
    printf("Carta 1 (%s - %s) obteve %d pontos\n", nomeCidade1, estado1, pontosC1);
    printf("Carta 2 (%s - %s) obteve %d pontos\n", nomeCidade2, estado2, pontosC2);
    printf("%s venceu!\n", (pontosC1 > pontosC2) ? nomeCidade1 : (pontosC2 > pontosC1) ? nomeCidade2 : "Empate!");

    return 0;
}
