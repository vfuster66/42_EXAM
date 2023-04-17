#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("\n");
        return 0;
    }

    int n = atoi(argv[1]);

    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    int i = 2;
    while (i <= n)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            n /= i;
            if (n > 1)
            {
                printf("*");
            }
            i = 1;
        }
        i++;
    }

    printf("\n");
    return 0;
}

