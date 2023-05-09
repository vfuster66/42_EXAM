/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

--------------------------------------*/

#include <stdlib.h>

/* La fonction ft_strspn calcule la longueur (en caractères) du segment initial de la chaîne s 
   qui ne contient que des caractères de la chaîne accept. 
   Cette fonction retourne un type size_t, qui est un type entier non signé. */

size_t ft_strspn(const char *s, const char *accept)
{
   // Compteur pour la chaîne s
   size_t  i;
   // Compteur pour la chaîne accept
   size_t	j; 
    
   i = 0;
   // On parcourt la chaine s
   while (s[i])
   {
      j = 0;
      // on parcourt la chaine accept
      while (accept[j])
      {
         // Si on trouve un caractère correspondant, on sort de la boucle
         if (s[i] == accept[j])
            break;
         j++;
      }
      // Si aucun caractère correspondant n'est trouvé, on retourne la longueur
      if (!accept[j])
         return (i);
      i++;
   }
   // Si on parcourt toute la chaîne s sans trouver de caractères qui ne sont pas dans accept, on retourne la longueur de s
   return (i); 
}

/*-------------------------------------

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept);

int main(void)
{
    const char *s = "Hello, world!";
    const char *accept = "eloH wrd";

    size_t ft_result = ft_strspn(s, accept);
    size_t std_result = strspn(s, accept);

    printf("ft_strspn result: %zu\n", ft_result);
    printf("strspn result: %zu\n", std_result);

    if (ft_result == std_result)
        printf("Both functions returned the same result.\n");
    else
        printf("The results differ.\n");

    return 0;
}

-------------------------------------*/
