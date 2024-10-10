# FUNCIONES VARIADICAS
## Manejo de los argumentos variádicos
 Necesitamos usar macros del archivo ```<stdarg.h>```

- **va_list**: Declara una variable que mantendrá la información sobre los argumentos adicionales.
- **va_start**: Inicializa la variable del tipo ```va_list``` con los parámetros variables.
- **va_arg**: Se utiliza para extraer cada argumento.
- **va_end**: Limpia la lista de argumentos cuando se han procesado todos.
  En el siguiente programa en la funcion: ```int sumatorio(int n, ...)``` ese 1º parámetro lo vamos a utilizar para decirle el nº de argumentos que le van a seguir, no es una regla definida pero lo usaremos de esta forma.
```c
#include <stdio.h>
#include <stdarg.h>

int sumatorio(int n, ...)
{
	va_list vargs;
	int	i;

	i = 0;
	int ac = 0;
	va_start(vargs, n); /* Inicio de la macro, inicializando la variable va_list */
	printf("inicializamos argumentos\n");
	while(i++ < n)
	{
		int	sig = va_arg(vargs, int); /* No se le puede llamar más veces de las
		que le pusimos en la función [5]): sumatorio(5, 1, 2, 3, 4, 5); */

		printf("El siguiente parámetro es un %d\n", sig); /* Extrayendo cada argumento */
		ac += sig;
	}
	va_end(vargs); /* Fin de la macro, limpiando lista de argumentos*/
	return(ac);
}
	int	main()
{
	int total = sumatorio(5, 1, 2, 3, 4, 5); /* Enviamos 5 que será el nº de argumentos
	seguido de los argumentos*/

	printf("Total: %d\n", total);
	return (0);
}
```
## va_list
-
