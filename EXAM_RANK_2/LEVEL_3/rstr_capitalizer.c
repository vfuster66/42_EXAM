/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
-------------------------------------

Write a program that takes one or more strings and, for each argument, puts 
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>

-------------------------------------*/

#include <unistd.h>

void rstr_capitalizer(char *str)
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
		// Convertit une lettre minuscule en majuscule si elle est suivie d'un espace ou d'une tabulation
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\t'))
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
		rstr_capitalizer(av[1]);
      // Écrit une nouvelle ligne après chaque argument
		write(1, "\n", 1); 
		i++;
	}
	return (0);
}
