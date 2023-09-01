#include <stdlib.h>

int	max(int* tab, unsigned int len)
{
    if (tab == NULL || len == 0)
        return (0);
    int    valeur_max = tab[0];
    unsigned int    i = 1;
    while (i < len)
    {
        if (valeur_max < tab[i])
            valeur_max = tab[i];
        i++;
    }
    return (valeur_max);
}
