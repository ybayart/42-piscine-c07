#include <stdio.h>

int     *ft_range(int min, int max);

int		main(void)
{
	int i;
	int *tab;
	int min;
	int max;

	min = 0;
	max = 5;
	tab = ft_range(min, max);
	if (tab != NULL)
	{
		i = -1;
		while (++i < max - min)
		{
			printf("%d\n", tab[i]);
		}
	}
	else
		printf("tozz");
}
