/*Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str 
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>

-----------------------------------*/

#include <unistd.h>

int word_len(char *str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

void expand_str(char *str)
{
	int len;
	int first_word = 1;
	
	while (*str != '\0')
	{
		while (*str == ' ' || *str == '\t')
			str++;
		len = word_len(str);
		if (len > 0 && !first_word)
			write(1, "   ", 3);
		first_word = 0;
		write(1, str, len);
		str += len;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}

