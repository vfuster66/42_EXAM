/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
---------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c :

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

------------------------------*/

// Définition d'une structure de liste chaînée
typedef struct    s_list
{
	// Pointeur vers le prochain élément de la liste
	struct s_list *next;
	// Pointeur générique vers les données stockées dans l'élément de la liste
	void          *data;
}                t_list;

// Fonction récursive qui calcule la taille d'une liste chaînée
int	ft_list_size(t_list *begin_list)
{
	// Si la liste est vide, la taille est de 0
	if (begin_list == 0)  
		return (0);
	// Sinon, on ajoute 1 à la taille de la sous-liste à partir de l'élément suivant
	else  
		return (1 + ft_list_size(begin_list->next));
}

/*------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_list *head = malloc(sizeof(t_list));
	t_list *second = malloc(sizeof(t_list));
	t_list *third = malloc(sizeof(t_list));
	
	head->data = "Premier élément";
	head->next = second;
	
	second->data = "Deuxième élément";
	second->next = third;
	
	third->data = "Troisième élément";
	third->next = NULL;

	int size = ft_list_size(head);
	printf("La liste chaînée a une taille de %d élément(s)\n", size);
	free(head);
	free(second);
	free(third);
	
	return 0;
}

------------------------------------*/

