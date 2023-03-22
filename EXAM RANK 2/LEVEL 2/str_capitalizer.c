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

int is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void rstr_capitalizer(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (is_letter(str[i]))
        {
            if (i == 0 || !is_letter(str[i - 1]))
                str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
            else
                str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
        }
        i++;
    }
    write(1, str, i);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }

    for (int i = 1; i < argc; i++)
    {
        rstr_capitalizer(argv[i]);
    }

    return (0);
}

