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

#include "libftprintf.h"

static int	ft_intlen(long int *n, int sign)
{
	int			len;
	long int	num;

	num = *n;
	if (num == 0)
		return (1);
	len = 1;
	if (num < 0)
	{
		num = -num;
		if (sign == 0)
			len++;
		else
			*n = -(*n);
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n, int sign)
{
	char		*str;
	int			len;
	long int	ln;

	ln = n;
	len = ft_intlen(&ln, sign);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (0);
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	str[len] = '\0';
	len--;
	while (ln >= 10)
	{
		str[len] = (ln % 10) + '0';
		ln = ln / 10;
		len--;
	}
	str[len] = ln + '0';
	return (str);
}
