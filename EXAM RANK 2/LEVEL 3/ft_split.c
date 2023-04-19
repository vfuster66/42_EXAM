/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

-------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    while (n--)
        *d++ = *s++;

    return dest;
}

char	**ft_split(char *str)
{
    char	**result;
    int	i;
    int	j;
    int	k;

    result = (char **)malloc(sizeof(char *) * (strlen(str) + 1));
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i] == '\0')
            break;
        k = i;
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        result[j] = (char *)malloc(sizeof(char) * (i - k + 1));
        if (!result[j])
            return (NULL);
        memcpy(result[j], str + k, i - k);
        result[j][i - k] = '\0';
        j++;
    }
    result[j] = NULL;
    return (result);
}

/*-----------------------------------
#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str);

int main(void)
{
    char str[] = "Hello, World! How are you today?";
    char **words = ft_split(str);

    if (words == NULL)
    {
        printf("Erreur: la fonction ft_split a renvoyé NULL.\n");
        return 1;
    }

    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    free(words);

    return 0;
}

----------------------------------------*/
