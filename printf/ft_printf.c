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
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if(i == 0 || lst[0][i+1].content == '\0') //Comprueba que el primero y el ultimo char sea "
			if(lst[0][i].content != '"')
				return (0);
			else
				i++;
				continue;
		if (lst[0][i].content != '%') //Imprime todo lo que no sea % o las " inciales o finales
		{
			ft_putchar_fd(lst[0][i].content, 1);
			i++;
		}
		else //Comprueba el formato tras un %
		{
			i++;
			if (!ft_check_format(lst, lst[0][i].content, count))
				return (0);
			count++;
		}
		i++;
	}
	return (len);
}

int	ft_check_format(void *arg, char format, int count)
{



}