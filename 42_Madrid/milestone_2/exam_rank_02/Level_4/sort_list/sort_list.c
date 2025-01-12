#include <stdlib.h>


typedef struct s_list t_list;

struct s_list
{
	int		data;
	t_list	*next;
};



t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	int swap;
	t_list *start;

	start = lst;

	while (lst != NULL && lst->next != NULL) //Mientras tengamos "nodo" y el "nodo siguiente" para comparar
	{
		if ((*cmp)(lst->data, lst->next->data) == 0) // Si no están en orden
		{  // Intercambiamos los valores
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;  // reiniciamos la lista para empezar de nuevo
		}
		else
			lst = lst->next;
	}
	return (start); // devolvemos el puntero al primer nodo de la lista.
}
