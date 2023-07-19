/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
---------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

----------------------------------*/

int		main(int ac, char **av)
{
	int	i;

	i = 0;
	 // Si le nombre d'arguments n'est pas égal à 2, on affiche une nouvelle ligne et on retourne 0
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	// On itère sur chaque caractère de la chaîne av[1]
	while (av[1][i]) 
		i++;
	// On décrémente i tant qu'on trouve des espaces ou des tabulations à la fin de la chaîne
	while (--i && (av[1][i] == ' ' || av[1][i] == '\t'))
		;
	// On décrémente i tant qu'on trouve des caractères qui ne sont pas des espaces ou des tabulations
	while (i && av[1][i] != ' ' && av[1][i] != '\t')
		i--;
	// Si le dernier caractère est un espace ou une tabulation, on incrémente i pour pointer sur le premier caractère du dernier mot
	if (av[1][i] == ' ' || av[1][i] == '\t') 
		i++;
	// On écrit chaque caractère du dernier mot sur la sortie standard 
	while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t') 
		write(1, &av[1][i++], 1);
	// On affiche une nouvelle ligne
	write(1, "\n", 1); 
	return (0);
}
