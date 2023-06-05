/*Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
-------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

-------------------------------------*/

#include <unistd.h>

int main(int ac, char **av)
{
   // Variable de boucle pour parcourir les arguments
   int   i;
   // Variable de boucle pour parcourir les caractères de chaque argument
   int   j;
   
   // Commencer à partir du premier argument (avant le nom du programme)
   i = 1;
   if (ac == 1)
   {
      // S'il n'y a pas d'arguments, écrire simplement un saut de ligne
      write(1, "\n", 1); 
      return (0);
   }
   // Parcourir tous les arguments
   while (i < ac)
   {
      // Réinitialiser la variable de boucle pour chaque argument
      j = 0;
      // Parcourir tous les caractères de l'argument actuel
      while (av[i][j])
      {
         if ((av[i][j] >= 'a' && av[i][j] <= 'z') || (av[i][j] >= 'A' && av[i][j] <= 'Z'))
         {
            // Si le caractère est une lettre majuscule ou minuscule
            if (j == 0 || !((av[i][j - 1] >= 'a' && av[i][j - 1] <= 'z') || (av[i][j - 1] >= 'A' && av[i][j - 1] <= 'Z')))
            {
               // Si c'est la première lettre de l'argument ou si la lettre précédente n'est pas une lettre
               if (av[i][j] >= 'a' && av[i][j] <= 'z')
                  // Convertir la lettre en majuscule
                  av[i][j] = av[i][j] - 32;
            }
            else
            {
               if (av[i][j] >= 'A' && av[i][j] <= 'Z')
                  // Convertir la lettre en minuscule
                  av[i][j] = av[i][j] + 32;
            }
         }
         // Écrire le caractère traité
         write(1, &av[i][j], 1);
         // Passer au caractère suivant dans l'argument actuel
         j++;
      }
      // Après avoir traité un argument complet, écrire un saut de ligne
      write(1, "\n", 1);
      // Passer à l'argument suivant
      i++;
   }
   return (0);
}

