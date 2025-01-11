# include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int c;

	if (argc == 2)
	{
		while(argv[1][i] != '\0')
		{
			c = 0;
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
				c = -32;
			if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				c = 32;
			c = argv[1][i] + c;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
