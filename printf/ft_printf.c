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
// #include "ft_itoa.c"
// #include "ft_putf.c"

void	ft_check_format(void *arg, char format, int	*len)
{
	if (format == 'c')
		*len = *len + ft_putchar_p(arg);
	if (format == 's')
		*len = *len + ft_putstr((char *)arg);
	if (format == 'd' || format == 'i')
		*len = *len + ft_putstr(ft_itoa((intptr_t)arg, 0));
	if (format == 'u')
		*len = *len + ft_putstr(ft_itoa((intptr_t)arg, 1));
}

int	ft_printf(char const *str, ...)
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
				ft_check_format(va_arg(arg, void *), str[i + 1], &len);
			else
				len = len + ft_putchar(str[i + 1]);
		i++;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	return (len);
}

// int	main(void)
// {
// 	ft_printf("%u\n%u\n%u\n%d\n%i\n", -69, -58, 45, 58, 57);
// 	return (0);
// }