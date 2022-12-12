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

int	ft_printf(char const *f, ...)
{
	t_list	args_lst;
	va_list	args;
	int		i;

	va_start(args, f);
	i = 0;
	while (i < f)
	{
		ft_lstadd_back(args_lst, ft_lstnew(va_arg(args, char const)));
		i++;
	}
	if (ft_check_str(args_lst) == 0)
		return (0);
	return (1);
}

int	ft_check_str(t_list *lst)
{
	int	i;

	i = 0;
	while(lst[0][i].content)
	{
		if(i == 0 || lst[0][i+1].content == '\0')
			if(lst[0][i].content != '"')
				return (0);
			else
				i++;
				continue;
		if (lst[0][i].content != '%')
		{
			ft_putchar_fd(lst[0][i].content, 1);
			i++;
			continue;
		}
		


	}

}


int	ft_check_format(t_list *lst, char format, int count)
{



}