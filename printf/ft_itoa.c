/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antlopez <antlopez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:31:35 by antlopez          #+#    #+#             */
/*   Updated: 2022/12/15 18:49:38 by antlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(long int num)
{
	int			intlen;

	if (num == 0)
		return (1);
	intlen = 1;
	if (num < 0)
	{
		num = -num;
		intlen++;
	}
	while (num >= 10)
	{
		num = num / 10;
		intlen++;
	}
	return (intlen);
}

void	ft_itoa(long int n, int *len)
{
	char		*str;
	int			intlen;

	intlen = ft_intlen(n) - 1;
	str = (char *)malloc(intlen + 2);
	if (str == NULL)
		return;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[intlen + 1] = '\0';
	while (n >= 10)
	{
		str[intlen] = (n % 10) + '0';
		n = n / 10;
		intlen--;
	}
	str[intlen] = n + '0';
	intlen = ft_putstr(str);
	free(str);
	*len = *len + intlen;
}
