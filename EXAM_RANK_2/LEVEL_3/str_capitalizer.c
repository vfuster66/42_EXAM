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

void str_capitalizer(char *str)
{
   // Variable pour l'itération
	int i = 0;

	// Vérifie si le premier caractère est une lettre minuscule et le convertit en majuscule 
   // si c'est le cas
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
   // Écrit le caractère modifié à la sortie standard
	write(1, &str[i], 1);
   // Parcourt les caractères restants de la chaîne
	while (str[++i])
	{
		// Convertit une lettre majuscule en minuscule si elle est rencontrée
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		// Convertit une lettre minuscule en majuscule si elle est précédée d'un espace ou d'une tabulation
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] -= 32;
      // Écrit le caractère modifié à la sortie standard
		write(1, &str[i], 1);
	}
}

int main(int ac, char **av)
{
	int i;

   // Si aucun argument n'est passé, écrit une nouvelle ligne et quitte
	if (ac == 1)
	{
		write(1, "\n", 1); 
		return (0);
	}
	i = 1;
   // Parcourt tous les arguments passés
	while (i < ac)
	{
      // Applique la fonction de capitalisation à chaque argument
		str_capitalizer(av[1]);
      // Écrit une nouvelle ligne après chaque argument
		write(1, "\n", 1); 
		i++;
	}
	return (0);
}
