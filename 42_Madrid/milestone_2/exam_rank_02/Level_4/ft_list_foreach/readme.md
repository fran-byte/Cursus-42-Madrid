
**Nombre de la asignación:** ft_list_foreach
**Archivos esperados:** ft_list_foreach.c, ft_list.h
**Funciones permitidas:** ninguna

---

Escribe una función que tome una lista y un puntero a una función, y aplique esta función a cada elemento de la lista.

Debe declararse de la siguiente manera:

```c
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
```

La función apuntada por `f` se utilizará de la siguiente manera:

```c
(*f)(list_ptr->data);
```

Debes usar la siguiente estructura y entregarla en un archivo llamado `ft_list.h`:

```c
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
```
