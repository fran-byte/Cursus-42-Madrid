#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h" // Asegúrate de que esta línea incluya el encabezado adecuado

int main(void)
{
	int fd;
	int fd2;
	int fd3;
	char *line;

	fd = open("file1", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("file1 Línea: %s", line);
		free(line);
	}
	close(fd);
	close(fd2);
	close(fd3);



	return (0);
}
