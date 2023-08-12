#include <stdio.h> //Importa a biblioteca de entrada e saída.
#include <stdlib.h>
#include <time.h>

// #define NUMERO_DE_TENTATIVAS 5 // Diretiva #define, define uma constante

int main()
{
    // Imprime o cabeçalho do nosso jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |"
           "  |  |_|  |"
           " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int segundos = time(0); // Função time trás todos os segundos passados desde 01/01/1970 até agora
    srand(segundos);
    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil  (2) Médio  (3) Difícil \n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas;

    switch (nivel)
    {
    case 1:
        numeroDeTentativas = 20;
        break;
    case 2:
        numeroDeTentativas = 15;
        break;
    default:
        numeroDeTentativas = 6;
        break;
    }

    int acertou = 0;

    for (int i = 1; i <= numeroDeTentativas; i++)
    {
        printf("Tentativa %d\n", tentativas);
        printf("Chute um número: ");
        scanf("%d", &chute);
        if (chute < 0)
        {
            printf("Você não pode chutar números negativos!\n");
            continue; // Para a execução do bloco e volta para iteração
        }

        printf("Seu chute foi %d \n", chute);

        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if (acertou)
        {
            break;
        }
        else if (maior)
        {
            printf("Seu chute foi maior que o número secreto!\n");
        }
        else
        {
            printf("Seu chute foi menor que o número secreto!\n");
        }
        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2; // abs devolve o valor absoluto(positivo)
        pontos = pontos - pontosPerdidos;
    }

    printf("Fim de Jogo!\n");

    if (acertou)
    {
        printf("\n\n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabéns! Você acertou!\n");
        printf("Você acertou em %d tentativas. \n", tentativas);
        printf("Total de pontos: %.1f \n", pontos);
    }
    else
    {
        printf("Você perdeu! Tente de novo!\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("\n\n");
    }
}
