#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*array;
	int dist = 0;
	int i = 0;

	dist = abs(end - start) + 1;
	array = (int *)malloc((sizeof (int) * dist));
	if(!array)
		return(NULL);
	if(start < end)
		{
			while(start <= end)
			{
				array[i] = start;
				i++;
				start++;
			}
		}
	else
			{
			while(start >= end)
			{
				array[i] = start;
				i++;
				start--;
			}
		}
	return(array);
}
