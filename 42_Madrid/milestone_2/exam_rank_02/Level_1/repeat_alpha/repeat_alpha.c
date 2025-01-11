# include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int rep;

	if (argc == 2)
	{
		while(argv[1][i])
		{
			rep = 1;
			if (argv[1][i] >='a' && argv[1][i] <='z')
				rep = argv[1][i] - 'a' + 1;
			if (argv[1][i] >='A' && argv[1][i] <='Z')
				rep = argv[1][i] - 'A' + 1;
			while(rep--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
