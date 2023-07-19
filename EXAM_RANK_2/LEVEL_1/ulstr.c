/*Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
-------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$

-----------------------------*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	// verifie que le nombre d'arguments est bien egal a 2
	if (ac == 2)
	{
		// parcourt chaque caractère de la chaîne de caractères passée en argument
		while (av[1][i])
		{
			// si le caractère est une lettre minuscule, le transforme en majuscule
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] -= 32;
			// sinon, si le caractère est une lettre majuscule, le transforme en minuscule
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += 32;
			// écrit le caractère transformé dans la sortie standard
			write(1, &av[1][i], 1);
			i++;
		}	
	}
	// écrit un retour à la ligne dans la sortie standard
	write(1, "\n", 1);
	return (0);
}


