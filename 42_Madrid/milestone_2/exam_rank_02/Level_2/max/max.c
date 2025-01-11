int		max(int* tab, unsigned int len)
{
	int number;
	int	i = 0;

	number = tab[0];
	while(len)
	{
		if(number < tab[i])
			number = tab[i];
		len--;
		i++;
	}
	return (number);
}
