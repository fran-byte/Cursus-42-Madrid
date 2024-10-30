	if (!stored_bff) // Si el buffer acumulado está vacio entramos y llamamos a read_buffer
	{
		stored_bff = read_buffer(stored_bff, fd);
		while(stored_bff[i]) //Buscamos si hay \n y si la hay vamos a extraer la linea
		{
			if(stored_bff[i] == '\n') // Si hay final de línea, vamos a extraerlo
			{
				line = find_and_return_line(stored_bff, '\n', &ptr_n);
				stored_bff = swap_delete(stored_bff ,ptr_n);
				ptr_n = 0;
				return (line);
			}
			i++;
		}
	}


while(stored_bff[i]) //Buscamos si hay \n y si la hay vamos a extraer la

char	*ft_strchr(const char *s, int c)

