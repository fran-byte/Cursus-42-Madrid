<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%20%20ft_printf%20%20-4682B4" style="width:125px;height:40px;"></a>

</div>



# ft_printf

Este proyecto implementa una versión simplificada de la función `printf`. La función utiliza **variadic functions** para manejar un número variable de argumentos, lo que permite realizar salidas formateadas de distintos tipos de datos según los especificadores que recibe (`%d`, `%s`, `%x`, etc.).

---

## Funciones clave

A continuación, se describen las funciones principales del proyecto:

| **Función**           | **Descripción**                                                                                                                                 |
|------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| **`ft_printf`**        | Punto de entrada que procesa la cadena `format` caracter por caracter. Cuando encuentra un `%`, delega el procesamiento a `extract_formt`.      |
| **`extract_formt`**    | Interpreta los especificadores de formato (`c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`, `%`) y gestiona la impresión de caracteres, cadenas y enteros. |
| **`extract_formt_two`**| Complementa a `extract_formt` para manejar especificadores adicionales o casos especiales.                                                      |
| **`put_num`**          | Maneja la impresión de números en distintas bases (decimal, hexadecimal en minúsculas o mayúsculas).                                            |
| **`put_pointer`**      | Imprime punteros en formato hexadecimal, gestionando el caso especial en que el puntero es `NULL` y debe mostrarse como `(nil)`.                |

---

## Especificadores de formato

La siguiente tabla resume los especificadores de formato soportados por `ft_printf`:

| **Especificador** | **Tipo de dato**                     | **Descripción**                                                                 |
|-------------------|--------------------------------------|---------------------------------------------------------------------------------|
| `%c`              | Carácter                             | Imprime un carácter.                                                            |
| `%s`              | Cadena de caracteres                 | Imprime una cadena de caracteres.                                               |
| `%d` o `%i`       | Entero con signo                     | Imprime un número entero con signo.                                             |
| `%u`              | Entero sin signo                     | Imprime un número entero sin signo en base decimal.                             |
| `%x`              | Entero sin signo (hexadecimal)       | Imprime un número entero sin signo en hexadecimal (minúsculas).                 |
| `%X`              | Entero sin signo (hexadecimal)       | Imprime un número entero sin signo en hexadecimal (mayúsculas).                 |
| `%p`              | Puntero                              | Imprime la dirección de memoria de un puntero en hexadecimal con el prefijo `0x`.|
| `%%`              | Carácter `%`                         | Imprime un símbolo `%`.                                                         |

---

## Flujo de trabajo

El flujo de trabajo de `ft_printf` se puede resumir en los siguientes pasos:

1. **Procesamiento de la cadena de formato**: `ft_printf` recorre la cadena de formato caracter por caracter.
2. **Identificación de especificadores**: Cuando encuentra un `%`, llama a las funciones de extracción (`extract_formt` o `extract_formt_two`).
3. **Conversión e impresión**: Las funciones de extracción gestionan la conversión e impresión según el tipo de dato.
4. **Manejo de números y punteros**: Para valores numéricos y punteros, se utilizan `put_num` y `put_pointer` para asegurar el formato correcto.

---

## Retorno

`ft_printf` devuelve el total de caracteres escritos, replicando la funcionalidad de la `printf` estándar. Esta implementación es útil para aprender cómo funciona `printf` internamente, manejando casos básicos de los tipos más comunes de salida.

---
