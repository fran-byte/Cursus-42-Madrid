<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%20%20ft_printf%20%20-4682B4" style="width:150px;height:40px;"></a>

</div>

# ft_printf

- Este proyecto implementa una versión simplificada de la función `printf` de C, llamada `ft_printf`. La función utiliza variadic functions para manejar un número variable de argumentos, lo que permite realizar salidas formateadas de distintos tipos de datos según los especificadores que recibe (`%d`, `%s`, `%x`, etc.).

### Explicación de las funciones clave:

1. **`ft_printf`**: Es el punto de entrada que procesa la cadena `format` caracter por caracter. Cuando encuentra un `%`, indica que hay un especificador de formato, así que delega el procesamiento a `extract_formt`, pasando el control al especificador correspondiente.

2. **`extract_formt` y `extract_formt_two`**: Estas funciones interpretan los especificadores de formato:
   - `c` imprime un carácter.
   - `s` imprime una cadena de caracteres.
   - `d` o `i` imprimen un entero con signo.
   - `u`, `x`, y `X` imprimen números enteros sin signo en distintas bases (decimal y hexadecimal).
   - `p` imprime la dirección de memoria de un puntero en hexadecimal con el prefijo `0x`.
   - `%` imprime un símbolo `%`.

3. **`put_num`**: Esta función maneja la impresión de números en distintas bases. Dependiendo del valor de `base`, imprime el número en decimal (`0`), hexadecimal en minúsculas (`1`), o en mayúsculas (`2`).

4. **`put_pointer`**: Imprime punteros en formato hexadecimal, gestionando el caso especial en que el puntero es `NULL` y debe mostrarse como `(nil)`.

### Resumen del flujo de trabajo
`ft_printf` recorre la cadena de formato e identifica los especificadores. Cuando encuentra uno, llama a las funciones de extracción (`extract_formt` o `extract_formt_two`), las cuales gestionan la conversión e impresión según el tipo de dato. Para los valores numéricos y punteros, se apoyan en `put_num` y `put_pointer` para asegurar el formato correcto.

### Retorno
`ft_printf` devuelve el total de caracteres escritos, lo que replica la funcionalidad de la `printf` estándar. Esta implementación es útil para aprender cómo funciona `printf` internamente, manejando casos básicos de los tipos más comunes de salida.
