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

int   main(int ac, char **av)
{
   int   i;
   int   j;
   
   i = 1;
   // Si le programme est lancé sans argument
   if (ac == 1) 
   {
      // Écrit une nouvelle ligne et quitte
      write(1, "\n", 1);
      return (0);
   }
   // Boucle sur les arguments fournis en ligne de commande
   while (i < ac)
    {
      j = 0;
      // Boucle sur les caractères du ième argument
      while (av[i][j])
      {
         // Si le caractère est une lettre
         if ((av[i][j] >= 'a' && av[i][j] <= 'z') || (av[i][j] >= 'A' && av[i][j] <= 'Z'))
         {
            // Si le caractère est le premier caractère du mot ou s'il est précédé d'un caractère non alphabétique
            if (j == 0 || !((av[i][j - 1] >= 'a' && av[i][j - 1] <= 'z') || (av[i][j - 1] >= 'A' && av[i][j - 1] <= 'Z')))
            {
               // Si le caractère est une minuscule
               if (av[i][j] >= 'a' && av[i][j] <= 'z')
                  // Convertit le caractère en majuscule
                  av[i][j] = av[i][j] - 32;
            }
            else
            {
               // Si le caractère est une majuscule
               if (av[i][j] >= 'A' && av[i][j] <= 'Z')
                  // Convertit le caractère en minuscule
                  av[i][j] = av[i][j] + 32;
            }
            // Passe au caractère suivant
            j++;
         }
         // Écrit le mot avec ses caractères convertis
         write(1, av[i], j);
         // Écrit une nouvelle ligne
         write(1, "\n", 1);
         // Passe au mot suivant
         i++;
      }
      return (0);
}
