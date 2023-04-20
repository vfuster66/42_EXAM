/*Assignment name  : flood_fill
Expected files   : flood_fill.c
Allowed functions: -
-----------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this: (put it in flood_fill.c)

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test.c

#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$> 

------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

// Définition de la structure de données pour un point
typedef struct s_point
{
    int x;
    int y;
} t_point;

// Fonction récursive qui remplit une zone de caractères identiques à partir d'un point donné
void fill_area(char **tab, t_point size, t_point begin, char c)
{
    // On vérifie si le point est en dehors des limites du tableau
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return;
    
    // On vérifie si le caractère du point actuel est différent de celui qu'on cherche à remplacer
    if (tab[begin.y][begin.x] != c)
        return;
    
    // On marque le point actuel comme étant rempli
    tab[begin.y][begin.x] = 'F';
    
    // On remplit les zones voisines récursivement
    fill_area(tab, size, (t_point){begin.x + 1, begin.y}, c);
    fill_area(tab, size, (t_point){begin.x - 1, begin.y}, c);
    fill_area(tab, size, (t_point){begin.x, begin.y + 1}, c);
    fill_area(tab, size, (t_point){begin.x, begin.y - 1}, c);
}

// Fonction principale qui appelle fill_area pour remplir la zone correspondante
void flood_fill(char **tab, t_point size, t_point begin)
{
    // On récupère le caractère à remplacer
    char c = tab[begin.y][begin.x];
    
    // On appelle fill_area pour remplir la zone correspondante
    fill_area(tab, size, begin, c);
}
