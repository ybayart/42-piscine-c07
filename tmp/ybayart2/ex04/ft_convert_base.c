/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:55:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/07 23:06:36 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base, char *retour, int *i);

int		ft_base_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '\f' || base[i] == '\n' ||
				base[i] == '\r' || base[i] == '\t' || base[i] == '\v' ||
				base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

int		ft_atoi_base_test(char str, char *base)
{
	int retour;
	int i;

	retour = 0;
	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		nb;
	int		tmp;
	int		len;

	nb = 0;
	i = 0;
	len = ft_base_error(base);
	if (len >= 2)
	{
		tmp = ft_atoi_base_test(str[i], base);
		while (tmp != -1)
		{
			nb = (nb * len) + tmp;
			i++;
			tmp = ft_atoi_base_test(str[i], base);
		}
		return (nb);
	}
	return (0);
}

int		ft_convert_base_sizeof(int nb, char *base)
{
	int sbase;
	int stab;

	sbase = 0;
	while (base[sbase])
		sbase++;
	stab = 1;
	while (nb >= sbase)
	{
		nb /= sbase;
		stab++;
	}
	return (stab);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	int		msize;
	int		i;
	char	*retour;

	decimal = ft_atoi_base(nbr, base_from);
	if (decimal != 0)
	{
		msize = ft_convert_base_sizeof(decimal, base_to);
		retour = malloc(sizeof(char) * msize + 1);
		i = 0;
		ft_putnbr_base(decimal, base_to, retour, &i);
		return (retour);
	}
	else
		return (NULL);
}
