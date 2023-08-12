#include <stdio.h> //Importa a biblioteca de entrada e saída.
#include <stdlib.h>
#include <time.h>

// #define NUMERO_DE_TENTATIVAS 5 // Diretiva #define, define uma constante

int main()
{
    // Imprime o cabeçalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int segundos = time(0); // Função time trás todos os segundos passados desde 01/01/1970 até agora
    srand(segundos);
    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    while (1)
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

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if (acertou)
        {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
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
    printf("Você acertou em %d tentativas. \n", tentativas);
    printf("Total de pontos: %.1f \n", pontos);
}
