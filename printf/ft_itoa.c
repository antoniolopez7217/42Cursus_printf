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

static int	ft_intlen(long int *ln, long int num, int sign)
{
	int			len;

	if (num == 0)
		return (1);
	len = 1;
	if (num < 0)
	{
		if (sign == 0)
		{	
			num = -num;
			len++;
		}
		else
		{
			*ln = 4294967295 + (*ln + 1);
			num = *ln;
		}
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_itoa(int n, int sign)
{
	char		*str;
	int			len;
	long int	ln;

	ln = n;
	len = ft_intlen(&ln, ln, sign) - 1;
	str = (char *)malloc(len + 2);
	if (str == NULL)
		return (0);
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	str[len + 1] = '\0';
	while (ln >= 10)
	{
		str[len] = (ln % 10) + '0';
		ln = ln / 10;
		len--;
	}
	str[len] = ln + '0';
	len = ft_putstr(str);
	free(str);
	return (len);
}
