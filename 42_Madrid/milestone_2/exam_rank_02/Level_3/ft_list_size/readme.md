```
Nombre de la asignación  : ft_list_size
Archivos esperados   : ft_list_size.c, ft_list.h
Funciones permitidas: Ninguna
--------------------------------------------------------------------------------

Escribe una función que retorne el número de elementos en la lista enlazada que se le pase como argumento.

Debe ser declarada como sigue:

int	ft_list_size(t_list *begin_list);

Debes utilizar la siguiente estructura, y entregarla como un archivo llamado ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
```
