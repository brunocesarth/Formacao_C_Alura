#include <stdio.h>

int main()
{
    int numero1, numero2, resultado;

    printf("Digite um número: ");
    scanf("%d", &numero1);
    printf("Digite mais um número: ");
    scanf("%d", &numero2);

    resultado = numero1 * numero2;

    printf("O resultado de %dx%d é igual a %d \n", numero1, numero2, resultado);
}