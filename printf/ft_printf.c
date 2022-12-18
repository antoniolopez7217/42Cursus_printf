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
#include "ft_itoa.c"
#include "ft_putf.c"
#include "ft_putnbr_base.c"

void	ft_check_format(va_list arg, char format, int	*len)
{
	if (format == 'c')
		*len = *len + ft_putchar(va_arg(arg, int));
	if (format == 's')
		*len = *len + ft_putstr(va_arg(arg, char *));
	if (format == 'd' || format == 'i')
		*len = *len + ft_itoa(va_arg(arg, int), 0);
	if (format == 'u')
		*len = *len + ft_itoa(va_arg(arg, long int), 1);
	if (format == 'x')
		*len = *len + ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
	if (format == 'X')
		*len = *len + ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
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

int	main(void)
{
	ft_printf("%u\n%u\n%u\n%u\n%u\n\n", -1, -2, -3, 58, 57);
	printf("%u\n%u\n%u\n%u\n%u\n", -1, -2, -3, 58, 57);

	return (0);
}