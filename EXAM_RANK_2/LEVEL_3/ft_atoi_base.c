/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
---------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

--------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base)
{
    // variable pour stocker la valeur convertie
    int result;
    // variable pour stocker le signe de la valeur convertie
    int sign;
    // variable pour parcourir la chaîne de caractères str
    int i;

    result = 0;
    sign = 1;
    i = 0;
    // vérification de la validité de la base
    if (str_base < 2 || str_base > 16) 
        return 0;
    // vérification du signe de la valeur à convertir
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    // parcours de la chaîne de caractères
    while (str[i] != '\0') 
    {
        // si le caractère est un chiffre
        if (str[i] >= '0' && str[i] <= '9')
            // conversion en base 10
            result = result * str_base + (str[i] - '0');
        // si le caractère est une lettre minuscule
        else if (str[i] >= 'a' && str[i] <= 'f')
            // conversion en base 10
            result = result * str_base + (str[i] - 'a' + 10);
        // si le caractère est une lettre majuscule
        else if (str[i] >= 'A' && str[i] <= 'F')
            // conversion en base 10
            result = result * str_base + (str[i] - 'A' + 10);
        else
            // si le caractère n'est pas valide, on arrête la conversion
            break;
        // passage au caractère suivant
        i++;
    }
    // retour de la valeur convertie avec son signe
    return sign * result;
}

/*-------------------------------------

#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base);

int main()
{
    printf("%d\n", ft_atoi_base("1010", 2)); // attendu : 10
    printf("%d\n", ft_atoi_base("a", 16)); // attendu : 10
    printf("%d\n", ft_atoi_base("-1010", 2)); // attendu : -10
    printf("%d\n", ft_atoi_base("z123", 16)); // attendu : 0
    printf("%d\n", ft_atoi_base("1010", 1)); // attendu : 0
    return 0;
}

------------------------------------*/
