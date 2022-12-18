/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antlopez <antlopez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:44:09 by antlopez          #+#    #+#             */
/*   Updated: 2022/12/15 21:46:11 by antlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long int nbr, char *base, int *len)
{
	int	size;

	if (nbr < 0)
	{
		*len = *len + ft_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr >= 16)
	{	
		ft_putnbr_base(nbr / 16, base, len);
		ft_putnbr_base(nbr % 16, base, len);
	}
	if (nbr < 16)
		*len = *len + ft_putchar(base[nbr]);
	size = *len;
	return (size);
}
