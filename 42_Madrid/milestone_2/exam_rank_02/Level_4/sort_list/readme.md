```
**Nombre de la asignación:** sort_list
**Archivos esperados:** sort_list.c
**Funciones permitidas:** ninguna

---

Escribe la siguiente función:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

Esta función debe ordenar la lista pasada como parámetro, utilizando la función puntero `cmp` para seleccionar el orden a aplicar, y devolver un puntero al primer elemento de la lista ordenada.

Los duplicados deben permanecer.

Las entradas siempre serán consistentes.

Debes usar el tipo `t_list` descrito en el archivo `list.h` que se te proporciona. Debes incluir ese archivo (`#include "list.h"`), pero no debes entregarlo. Nosotros utilizaremos el nuestro para compilar tu asignación.

Las funciones pasadas como `cmp` siempre devolverán un valor diferente de 0 si `a` y `b` están en el orden correcto, y 0 en caso contrario.

Por ejemplo, la siguiente función usada como `cmp` ordenará la lista en orden ascendente:


int ascending(int a, int b)
{
	return (a <= b);
}
```
