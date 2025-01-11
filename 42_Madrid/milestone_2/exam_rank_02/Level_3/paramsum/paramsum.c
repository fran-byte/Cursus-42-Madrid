# include <unistd.h>

void ft_putnbr(int number)
{
	char	c;
	if(number >= 10)
		ft_putnbr(number / 10);
	c = number % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;

	if(argc >= 2)
		ft_putnbr(argc - 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return(0);
}
