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
	int			len;

	if (num == 0)
		return (1);
	len = 1;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_itoa(long int n)
{
	char		*str;
	int			len;

	len = ft_intlen(n) - 1;
	str = (char *)malloc(len + 2);
	if (str == NULL)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len + 1] = '\0';
	while (n >= 10)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	str[len] = n + '0';
	len = ft_putstr(str);
	free(str);
	return (len);
}
