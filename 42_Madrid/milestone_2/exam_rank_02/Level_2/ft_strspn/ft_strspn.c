#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i = 0;
	int j = 0;
	int	count = 0;

	while(s[i])
	{
		while(accept[j])
		{
			if(s[i] == accept[j])
			{
				count++;
				j = 0;
				break;
			}
			j++;
		}
		i++;
	}
	return (count);
}
