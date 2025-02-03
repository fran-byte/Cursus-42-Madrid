<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%20%20get_next_line%20%20-4682B4" style="width:150px;height:40px;"></a>

</div>

# get_next_line

Esta función lee línea por línea desde un `fd` (file descriptor). Utiliza un buffer estático (`stored`) para guardar el texto restante entre llamadas, lo que permite manejar líneas parciales en varias lecturas. La función `my_line` extrae una línea completa, y `re_adj_storage` ajusta el buffer para la próxima llamada.

---

## Consideraciones Importantes

1. **Manejo de Memoria**: Cada función libera las variables dinámicas cuando ya no se usan, minimizando pérdidas de memoria.
2. **Gestión de Errores**: Verifica la accesibilidad del archivo y el tamaño del `BUFFER_SIZE`, y retorna `NULL` si algo falla.
3. **Almacenamiento Estático**: `stored` es una variable estática que persiste entre llamadas a `get_next_line`, permitiendo que la lectura de líneas sea continua.

---

## Funciones Principales

A continuación, se describe el propósito de cada función clave en el proyecto:

<p align="center" width="100%"><a href="#"><img src="../../img/milestone_3/get_nect_line.png" width="900" /></a></p>

| **Función**              | **Descripción**                                                                                     |
|--------------------------|-----------------------------------------------------------------------------------------------------|
| **`get_next_line(int fd)`** | Función principal que controla el flujo de lectura. Verifica el archivo y llama a otras funciones. |
| **`read_join(char *stored, int fd)`** | Lee datos del archivo y los almacena en `stored`.                                                |
| **`initialize_stored(char *stored, char *read_bff)`** | Inicializa `stored` si es `NULL`, evitando errores en operaciones de concatenación.             |
| **`my_line(char *stored)`** | Extrae una línea completa de `stored` y la devuelve.                                             |
| **`re_adj_storage(char *stored)`** | Ajusta `stored` eliminando la línea ya leída, preparándolo para la siguiente llamada.           |

---

## Bonus: Lectura de Múltiples `fd`

- **Implementación**: Se permite leer de varios `fd` simultáneamente sin perder las líneas correspondientes a cada uno.
- **Modificación Principal**:
  - Se convierte `stored` en un array estático: `static char *stored[65536]`.
  - Cada `fd` tiene su propio espacio en el array, lo que permite manejar múltiples archivos de manera independiente.

### Código Modificado

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
