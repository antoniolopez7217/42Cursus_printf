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

int	ft_printf(char const *str, ...) //Debe devolver el numero de chars impresos
{
	va_list		arg;
	size_t		i;
	size_t		len;

	va_start(arg, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				ft_check_format(va_arg(arg, void*), str[i + 1], &len);
			else
				ft_putchar(str[i + 1], &len);
		i++;
		}
		else if (i != 0 && str[i + 1] != '\0')
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}

int	ft_check_format(void *arg, char format, size_t	*len)
{



}

int	ft_putchar(char c, size_t *len)
{


}