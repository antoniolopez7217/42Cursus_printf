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

void	ft_pconvert(unsigned long int nbr, int *len)
{
	if (nbr == 0)
		*len = *len + ft_putstr("(nil)");
	else
	{
		*len = *len + ft_putchar('0') + ft_putchar('x');
		ft_putnbr_base(nbr, HEX_L, len);
	}
}

void	ft_putnbr_base(unsigned long int nbr, char *base, int *len)
{
	if (nbr >= 16)
	{	
		ft_putnbr_base(nbr / 16, base, len);
		ft_putnbr_base(nbr % 16, base, len);
	}
	if (nbr < 16)
		*len = *len + ft_putchar(base[nbr]);
}
