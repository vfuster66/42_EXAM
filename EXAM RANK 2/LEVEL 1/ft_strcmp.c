/*Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
-----------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);

------------------------------------*/

int	ft_strcmp(const char *s1, const char *s2)
{
	// Déclaration de la variable i qui sera utilisée pour parcourir les chaînes de caractères
	int	i;
	
	// Initialisation de i à 0
	i = 0;
	//Boucle while qui parcourt les deux chaînes de caractères s1 et s2 en même temps, 
	//caractère par caractère. La boucle continue tant que les caractères s1[i] et s2[i] ne sont pas nuls 
	//(c'est-à-dire qu'ils n'ont pas atteint la fin de la chaîne) et qu'ils sont égaux.
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	// Retourne la différence entre les deux caractères s1[i] et s2[i], 
	//en les convertissant d'abord en entiers non signés de 8 bits à l'aide de l'opérateur cast (unsigned char). 
	//Cette technique permet de s'assurer que la fonction renvoie un résultat correct même si les caractères sont signés.
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*-----------------------------

#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
    char str1[] = "hello";
    char str2[] = "world";
    
    int result = ft_strcmp(str1, str2);
    
    if (result == 0)
        printf("Les chaînes sont identiques\n");
    else if (result < 0)
        printf("La chaîne \"%s\" est avant la chaîne \"%s\" dans l'ordre alphabétique\n", str1, str2);
    else
        printf("La chaîne \"%s\" est après la chaîne \"%s\" dans l'ordre alphabétique\n", str1, str2);
        
    return 0;
}

----------------------------*/
