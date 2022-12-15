/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antlopez <antlopez@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:59:00 by antlopez          #+#    #+#             */
/*   Updated: 2022/12/11 17:59:01 by antlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(char const *f, ...);
char	*ft_itoa(int n, int sign);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_check_format(va_list arg, char format, int	*len);
void	ft_putnbr_base(int nbr, char *base);

#endif