# include <stdio.h>
# include <stdlib.h>

void ft_gcd(int a, int b)
{
	int n = 0;
	int gcd = 1;

	if (a > b)
		n = a;
	else
		n = b;
	while(1)
	{
		if(n % b == 0 && n % a == 0)
		{
			printf("%d", n);
			break;
		}
		n++;
	}
}


int	main(int argc, char **argv)
{
	if(argc == 3)
		ft_gcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return(0);
}
