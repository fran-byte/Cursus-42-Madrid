# include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int *array;
	int	i = 0;
	int dist = 0;

	dist = abs(end - start) + 1;
	array = malloc((sizeof array) * dist);
	if(!array)
		return (NULL);
	if (end > start)
	{
		while(start <= end)
		{
			array[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while(start >= end)
		{
			array[i] = end;
			end++;
			i++;
		}
	}
	return (array);
}
