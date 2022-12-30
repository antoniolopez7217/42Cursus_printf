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

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		s = "(null)";
	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

void	ft_check_format(va_list arg, char format, int *len)
{
	if (format == 'c')
		*len = *len + ft_putchar(va_arg(arg, int));
	if (format == 's')
		*len = *len + ft_putstr(va_arg(arg, char *));
	if (format == 'p')
		ft_pconvert((unsigned long int)va_arg(arg, void *), len);
	if (format == 'd' || format == 'i')
		ft_itoa(va_arg(arg, int), len);
	if (format == 'u')
		ft_itoa(va_arg(arg, unsigned int), len);
	if (format == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), HEX_L, len);
	if (format == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), HEX_U, len);
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
// 	void	*str;

// 	str = 0;

// 	len1 = ft_printf(" %p ", 0);
// 	printf("\nlen1: %d\n", len1);
// 	len2 = printf(" %p ", str);
// 	printf("\nlen2: %d\n", len2);

// 	return (0);
// }