int	ft_atoi_base(const char *str, int str_base)
{
	int	s = 1;
	int	i = 0;
	int	result = 0;
	char c;

	if(str[i] == '-')
		s = -1;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		else if(str[i] >= 'a' && str[i] <= 'f')
			c = str[i] - 'a' + 10;
		else if(str[i] >= 'A' && str[i] <= 'F')
			c = str[i] - 'A'+ 10;
		else
			break;
		result = result * str_base + c;
		i++;
	}
	return (result * s);

}
