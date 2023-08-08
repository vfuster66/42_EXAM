/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:19:22 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/12 08:31:16 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Écrire une fonction qui inverse (en place) une chaîne de caractères.

Elle devra renvoyer son paramètre.

Votre fonction devra être prototypée de la façon suivante :

char    *ft_strrev(char *str);

----------------------------------------*/

#include <stdlib.h>

char    *ft_strrev(char *str)
{
	// Pointeur pour marquer le debut de la chaine de caracteres
	char	*start;
	// Pointeur pour marquer la fin de la chaine de caracteres
	char	*end;
	// Variable temporaire
	char	temp;

	// Verifier s'il y a une chaine de caracteres
	if (!str)
		return (NULL);
	// Initialiser start et end pour qu'ils pointent vers le debut de la chaine
	start = str;
	end = str;

	// Boucle pour deplacer le pointeur end jusqu'a la fin de la chaine de caracteres
	while (*end)
		end++;
	end--;
	// Boucle tant que start n'a pas atteint end
	while (start < end)
	{
		// Echange des caracteres start et end
		temp = *start;
		*start = *end;
		*end = temp;
		// Les index se rapprochent jusqu'a se croiser
		start++;
		end--;
	}
	return (str);	
}

#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *str);

int	main()
{
	char str[] = "Hello World";
	printf("Original string: %s\n", str);
	ft_strrev(str);
	printf("Reversed string: %s\n", str);
	return (0);
}
