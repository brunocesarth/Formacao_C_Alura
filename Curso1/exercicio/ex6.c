#include <stdio.h>

int main()
{
    int n = 0;

    printf("Digite um número: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
    {
        int resultado = n * i;
        printf("%dx%d=%d\n", n, i, resultado);
    }
}