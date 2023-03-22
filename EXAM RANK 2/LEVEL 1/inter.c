/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

-----------------------------------------*/

#include <unistd.h>

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	ft_char_in_str(char c, char *str, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void	ft_inter(char *s1, char *s2)
{
    int	i;
    int	j;
    int	k;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j] && !ft_char_in_str(s1[i], s1, i))
            {
                k = 0;
                while (k < j && s2[k] != s2[j])
                    k++;
                if (k == j)
                    write(1, &s1[i], 1);
            }
            j++;
        }
        i++;
    }
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}

