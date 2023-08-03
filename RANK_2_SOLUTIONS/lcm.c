/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 08:42:46 by vfuster-          #+#    #+#             */
/*   Updated: 2023/07/13 08:46:31 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
-------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>

-------------------------------*/

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b);

int main(void)
{
	unsigned int a, b;
	unsigned int result;

	// Test case 1
	a = 12;
	b = 18;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	// Test case 2
	a = 7;
	b = 13;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	// Test case 3
	a = 0;
	b = 5;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	// Test case 4
	a = 16;
	b = 0;
	result = lcm(a, b);
	printf("LCM of %u and %u is %u\n", a, b, result);

	return (0);
}
