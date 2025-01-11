#include <stdlib.h>
# include<stdio.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char	*new;

	while(src[i] != '\0')
		i++;
	new = malloc((sizeof new) * i + 1);
	if(!new)
		return(NULL);
	i = 0;
	while(src[i] != '\0')
	{
		new[i] = src [i];
		i++;
	}
	new[i] = '\0';
	return(new);
}
