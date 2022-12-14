/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antlopez <antlopez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:01:46 by antlopez          #+#    #+#             */
/*   Updated: 2022/12/11 18:01:48 by antlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_check_format(int arg, char format, int	*len)
{
	if (format == 'c')
		*len = *len + ft_putchar((char)arg);
	if (format == 's')
		*len = *len + ft_putstr((char *)arg);
}

int	ft_printf(char const *str, ...) //Debe devolver el numero de chars impresos
{
	va_list		arg;
	int			i;
	int			len;

	va_start(arg, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				ft_check_format(va_arg(arg, int), str[i + 1], &len);
			else
				len = len + ft_putchar(str[i + 1]);
		i++;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	printf("\nLen: %d\n", len); //BORRAR************************
	return (len);
}



int	main(void)
{
	ft_printf("Hello %s", "World");
	return (0);
}