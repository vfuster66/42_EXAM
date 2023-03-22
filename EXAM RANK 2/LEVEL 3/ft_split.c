/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

-------------------------------*/

#include <stdlib.h>

int		ft_wordlen(char *str)
{
	int len = 0;
	while (str[len] && str[len] != ' ' && str[len] != '\t' && str[len] != '\n')
		++len;
	return (len);
}

char	*word_dupe(char *str)
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int i = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
		{
			array[i++] = word_dupe(str);
			str += ft_wordlen(str);
		}
		else
			++str;
	}
}

int		count_words(char *str)
{
	int count = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
		{
			++count;
			str += ft_wordlen(str);
		}
		else
			++str;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int num_words = count_words(str);
	char **array = malloc(sizeof(char *) * (num_words + 1));
	
	array[num_words] = NULL;
	fill_words(array, str);
	return (array);
}

/*-----------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int ft_wordlen(char *str);
char *word_dupe(char *str);
void fill_words(char **array, char *str);
int count_words(char *str);
char **ft_split(char *str);

int main()
{
    char *str = "This is a test string";
    char **words = ft_split(str);
    int i = 0;

    while (words[i] != NULL)
    {
        printf("Word %d: %s\n", i, words[i]);
        free(words[i]);
        i++;
    }

    free(words);
    return 0;
}


/*----------------------------------------*/
