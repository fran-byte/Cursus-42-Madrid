# include <unistd.h>

int	main(int argc, char **argv)
{
	int flag = 0;
	int i = 0;

	if(argc == 2)
	{
		while(argv[1][i] == ' '|| argv[1][i] == '\t')
				i++;
		while(argv[1][i])
		{
			if(argv[1][i] == ' ' || argv[1][i] == '\t')
				flag = 1;
			if(argv[1][i] != ' ' || argv[1][i] != '\t')
			{
				if(flag == 1)
					write(1, " ", 1);
				write(1, &argv[1][i], 1);
				flag = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
