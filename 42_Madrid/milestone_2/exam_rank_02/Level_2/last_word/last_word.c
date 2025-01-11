# include <unistd.h>

int	main(int argc, char **argv)
{
	int start = 0;
	int end = 0;
	int	lenght = 0;

	if (argc == 2)
	{

		{
			while(argv[1][lenght] != '\0')
				lenght++;
			lenght = lenght -1;
			while (argv[1][lenght] == ' ')
				lenght--;
			end = lenght;
			while (argv[1][lenght] >=  33 && argv[1][lenght] <= 126)
				lenght--;
			start = lenght+1;
			while(start <= end)
			{
				write(1, &argv[1][start], 1);
				start++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
