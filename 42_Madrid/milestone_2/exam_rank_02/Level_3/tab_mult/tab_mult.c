# include <unistd.h>

int	x_atoi(char *str)
{
	int	i = 0;
	int number = 0;

	while(str[i])
	{
		number = 10 * number + str[i] - '0';
		i++;
	}
	return(number);
}
int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return(i);
}
void put_nbr(int nb)
{
	char c;
	if (nb > 9)
		put_nbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);

}

int	main(int argc, char **argv)
{
	int	number = 0;
	int	i = 1;
	int result = 0;
	char c;
	char *str;

	if (argc == 2)
	{
		number = x_atoi(argv[1]);
		while(i < 10)
		{
			c = i + '0';
			result = i * number;
			write(1, &c, 1);
			write(1, " x ", 3);
			str = argv[1];
			write(1, str, ft_strlen(argv[1]));
			write(1, " = ", 3);
			put_nbr(result);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}
