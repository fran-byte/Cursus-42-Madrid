<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%20%20get_next_line%20%20-4682B4" style="width:150px;height:40px;"></a>

</div>



# get_next_line

- Esta función lee línea por línea desde un `fd` file descriptor. Guarda el texto restante en un buffer estático entre llamadas, manejando líneas parciales en varias lecturas. La función `my_line` extrae una línea completa, y `re_adj_storage` ajusta el buffer para la próxima llamada.

### Consideraciones Importantes:

1. **Manejo de Memoria**: Cada función libera las variables dinámicas cuando ya no se usan, minimizando pérdidas de memoria.
2. **Gestión de Errores**: Verifica la accesibilidad del archivo y el tamaño del `BUFFER_SIZE`, y retorna `NULL` si algo falla.
3. **Almacenamiento Estático**: `stored` es una variable estática que persiste entre llamadas a `get_next_line`, permitiendo que la lectura de líneas sea continua.


### 1. **`get_next_line(int fd)`**

Esta es la función principal que:
- Controla si el archivo es accesible (`fd < 0`), si el tamaño del `BUFFER_SIZE` es válido.
- Llama a `read_join`, que lee los datos del archivo y los almacena en `stored`.
- Si `stored` contiene texto, extrae una línea completa a través de `my_line`.
- Después de extraer la línea, llama a `re_adj_storage` para ajustar `stored` y prepararlo para la siguiente línea.

  Finalmente, devuelve la línea leída o `NULL` si el archivo ha terminado o hay un error.

### 2. **`read_join(char *stored, int fd)`**

Esta función:
- Lee del archivo en bloques de tamaño `BUFFER_SIZE` y almacena temporalmente los datos en `read_bff`.
- Usa `initialize_stored` para asegurarse de que `stored` no esté vacío.
- Lee de manera repetitiva hasta que se encuentre un salto de línea o se llegue al final del archivo.
- Si se encuentra un salto de línea, detiene la lectura y actualiza `stored` concatenando los datos leídos mediante `special_strjoin_`.

### 3. **`initialize_stored(char *stored, char *read_bff)`**

- Esta pequeña función se asegura de que `stored` esté correctamente inicializado a una cadena vacía si es `NULL`, evitando errores al realizar operaciones de concatenación.

### 4. **`my_line(char *stored)`**

- Extrae una línea completa de `stored`.
- Calcula la longitud de la línea hasta encontrar un salto de línea o el final de la cadena.
- Almacena la línea en `line`, asegurando que termine con `'\0'`.

  Esto ayuda a separar cada línea para retornarla individualmente desde `get_next_line`.

### 5. **`re_adj_storage(char *stored)`**

- Esta función ajusta `stored` eliminando la línea ya leída, de modo que solo se conserven los datos no procesados.
- Si `stored` solo contiene una línea sin caracteres adicionales, libera `stored` y devuelve `NULL`.

  Esto garantiza que en la siguiente llamada a `get_next_line` se empiece directamente desde el punto donde se quedó.

# Bonus

- Simplemente implementamos la posibilidad de leer de varios `fd` a la vez sin perder las líneas a las que pertenece cada uno.
- Para ello solo hacemos una modificación substancial en el ´get_next_line.c´ para convertirlo en el `get_next_line_bonus.c`.

## Modificando **`get_next_line(int fd)`**

- Introducimos una dimensión mas a nuestra variable `static *stored[65536]` y en todas las líneas de esta función trabajaremos solo la dimensión que sea enviada por el `fd` que nos llegue a la función principal, quedando de la siguinte manera:

```c

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stored[65536];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored[fd] = read_join(stored[fd], fd);
	if (!stored[fd])
		return (free(stored[fd]), NULL);
	line = my_line(stored[fd]);
	stored[fd] = re_adj_storage(stored[fd]);
	return (line);
}

```
