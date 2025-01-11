char    *ft_strrev(char *str)
{
	int	i = 0;
	int	lenght = 0;
	char	tmp;

	while(str[lenght])
		lenght++;
	lenght = lenght -1;
	while(lenght >= i)
	{
		tmp = str[lenght];
		str[lenght] = str[i];
		str[i] = tmp;
		i++;
		lenght--;
	}
	return (str);
}
