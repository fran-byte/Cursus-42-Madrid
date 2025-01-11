#include <unistd.h>

char *rev_print(char *str)
{

	int	lenght = 0;

	while(str[lenght])
		lenght++;

	while(--lenght >= 0)
	{
		write(1, &str[lenght], 1);
	}
	write(1, "\n", 1);
	return (str);
}
