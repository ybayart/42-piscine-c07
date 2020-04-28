/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:58:41 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/07 23:06:38 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_base_error(char *base);

void	ft_putnbr_getout(char *retour, char c, int *i)
{
	retour[*i] = c;
	*i += 1;
}

void	ft_putnbr_base(int nbr, char *base, char *retour, int *i)
{
	long	nb;
	long	len;

	len = ft_base_error(base);
	if (len >= 2)
	{
		if (nbr < 0)
		{
			ft_putnbr_getout(retour, '-', i);
			nb = nbr;
			nb *= -1;
		}
		else
			nb = nbr;
		if (nb > len)
		{
			ft_putnbr_base(nb / len, base, retour, i);
			ft_putnbr_base(nb % len, base, retour, i);
		}
		else
		{
			ft_putnbr_getout(retour, base[nb], i);
		}
	}
}
