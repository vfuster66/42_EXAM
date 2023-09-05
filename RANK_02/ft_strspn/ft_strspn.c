#include <stdlib.h>

size_t  ft_strspn(const char *s, const char *accept)
{
    size_t  i = 0;
    size_t  j;

    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
                break ;
            j++;
        }
        if (accept[j] == '\0')
            return (i);
        i++;
    }
    return (i);
}
