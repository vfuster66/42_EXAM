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

// Fonction qui copie n octets depuis l'adresse src vers l'adresse dest
void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    while (n--)
        *d++ = *s++;
    return dest;
}

char    **ft_split(char *str)
{
    char    **result;
    int i;
    int j;
    int k;
    
    i = 0;
    j = 0;
    k = 0;
    // Compter le nombre de mots dans la chaîne de caractères
    while (str[i])
    {
        // Ignorer les espaces, les tabulations et les sauts de ligne
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        // Compter la longueur du mot
        k = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        // Si la longueur du mot est supérieure à zéro, incrémenter le compteur de mots
        if (i > k)
            j++;
    }
    // Allouer de la mémoire pour le tableau de résultats
    result = (char **)malloc(sizeof(char *) * (j + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        // Ignorer les espaces, les tabulations et les sauts de ligne
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        // Copier le mot dans un nouveau tampon
        k = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        // Si la longueur du mot est supérieure à zéro, l'ajouter au tableau de résultats
        if (i > k)
        {
            result[j] = (char *)malloc(sizeof(char) * (i - k + 1));
            if (!result[j])
                return (NULL);
            // Copier le mot dans le tableau de résultats
            ft_memcpy(result[j], &str[k], i - k);
            result[j][i - k] = '\0';
            j++;
        }
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
