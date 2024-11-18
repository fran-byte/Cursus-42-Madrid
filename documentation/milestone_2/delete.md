#include <stdlib.h>
#include "libft.h"

int ft_str_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}
int read_inputs(int argc, char **argv)
{
	int i;
	int j;
	// char *ptr;

	i = 0;
	while (++i <= argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
	}

	// ptr = (char *)(malloc (i * sizeof(char)));
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		read_inputs(argc, argv);
	}
}
