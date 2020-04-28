/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:36:47 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/08 18:41:42 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_split_count(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		end;

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] == charset[0])
		{
			j = -1;
			end = 0;
			while (charset[++j] && end == 0)
				if (str[i + j] != charset[j] || str[i + j + 1] == '\0')
					end = 1;
			if (end == 0)
				k++;
		}
	return (k);
}

int		*ft_split_get(char *str, char *charset, int size)
{
	int		*tab;
	int		i[4];

	i[0] = 0;
	i[2] = 0;
	tab = malloc(sizeof(int) * size);
	i[3] = i[0];
	while (*str)
	{
		if (*str == *charset)
		{
			i[1] = -1;
			while (charset[++i[1]] != '\0')
				if (charset[i[1]] != str[i[1]])
					break ;
			tab[i[2]] = i[0] - i[3];
			i[3] = i[0] + i[1];
			i[2]++;
		}
		i[0]++;
		str++;
	}
	tab[i[2]] = i[0] - i[3];
	return (tab);
}

char	*ft_split_create(char *str, int start, int len)
{
	int		i;
	char	*chain;

	i = 0;
	chain = malloc(sizeof(char) * (len + 1));
	if (chain == NULL)
		return (0);
	while (i < len)
	{
		chain[i] = str[start + i];
		i++;
	}
	chain[i] = '\0';
	return (chain);
}

char	**ft_split(char *str, char *charset)
{
	int		i[4];
	int		*tab;
	char	**c;

	i[3] = ft_split_count(str, charset);
	tab = ft_split_get(str, charset, i[3]);
	i[0] = 0;
	i[1] = -1;
	if ((c = malloc(sizeof(char*) * (i[3] + 2))) == 0)
		return (0);
	i[2] = 0;
	while (++i[1] <= i[3])
	{
		if (tab[i[1]] != 0)
		{
			if ((c[i[0]] = ft_split_create(str, i[2], tab[i[1]])) == 0)
				return (0);
			i[2] += tab[i[1]] + 2;
			i[0]++;
		}
		else
			i[2] += tab[i[1]] + 2;
	}
	c[i[0]] = 0;
	return (c);
}
