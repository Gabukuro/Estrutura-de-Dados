#include <stdio.h>

int potencia(int x, int n, int count)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        x *= x;
    }

    while (count <= n)
    {
        count += 1;
        potencia(x, n, count);
        printf("\n%i\n%i\n", count, x);
    }
}

int main()
{
    int count = 0;
    int x = 10;
    int n = 2;

    potencia(x, n, count);
}