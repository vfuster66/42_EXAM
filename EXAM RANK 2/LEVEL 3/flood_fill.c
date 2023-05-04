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

// Définition de la structure de données pour un point
typedef struct s_point
{
    int x;
    int y;
} t_point;

// Fonction récursive qui remplit une zone de caractères identiques à partir d'un point donné
// Cette fonction récursive est appelée pour remplir toutes les cases d'une
// région connexe à partir de la case de départ (cur) et en remplaçant tous
// les caractères to_fill par 'F'. La fonction arrête de se propager dans une
// direction si elle rencontre les bords de la grille (taille size) ou si la case
// courante n'a pas la valeur to_fill.

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		// Arrête si on est hors des limites ou si la case n'a pas la valeur to_fill
		return ;
	// Remplace la case courante par 'F'
	tab[cur.y][cur.x] = 'F'; 
	// Appelle récursivement fill() pour toutes les cases adjacentes
	// Case à gauche
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	// Case à droite
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	// Case en haut
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	// Case en bas
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill); 
}

// Cette fonction est appelée pour remplir toute la région connexe à partir de la
// case de départ (begin) en appelant la fonction fill(). Elle utilise la valeur
// de la case de départ (tab[begin.y][begin.x]) comme valeur to_fill pour fill().

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

