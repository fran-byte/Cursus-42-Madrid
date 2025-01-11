unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char result;
	while(i >= 0)
	{
		result = (result * 2 +(octet % 2));
		octet = octet / 2;
		i--;
	}
	return(result);
}
