# include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int j = 0;

	char rep[256] = {0};

	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			j = 0;
			while(argv[2][j] != '\0')
			{
				if(argv[1][i] == argv[2][j] && rep[(int)argv[1][i]] == 0)
				{
					write(1, &argv[1][i], 1);
					rep[(int)argv[1][i]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
