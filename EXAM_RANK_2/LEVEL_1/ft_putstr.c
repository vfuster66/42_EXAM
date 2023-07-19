/*Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
-------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);

-------------------------------*/

#include <unistd.h>

void    ft_putstr(char *str)
{
    // On continue de boucler tant que l'on ne rencontre pas le caractère null ('\0')
    while (*str)
        // On écrit le caractère pointé par le pointeur 'str' sur la sortie standard 
        //puis on incrémente le pointeur pour passer au caractère suivant
        write(1, str++, 1); 
}


/*-------------------------------

#include <unistd.h>

void ft_putstr(char *str);

int main()
{
    char str[] = "Hello, World!";
    ft_putstr(str);
    return 0;
}

----------------------------*/
