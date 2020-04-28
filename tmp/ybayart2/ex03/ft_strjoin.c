/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:48:26 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/09 00:21:26 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin_chain(int *nb, char **strs, char *sep, char *chain)
{
	while (nb[1] < nb[0])
	{
		nb[2] = 0;
		while (strs[nb[1]][nb[2]] != '\0')
		{
			chain[nb[3]] = strs[nb[1]][nb[2]];
			nb[3]++;
			nb[2]++;
		}
		nb[2] = 0;
		if (nb[1] < nb[0] - 1)
		{
			while (sep[nb[2]] != '\0')
			{
				chain[nb[3]] = sep[nb[2]];
				nb[2]++;
				nb[3]++;
			}
		}
		nb[1]++;
	}
	chain[nb[3]] = '\0';
	return (chain);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		nb[4];
	int		sizetot;
	char	*chain;

	if (size == 0)
		return (malloc(sizeof("")));
	sizetot = 1;
	i = 0;
	while (i < size)
	{
		sizetot += sizeof(strs[i]);
		i++;
	}
	sizetot += sizeof(sep) * (size - 1);
	chain = malloc(sizetot);
	if (chain == NULL)
		return (NULL);
	nb[0] = size;
	nb[1] = 0;
	nb[3] = 0;
	chain = ft_strjoin_chain(nb, strs, sep, chain);
	return (chain);
}
