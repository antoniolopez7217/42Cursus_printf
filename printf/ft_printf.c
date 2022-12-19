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

#include "ft_printf.h"
// #include "ft_itoa.c"
// #include "ft_putf.c"
// #include "ft_putnbr_base.c"

void	ft_check_format(va_list arg, char format, int *len)
{
	if (format == 'c')
		*len = *len + ft_putchar(va_arg(arg, int));
	if (format == 's')
		*len = *len + ft_putstr(va_arg(arg, char *));
	if (format == 'p')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", len);
	if (format == 'd' || format == 'i')
		ft_itoa(va_arg(arg, int), len);
	if (format == 'u')
		ft_itoa(va_arg(arg, unsigned int), len);
	if (format == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", len);
	if (format == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", len);
	if (format == '%')
		*len = *len + ft_putchar('%');
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
			i++;
			ft_check_format(arg, str[i], &len);
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	return (len);
}

// int	main(void)
// {
// 	int len1;
// 	int len2;

// 	len1 = ft_printf(" %p ", &len2);
// 	printf("\nlen1: %d\n", len1);
// 	len2 = printf(" %p ", &len2);
// 	printf("\nlen2: %d\n", len2);

// 	return (0);
// }