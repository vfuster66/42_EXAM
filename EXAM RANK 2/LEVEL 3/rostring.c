/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
-----------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

--------------------------------*/

#include <unistd.h>

// Cette fonction renvoie la position de la première occurrence d'un caractère qui n'est pas une espace ou une tabulation dans la chaîne str à partir de la position i.
int		skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	return (i);
}

// Cette fonction renvoie la longueur du premier mot dans la chaîne str.
int		ft_wordlen(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		++i;
	return (i);
}

// Cette fonction imprime le premier mot dans la chaîne str à partir de la position i, et renvoie la nouvelle position dans la chaîne.
int		print_word(char *str, int i, int *is_first)
{
	int word_len;

	// On ignore les espaces et les tabulations au début du mot.
	i = skip_whitespace(str, i);
	// On calcule la longueur du mot.
	word_len = ft_wordlen(str + i);
	// Si ce n'est pas le premier mot qu'on imprime, on ajoute un espace avant.
	if (*is_first == 0)
		write(1, " ", 1);
	// On imprime le mot.
	write(1, str + i, word_len);
	// On met is_first à 0 pour indiquer que le premier mot a été imprimé.
	*is_first = 0;
	// On renvoie la nouvelle position dans la chaîne.
	return (i + word_len);
}

// Cette fonction imprime tous les mots dans la chaîne str séparés par un seul espace, et renvoie 1 si la chaîne est vide (c'est-à-dire qu'il n'y a pas de mots à imprimer).
int		epur_str(char *str)
{
	int i = 0;
	int is_first = 1;

	// On ignore les espaces et les tabulations au début de la chaîne.
	i = skip_whitespace(str, i);
	// Tant qu'on n'a pas atteint la fin de la chaîne,
	while (str[i] != '\0')
	{
		// On imprime le premier mot à partir de la position i, et on met à jour la nouvelle position i.
		i = print_word(str, i, &is_first);
		// On ignore les espaces et les tabulations après le mot qu'on vient d'imprimer.
		i = skip_whitespace(str, i);
	}
	// On renvoie is_first qui vaut 1 si la chaîne est vide, et 0 sinon.
	return (is_first);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		// On récupère la chaîne à traiter depuis les arguments du programme.
		char *str = av[1];
		int i;
		int is_first;

		i = 0;
		// On ignore les espaces et les tabulations au début de la chaîne.
		i = skip_whitespace(str, i);
		// On avance jusqu'au début du deuxième mot dans la chaîne.
		i = i + ft_wordlen(str + i);
		// On imprime tous les mots dans la chaîne séparés par un seul espace, à partir de la position i.
		is_first = epur_str(str + i);
		// Imprime le premier mot, avec is_first défini sur vrai
		print_word(str, 0, &is_first);
	}
	// Imprime un caractère de saut de ligne pour terminer la sortie
	write(1, "\n", 1);
	// Renvoie 0 pour indiquer une exécution réussie du programme
	return (0);

	
