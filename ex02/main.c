#include <stdio.h>

int     ft_ultimate_range(int **range, int min, int max);

int		main(void)
{
	int i;
	int *tab;
	int min;
	int max;
	int size;

	min = 0;
	max = 5;
	size = ft_ultimate_range(&tab, min, max);
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
